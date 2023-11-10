#include <iostream>
#include <string>

std::string encodeString(const std::string& s) {
    std::string encodedString;
    int count = 1;

    for (int i = 0; i < s.length(); i++) {
        if (i + 1 < s.length() && s[i] == s[i + 1]) {
            count++;
        } else {
            encodedString += s[i] + std::to_string(count);
            count = 1;
        }
    }

    return encodedString;
}

int main() {
    std::string s;

    std::cout << "Nhap chuoi: ";
    std::cin >> s;

    std::string encoded = encodeString(s);
    std::cout << "Chuoi ma hoa: " << encoded << std::endl;

    return 0;
}