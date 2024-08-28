#ifndef CRYPT_HPP
#define CRYPT_HPP

#include <string>
#include <iostream>
#include <fstream>

enum MODE{
    FILE,
    STRING  
};
namespace cry{
    class Crypt{ 
    public:
        Crypt() = default;
        Crypt(const std::string & data);
        virtual void encrypt() const = 0;
        virtual void decrypt() const = 0;
        virtual ~Crypt() = default;
    };

    class SHA256 : public Crypt{

    }; // todo

    class CrKey : public Crypt{
    public:
        CrKey() = default;
        CrKey(MODE m);
        CrKey(const std::string & s); // to work with string    
        CrKey(std::fstream & is); // to work with file

        void ChangeMode(MODE mode);
        void Open(std::fstream & fs);
        void Close(std::fstream & fs);

        void encrypt();
        void decrypt();

        ~CrKey()=default;
    private:
        MODE m_mode = FILE; // by default
        std::string data;
        int32_t key{};
    };
}

#endif // CRYPT_HPP