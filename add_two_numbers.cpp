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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //此题重点是要解决,进位之后该如何处理
        //用了carry来标记下一位是否+1
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        
        //carry记录进位
        int carry = 0;
        while(l1!=NULL || l2!=NULL)
        {
               //sum配合carry,记录和值
               int sum = carry;
               if(l1!=NULL)
               {
                    sum += l1->val;
                    l1 = l1->next;
               }
               if(l2!=NULL)
               {
                    sum += l2->val;
                    l2 = l2->next;
               }
               int val = sum<10?sum:sum-10;
               carry = sum<10?0:1;
               cur->val += val;
               //没有可以加的数了,也就不用申请结点了
               if(l1==NULL && l2==NULL)
               {
                   break;
               }
               //更替下一个结点
               cur->next = new ListNode(0);
               cur = cur->next;
        }
        //最后一次加是否有进位  
        if(carry == 1)
        {
            cur->next = new ListNode(1);
        }
       
        

        return head;
    }
};
