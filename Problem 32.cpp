// 2130. Maximum Twin Sum of a Linked List

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
    ListNode* reverse(ListNode* head)
    {
        if(!head || !head->next)return head;

        ListNode* newHead=reverse(head->next);

        head->next->next=head;
        head->next=NULL;

        return newHead;
    }

    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        slow=reverse(slow);
        fast=head;

        int twinSum=INT_MIN;
        while(slow&&fast)
        {
            twinSum=max(twinSum,slow->val+fast->val);
            slow=slow->next;
            fast=fast->next;
        }

        return twinSum;
    }
};