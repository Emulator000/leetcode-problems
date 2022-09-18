#include "0209-MinimumSizeSubarraySum.h"

#include <limits>

// Educative version for this exercise
int MinimumSizeSubarraySum::minSubArrayLenCanonical(int target, vector<int> &nums) {
    int minLength = numeric_limits<int>::max(), windowSum = 0, windowStart = 0;

    for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
        windowSum += nums[windowEnd];

        while (windowSum >= target) {
            minLength = min(minLength, windowEnd - windowStart + 1);

            windowSum -= nums[windowStart];
            windowStart++;
        }
    }

    return minLength == numeric_limits<int>::max() ? 0 : minLength;
}

// My personal version
int MinimumSizeSubarraySum::minSubArrayLen(int target, vector<int> &nums) {
    int result = numeric_limits<int>::max(), total = 0, windowStart = 0;

    for (int windowEnd = 0; windowEnd < nums.size();) {
        if (nums[windowEnd] >= target) {
            return 1;
        }

        total += nums[windowEnd];

        if (total >= target) {
            result = min(windowEnd - windowStart + 1, result);

            total -= nums[windowStart];
            total -= nums[windowEnd];

            windowStart++;
        } else {
            windowEnd++;
        }
    }

    if (result == numeric_limits<int>::max()) {
        result = 0;
    }

    return result;
}
