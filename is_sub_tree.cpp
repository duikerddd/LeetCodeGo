class Solution {
public:
    //寻找相同的子树
    bool isSubtree(TreeNode* s, TreeNode* t) {        
        bool flag = false;
        if (s != nullptr && t != nullptr) {
            if (s->val == t->val) {
                flag = DoesTreeHavaTree(s, t);
            }
            if (!flag) {
                flag = isSubtree(s->left, t);
            } 
            if (!flag) {
                flag = isSubtree(s->right, t);
            }
        }        
        return flag;
    }

    //判断是否相等
    bool DoesTreeHavaTree(TreeNode *s, TreeNode *t) {
        //都为空
        if (!s && !t) {
            return true;
        }
        //一个为空
        if (!s || !t) {
            return false;
        }
        //不相等
        if (s->val != t->val) {
            return false;
        }
        return DoesTreeHavaTree(s->left, t->left) && DoesTreeHavaTree(s->right, t->right);
    }
};
