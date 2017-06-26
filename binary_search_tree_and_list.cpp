/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
//大概就是线索化的意思，对象为二叉搜索树
class Solution {
private:
    //要注意head和tail都必须有*修饰符
    TreeNode* head, *tail;
    void recursive(TreeNode* pRootOfTree){
        //用临时的变量先保存当前的head和tail
        TreeNode* tmp_head;
        TreeNode* tmp_tail;
        if(pRootOfTree->left){
            recursive(pRootOfTree->left);
            tmp_head = head;
            //注意绑定双向关系
            pRootOfTree->left = tail;
            tail->right = pRootOfTree;
        }
        else    tmp_head = pRootOfTree;
        if(pRootOfTree->right){
            recursive(pRootOfTree->right);
            tmp_tail = tail;
            //注意绑定双向关系
            pRootOfTree->right = head;
            head->left = pRootOfTree;
        }
        else    tmp_tail = pRootOfTree;
        head = tmp_head;
        tail = tmp_tail;
        return;
    }
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL) return NULL;
        recursive(pRootOfTree);
        return head;
    }
};