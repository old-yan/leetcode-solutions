#include "utils.h"

class Solution {
public:
    //贪心处理即可，从前往后遍历遇到X就来一次转换
    int minimumMoves(string s) {
        int ans=0;
        for(int i=0;i<s.size();){
            if(s[i]=='O'){
                i++;
            }
            else{
                ans++;
                i+=3;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="XXOX";
    auto ans=sol.minimumMoves(s);
    DBG(ans);

    system("pause");
    return 0;
}