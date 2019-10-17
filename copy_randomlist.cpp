/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
          //这道题重点是要考虑random的位置,为了方便找到,用    影子节点
        
          //排除空结点
          if(head == NULL) 
          {
              return NULL;
          }
          //1.制造影子节点
          Node* cur = head;
          while(cur!=NULL)
          {
              Node* copy = new Node;
              copy->val = cur->val;
              
              copy->next = cur->next;
              cur->next = copy;
              cur = cur->next->next;
          }
        
          //2.根据原指针确定拷贝节点的random
          cur = head;
          while(cur!=NULL)
          {
              //random为空的时候
              if(cur->random == NULL)
              {
                  cur->next->random = NULL;
                  cur = cur->next->next;
                  continue;
              }
              cur->next->random = cur->random->next;
              cur = cur->next->next;
          }
        
          Node* cp = head->next;
          //3.分离指针
          Node* copy = cp;
          Node* origin = head;
          while(origin!=NULL || copy!=NULL)
          {
              origin->next = copy->next;
              //结束条件,原生到尾
              if(origin->next == NULL)
              {
                  copy->next = NULL;
                  return cp;
              }
              copy->next = origin->next->next;
                
              origin = origin->next;
              copy = copy->next;
          }
          
          return cp;
           
    }
};
