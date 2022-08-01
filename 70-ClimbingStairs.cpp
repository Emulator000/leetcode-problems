#include "70-ClimbingStairs.h"

int ClimbStairs::climbStairs(int n) {
    int oneStep = 1, twoStep = 1;

    for (int i = n; i > 0; i--) {
        if (i == n) {
            oneStep = 1;
        } else {
            int oldStep = oneStep;
            oneStep = oneStep + twoStep;
            twoStep = oldStep;
        }
    }

    return oneStep;
}
