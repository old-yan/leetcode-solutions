#include "utils.h"

class Solution {
public:
    //本题显然只需要按照题意模拟
    //要想知道每个位置左边和右边的斜坡有多长，可以动态规划
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        //从左到右递推出左侧坡长
        vector<int>left(n);
        for(int i=0;i<n;i++){
            if(i==0)left[i]=0;
            else if(security[i-1]>=security[i])left[i]=left[i-1]+1;
            else left[i]=0;
        }
        //从右到左递推出右侧坡长
        vector<int>right(n);
        for(int i=n-1;i>=0;i--){
            if(i==n-1)right[i]=0;
            else if(security[i+1]>=security[i])right[i]=right[i+1]+1;
            else right[i]=0;
        }
        //收集答案
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(left[i]>=time and right[i]>=time){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>security{5,3,3,3,5,6,2};
    int time=2;
    auto ans=sol.goodDaysToRobBank(security,time);
    DBGV(ans);

    system("pause");
    return 0;
}