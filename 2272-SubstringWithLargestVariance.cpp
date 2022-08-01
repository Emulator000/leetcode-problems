#include <unordered_set>

#include "2272-SubstringWithLargestVariance.h"

int SubstringWithLargestVariance::largestVariance(string s) {
    int total = 0;
    unordered_set<char> unique(begin(s), end(s));

    for (char a: unique) {
        for (char b: unique) {
            if (a == b) continue;

            int countA = 0, countB = 0;
            for (auto ch: s) {
                countA += (ch == a) ? 1 : 0;
                countB += (ch == b) ? 1 : 0;

                int variance = countA - countB;

                total = max(total, countB > 0 ? variance : variance - 1);

                if (variance < 0) {
                    countA = 0;
                    countB = 0;
                }
            }
        }
    }

    return total;
}
