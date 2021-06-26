#include "utils.h"

class Solution {
    string s;
    //参数idx表示当前数字从s的那个下标开始
    //参数path表示之前的取数路径
    bool dfs(int idx,vector<ll>&path){
        if(idx==s.size())return path.size()>2;
        ll cur=0;
        //用变量i枚举下一个数字的开始下标
        for(int i=idx+1;i<=s.size();i++){
            //那就可以确定当前数字cur
            cur=cur*10+(s[i-1]-'0');
            if(cur>=path.back())break;
            if(!idx||cur==path.back()-1){
                path.pb(cur);
                if(dfs(i,path))return true;
                path.pop_back();
            }
        }
        return false;
    }
public:
    //回溯算法
    bool splitString(string _s) {
        s=_s;
        vector<ll>path{0x3f3f3f3f3f3f};
        return dfs(0,path);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="9080701";
    auto ans=sol.splitString(s);
    DBG(ans);

    system("pause");
    return 0;
}
