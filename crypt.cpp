#include "crypt.hpp"

namespace cry{
    void SymmetricKey::Encrypt(MODE mode){
        switch(mode){
            case FILE:
                CheckForFile();
                break;
            case STRING:
                CheckForString();
                break;
        }
    }

    void SymmetricKey::Decrypt(MODE mode){
        switch(mode){
            case FILE:
                CheckForFile();
            case STRING:
                CheckForString();
        }
    }

    std::string SymmetricKey::GetString() const {
        return m_data;
    }

    std::string SymmetricKey::GetKey() const {
        return m_key;
    }

    std::string SymmetricKey::GetFile() const {
        return m_file;
    }

    std::string SymmetricKey::GetFileKey() const {
        return m_fileKey;
    }

    void SymmetricKey::SetString(const std::string& data) {
        m_data = data;
    }

    void SymmetricKey::SetKey(const std::string& key){
        m_key = key;
    }

    void SymmetricKey::SetStream(const std::string& file){
        m_file = file;
    }

    void SymmetricKey::SetStreamKey(const std::string& fileKey){
        m_fileKey = fileKey;
    }

}

