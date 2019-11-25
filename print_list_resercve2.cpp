void PrintListReserve(ListNode* pHead)
{
     std::stack<ListNode*> st;
     
     //无效输入
     if(pHead == NULL) 
         return;
     //将链表从头到尾放到栈中
     ListNode* cur = pHead;
     while(cur)
     {
         st.push(cur);
     }   
     //将栈中结点一个个输出
     while(!st.empty()){
     cur = st.top();
     st.pop();
     cout<<cur->val<<" ";
     }
     cout<<endl;
}
