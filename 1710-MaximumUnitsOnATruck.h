#ifndef LEETCODE_PROBLEMS_MAXIMUMUNITSONATRUCK_H
#define LEETCODE_PROBLEMS_MAXIMUMUNITSONATRUCK_H


#include <vector>

using namespace std;

class MaximumUnitsOnATruck {
private:
    static bool compareBoxes(const vector<int> &boxA, const vector<int> &boxB);

public:
    static int maximumUnits(vector<vector<int>> &boxTypes, int truckSize);
};


#endif //LEETCODE_PROBLEMS_MAXIMUMUNITSONATRUCK_H
