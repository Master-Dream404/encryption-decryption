#pragma once
#include <Windows.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

using json = nlohmann::json;

json node2;
std::fstream fps, fpt;

class Decrypt
{
private:
	std::string key;
	std::string file;
	std::string data;
	std::string find = "encrypt_key_";
	char ch;
public:
	void Render()
	{
		system("cls");
		node2["decrypt"]["key"];
		std::cout << "Enter File Path\n>";
		std::getline(std::cin, file);

		std::cout << "\nEnter decrypt key\n>";
		std::getline(std::cin, key);
		node2["decrypt"]["key"] = key;
		find += key;

		system("cls");
		system("cls");
		system("cls");

		fps.open("Decrypt.txt", std::fstream::out);

		fpt.open(file, std::fstream::in);


		while (fpt >> std::noskipws >> ch)
		{
			ch = ch - 100;
			data += ch;
			//fps << ch;
		}
		if (data.find(find) == std::string::npos)
		{
			fps.clear();
			fps << "decrypt key error";
			fps.close();
			fpt.close();
			std::cout << "\nFile " << file << " decrypt Error!";
		}
		else
		{
			data.replace(data.find(find), data.length(), "");
			fps << data;
			fps.close();
			fpt.close();
			std::cout << "\nFile " << file << " Decrypted Successfully!";
		}
		Sleep(3000);




	}
};
