//Реалізувати роботу з великими дійсними числами. Програма запитує користувача ввести 2 великих числа(можна ввести від’ємне),
//програма інтерпретує введений рядок числа і зберігає його у якомусь представленні (наприклад, у масиві).
//Програма виводить введені рядки. Додатково:
//1) + реалізувати операцію додавання
//a) + реалізувати операцію добутку
//b) + реалізувати операцію ділення


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string cleanZeros(string s) {
    if (s.empty()) return "0";
    if (s[0] == '-') {
        int k = 1;
        while (k < s.length() - 1  && s[k] == '0') {
            k++;
        }
        string result = "-";
        for (int p=k; p < s.length(); p++) {
            result = result + s[p];
        }
        if (k == s.length() - 1 && s[k] == '0') {
            return "0";
        }
        return result;

    }
    else {
        int i = 0;
        while (i < s.length() - 1 && s[i] == '0') {
            i++;
        }
        string result = "";

        for (int j = i; j < s.length(); j++) {
            result = result + s[j];
        }
        return result;
    }

    /*while (i < s.length() - 1 && s[i] == '0') {
        i++;
    }
    while (k < s.length()  && s[k] == '0') {
        k++;
    }*/



}
bool Greater_or_Equals(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() > b.length();
    }
    return a >= b;
}

string add(string a, string b) {
    string res = "";
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        res += (sum % 10 + '0');
        carry = sum / 10;
    }

    reverse(res.begin(), res.end());
    return cleanZeros(res);
}

string subtract(string a, string b) {
    string res = "";
    int borrow = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0) {
        int digitA = (a[i] - '0') - borrow;
        int digitB = (j >= 0) ? (b[j] - '0') : 0;

        if (digitA < digitB) {
            digitA += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        res += ((digitA - digitB) + '0');
        i--;
        j--;
    }

    reverse(res.begin(), res.end());
    return cleanZeros(res);
}

string multiply(string a, string b) {
    if (a == "0" || b == "0") return "0";

    string result(a.length() + b.length(), '0');

    for (int i = a.length() - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = b.length() - 1; j >= 0; j--) {
            int cur = (result[i + j + 1] - '0') + (a[i] - '0') * (b[j] - '0') + carry;
            result[i + j + 1] = (cur % 10 + '0');
            carry = cur / 10;
        }
        result[i] += carry;
    }

    return cleanZeros(result);
}

string divide(string a, string b, string &fractional) {
    string result = "";
    string current = "";
    int precision = 10;

    for (int i = 0; i < a.length(); i++) {
        current += a[i];
        current = cleanZeros(current);

        int count = 0;
        while (Greater_or_Equals(current, b)) {
            current = subtract(current, b);
            count++;
        }
        result += (count + '0');
    }

    fractional = "";
    for (int step = 0; step < precision; step++) {
        if (current == "0") break;

        current += '0';
        current = cleanZeros(current);

        int count = 0;
        while (Greater_or_Equals(current, b)) {
            current = subtract(current, b);
            count++;
        }
        fractional += (count + '0');
    }

    return cleanZeros(result);
}

void printResult(string digits, int decimals, bool isNegative) {
    while (digits.length() <= decimals) {
        digits = "0" + digits;
    }

    string whole = digits.substr(0, digits.length() - decimals);
    string frac = digits.substr(digits.length() - decimals);

    whole = cleanZeros(whole);

    while (frac.length() > 0 && frac.back() == '0') {
        frac.pop_back();
    }

    string finalStr = whole;
    if (!frac.empty()) {
        finalStr += "." + frac;
    }

    bool isZero = (whole == "0" && frac.empty());

    if (isNegative && !isZero) {
        cout << "-";
    }
    cout << finalStr;
}

int main() {
    string s1, s2;

    cout << "Enter first number: ";
    cin >> s1;
    cout << "Enter second number: ";
    cin >> s2;

    cout << endl << "You entered:" << endl;
    cout << "A = " << cleanZeros(s1) << endl;
    cout << "B = " << cleanZeros(s2) << endl;


    bool neg1 = false;
    int start1 = 0;
    if (!s1.empty() && s1[0] == '-') {
        neg1 = true;
        start1 = 1;
    }

    int dot1 = -1;
    for (int i = start1; i < s1.length(); i++) {
        if (s1[i] == '.' || s1[i] == ',') {
            dot1 = i;
            break;
        }
    }

    int decimals1 = 0;
    if (dot1 != -1) {
        decimals1 = s1.length() - 1 - dot1;
    }

    string temp1 = "";
    for (int i = start1; i < s1.length(); i++) {
        if (i != dot1) {
            temp1 += s1[i];
        }
    }
    s1 = cleanZeros(temp1);

    bool neg2 = false;
    int start2 = 0;
    if (!s2.empty() && s2[0] == '-') {
        neg2 = true;
        start2 = 1;
    }

    int dot2 = -1;
    for (int i = start2; i < s2.length(); i++) {
        if (s2[i] == '.' || s2[i] == ',') {
            dot2 = i;
            break;
        }
    }

    int decimals2 = 0;
    if (dot2 != -1) {
        decimals2 = s2.length() - 1 - dot2;
    }

    string temp2 = "";
    for (int i = start2; i < s2.length(); i++) {
        if (i != dot2) {
            temp2 += s2[i];
        }
    }
    s2 = cleanZeros(temp2);

    string product = multiply(s1, s2);
    cout << endl << "A * B = ";
    printResult(product, decimals1 + decimals2, neg1 != neg2);
    cout << endl;

    string addA = s1;
    string addB = s2;
    int maxDecimals = max(decimals1, decimals2);

    if (decimals1 < maxDecimals) {
        addA.append(maxDecimals - decimals1, '0');
    }
    if (decimals2 < maxDecimals) {
        addB.append(maxDecimals - decimals2, '0');
    }

    addA = cleanZeros(addA);
    addB = cleanZeros(addB);

    cout << "A + B = ";
    if (neg1 == neg2) {
        printResult(add(addA, addB), maxDecimals, neg1);
    } else if (Greater_or_Equals(addA, addB)) {
        printResult(subtract(addA, addB), maxDecimals, neg1);
    } else {
        printResult(subtract(addB, addA), maxDecimals, neg2);
    }
    cout << endl;
    cout << "A / B = ";
    if (addB == "0") {
        cout << "Division by zero is not allowed" << endl;
        return 0;
    }

    string fractional;
    string whole = divide(addA, addB, fractional);

    string divResult = whole;
    while (fractional.length() > 0 && fractional.back() == '0') {
        fractional.pop_back();
    }
    if (!fractional.empty()) {
        divResult += "." + fractional;
    }

    if (neg1 != neg2 && divResult != "0") {
        cout << "-";
    }
    cout << divResult << endl;

    return 0;
}