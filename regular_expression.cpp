//经典的dp问题，正则表达式，还有一个是通配符题目
class Solution {
private:
    bool isMatch(const char* str, int str_lens, const char* pattern, int pattern_lens){
        vector<vector<bool>> dp(str_lens+1, vector<bool>(pattern_lens+1, false));
        //首先是初始化，要注意一定要有越界保护
        //当碰到pattern的*号时等于向左数两位的值
        for(int i=0;i<=pattern_lens;i++){
            if(i == 0)  dp[0][i] = true;
            else    dp[0][i] = pattern[i-1]!='*'?false:(i>=2?dp[0][i-2]:false);
        }
        for(int i=1;i<=str_lens;i++){
            for(int j=1;j<=pattern_lens;j++){
                //当在正式部分中，遇到*号，要么选择为0，即是向左数两位
                //要么选择为表示为该字符并且数量+1，所以需要和*之前的字符比较，相匹配才能进行
                //依然要注意越界保护
                if(pattern[j-1] == '*'){
                    if(j >= 2)  dp[i][j] = dp[i][j-2] || ((pattern[j-2]==str[i-1]||pattern[j-2]=='.')?dp[i-1][j]:false);
                    else    dp[i][j] = false;
                }
                //普普通通的通配符表达式
                else    dp[i][j] = (pattern[j-1]==str[i-1] || pattern[j-1]=='.')?dp[i-1][j-1]:false;
            }
        }
        return dp[str_lens][pattern_lens];
    }
public:
    bool match(char* str, char* pattern)
    {
        int str_lens = strlen(str);
        int pattern_lens = strlen(pattern);
        //用dp来做，返回结果
        return isMatch(str, str_lens, pattern, pattern_lens);
    }
};