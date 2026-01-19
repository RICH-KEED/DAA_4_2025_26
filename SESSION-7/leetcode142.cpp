
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next !=NULL)
        {
            slow = slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                slow= head;
                while(slow!=fast)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n3; 

    Solution s;
    ListNode* cycleStart = s.detectCycle(n1);
    if (cycleStart) {
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle found" << endl;
    }
    
    return 0;
}