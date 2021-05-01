#include "utils.h"

class Solution {
public:
    vector<string> printVertically(string s) {
        auto v=split(s);
        int maxlen=0;
        for(string&a:v)chmax(maxlen,int(a.size()));
        vector<string>ans(maxlen);
        for(string&a:v){
            REP(i,maxlen){
                if(i<a.size())ans[i]+=a[i];
                else ans[i]+=" ";
            }
        }
        for(string&a:ans){
            while(a.size()&&a.back()==' ')a.pop_back();
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="HOW ARE YOU";
    auto ans=sol.printVertically(s);
    DBGV(ans);

    system("pause");
    return 0;
}
