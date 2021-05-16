#include "utils.h"

class Solution {
public:
    //如果想换成“奇0偶1”，就要找出奇1、偶0的数量，然后让它们配对交换
    //如果想换成“奇1偶0”，就要找出奇0、偶1的数量，然后让它们配对交换
    int minSwaps(string s) {
        int odd_zero=0,odd_one=0,even_zero=0,even_one=0;
        REP(i,s.size()){
            if(i%2==0){
                even_zero+=s[i]=='0';
                even_one+=s[i]=='1';
            }
            else{
                odd_zero+=s[i]=='0';
                odd_zero+=s[i]=='1';
            }
        }
        int ans=INT_MAX;
        if(even_zero==odd_one){
            chmin(ans,even_zero);
        }
        if(even_one==odd_zero){
            chmin(ans,even_one);
        }
        return ans==INT_MAX?-1:ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="111000";
    auto ans=sol.minSwaps(s);
    DBG(ans);

    system("pause");
    return 0;
}
