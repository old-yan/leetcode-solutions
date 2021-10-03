#include "utils.h"

class Solution {
public:
    //检查可能性，只要可行，就能构造
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        //根据平均数计算总和
        int total=mean*(rolls.size()+n);
        //减去已知的m个数
        total-=accumulate(rolls.begin(),rolls.end(),0);
        //检查剩余的数的和是否在 [n,n*6] 区间内
        if(total>n*6||total<n)return {};
        //把这些点数平摊到答案里
        vector<int>ans(n,0);
        while(total){
            if(total>=n){
                total-=n;
                for(int&a:ans)a++;
            }
            else{
                for(int&a:ans){
                    total--;
                    a++;
                    if(total==0)break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi rolls{1,2,3,4};
    int mean=6;
    int n=4;
    auto ans=sol.missingRolls(rolls,mean,n);
    DBGV(ans);

    system("pause");
    return 0;
}