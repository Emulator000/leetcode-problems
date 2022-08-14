#ifndef LEETCODE_PROBLEMS_0140_WORDBREAKII_H
#define LEETCODE_PROBLEMS_0140_WORDBREAKII_H


#include <string>
#include <vector>
#include <map>

using namespace std;

class WordBreakII {
private:
    static map<string, vector<string>> cache;

public:
    static vector<string> wordBreak(string s, vector<string>& wordDict);
};


#endif //LEETCODE_PROBLEMS_0140_WORDBREAKII_H
