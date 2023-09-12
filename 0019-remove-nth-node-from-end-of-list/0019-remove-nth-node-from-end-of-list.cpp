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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c=0;
        ListNode* temp= new ListNode();
        temp=head;
        ListNode* ans= new ListNode(0);
        ListNode* head1=ans;
        //temp1=temp;
        while(head)
        {
            c++;
            head=head->next;
            
        }
        c=c-n+1;
        
        while(temp)
        {
            if(c==1)
            {
                temp=temp->next;
                
            }
            else 
            {
                
                int k=temp->val;
                ans->next= new ListNode(k);
                temp=temp->next;
                ans=ans->next;
            }
            
            c--;
        }
        return head1->next;
        
    }
};