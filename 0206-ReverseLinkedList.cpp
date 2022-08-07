#include "0206-ReverseLinkedList.h"

#include <stack>

using namespace std;

ListNode *ReverseLinkedList::reverseList(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->next == nullptr) {
        return head;
    }

    auto cursor = head;
    stack<ListNode*> reverse;

    while (cursor != nullptr) {
        reverse.push(cursor);

        cursor = cursor->next;
    }

    cursor = head = reverse.top();
    reverse.pop();

    while (!reverse.empty()) {
        reverse.top()->next = nullptr;
        cursor->next = reverse.top();
        cursor = reverse.top();
        reverse.pop();
    }

    return head;
}
