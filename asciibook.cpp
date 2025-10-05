#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//Code untuk display element dalam bentuk ASCII

std::string revertASCII(std::vector<int> letter);

int main() {
	
	std::string element;
	int SIZE;
	std::vector<int> letter;
	std::fstream file;

	std::cout << "Enter lines count for one paragraph: ";
	std::cin >> SIZE;
	std::cin.ignore();

	for (int i = 0; i < SIZE; i++) {
		std::cout << "Write a sentences in lines #" << i<<": ";
		std::getline(std::cin, element);

		//Nested loop akan iterates character yang ada dalam setiap element.
		for (char e: element) {
			letter.push_back((int)e); //Code masukkan nilai ASCII dalam vector letter.
		}
		letter.push_back((int)' ');
	}
	
	
	std::cout << "\nReturning the ASCII Value: ";
	std::cout << revertASCII(letter);

	
	file.open("decrypt.txt", std::ios::out);
	if (file.is_open()) {
		for (int j : letter) {
			file << j << " ";
		}
		file<<std::endl;
		file.close();
	}

	return 0;
}
std::string revertASCII(std::vector<int> letter) {
	std::string temp;

	for (int characters: letter) {
		temp += static_cast<char>(characters);
	}
	return temp;
}