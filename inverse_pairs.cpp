//又是逆序对，不过这个题目比LeetCode的contest好理解
class Solution {
private:
    //使用全局的私有成员来表示逆序对数目
    //下面的取模操作是常量，可以直接在类里面固定初始值
    int res;
    const int MOD = 1000000007;
    void mergeArray(vector<int> &data, int begin, int mid, int end, vector<int> &tmp){
        int a = mid, b = end, i = 0;
        //判断每一次归并的两个数组最后一位，如果前一个数组的最后一位大于后一个数组的最后一位
        //逆序对直接加上后一个数组当前的长度，如果不每一次都取模操作，可以优化时间，不过最好用long long来表示
        while(a>=begin && b>=mid+1){
            if(data[a] > data[b]){
                tmp[i++] = data[a--];
                res += b-mid; res %= MOD;
            }
            else{
                tmp[i++] = data[b--];
            }
        }
        while(a>=begin) tmp[i++] = data[a--];
        while(b>=mid+1) tmp[i++] = data[b--];
        for(int x=begin;x<=end;x++) data[x] = tmp[--i];
    }

    void mergeSort(vector<int> &data, int begin, int end, vector<int> &tmp){
        //归并排序的基本框架，比较经典的
        if(begin < end){
            int mid = begin + (end - begin)/2;
            mergeSort(data, begin, mid, tmp);
            mergeSort(data, mid+1, end, tmp);
            mergeArray(data, begin, mid, end, tmp);
        }
    }
public:
    int InversePairs(vector<int> data) {
        res = 0;
        if(data.size() <= 1)    return res;
        vector<int> tmp(data);
        mergeSort(data, 0, (int)data.size()-1, tmp);
        return res;
    }
};