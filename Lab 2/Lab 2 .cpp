#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string cleanZeros(string s) {
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
bool Greater_or_Equals(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() > b.length();
    }
    return a >= b;
}
string add(string a, string b) {
    string result1 = "";
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;
    while (i >= 0 && j >= 0) {
        int sum = a[i] - '0' + b[j] - '0' + carry;
        result1 += to_string(sum % 10);
        carry = sum / 10;
        i--;
        j--;
    }

    // 2. Если остались цифры только в a
    while (i >= 0) {
        int sum = a[i] - '0' + carry;
        result1 += to_string(sum % 10);
        carry = sum / 10;
        i--;
    }

    // 3. Если остались цифры только в b
    while (j >= 0) {
        int sum = b[j] - '0' + carry;
        result1 += to_string(sum % 10);
        carry = sum / 10;
        j--;
    }

    // 4. Если остался перенос (например, 99 + 1)
    if (carry > 0) {
        result1 += to_string(carry);
    }

    reverse(result1.begin(), result1.end());
    return result1;
}
int main() {
    string s1;
    cout<<"Enter your number: ";
    cin>>s1;
    cout<<cleanZeros(s1);



    return 0;
}

