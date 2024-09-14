#include "crypt.hpp"
#include <iostream> //cerr cout
#include <iomanip> // hex uppercase nouppercase setw setfill
#include <fstream> // ofstream ifstream 
#include <exception> // ...
#include <algorithm> // reverse
#include <sstream> // ostringstream
#include <stdint.h> // uint32_t uint8_t
#include <vector> // vector


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

    std::string SymmetricKey::FileToString(const std::string& file) const{
        std::string result;
        std::ifstream ifs(file);
        std::string line;

        while(getline(ifs,line))
            result+=line;
        return result;
    }

    std::string SymmetricKey::ToHex(const std::string& normStr, bool upperCase) const{
        std::ostringstream ss;

        for(ssize i = 0;i<normStr.size();++i){
            ss<<std::hex<<std::setfill('0')<<std::setw(2)<<(upperCase ? std::uppercase : std::nouppercase) << (int)normStr[i];
        }
        return ss.str();
    }

    std::string SymmetricKey::ToString(const std::string& hexValue, bool upperCase) const{
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


    std::string SymmetricKey::EncryptString(const std::string& data,const std::string& key) const{
        std::string result = data;

        for(ssize i = 0;i<data.size();++i){
            for(ssize j = 0;j<key.size();++j){
                result[i] = data[i] ^ key[j];
            }
        }

        std::reverse(result.begin(),result.end());
        return ToHex(result);
    }

    std::string SymmetricKey::DecryptString(std::string data,const std::string& key) const{
        std::string result = ToString(data);
        std::reverse(result.begin(),result.end());
        data = result;
        
        for(ssize i = 0;i<data.size();++i){
            for(ssize j = 0;j<key.size();++j){
                result[i] = data[i] ^ key[j];
            }
        }

        return result;
    }

    void SymmetricKey::EncryptFile() const {
        std::ifstream ifs(m_file);
        std::vector<std::string> lines;
        std::string line;
        std::string key = FileToString(m_key);

        if(!ifs)
            std::cerr<<"Can't find or read file\n";

        while(getline(ifs,line)){
            if(line.size() > 0)
                lines.push_back(EncryptString(line,key));
            else
                lines.push_back("");
        }
        ifs.close();

        std::ofstream ofs(m_file);
        for(const auto& i : lines){
            ofs<<i<<std::endl;
        }
        ofs.close();
    }

    void SymmetricKey::DecryptFile() const {
        std::ifstream ifs(m_file);
        std::vector<std::string> lines;
        std::string line;
        std::string key = FileToString(m_key);

        if(!ifs)
            std::cerr<<"Can't find or read file \n";

        while(getline(ifs,line)){
            if(line.size() > 0)
                lines.push_back(DecryptString(line,m_key));
            else 
                lines.push_back("");
        }
        ifs.close();

        std::ofstream ofs(m_file);
        for(const auto& i : lines){
            ofs<<i<<std::endl;
        }
        ofs.close();
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
                    EncryptFile();
                    std::cout<<"File is encrypted!\n";
                }else{
                    std::cerr<<"ERROR: EMPTY FILE NAME OR KEY\n";
                    return false;
                }
                break;
            case MODE::STRING:
                if(CheckForString()){
                    m_data = EncryptString(m_data,m_key);
                    std::cout<<"String is encrypted!\n";
                }else{
                    std::cerr<<"ERROR: EMPTY STRING OR KEY\n";
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
                    DecryptFile();
                    std::cout<<"File is decrypted!\n";
                }else{
                    std::cerr<<"ERROR: EMPTY FILE NAME OR KEY\n";
                    return false;
                }
                break;
            case MODE::STRING:
                if(CheckForString()){
                    m_data = DecryptString(m_data,m_key);
                    std::cout<<"String is decrypted!\n";
                }else{
                    std::cerr<<"ERROR: EMPTY STRING OR KEY\n";
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

