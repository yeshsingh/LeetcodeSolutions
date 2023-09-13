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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* node=head;
        int c=0;
        if(head==NULL)
        {
            return head;
        }
        while(node->next)
        {
            c++;
            node=node->next;
        }
        node->next=head;
        int c1=k%(c+1);
        int i=c-c1;
        node=head;
        while(i)
        {
            i--;
            node=node->next;
        }
        ListNode* returnHead=node->next;
        node->next=NULL;
        return returnHead;
    }
};