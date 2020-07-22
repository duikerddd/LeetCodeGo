//和为s的两个数字

//递增序列,求任意一对和为t的两个数字

//1 2 4 7 11
//8
//解题思路: 双指针很容易解决
//解法: 1.定义front,behind指针 2.判断sum. >target:behind--; <target:front++; ==输出

bool FindNumSum(int *data,int len,int target,int* num1,int* num2)
{
    if(data==NULL || len<1) return false;
    
    int front = 0;
    int behind = len-1;
    int sum = 0;
    
    while(front<behind)
    {
        sum = data[front]+data[behind];
        if(sum > target)
            behind--;
        else if(sum < target)
            front++;
        else
        {
            *num1 = data[front];
            *num2 = data[behind];
            return true;
        }  
    }
    
    return false;
}

