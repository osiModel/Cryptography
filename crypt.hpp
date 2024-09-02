#ifndef CRYPT_HPP
#define CRYPT_HPP

#include <string>
#include <initializer_list> // will be

enum class MODE{
    FILE,
    STRING
};

namespace cry{
    class Crypt{ 
    public:
        Crypt() = default;
        virtual bool Encrypt(MODE) = 0;
        virtual bool Decrypt(MODE) = 0;
        virtual ~Crypt() = default;
    };

    class SymmetricKey : public Crypt{
    public:
        SymmetricKey() = default;
        SymmetricKey(const std::string&,const std::string&, MODE = MODE::STRING);
        
        void SetString(const std::string&);
        void SetKey(const std::string&);
        void SetStream(const std::string&);
        void SetStreamKey(const std::string&);

        std::string GetString() const;
        std::string GetKey() const;
        std::string GetFile() const;
        std::string GetFileKey() const;

        bool Encrypt(MODE) override;
        bool Decrypt(MODE) override;

        ~SymmetricKey() = default;

    private:
        std::string m_file;
        std::string m_fileKey;
        std::string m_data;
        std::string m_key;

        void EncryptString();
        void EncryptFile(); // todo
        void DecryptString();
        void DecryptFile(); // todo

        std::string ToHex(const std::string&,bool = false);
        std::string ToString(const std::string&,bool = false);

        bool CheckForString() const;
        bool CheckForFile() const;
    };
}

#endif // CRYPT_HPP
