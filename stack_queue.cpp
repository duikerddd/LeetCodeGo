//栈实现队列
//两个栈

//   栈1     栈2
//    2
//    3
//    4       

//   队列: 
//    入栈: 栈1++
//    出栈: 如果栈2有元素,出一个元素
//              栈2没元素,栈1元素进栈2,栈2出一个元素
//              特殊情况: 栈1没元素,直接返回/抛异常

template<class T> 
class Queue{
  public:
  Queue(){}
  ~Queue(){}
  private:
  stack<T> stack1;
  stack<T> stack2;
};

template<class T>
void appendTail(const T& node)
{
    stack1.push(node);
}
T deleteHead()
{
    if(stack2.empty())
    {
        while(stack1.size()>0)
        {
            T node = stack1.pop();
            stack2.push(node);
        }
    }
    if(stack1.empty())
      throw new exception("queue is empty");
      
    T delNode = stack2.pop();
    return delNode;
}
