/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Submitted At 10:37 Earlier submitted it using vector


class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast = head;

        while(fast->next!=nullptr&&fast->next->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while(curr)
        {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        ListNode* first = head;
        ListNode* second = prev;
        
        while(second->next != nullptr&&first!=nullptr)
        {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            
            first->next = second;
            second->next = temp1;
            
            first = temp1;
            second = temp2;
        }
    }
};