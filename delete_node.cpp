/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void Swap(ListNode* n1,ListNode* n2)
{
    if(n2 == NULL)
    {
        return;
    }
    int tmp = n1->val;
    n1->val = n2->val;
    n2->val = tmp;
}

class Solution {
public:
    void deleteNode(ListNode* node) {
        //将删除的值交换到最后再删除
        ListNode* cur = node;
        ListNode* father = cur;
        while(cur->next!=NULL)
        {
            Swap(cur,cur->next);
            father = cur;
            cur = cur->next;
        }
        delete cur;
        father->next = NULL;
        
    }
};
