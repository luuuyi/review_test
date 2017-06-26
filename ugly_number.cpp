//求丑数，第一次碰到，丑数为质因子只为2,3,5的数
//1是第一个丑数，往后的每一个丑数都是前面某一个数乘以2,3,5得到
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        //使用动态规划的思路去做，判断边界情况
        if(index <= 0)  return 0;
        vector<int> dp(index, 0);
        dp[0] = 1;
        //三个变量表示分别要乘以2,3,5的丑数的索引
        int t2 = 0, t3 = 0, t5 = 0;
        for(int i=1;i<index;i++){
            //选择三个索引得到的值乘上对应的质因数最小结果
            dp[i] = min(dp[t2]*2, min(dp[t3]*3, dp[t5]*5));
            //判断选择的是哪一个索引乘以质因数得到的数，然后使得索引向后走一位
            //利用了动态规划的记忆性特点
            t2 += dp[i]==dp[t2]*2?1:0;
            t3 += dp[i]==dp[t3]*3?1:0;
            t5 += dp[i]==dp[t5]*5?1:0;
        }
        return dp[index-1];
    }
};