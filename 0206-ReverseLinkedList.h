#ifndef LEETCODE_PROBLEMS_0206_REVERSELINKEDLIST_H
#define LEETCODE_PROBLEMS_0206_REVERSELINKEDLIST_H


struct ListNode {
    int val;
    ListNode *next;
};

class ReverseLinkedList {
public:
    static ListNode* reverseList(ListNode* head);
    static ListNode* reverseListPlain(ListNode* head);
};


#endif //LEETCODE_PROBLEMS_0206_REVERSELINKEDLIST_H
