#include <iostream>
#include <fstream>
#include <string>

std::string twoDigitsToWords(int n) {
    if (n == 0) return "zero";

    std::string units[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen","fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    std::string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    if (n < 10) {
        return units[n];
    } else if (n >= 10 && n < 20) {
        return teens[n - 10];
    } else {
        int tens_digit = n / 10;
        int units_digit = n % 10;
        if (units_digit == 0) {
            return tens[tens_digit];
        } else {
            return tens[tens_digit] + " " + units[units_digit];
        }
    }
}

std::string numberToWords(double val) {
    if (val < 0.0 || val > 100.0) {
        return "out of range";
    }

    int integer_part = static_cast<int>(val);
    int fractional_part = static_cast<int>((val - integer_part) * 100 + 0.5);

    std::string result = "";

    if (integer_part == 100) {
        result = "one hundred";
    } else if (integer_part == 0) {
        result = "zero";
    } else {
        result = twoDigitsToWords(integer_part);
    }

    if (fractional_part > 0) {
        result += " point ";
        if (fractional_part < 10) {
            result += "zero " + twoDigitsToWords(fractional_part);
        } else {
            result += twoDigitsToWords(fractional_part);
        }
    }

    return result;
}

int main() {
    double number;
    std::cout << "Enter a number between 0.0 and 100.00: ";
    std::cin >> number;

    if (number < 0.0 || number > 100.0) {
        std::cout << "Invalid input range." << std::endl;
        return 1;
    }

    std::string words = numberToWords(number);
    std::cout << "Result: " << words << std::endl;

    std::string output_path = "../Modular 2/number.txt";
    std::ofstream outFile(output_path);
    if (!outFile) {
        std::cout << "file not found" << std::endl;
        return 1;
    }

    outFile << number << " - " << words << std::endl;
    outFile.close();

    return 0;
}