#ifndef LEETCODE_PROBLEMS_VALIDPARENTHESES_H
#define LEETCODE_PROBLEMS_VALIDPARENTHESES_H


#include <string>
#include <map>

using namespace std;

class ValidParentheses {
private:
    static map<char, char> parentheses;
public:
    static bool isValid(string s);
};


#endif //LEETCODE_PROBLEMS_VALIDPARENTHESES_H
