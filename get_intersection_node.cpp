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
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //让指针齐头并进
        //计算链表长度
        int Al = 0;
        int Bl = 0;
        for(ListNode* A = headA;A!=NULL;A=A->next)
        {
            ++Al;
        }
        for(ListNode* B = headB;B!=NULL;B=B->next)
        {
            ++Bl;
        }
        //将链表放在一个起点
        ListNode* CurB = headB;
        ListNode* CurA = headA;
        if(Al<=Bl)
        {
            int dif = Bl-Al;
            while(dif!=0)
            {
                CurB = CurB->next;        
                --dif;       
            }
        }
        else
        {
            int dif = Al-Bl;
            while(dif!=0)
            {
                CurA = CurA->next;        
                --dif;       
            }
        }
        //查找相交点
        while(CurA!=NULL && CurB!=NULL)
        {
            if(CurA == CurB)
            {
                return CurA;
            }
            CurA = CurA->next;  
            CurB = CurB->next;  
        }
        return NULL;
    }
};
