#include "1584-MinCostToConnectAllPoints.h"

#include <functional>
#include <queue>

int MinCostToConnectAllPoints::minCostConnectPoints(vector<vector<int>> &points) {
    size_t size = points.size();
    vector<pair<int, int>> costs[size];

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int cost = std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);

            costs[i].emplace_back(j, cost);
            costs[j].emplace_back(i, cost);
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    int totalCost = 0;

    vector<bool> visited(size, false);

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        int coord = curr.second;

        if (visited[coord]) continue;

        int cost = curr.first;

        visited[coord] = true;
        totalCost += cost;

        for (auto it: costs[coord]) {
            if (visited[it.first]) continue;

            pq.push({it.second, it.first});
        }
    }

    return totalCost;
}
