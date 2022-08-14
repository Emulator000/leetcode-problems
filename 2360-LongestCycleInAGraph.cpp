#include "2360-LongestCycleInAGraph.h"

int
LongestCycleInAGraph::dfs(int vertex, int counter, vector<int> &edges, vector<int> &visited, vector<bool> &dfsVisited) {
    visited[vertex] = counter++;
    dfsVisited[vertex] = true;

    int nextVertex = edges[vertex];

    if (nextVertex == -1) {
        return -1;
    }

    if (dfsVisited[nextVertex] && visited[nextVertex] != -1) {
        return counter - visited[nextVertex];
    }

    int res = !dfsVisited[nextVertex] ? dfs(nextVertex, counter, edges, visited, dfsVisited) : -1;

    visited[nextVertex] = -1;

    return res;
}


int LongestCycleInAGraph::longestCycle(vector<int> &edges) {
    size_t size = edges.size();
    vector<int> visited(size, -1);
    vector<bool> dfsVisited(size, false);

    int longestCycle = -1;

    for (int i = 0; i < size; i++) {
        if (dfsVisited[i]) continue;

        longestCycle = std::max(dfs(i, 0, edges, visited, dfsVisited), longestCycle);

        visited[i] = -1;
    }

    return longestCycle;
}
