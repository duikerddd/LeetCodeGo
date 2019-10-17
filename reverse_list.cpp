/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //前中后指针,配合完成
        //排除空结点
        if(head == NULL)
        {
            return NULL;
        }
        
        ListNode* first = NULL;
        ListNode* second = head;
        ListNode* third = head->next;
        while(second!=NULL)
        {
            second->next = first;
            first = second;
            second = third;
            if(third == NULL)
            {
                return first;
            }
            third = third->next;
        }
        return first;
    }
};
