#include "utils.h"

class Solution {
    string fun(string&S,int l,int r){
        vector<string>v;
        for(int i=l,j;i<=r;i=j+1){
            int d=0;
            for(j=i;j<=r;j++){
                S[j]=='1'?d++:d--;
                if(!d)break;
            }
            v.pb('1'+fun(S,i+1,j-1)+'0');
        }
        sort(ALL(v),[](string&x,string&y){return x+y>y+x;});
        string ans;
        for(string&s:v)ans+=s;
        return ans;
    }
public:
    string makeLargestSpecial(string S) {
        return fun(S,0,S.size()-1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="1011010011010010";
    auto ans=sol.makeLargestSpecial(S);
    DBG(ans);

    system("pause");
    return 0;
}
