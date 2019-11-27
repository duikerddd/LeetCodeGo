template<typename T>class CQueue
void appendTail(const T& node)
{
    stack1.push(node);
} 
T deleteHead()
{
    if(stack2.empty())
    {
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    if(stack.empty())
    {
        throw new exception("queue is empty");
    }
    T del = stack2.top();
    stack.pop();
    return del;
}
