//用队列实现栈

//   队列1     队列2
//    4          1
//    3          2
//    2          3
//    1              

// 入栈: 直接加入元素
// 出栈: 出队移入空队列,剩余一个时,pop
//       特殊情况: 无元素,抛异常/退出

template<typename T>class CQueue
void appendTail(const T& node)
{
    queue1.push(node);
} 
T deleteHead()
{
   //无效输入
   if(queue1.empty()&&queue2.empty())
   {
      throw new exception("stack is empty");
   }

   T delt;
   if(queue1.empty())
   {
            while(queue2.size()!=1)
            {
                queue1.push(queue2.top());
                queue2.pop();
            }
            delT = queue2.top();
            queue2.pop();
            
   }
   else 
   {
            while(queue1.size()!=1)
            {
                queue2.push(queue1.top());
                queue1.pop();
            }
            delT = queue1.top();
            queue1.pop();
            
   }
   
   
   return delT;
   
}
