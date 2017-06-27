/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
//查找二叉搜索树中序遍历的下一个节点
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        //判断边缘条件
        if(pNode == NULL)   return NULL;
        TreeLinkNode* cur;
        //可以把当前节点分为两类来讨论，有无右孩子节点
        //如果有，那么下一个节点就是右孩子节点的最左叶节点
        if(pNode->right){
            cur = pNode->right;
            while(cur->left)    cur = cur->left;
            return cur;
        }
        //如果没有，那就循环往父节点去找，如果父节点的左孩子节点刚好等于
        //当前节点，那么该父节点就为下一个节点
        else{
            TreeLinkNode* nxt = pNode->next;
            cur = pNode;
            while(nxt && nxt->right == cur){
                cur = nxt; nxt = nxt->next;
            }
            return nxt;
        }
    }
};