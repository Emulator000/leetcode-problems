#ifndef LEETCODE_PROBLEMS_2360_LONGESTCYCLEINAGRAPH_H
#define LEETCODE_PROBLEMS_2360_LONGESTCYCLEINAGRAPH_H


#include <vector>

using namespace std;

class LongestCycleInAGraph {
private:
    static int dfs(int vertex, int counter, vector<int>& edges, vector<int>& visited, vector<bool>& dfsVisited);
public:
    static int longestCycle(vector<int>& edges);
};


#endif //LEETCODE_PROBLEMS_2360_LONGESTCYCLEINAGRAPH_H
