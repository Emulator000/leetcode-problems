#include "0300-LongestIncreasingSubsequence.h"

int LongestIncreasingSubsequence::lengthOfLIS(vector<int> &nums) {
    unsigned long len = nums.size();
    vector<int> cache(len, 1);
    int maximum = 1;

    for (int i = 1; i < len; i++) {
        for (int x = 0; x < i; x++) {
            if (nums[x] < nums[i]) {
                cache[i] = max(cache[i], cache[x] + 1);
            }
        }

        maximum = max(maximum, cache[i]);
    }

    return maximum;
}
