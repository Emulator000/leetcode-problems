#include <algorithm>

#include "1710-MaximumUnitsOnATruck.h"

bool MaximumUnitsOnATruck::compareBoxes(const vector<int> &boxA, const vector<int> &boxB) {
    return boxA[1] > boxB[1];
}

int MaximumUnitsOnATruck::maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    int units = 0;
    int currentBoxes = truckSize;

    sort(boxTypes.begin(), boxTypes.end(), MaximumUnitsOnATruck::compareBoxes);

    for (auto boxType: boxTypes) {
        int numberOfBoxes = boxType[0];
        int numberOfUnits = boxType[1];

        int pickedBoxes = numberOfBoxes > currentBoxes ? currentBoxes : numberOfBoxes;

        currentBoxes -= pickedBoxes;
        units += numberOfUnits * pickedBoxes;
    }

    return units;
}
