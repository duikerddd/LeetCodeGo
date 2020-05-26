//判断B是不是A的子结构
strcut BTNode{
    int val;
    BTNode* left;
    BTNode* right;
};

//递归:
//1.A树找到B的root(命中比较,没命中左右子树寻找)
//2.比较是否相等

bool IsSubtree(BTNode* A,BTNode* B)
{
    bool flag = false;  
    //终止条件
    if(A!=NULL && B!=NULL){
      //找到了
      if(A->val==B->val)
      {
            flag = DoesTreeHavaTree(A,B);
      }
      //找到的不是子结构则继续左右子树找
      if (!flag) {
           flag = isSubtree(s->left, t);
      } 
      if (!flag) {
           flag = isSubtree(s->right, t);
      }
     
   }
     
     return flag;
}

//判断是否为相等
bool DoesTreeHavaTree(BTNode *s, BTNode *t) {
      
      //两个都为空
      if(s==NULL && t==NULL) return true;
      
      //一个为空一个不为空
      if(s==NULL || t==NULL) return false;
      
      //都存在则比较
      if(s->val != t->val)
      {
            return false;
      }
    
      return DoesTreeHavaTree(s->left, t->left) && DoesTreeHavaTree(s->right, t->right);
}
