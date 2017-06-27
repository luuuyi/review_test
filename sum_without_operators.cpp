//不用算术运算符来完成加运算，类似的问题还有不用额外变量完成交换函数
class Solution {
public:
    int Add(int num1, int num2)
    {
        int first = 0, second = 0;
        //循环直到没有进位为0
        do{
            //first为两个数不算进位的加法结果
            first = num1 ^ num2;
            //second为两个数相加的进位情况
            second = (num1 & num2) << 1;
            num1 = first; num2 = second;
        }while(second != 0);
        return first;
    }
};