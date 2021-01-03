#include "utils.h"

class Solution {
    string num;
    bool dfs(int i1,int i2,int i3){
        if(i3==num.size())return true;
        vi v(max(i2-i1,i3-i2));
        REP(i,i2-i1){
            v[i]+=num[i2-1-i]-'0';
        }
        REP(i,i3-i2){
            v[i]+=num[i3-1-i]-'0';
        }
        int jinwei=0;
        REP(i,v.size()){
            v[i]+=jinwei;
            jinwei=v[i]/10;
            v[i]%=10;
        }
        if(jinwei)v.pb(1);
        int i4=i3+v.size();
        if(num.size()<i4)return false;
        REP(i,v.size()){
            if(v[i]!=num[i4-1-i]-'0')return false;
        }
        return dfs(i2,i3,i4);
    }
public:
    bool isAdditiveNumber(string _num) {
        num=_num;
        FOR(i,1,num.size()){
            if(num[0]=='0'&&i>1)break;
            if(i*2+1>num.size())break;
            FOR(j,i+1,num.size()){
                if(num[i]=='0'&&j>i+1)break;
                if(j+max(i,j-i)>num.size())break;
                if(dfs(0,i,j))return true;
            }
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string num="199100199";
    auto ans=sol.isAdditiveNumber(num);
    DBG(ans);

    system("pause");
    return 0;
}
