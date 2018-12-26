#include<string>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>

char * convertToBinary(std::string data) {
	char * result = new char[data.length() * 8 + 1 + data.length()];
	int index = data.length() * 8 - 1 + data.length();
	for (int j = data.length() - 1; j >= 0; j--) {
		result[index--] = ' ';
		for (int i = 0; i < 8; i++) {
			result[index--] = (data[j] >> i & 1) == 0 ? '0' : '1';
		}
	}
	result[data.length() * 8 + data.length()] = '\0';
	return result;
}

void main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	std::string input_string;
	char ch;
	do {
		system("cls");
		std::cout << "Text to Binary Converter" << std::endl;
		std::cout << "program by atthawut" << std::endl;
		std::cout << std::endl << "write your text : ";
		std::getline(std::cin, input_string);
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << std::endl << "Result = " << convertToBinary(input_string) << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << std::endl << "press space bar for write new text . . ." << std::endl;
		std::cout << "press esc for exit . . ." << std::endl;
		do 
			ch = getch();
		while (ch != 32 && ch != 27);
	} while (ch!=27);
}