#include "0206-ReverseLinkedList.h"

#include <stack>

using namespace std;

ListNode *ReverseLinkedList::reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    auto cursor = head;
    stack<ListNode *> reverse;

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

ListNode *ReverseLinkedList::reverseListPlain(ListNode *head) {
    ListNode *next = head, *prev = nullptr;

    while (next != nullptr) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}
