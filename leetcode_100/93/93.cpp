#include "utils.h"

class Solution {
    string s;
    vector<string>path;
    vector<string>ans;
    void dfs(int i){
        if(path.size()==4){
            if(i==s.size()){
                string temp=path[0];
                FOR(j,1,4){
                    temp+="."+path[j];
                }
                ans.pb(temp);
            }
        }
        else{
            if(i<s.size()){
                if(s[i]=='0'){
                    path.pb(s.substr(i,1));
                    dfs(i+1);
                    path.pop_back();
                }
                else{
                    FOR(j,i+1,min(i+4,int(s.size()+1))){
                        if(s2i(s.substr(i,j-i))>255)break;
                        path.pb(s.substr(i,j-i));
                        dfs(j);
                        path.pop_back();
                    }
                }
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string _s) {
        s=_s;
        dfs(0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="101023";
    auto ans=sol.restoreIpAddresses(s);
    DBGV(ans);

    system("pause");
    return 0;
}
