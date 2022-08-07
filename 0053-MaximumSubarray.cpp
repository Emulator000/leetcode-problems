#include "0053-MaximumSubarray.h"

int MaximumSubarray::maximumSubarrayProblem(list<int> integers) {
    int arr[integers.size()];
    std::copy(integers.begin(), integers.end(), arr);

    int count = 0;
    int total;

    for (int i = 0; i < integers.size(); i++) {
        total = min(arr[i], total);
    }

    for (int i = 0; i < integers.size(); i++) {
        count = max(arr[i], arr[i] + count);
        total = max(count, total);
    }

    return total;
}
