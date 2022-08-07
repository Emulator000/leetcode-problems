#ifndef LEETCODE_PROBLEMS_REMOVENTHNODEFROMENDOFLIST_H
#define LEETCODE_PROBLEMS_REMOVENTHNODEFROMENDOFLIST_H


struct ListNode {
    int val;
    ListNode *next;
};

class RemoveNthNodeFromEndOfList {
public:
    static ListNode* removeNthFromEnd(ListNode* head, int n);
};


#endif //LEETCODE_PROBLEMS_REMOVENTHNODEFROMENDOFLIST_H
