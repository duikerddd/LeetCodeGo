/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//递归思想:
//     终止条件: 有一个链表为空,比较结束,排序也就结束了
//     递归条件: 比较两值 :          总链表确定当前l1是最小值,递归计算l1->next=(l1->next,l2)
//                                              l2是小值,递归计算l2->next=(l1,l2->next);
//     递归返回值: 当前最小值
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) {
            return l2;
        }
        if(l2 == NULL) {
            return l1;
        }

        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }

    }
};
