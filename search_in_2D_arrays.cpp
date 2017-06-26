//比较经典的一个题，类似于二分查找法
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int h = array.size();
        //首先判断边缘情况
        if(h == 0)  return false;
        int w = array[0].size();
        int start_x = w-1, start_y = 0;
        //开始时固定初始点在二维矩阵的右上角
        //如果大于target，初始点左移一位
        //如果小于target，初始点下移一位
        //找到了目标，返回true，否则返回false
        while((start_x >=0 && start_x <w) && (start_y >=0 && start_y <h)){
            if(array[start_y][start_x] > target){
                start_x--;
            }
            else if(array[start_y][start_x] < target){
                start_y++;
            }
            else    return true;
        }
        return false;
    }
};