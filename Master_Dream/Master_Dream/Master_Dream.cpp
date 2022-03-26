#include <nlohmann/json.hpp>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include "decrypt.h"
#include <Windows.h>

Decrypt decrypt;
using json = nlohmann::json;

int main()
{

    std::string point;
    std::cout << "[1] encrypt\n[2] decrypt\n>";
    std::getline(std::cin, point);

    if (point == "2")
    {
        decrypt.Render();
        Sleep(1000);
        exit(0x0);
    }
    system("cls");

    char fileName[30], ch;
    std::fstream fps, fpt;
    json node;
    std::cout << "Hello World By !Master Dream!\n";
    std::string file;
    std::string key;


    std::cout << "\nenter a file path\n>";
    std::getline(std::cin, file);

    std::cout << "\n\nEnter an decrypt key\n>";
    std::getline(std::cin, key);
    system("cls");
    node["encrypt"]["key"] = key;

    node["file"] = file;
    fps.open(file, std::fstream::in);

/*
    std::ofstream LoadKey;
    LoadKey.open(file);
    LoadKey << "encrypt_key_" + key;
    LoadKey.close();
*/

    std::string encrypt;
    std::string data;
    std::fstream newfile(file);
    while (std::getline(newfile, encrypt)) {
        data += encrypt + "\n";
    }
/*
    std::cout << data;
    Sleep(2000);
*/

    std::ofstream LoadKey;
    LoadKey.open(file);
    LoadKey << data + "\n";
    LoadKey << "encrypt_key_" + key;
    LoadKey.close();


    std::string encryptkey = node["encrypt"]["key"];

    fpt.open("encrypt.txt", std::fstream::out);


    while (fps >> std::noskipws >> ch)
    {
        ch = ch + 100;
        fpt << ch;
    }
    fps.close();

    fpt.close();
    fps.open(file, std::fstream::out);
    fpt.open("encrypt.txt", std::fstream::in);
    while (fpt >> std::noskipws >> ch)
    {
        fps << ch;
    }
    fps.close();
    fpt.close();
    std::cout << "\nFile " << file << " Encrypted Successfully key: " << encryptkey;
    Sleep(4000);
}
