#include "crypt.hpp"

// for now
void cry::CrKey::encrypt(){
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
void cry::CrKey::decrypt(){
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
