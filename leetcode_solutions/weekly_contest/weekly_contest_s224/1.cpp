#include "utils.h"

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxlen=0;
        //第一次遍历求得最大边长
        for(auto&A:rectangles){
            chmax(maxlen,max(A[0],A[1]));
        }
        int ans=0;
        //第二次遍历求得最大边长的出现次数
        for(auto&A:rectangles){
            if(max(A[0],A[1])==maxlen)ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    

    system("pause");
    return 0;
}
