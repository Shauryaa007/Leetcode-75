// 328. Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next)return head;

        ListNode* pre=head;
        ListNode* curr=head->next;

        ListNode* head2=head->next;

        bool flag=0;
        while(curr->next)
        {
            pre->next=curr->next;
            pre=curr;
            curr=curr->next;

            flag=!flag;
        }

        if(flag)
        {
            curr->next=head2;
            pre->next=nullptr;
        }
        else
        {
            pre->next=head2;
        }

        return head;
    }
};