#include <algorithm>

#include "2055-PlatesBetweenCandles.h"

vector<int> PlatesBetweenCandles::platesBetweenCandles(string s, vector<vector<int>> &queries) {
    vector<int> result;

    // Collect all the candles indexes only
    vector<int> candles;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '|') candles.push_back(i);
    }

    // Iterate over all queries (start index - end index)
    for (auto &query: queries) {
        int startIndex = query[0];
        int endIndex = query[1];

        // Find the index of the candles with a value that is equal or greater than startIndex
        auto left = std::lower_bound(candles.begin(), candles.end(), startIndex) - candles.begin();
        // Find the index of the candles with a value that is greater than endIndex and subtract 1, eg. index - 1
        auto right = (std::upper_bound(candles.begin(), candles.end(), endIndex) - candles.begin()) - 1;

        if (left < right) {
            // Guess the number of candles calculating the difference between (candles indexes on the string)
            // so we get the exact number of plates only and subtracting (indexes of the candles vector) that is the
            // candles count we could obtain the number of plates only
            auto plates = ((candles[right] - candles[left]) - (right - left));

            result.push_back((int) plates);
        } else {
            // No plates found as we reached an invalid candles indices
            result.push_back(0);
        }
    }

    return result;
}
