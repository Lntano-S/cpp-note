#include <iostream>

int main(void) {
    struct ListNode {
        int val;
        ListNode* next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };
    
    ListNode* dummy = new ListNode(0);
    ListNode* curt = dummy;
    for (int i = 1; i < 6; ++i) {
        curt->next = new ListNode(i);
        curt = curt->next;
    }

    ListNode* head = dummy->next;
    curt = head;
    
    // for (int i = 1; i < 6; ++i)
    while (curt != nullptr) {
        std::cout << curt->val << std::endl;
        curt = curt->next;
    }

    return 0;
}