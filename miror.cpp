//二叉树镜像

/*
    1                  1
   2  3       --->    3   2
  4 5 6 7           7  6  5  4
  
     1
    3  2
  6  7 4 5
  
      1
     3  2
    7 6 5 4
 */
 //递归: 左右子树交换
 
 void Mirror(BTNode* root)
 {
    //终止条件
    if(root==NULL) return;
    
    //交换
    BTnode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    
    Mirror(root->left) && Mirror(root->right);
 }
