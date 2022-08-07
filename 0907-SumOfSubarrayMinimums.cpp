#include <stack>

#include "0907-SumOfSubarrayMinimums.h"

int SumOfSubarrayMinimums::sumSubarrayMins(vector<int> arr) {
    // Grab each next left smaller number of every element
    auto left_smaller = getNextSmaller(arr);

    // Grab each next right smaller number of every element
    auto right_smaller = getNextSmaller(arr, true);

    unsigned int len = arr.size();
    long long total = 0;

    for (int i = 0; i < len; i++) {
        total += ((right_smaller[i] - i) % modulo * (i - left_smaller[i])) % modulo * arr[i] % modulo;
    }

    return (int) (total % modulo);
}

vector<int> SumOfSubarrayMinimums::getNextSmaller(vector<int> arr, bool isRight) {
    unsigned int len = arr.size();

    vector<int> smallers(len, isRight ? (int)len : -1);

    // An empty stack (a LIFO queue)
    stack<int> st;

    for (int i = isRight ? (int)len - 1 : 0; isRight ? i >= 0 : i < len; isRight ? i-- : i++) {
        while (!st.empty() && arr[st.top()] >= (arr[i] + (isRight ? 1 : 0))) {
            st.pop();
        }

        if (!st.empty()) {
            smallers[i] = st.top();
        } else {
            smallers[i] = isRight ? (int)len : -1;
        }

        st.push(i);
    }

    return smallers;
}
