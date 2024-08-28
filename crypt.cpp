#include "crypt.hpp"
Crypt::Crypt(const std::string & data): m_data(data){ std::cout<<"Data: "<<m_data<<std::endl;}
void Crypt::encrypt(){
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
void Crypt::decrypt(){
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
