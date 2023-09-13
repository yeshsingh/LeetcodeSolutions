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
    ListNode* deleteDuplicates(ListNode* head) {
         ListNode* node=head;
        map<int,int> m;
        vector<int> v;
        while(node)
        {
            if(m[node->val]==0)
            {
                v.push_back(node->val);
                m[node->val]++;
            }
            else 
            {
                m[node->val]=-1;
            }
            node=node->next;
        }
        
         
        sort(v.begin(),v.end());
        ListNode* node1=new ListNode();
        node=node1;
        for(int i=0;i<v.size();i++)
        {
            if(m[v[i]]!=-1)
            { 
            ListNode* node2=new ListNode(v[i]);
            
            node1->next=node2;
            node1=node1->next;
            }
        }
        return node->next;
    }
};