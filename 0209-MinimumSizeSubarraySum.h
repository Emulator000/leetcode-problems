#ifndef LEETCODE_PROBLEMS_0209_MINIMUMSIZESUBARRAYSUM_H
#define LEETCODE_PROBLEMS_0209_MINIMUMSIZESUBARRAYSUM_H


#include <vector>

using namespace std;

class MinimumSizeSubarraySum {
public:
    static int minSubArrayLenCanonical(int target, vector<int>& nums);
    static int minSubArrayLen(int target, vector<int>& nums);
};


#endif //LEETCODE_PROBLEMS_0209_MINIMUMSIZESUBARRAYSUM_H
