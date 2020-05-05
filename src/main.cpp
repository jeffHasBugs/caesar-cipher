#include <iostream>
#include <string>

void encrypt(std::string &message, long key)
{
    key %= 26;
    for (char &c : message) {
        // int(c) to prevent overflow
        if (isalpha(c)) {
            if (islower(c) && int(c) + key > 'z') {
                c = 'a' + (int(c) + key - 'z') - 1;
            }
            else if (isupper(c) && int(c) + key > 'Z') {
                c = 'A' + (int(c) + key - 'Z') - 1;
            }
            else c += key;
        }       
    }
}

void decrypt(std::string &message, long key)
{
    key %= 26;
    for (char &c : message) {
        // int(c) to prevent overflow
        if (isalpha(c)) {
            if (islower(c) && int(c) - key < 'a') {
                c = 'z' - ('a' - (int(c) - key)) + 1;
            }
            else if (isupper(c) && int(c) - key < 'A') {
                c = 'Z' - ('A' - (int(c) - key)) + 1;
            }
            else c -= key;
        }
    }
}

inline void collect(std::string &s, long &key)
{
    std::cout << "Message :\n";
    std::getline(std::cin, s);
    std::cout << "Key :\n";
    std::cin >> key;
    // clean input stream
    std::cin.ignore(1000, '\n');
    std::cin.clear();
}

int main()
{
    char selection = 0;
    std::string s;
    long key = 0;
    // selection
    std::cout << "Encrypt[e] / Decrypt[d]?\n";
    std::cin >> selection;
    std::cin.ignore(1000, '\n');
    std::cin.clear();
    // collect message and key and encrypt/decrypt
    collect(s, key);
    if (selection == 'e')
        encrypt(s, key);
    else
        decrypt(s, key);
    std::cout << s << std::endl;
}