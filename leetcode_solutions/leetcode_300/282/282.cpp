#include "utils.h"

class Solution {
    string num;
    int target;
    vector<string>ans;
    char c[20];
    void dfs(int i,int idx,ll multiply,ll add){
        ll cur=0;
        FOR(j,i+1,num.size()+1){
            if(num[i]=='0'&&j>i+1)break;
            c[idx++]=num[j-1];
            cur=cur*10+num[j-1]-'0';
            if(j==num.size()){
                if(add+multiply*cur==target){
                    c[idx]=0;
                    ans.pb(c);
                }
            }
            else{
                c[idx]='+';
                dfs(j,idx+1,1,add+multiply*cur);
                c[idx]='-';
                dfs(j,idx+1,-1,add+multiply*cur);
                c[idx]='*';
                dfs(j,idx+1,multiply*cur,add);
            }
        }
    }
public:
    vector<string> addOperators(string _num, int _target) {
        num=_num;
        target=_target;
        dfs(0,0,1,0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string num="123";
    int target=6;
    auto ans=sol.addOperators(num,target);
    DBGV(ans);

    system("pause");
    return 0;
}
