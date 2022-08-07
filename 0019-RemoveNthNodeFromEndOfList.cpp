#include "0019-RemoveNthNodeFromEndOfList.h"

#include <unordered_map>

using namespace std;

ListNode *RemoveNthNodeFromEndOfList::removeNthFromEnd(ListNode *head, int n) {
    if (head == nullptr) {
        return nullptr;
    }

    auto cursor = head;
    unordered_map<int, ListNode*> list;
    int size = 0;

    while (cursor != nullptr) {
        list[size++] = cursor;

        cursor = cursor->next;
    }

    if (size == 0) {
        return nullptr;
    }

    int pos = size - n;
    if (pos <= 0) {
        if (pos + 1 >= size) {
            return nullptr;
        }

        return list[pos + 1];
    }

    list[pos - 1]->next = list[pos]->next;

    return head;
}
