#pragma once
#include <string>
#include <iostream>
#include <fstream>
namespace cry{
    class Crypt{
    public:
        Crypt() = default;
        Crypt(const std::string & data);
        virtual void encrypt() const = 0;
        virtual void decrypt() const = 0;
    private:
        
    };

    class SHA256 : public Crypt{

    };

    class CrKey : public Crypt{

    };
}