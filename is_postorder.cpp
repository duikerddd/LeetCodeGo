bool IsPostOrder(int* root,int len)        //5 7 6 9 11 10 8
{                                                     i    r
    int r = len-1;               
     //通过左子树确认左子树和右子树
     int i;       
    for(i=0;i<r;++i)              //5 7 6 9 11
    {                                        i = 4
        if(r[i]>root[r])
            break;
    }
    //判断右子树是否满足条件(如果左子树不满足条件,会导致右子树出问题)
     int j = i;
     for(;j<r;++j)               //11 10
     {
         if(r[j]<root[r])         
             return false;
     }   
     
     bool left = true;
     if(i>0)
         left = IsPostOrder(root,i);    //5 7 6 9 
     bool right = true;    
     if(i<r)
         right = IsPostOrder(root+i,r-i);   //11   10
     
     return left && right;         
}
