#ifndef LEETCODE_PROBLEMS_PLATESBETWEENCANDLES_H
#define LEETCODE_PROBLEMS_PLATESBETWEENCANDLES_H


#include <string>
#include <vector>

using namespace std;

class PlatesBetweenCandles {
public:
    static vector<int> platesBetweenCandlesSlow(string s, vector<vector<int>> &queries);

    static vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries);
};


#endif //LEETCODE_PROBLEMS_PLATESBETWEENCANDLES_H
