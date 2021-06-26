#include "utils.h"

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string>ans;
        auto makestring=[&](int l,int r){
            if(S[l]=='0'){
                if(r==l)return vector<string>{"0"};
                else return vector<string>{"0."+S.substr(l+1,r-l)};
            }
            else{
                vector<string>res{S.substr(l,r+1-l)};
                if(S[r]!='0'){
                    for(int j=l+1;j<=r;j++){
                        res.pb(S.substr(l,j-l)+"."+S.substr(j,r+1-j));
                    }
                }
                return res;
            }
        };
        for(int split=2;split<S.size()-1;split++){
            if(split>2&&S[1]=='0'&&S[split-1]=='0')continue;
            if(split<S.size()-2&&S[split]=='0'&&S[S.size()-2]=='0')continue;
            auto left=makestring(1,split-1),right=makestring(split,S.size()-2);
            for(auto&a:left){
                for(auto&b:right){
                    ans.pb('('+a+", "+b+')');
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="(1230)";
    auto ans=sol.ambiguousCoordinates(S);
    DBGV(ans);

    system("pause");
    return 0;
}
