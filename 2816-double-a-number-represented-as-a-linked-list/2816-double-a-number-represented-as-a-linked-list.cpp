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
    ListNode* doubleIt(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        int carry=0;
        while(curr)
        {
            ListNode* temp = curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        curr=prev;
        ListNode* h1=new ListNode(0);
        head=h1;
        while(curr)
        {
            int value=((curr->val)*2+carry);
            carry=value/10;
            value=value%10;
            h1->next=new ListNode(value);
            h1=h1->next;
            curr=curr->next;
        }
        if(carry)
        {
            h1->next=new ListNode(carry);
        }
        h1=head->next;
        prev=NULL;
        curr=h1;
        while(curr)
        {
            ListNode* temp = curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
};