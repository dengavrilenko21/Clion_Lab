#include <iostream>
#include <fstream>
#include <string>

bool isDuplicate(const std::string words[], int count, const std::string& target) {
    for (int i = 0; i < count; i++) {
        if (words[i] == target) {
            return true;
        }
    }
    return false;
}

int main() {
    std::string file1_name = "../Modular 2/file1.txt";
    std::string file2_name = "../Modular 2/file2.txt";
    std::string output_name = "../Modular 2/output.txt";

    std::ofstream makeFile1(file1_name);
    if (!makeFile1) {
        std::cout << "file not found" << std::endl;
        return 1;
    }
    makeFile1 << "sport bear beer beer  " << std::endl;
    makeFile1.close();

    std::ofstream makeFile2(file2_name);
    if (!makeFile2) {
        std::cout << "file not found" << std::endl;
        return 1;
    }
    makeFile2 << "orange beer sport Konotop" << std::endl;
    makeFile2.close();

    const int MAX_WORDS = 1000;
    std::string unique_words[MAX_WORDS];
    int word_count = 0;
    std::string word;

    std::ifstream inFile1(file1_name);
    if (!inFile1) {
        std::cout << "file not found" << std::endl;
        return 1;
    }
    while (inFile1 >> word) {
        if (!isDuplicate(unique_words, word_count, word)) {
            unique_words[word_count] = word;
            word_count++;
        }
    }
    inFile1.close();

    std::ifstream inFile2(file2_name);
    if (!inFile2) {
        std::cout << "file not found" << std::endl;
        return 1;
    }
    while (inFile2 >> word) {
        if (!isDuplicate(unique_words, word_count, word)) {
            unique_words[word_count] = word;
            word_count++;
        }
    }
    inFile2.close();
    
    std::ofstream outFile(output_name);
    if (!outFile) {
        std::cout << "file not found" << std::endl;
        return 1;
    }
    for (int i = 0; i < word_count; i++) {
        outFile << unique_words[i] << std::endl;
    }
    outFile.close();

    return 0;
}