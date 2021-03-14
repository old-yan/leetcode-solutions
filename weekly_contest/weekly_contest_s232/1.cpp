#include "utils.h"

class Solution {
public:
    //暴力枚举所有的交换对，时间复杂度 O(n^3)
    //O(n)做法可以参考力扣859题
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)return true;
        int n=s1.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(s1[i],s1[j]);
                if(s1==s2)return true;
                swap(s1[i],s1[j]);
            }
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s1="bank";
    string s2="kanb";
    auto ans=sol.areAlmostEqual(s1,s2);
    DBG(ans);

    system("pause");
    return 0;
}
