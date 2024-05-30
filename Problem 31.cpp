//  206. Reverse Linked List

// ---------------------------------Iterative--------------------------------
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)return head;

        ListNode* pre=head;
        ListNode* curr=head->next;

        while(curr)
        {
            ListNode* post=curr->next;

            curr->next=pre;

            pre=curr;
            curr=post;
        }

        head->next=NULL;
        return pre;
    }
};

// --------------------------------Recursive----------------------------------


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* head2=reverseList(head->next);

        head->next->next=head;
        head->next=NULL;

        return head2;
    }
};