#include "crypt.hpp"
#include <iostream>
#include <algorithm>
namespace cry{
    SymmetricKey::SymmetricKey(const std::string& data, const std::string& key,MODE mode = MODE::STRING){
        switch(mode){
            case MODE::STRING:
                m_data = data;
                m_key = key;
                break;
            case MODE::FILE:
                m_file = data;
                m_fileKey = key;
                break;
        }
    }

    void SymmetricKey::EncryptString(){
        std::string result = m_data;

        for(size_t i = 0;i<m_data.size();++i){
            for(size_t j = 0;j<m_key.size();++j){
                result[i] = m_data[i] ^ m_key[j];
            }
        }

        std::reverse(result.begin(),result.end());

        m_data = result;
        std::cout<<"\nString was encrypted!\n";
    }

    bool SymmetricKey::CheckForString() const {
        return !m_data.empty() && !m_key.empty(); 
    }

    bool SymmetricKey::CheckForFile() const {
        return !m_fileKey.empty() && !m_file.empty();
    }

    bool SymmetricKey::Encrypt(MODE mode) {
        switch(mode){
            case MODE::FILE:
                if(CheckForFile()){
                    //EncryptFile();
                }else{
                    std::cout<<"Filename with key or data is empty.\n";
                    return 1;
                }
                break;
            case MODE::STRING:
                if(CheckForString()){
                    EncryptString();
                }else{
                    std::cout<<"String or key is empty.\n";
                    return 1;
                }
                break;
        }
        return 0;
    }
    bool SymmetricKey::Decrypt(MODE mode) {
        switch(mode){
            case MODE::FILE:
                CheckForFile();
                break;
            case MODE::STRING:
                CheckForString();
                break;
        }
        return 0;
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

