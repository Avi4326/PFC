#include <iostream>
#include <fstream>
#include <string>
int main() {
 std::ifstream inputFile("FILE.txt");
 std::ofstream outputFile("OUTPUTFILE.txt");

 if (!inputFile.is_open()) {
 std::cout << "Failed to open input file." << std::endl;
 return 1;
 }

 if (!outputFile.is_open()) {
 std::cout << "Failed to create output file." << std::endl;
 return 1;
 }

 char ch;
 while (inputFile.get(ch)) {
 if (!std::isspace(ch)) {
 outputFile << ch;
 }
 }

 inputFile.close();
 outputFile.close();

 std::cout << "File copied successfully!" << std::endl;

 return 0;
}