#include "0021-MergeTwoSortedLists.h"

ListNode *MergeTwoSortedLists::mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);

            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);

            return list2;
        }
    } else if (list1 != nullptr) {
        return list1;
    } else {
        return list2;
    }
}
