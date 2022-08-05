#include <unordered_map>

#include "3-LongestSubstringWithoutRepeatingCharacters.h"

int LongestSubstringWithoutRepeatingCharacters::lengthOfLongestSubstring(string s) {
    int max = 0;
    unordered_map<char, int> visitedPosition;

    for (int start = 0, end = 0; end < s.size(); end++) {
        if (visitedPosition.find(s[end]) != visitedPosition.end()) {
            start = std::max(start, visitedPosition[s[end]] + 1);
        }

        visitedPosition[s[end]] = end;

        max = std::max(max, end - start + 1);
    }

    return max;
}
