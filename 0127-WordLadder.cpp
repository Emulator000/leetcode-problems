#include "0127-WordLadder.h"

#include <queue>
#include <unordered_set>

int WordLadder::ladderLength(const string& beginWord, const string& endWord, vector<string> &wordList) {
    unordered_set<string> words;
    for (const auto& word: wordList) {
        words.insert(word);
    }

    if (words.find(endWord) == words.end()) {
        return 0;
    }

    queue<string> q;
    q.push(beginWord);

    size_t len = beginWord.length(), level = q.size();

    while (!q.empty()) {
        size_t size = q.size();
        while (size-- > 0) {
            auto currentWord = q.front();
            q.pop();

            if (currentWord == endWord) {
                return (int)level;
            }

            for (int j = 0; j < len; j++) {
                char previousChar = currentWord[j];

                for (char c = 'a'; c <= 'z'; c++) {
                    if (currentWord[j] == c) continue;

                    currentWord[j] = c;

                    if (words.find(currentWord) != words.end()) {
                        q.push(currentWord);
                        words.erase(currentWord);
                    }
                }

                currentWord[j] = previousChar;
            }
        }

        level++;
    }

    return 0;
}
