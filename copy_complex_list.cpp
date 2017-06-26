/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
//使用hash表来统计原链表和复制之后链表一一对应的关系
//链表的题目最好使用dummy来操作最容易
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        //首先判断边缘条件，之后构建复制数组
        if(pHead == NULL)   return NULL;
        RandomListNode* tmp = pHead;
        RandomListNode* dummy = new RandomListNode(0);
        RandomListNode* cur = dummy;
        //使用一个hash表来保持原链表和复制链表对应节点的关系
        //然后先遍历一边原来的链表，构建一个初始复制链表
        unordered_map<RandomListNode*, RandomListNode*> table;
        while(tmp){
            RandomListNode* copy_node = new RandomListNode(tmp->label);
            table[tmp] = copy_node;
            cur->next = copy_node;
            tmp = tmp->next; cur = cur->next;
        }
        tmp = pHead;
        //再遍历一次原链表，通过原链表的hash关系去完善复制链表的random节点
        while(tmp){
            if(tmp->random){
                table[tmp]->random = table[tmp->random];
            }
            tmp = tmp->next;
        }
        return dummy->next;
    }
};