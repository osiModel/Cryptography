#include "crypt.hpp"
#include <iostream> //cerr cout
#include <iomanip> // hex uppercase nouppercase setw setfill
#include <fstream>
#include <exception> // ...
#include <algorithm> // reverse
#include <sstream> // ostream stringstream
#include <stdint.h> // uint32_t uint8_t

/*
REFRENCE:


ifstream is("s.txt",fstream::binary);
    string s = "asd";
    vector<string> v;
    while(getline(is,s)){
        if(s.size() > 0)
            s[s.size()-1] = 'O';
        v.push_back(s);
    }
    is.close();
    ofstream os("s.txt");
    for(const auto& i : v){
        os << i << std::endl;
    }

*/

namespace cry{
    using ssize = std::string::size_type;

    SymmetricKey::SymmetricKey(const std::string& data, const std::string& key, MODE mode){
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

    std::string SymmetricKey::ToHex(const std::string& normStr, bool upperCase){
        std::ostringstream ss;

        for(ssize i = 0;i<normStr.size();++i){
            ss<<std::hex<<std::setfill('0')<<std::setw(2)<<(upperCase ? std::uppercase : std::nouppercase) << (int)normStr[i];
        }
        return ss.str();
    }

    std::string SymmetricKey::ToString(const std::string& hexValue, bool upperCase){
        std::string result;

        for(ssize i = 0;i<hexValue.size()/2;++i){
            std::stringstream ss;
            ss<<std::hex<<hexValue.substr(i*2,2);
            uint32_t c{};
            ss>>c;

            result.push_back(static_cast<uint8_t>(c));
        }

        return result;
    }

    void SymmetricKey::EncryptFile() const{
        using std::fstream;
        fstream is(m_file,fstream::in | 
                        fstream::out  |
                        fstream::binary);

        if(!is)
            std::cerr<<"Can't find or read file.\n";
        std::fstream result;
        std::string line;
        while(getline(is,line)){
            
        }
    }

    void SymmetricKey::DecryptFile() const{

    }

    void SymmetricKey::EncryptString(){
        std::string result = m_data;

        for(ssize i = 0;i<m_data.size();++i){
            for(ssize j = 0;j<m_key.size();++j){
                result[i] = m_data[i] ^ m_key[j];
            }
        }

        std::reverse(result.begin(),result.end());
        m_data = ToHex(result);
        std::cout<<"String was encrypted!\n";
    }

    void SymmetricKey::DecryptString(){
        std::string result = ToString(m_data);
        std::reverse(result.begin(),result.end());
        m_data = result;
        
        for(ssize i = 0;i<m_data.size();++i){
            for(ssize j = 0;j<m_key.size();++j){
                result[i] = m_data[i] ^ m_key[j];
            }
        }

        m_data = result;
        std::cout<<"String was decrypted!\n";
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
                    // todo
                }else{
                    std::cerr<<"ERROR: EMPTY FILE NAME OR KEY.\n";
                    return false;
                }
                break;
            case MODE::STRING:
                if(CheckForString()){
                    EncryptString();
                }else{
                    std::cerr<<"ERROR: EMPTY STRING OR KEY.\n";
                    return false;
                }
                break;
        }
        return true;
    }
    bool SymmetricKey::Decrypt(MODE mode) {
        switch(mode){
            case MODE::FILE:
                if(CheckForFile()){
                    // todo
                }else{
                    std::cerr<<"ERROR: EMPTY FILE NAME OR KEY.\n";
                    return false;
                }
                break;
            case MODE::STRING:
                if(CheckForString()){
                    DecryptString();
                }else{
                    std::cerr<<"ERROR: EMPTY STRING OR KEY.\n";
                    return false;
                }
                break;
        }
        return true;
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

