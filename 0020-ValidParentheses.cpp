#include <stack>

#include "0020-ValidParentheses.h"

map<char, char> ValidParentheses::parentheses = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

bool ValidParentheses::isValid(string s) {
    if (s.size() < 2) return false;

    stack<char> st;
    for (const auto &ch : s) {
        if (parentheses.find(ch) != parentheses.end()) {
            st.push(ch);
            continue;
        }

        if (st.empty()) {
            return false;
        }

        if (parentheses.find(st.top()) != parentheses.end()) {
            if (parentheses.at(st.top()) != ch) {
                return false;
            }

            st.pop();
        }
    }

    return st.empty();
}
