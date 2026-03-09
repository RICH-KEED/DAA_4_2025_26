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
class Solution {
public:
    void reorderList(ListNode* head) {
        
        vector<int> nums;
        vector<int> res;
        ListNode* temp=head;
        while(temp)
        {
            nums.push_back(temp->val);
            temp=temp->next;
        }
        int start =0;
        int end = nums.size()-1;
        while(start<end)
        {
            res.push_back(nums[start]);
            res.push_back(nums[end]);
            start++;
            end--;
        }
        if(start==end)
        {
            res.push_back(nums[start]);
        }
        ListNode* temp2=head;
        int j = 0;
        while(temp2!=nullptr)
        {
            temp2->val=res[j++];
            temp2=temp2->next;
        }
    }
};