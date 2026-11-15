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
    std::string file1_path = "../file1.txt";
    std::string file2_path = "../file2.txt";
    std::string output_path = "../output.txt";

    // 1. Automatically create file1.txt with sample words if it doesn't exist
    std::ofstream initFile1(file1_path, std::ios::app);
    if (initFile1) {
        // If file is empty, write default words
        initFile1.seekp(0, std::ios::end);
        if (initFile1.tellp() == 0) {
            initFile1 << "apple banana orange apple\n";
        }
        initFile1.close();
    }

    // 2. Automatically create file2.txt with sample words if it doesn't exist
    std::ofstream initFile2(file2_path, std::ios::app);
    if (initFile2) {
        // If file is empty, write default words
        initFile2.seekp(0, std::ios::end);
        if (initFile2.tellp() == 0) {
            initFile2 << "banana grape kiwi apple\n";
        }
        initFile2.close();
    }

    const int MAX_WORDS = 1000;
    std::string unique_words[MAX_WORDS];
    int word_count = 0;
    std::string word;

    // Read from the first file
    std::ifstream inFile1(file1_path);
    if (!inFile1) {
        std::cout << "file not found" << std::endl;
        return 1;
    }
    while (inFile1 >> word) {
        if (!isDuplicate(unique_words, word_count, word) && word_count < MAX_WORDS) {
            unique_words[word_count] = word;
            word_count++;
        }
    }
    inFile1.close();

    // Read from the second file
    std::ifstream inFile2(file2_path);
    if (!inFile2) {
        std::cout << "file not found" << std::endl;
        return 1;
    }
    while (inFile2 >> word) {
        if (!isDuplicate(unique_words, word_count, word) && word_count < MAX_WORDS) {
            unique_words[word_count] = word;
            word_count++;
        }
    }
    inFile2.close();

    // Write unique words to the output file (creates output.txt automatically)
    std::ofstream outFile(output_path);
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