#ifndef CRYPT_HPP
#define CRYPT_HPP

#include <string>
#include <initializer_list>
#include <fstream>

enum MODE{
    FILE,
    STRING  
};

namespace cry{
    class Crypt{ 
    public:
        Crypt() = default;
        virtual void Encrypt(MODE) = 0;
        virtual void Decrypt(MODE) = 0;
        virtual ~Crypt() = default;
    };

    class SymmetricKey : public Crypt{
    public:
        SymmetricKey() = default;

        void SetString(const std::string&);
        void SetKey(const std::string&);
        void SetStream(const std::string&);
        void SetStreamKey(const std::string&);

        std::string GetString() const;
        std::string GetKey() const;
        std::string GetFile() const;
        std::string GetFileKey() const;

        void Encrypt(MODE) override;
        void Decrypt(MODE) override;

        ~SymmetricKey() = default;
    private:
        std::string m_file;
        std::string m_fileKey;
        std::string m_data;
        std::string m_key;

        std::string Stoh(const std::string&); //todo
        std::string Htos(const std::string&); //todo

        bool CheckForString() const;
        bool CheckForFile() const;
    };
}

#endif // CRYPT_HPP