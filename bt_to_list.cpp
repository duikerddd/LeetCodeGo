//二叉搜索树 转换成排序的双向链表
//  10
// 6   12            --->   4===6===7===10===11===12===13
//4 7 11  13   

//中序遍历: 4 6 7 10 11 12 13
//解题思路 : 将中序遍历结果存放到数组中,再将元素连接成队列
//模型 : 数组存放

ListNode* BSTTODoubleList(ListNode* root)
{
     if(root==NULL) return NULL;
     
     vector<ListNode*> deque;
     
     //1.中序遍历
     InOrder(root,deque);
     
     //2.连接队列
     for(int i=0;i<deque.size()-1;++i)
     {
          deque[i]->right = deque[i+1];
          deque[i+1]->left = deque[i];
     }
     
     return deque[0];
     
}

//左,插入 根 右
void InOrder(ListNode* root,vector<ListNode*>& deque)
{
     //终止条件: 到叶子节点
     if(root==NULL) return;
     
     //向左深入,插入队列
     InOrder(root->left,deque);
     deque.push_back(root);
     
     InOrder(root->right,deque);
     
}
