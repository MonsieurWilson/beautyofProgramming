#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode (const int v = 0, ListNode *n = nullptr): val(v), next(n) {}
};

int deleteListNode(ListNode **head, ListNode *toBeDeleted) {
    if (*head == nullptr || toBeDeleted == nullptr) {
        return -1;
    }
    if (toBeDeleted->next) {
        ListNode *tmp = toBeDeleted->next;
        toBeDeleted->val = tmp->val;
        toBeDeleted->next = tmp->next;
        delete tmp;
        return 0;
    }
    else if (*head == toBeDeleted) {
        delete toBeDeleted;
        *head = nullptr;
        return 0;
    }
    else {
        ListNode *cur = *head;
        while (cur && cur->next != toBeDeleted) {
            cur = cur->next;
        }
        if (cur->next != toBeDeleted) {
            return -1;
        }
        else {
            cur->next = nullptr;
            delete toBeDeleted;
            return 0;
        }
    }
}
