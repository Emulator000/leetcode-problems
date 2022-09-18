#include "????-LongestSubstringWithAtMostKDistinctCharacters.h"

#include <unordered_map>
#include <unordered_set>

// Educative version for this exercise
int LongestSubstringWithAtMostKDistinctCharacters::longestSubstringWithAtMostKDistinctCharactersCanonicalApproach(string s, int k) {
    int windowStart = 0, maxLength = 0;
    unordered_map<char, int> charFrequencyMap;

    for (int windowEnd = 0; windowEnd < s.length(); windowEnd++) {
        charFrequencyMap[s[windowEnd]]++;

        while (charFrequencyMap.size() > k) {
            char leftChar = s[windowStart];
            charFrequencyMap[leftChar]--;

            if (charFrequencyMap[leftChar] == 0) {
                charFrequencyMap.erase(leftChar);
            }

            windowStart++;
        }

        maxLength = max(maxLength, windowEnd - windowStart + 1);
    }

    return maxLength;
}

// My personal version (a bit slow)
int LongestSubstringWithAtMostKDistinctCharacters::longestSubstringWithAtMostKDistinctCharacters(string s, int k) {
    int maxLength = 0, windowStart = 0;
    unordered_set<char> found;

    for (int windowEnd = 0; windowEnd < s.size();) {
        found.insert(s[windowEnd]);

        if (found.size() > k) {
            windowStart++;
            windowEnd = windowStart;

            found.clear();
        } else {
            maxLength = max(windowEnd - windowStart + 1, maxLength);
            windowEnd++;
        }
    }

    return maxLength;
}
