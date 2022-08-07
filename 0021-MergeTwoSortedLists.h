#ifndef LEETCODE_PROBLEMS_MERGETWOSORTEDLISTS_H
#define LEETCODE_PROBLEMS_MERGETWOSORTEDLISTS_H


struct ListNode {
    int val;
    ListNode *next;
};

class MergeTwoSortedLists {
public:
    static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
};


#endif //LEETCODE_PROBLEMS_MERGETWOSORTEDLISTS_H
