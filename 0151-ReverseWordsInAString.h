#ifndef LEETCODE_PROBLEMS_0151_REVERSEWORDSINASTRING_H
#define LEETCODE_PROBLEMS_0151_REVERSEWORDSINASTRING_H


#include <string>

using namespace std;

class ReverseWordsInAString {
private:
    static string recurseString(string s, size_t start = 0, size_t end = 0);
public:
    static string reverseWords(string s);
    static string reverseWordsNative(string s);
    static string reverseWordsVector(string s);
    static string reverseWordsStack(string s);
    static string reverseWordsRecursion(string s);
};


#endif //LEETCODE_PROBLEMS_0151_REVERSEWORDSINASTRING_H
