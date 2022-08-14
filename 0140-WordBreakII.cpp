#include "0140-WordBreakII.h"

map<string, vector<string>> WordBreakII::cache = {};

vector<string> WordBreakII::wordBreak(string s, vector<string> &wordDict) {
    const auto found = cache.find(s);
    if (found != cache.end()) {
        return found->second;
    }

    vector<string> sentences;
    if (std::find(wordDict.begin(), wordDict.end(), s) != wordDict.end()) {
        sentences.emplace_back(s);
    }

    for (int i = 1; i <= s.size(); i++) {
        const string leftString = s.substr(0, i);
        if (std::find(wordDict.begin(), wordDict.end(), leftString) != wordDict.end()) {
            const auto rightString = s.substr(i, s.size());

            if (rightString.empty()) {
                continue;
            }

            vector<string> additionalSentences = wordBreak(rightString, wordDict);

            for (const auto &sentence: additionalSentences) {
                string temp;
                temp.append(leftString);
                temp.append(" ");
                temp.append(sentence);

                sentences.emplace_back(temp);
            }
        }
    }

    if (cache.find(s) == cache.end()) {
        cache.insert(pair<string, vector<string>>(s, sentences));
    }

    return sentences;
}
