#include <bits/stdc++.h>
#include <cstring>
#include <unordered_map>
#include <cctype>
using namespace std;
const std::unordered_map<char, char> CAESER_MAP = {
    {'a', 'f'}, {'b', 'g'}, {'c', 'h'}, {'d', 'i'}, {'e', 'j'},{'f', 'k'}, {'g', 'l'}, {'h', 'm'}, {'i', 'n'}, {'j', 'o'},{'k', 'p'}, {'l', 'q'}, {'m', 'r'}, {'n', 's'}, {'o', 't'},{'p', 'u'}, {'q', 'v'}, {'r', 'w'}, {'s', 'x'}, {'t', 'y'},{'u', 'z'}, {'v', 'a'}, {'w', 'b'}, {'x', 'c'}, {'y', 'd'},
    {'0', '5'}, {'1', '6'}, {'2', '7'}, {'3', '8'}, {'4', '9'},{'5', '0'}, {'6', '1'}, {'7', '2'}, {'8', '3'}, {'9', '4'},
    {'.', ','}, {',', '.'}, {'!', '?'}, {'?', '!'},{';', ':'}, {':', ';'}, {'\'', '\"'}, {'\"', '\''},{' ', ' '},{'-', '_'}, {'_', '-'}, {'(', ')'}, {')', '('},{'[', ']'}, {']', '['}, {'{', '}'}, {'}', '{'}
};
std::unordered_map<char, char> createReverseMap(const std::unordered_map<char, char>& map) {
    std::unordered_map<char, char> reverseMap;
    for (const auto& pair : map) {
        reverseMap[pair.second] = pair.first;
    }
    return reverseMap;
}
string _encrypt(const string& text,const std::unordered_map<char, char>& caeserMap) {
    stringstream result;
    for (char c : text) {
        bool isLower = islower(c);
        auto fchar = caeserMap.find(tolower(c));
        if (fchar != caeserMap.end()) {
            auto nChar = fchar->second;
            if (!isLower) {
                nChar = toupper(nChar);
            }
            result << nChar;
        }
        else {
            result << c;
        }
    }
    return result.str();
}
string decrypt(string text) {
    unordered_map decryptCaeserMap = createReverseMap(CAESER_MAP);
    return _encrypt(text,decryptCaeserMap);
}
string encrypt(string text) {
    return _encrypt(text,CAESER_MAP);
}