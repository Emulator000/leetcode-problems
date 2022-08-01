#ifndef LEETCODE_PROBLEMS_SUMOFSUBARRAYMINIMUS_H
#define LEETCODE_PROBLEMS_SUMOFSUBARRAYMINIMUS_H


#include <vector>

using namespace std;

class SumOfSubarrayMinimums {
private:
    static vector<int> getNextSmaller(vector<int> arr, bool isRight = false);
public:
    static const int modulo = 1e9+7;

    static int sumSubarrayMins(vector<int> arr);
};


#endif //LEETCODE_PROBLEMS_SUMOFSUBARRAYMINIMUS_H
