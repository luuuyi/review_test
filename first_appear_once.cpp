//很简单的题目
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> table;
        //先遍历一次，统计每一个字符出现的次数
        for(int i=0;i<(int)str.size();i++){
            table[str[i]]++;
        }
        //从头开始遍历，第一个只出现一次的字符，输出
        for(int i=0;i<(int)str.size();i++){
            if(table[str[i]] == 1)  return i;
        }
        return -1;
    }
};