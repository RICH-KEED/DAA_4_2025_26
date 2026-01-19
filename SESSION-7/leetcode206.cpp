#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr!=NULL)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};


void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    a->next = b;
    b->next = c;

    cout << "Original list: ";
    printList(a);

    Solution s;
    ListNode* rev = s.reverseList(a);

    cout << "Reversed list: ";
    printList(rev);

    return 0;
}

