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
    bool hasCycle(ListNode *head) {
        //排除不符合条件的
        if(head == NULL || head->next == NULL) return false;
        //快慢指针
        ListNode* front = head;
        ListNode* behind = head;
        
        while(front!=NULL && front->next!=NULL)
        {      
            
            front = front->next->next; 
            behind = behind->next;
            
            if(front->next == behind)
            {
                return true;
            }
               
        }
       
        return false;
        
    }
};
