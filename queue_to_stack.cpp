template<typename T>class CQueue
void appendTail(const T& node)
{
    queue1.push(node);
} 
T deleteHead()
{
    if(queue2.empty())
    {
        while(!queue1.size()<=1)
        {
            queue2.push(queue1.front());
            queue1.pop();
        }
    }
    else
    {
         while(!queue2.size()<=1)
        {
            queue1.push(queue2.front());
            queue2.pop();
        }
    }
    
    if(queue1.empty()&&queue2.empty())
        throw new exception("queue is empty");
        
    if(queue2.size()==1)
    {
            T del = queue2.front();
            queue2.pop();
    } 
    else
    {
            T del = queue1.front();
            queue1.pop();
    }   
    
    return del;
}
