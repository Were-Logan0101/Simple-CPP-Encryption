#include "caeserCipher.cpp"
#include <iostream>
#include <cstring>
#include <iomanip>
#include "md5.c"
using namespace std;
string toHexString(const uint8_t* data, size_t length) {
    ostringstream oss;
    for (size_t i = 0; i < length; ++i) {
        oss << hex << setw(2) << setfill('0') << static_cast<int>(data[i]);
    }
    return oss.str();
}
void showHelp() {
    std::cout << "Usage: Simple-Encrypter [command] [argument]\n";
    std::cout << "Commands:\n";
    std::cout << "  md5 [text]   Generate MD5 Hash Of The Given Text\n";
    std::cout << "  encrypt [text]     Apply Caeser Cipher On The Given Text\n";
    std::cout << "  decrypt [text]     Decrypt Caeser Cipher On Given Text\n";
}
string getText(string inputText) {
    string text;
    cout << "Enter String To Hash: ";
    getline(cin, text);
    return text;
}
int main(int argc, char* argv[]) {
    if (argc < 2) {
        showHelp();
        return 1;
    }
    std::string command = argv[1];
    if (argc != 3) {
        std::cerr << "Error: Missing name argument for '" << command <<"' command.\n";
        return 1;
    }
    if (command == "md5") {
        uint8_t* hash = md5String(argv[2]);
        if (hash == nullptr) {
            cerr << "Error: Failed to compute MD5 hash." << endl;
            return 1;
        }
        string hashString = toHexString(hash, 16);
        cout << "MD5 Hash: " << hashString;
    }
    else if (command == "encrypt") {
        cout << "Encrypted Text: " << encrypt(argv[2]);
    }
    else if (command == "decrypt") {
        cout << "Decrypted Text: " << decrypt(argv[2]);
    }
    return 0;
}