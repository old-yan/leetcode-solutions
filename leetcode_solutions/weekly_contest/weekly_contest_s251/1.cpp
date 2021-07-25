#include "utils.h"

class Solution {
public:
    //简单模拟
    int getLucky(string s, int k) {
        string ss;
        for(char c:s)ss+=to_string(c-'a'+1);
        s=ss;
        while(k--){
            int sum=0;
            for(char c:s)sum+=c-'0';
            s=to_string(sum);
        }
        return stoi(s);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="leetcode";
    int k=2;
    auto ans=sol.getLucky(s,k);
    DBG(ans);

    system("pause");
    return 0;
}
