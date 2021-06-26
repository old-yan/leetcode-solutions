#include "utils.h"

class Solution {
    vvi sum;
    int k;
    int fun(string&s,int l,int r){
        #define num(c) sum[r+1][c]-sum[l][c]
        int res=0;
        int i=l,j;
        bool first=true;
        while(true){
            while(i<=r&&num(s[i]-'a')<k)i++;
            if(i>r)break;
            for(j=i+1;j<=r&&num(s[j]-'a')>=k;j++);
            if(first){
                if(j==r+1)return j-i;
                else first=false;
            }
            chmax(res,fun(s,i,j-1));
            i=j+1;
        }
        return res;
    }
public:
    int longestSubstring(string s, int _k) {
        k=_k;
        sum.emplace_back(26,0);
        REP(i,s.size()){
            sum.emplace_back(sum.back());
            sum.back()[s[i]-'a']++;
        }
        return fun(s,0,s.size()-1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="ababacb";
    int k=3;
    auto ans=sol.longestSubstring(s,k);
    DBG(ans);

    system("pause");
    return 0;
}
