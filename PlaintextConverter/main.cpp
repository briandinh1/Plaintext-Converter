#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

void end() {
	std::string str;
	std::cout << "Press any key to exit..." << std::endl;
	std::getline(std::cin, str);
}

std::string getFileName() {
	std::cout << "Enter file name to be converted: ";
	std::string fileName;
	std::getline(std::cin, fileName);
	return fileName;
}

std::string readFile(std::string fileName) {
	std::ifstream inFile;
	inFile.open(fileName);
	if (!inFile) {
		std::cout << "Unable to open input file" << std::endl;
		end();
		exit(1);
	}
	try {
		std::string word;
		std::string str = "";
		while (inFile >> word)
			str += word + ' ';
		std::cout << "Read successful" << std::endl;
		return str;
	}
	catch (const std::exception& e) {
		std::cout << "Read error" << std::endl;
	}
}

void writeFile(const std::string& str) {
	std::ofstream outFile;
	outFile.open("convertedText.txt");
	if (!outFile) {
		std::cout << "Unable to open output file" << std::endl;
		end();
		exit(1);
	}
	try {
		outFile << str;
		std::cout << "File has been converted" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Conversion error" << std::endl;
	}
}

// remove ascii values > 127
void cleanString(std::string& str) {
	for (char c : str) 
		if (c > 127)
			c = 0; // null it out
}

int main() {
	std::string fileName = getFileName();
	std::string text = readFile(fileName);
	cleanString(text);
	writeFile(text);
	end();
	return 0;
}