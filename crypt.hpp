#ifndef CRYPT_HPP
#define CRYPT_HPP

#include <string>

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

    class SymmetricKey : public Crypt{
    public:
        SymmetricKey() = default;
        void SetKey(const std::string &);
        void SetString(const std::string &);

        void encrypt();
        void decrypt();

    private:
        std::string data;
        std::string key;
    };
}

#endif // CRYPT_HPP