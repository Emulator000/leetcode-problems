#include "0151-ReverseWordsInAString.h"
#include "Utils.h"

#include <stack>
#include <utility>

string ReverseWordsInAString::reverseWords(string s) {
    std::reverse(s.begin(), s.end());

    size_t pos = 0;
    string result;

    while ((pos = s.find(' ')) != string::npos) {
        auto newS = s.substr(0, pos);
        std::reverse(newS.begin(), newS.end());

        if (!newS.empty()) {
            if (!result.empty()) {
                result += " ";
            }

            result += newS;
        }

        s.erase(0, pos + 1);
    }

    if (!s.empty()) {
        std::reverse(s.begin(), s.end());

        if (!result.empty()) {
            result += " ";
        }

        result += s;
    }

    return result;
}

string ReverseWordsInAString::reverseWordsNative(string s) {
    std::reverse(s.begin(), s.end());

    size_t pos, start = 0;
    while ((pos = s.substr(start, -1).find(' ')) != string::npos) {
        pos = start + pos;

        if (s.substr(start, 1) != " ") {
            std::reverse(s.begin() + (long) start, s.begin() + (long) pos);

            start = (long) pos + 1;
        } else {
            s.erase(start, 1);

            start = (long) pos;
        }
    }

    std::reverse(s.begin() + (long) start, s.end());

    if (s.substr(s.size() - 1, 1) == " ") {
        s.erase(s.size() - 1, 1);
    }

    return s;
}

string ReverseWordsInAString::reverseWordsVector(string s) {
    auto strings = Utils::splitString(std::move(s));
    std::reverse(strings.begin(), strings.end());

    string result;
    for (auto word = strings.begin(); word != strings.end(); word++) {
        result += *word;

        if (word != strings.end() - 1) {
            result += " ";
        }
    }

    return result;
}

string ReverseWordsInAString::reverseWordsStack(string s) {
    size_t pos;
    stack<string> strings;

    while ((pos = s.find(' ')) != string::npos) {
        auto newS = s.substr(0, pos);

        if (!newS.empty()) {
            strings.push(newS);
        }

        s.erase(0, pos + 1);
    }

    if (!s.empty()) {
        strings.push(s);
    }

    string result;
    while (!strings.empty()) {
        result += strings.top();
        strings.pop();

        if (!strings.empty()) {
            result += " ";
        }
    }

    return result;
}

string ReverseWordsInAString::recurseString(string s, size_t start, size_t end) {
    if ((end = s.substr(start, -1).find(' ')) != string::npos) {
        end = start + end;

        if (s.substr(start, 1) != " ") {
            std::reverse(s.begin() + (long) start, s.begin() + (long) end);

            start = (long) end + 1;
        } else {
            s.erase(start, 1);

            start = (long) end;
        }

        return recurseString(s, start, end);
    }

    std::reverse(s.begin() + (long) start, s.end());

    return s;
}

string ReverseWordsInAString::reverseWordsRecursion(string s) {
    std::reverse(s.begin(), s.end());

    s = recurseString(std::move(s));

    if (s.substr(s.size() - 1, 1) == " ") {
        s.erase(s.size() - 1, 1);
    }

    return s;
}
