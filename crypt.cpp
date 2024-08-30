#include "crypt.hpp"
#include <iostream>



// for now
/*
void cry::AES::encrypt(){
    int key{};
    char c = 'a';
    std::cout<<"key: ";
    std::cin>>key;
    std::fstream fin,fout;
    fin.open("file.txt",std::fstream::in);
    fout.open("encrypt.txt",std::fstream::out);
    while(fin>>std::noskipws>>c){
        int temp = c+key;

        fout<<char(temp);
    }
    fin.close();
    fout.close();
}
void cry::AES::decrypt(){
    int key{};
    char c = 'a';
    std::cout<<"key: ";
    std::cin>>key;
    std::fstream fin,fout;
    fin.open("encrypt.txt",std::fstream::in);
    fout.open("decrypt.txt",std::fstream::out);
    while(fin>>std::noskipws>>c){
        int temp = c-key;

        fout<<char(temp);
    }
    fin.close();
    fout.close();
}
*/
