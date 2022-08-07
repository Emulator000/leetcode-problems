#include <unordered_map>
#include "00001-TwoSum.h"

vector<int> TwoSum::twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> cache;
    for (int index = 0; index < nums.size(); index++) {
        const auto combination = cache.find(target - nums[index]);
        if (combination != cache.end()) {
            return {combination->second, index};
        }

        cache.insert({nums[index], index});
    }

    return {};
}
