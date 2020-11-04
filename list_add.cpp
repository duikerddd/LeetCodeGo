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
    //链表加法
    //低位开始加,carry计进位
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while(l1 || l2)
        {
            int sum = carry;
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            carry = sum<10?0:1;
            sum = sum<10?sum:sum%10;
            cur->val = sum;

            if(l1==nullptr && l2==nullptr){
               break; 
            }
            cur->next = new ListNode(0);
            cur = cur->next;
        }
        //最高位是否进位情况
        if(carry==1)
        {
            cur->next = new ListNode(1);
        }
       
        return head;
    }
};
