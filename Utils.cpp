#include "Utils.h"

vector<string> Utils::splitString(string s, const string &delimiter) {
    size_t pos = 0;
    vector<string> strings;

    while ((pos = s.find(delimiter)) != std::string::npos) {
        strings.push_back(s.substr(0, pos));
        s.erase(0, pos + delimiter.length());
    }

    strings.push_back(s);

    return strings;
}

std::string Utils::trim(string &s) {
    s.erase(s.find_last_not_of(' ') + 1);
    s.erase(0, s.find_first_not_of(' '));

    return s;
}
