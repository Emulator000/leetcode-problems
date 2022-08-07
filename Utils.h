#ifndef LEETCODE_PROBLEMS_UTILS_H
#define LEETCODE_PROBLEMS_UTILS_H


#include <string>
#include <vector>
#include <map>

using namespace std;

class Utils {
public:
    static std::string trim(std::string &s);
    static vector<string> splitString(string s, const string &delimiter = " ");
};


#endif //LEETCODE_PROBLEMS_UTILS_H
