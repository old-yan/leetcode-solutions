#include "utils.h"

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n=indexes.size();
        int idx[n];
        iota(idx,idx+n,0);
        sort(idx,idx+n,[&](int x,int y){return indexes[x]<indexes[y];});
        string ans;
        int cursor=0;
        REP(i,n){
            int j=idx[i];
            ans+=S.substr(cursor,indexes[j]-cursor);
            if(S.substr(indexes[j],sources[j].size())==sources[j]){
                ans+=targets[j];
            }
            else{
                ans+=S.substr(indexes[j],sources[j].size());
            }
            cursor=indexes[j]+sources[j].size();
        }
        ans+=S.substr(cursor);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S ="abcd";
    vi indexes{0,2};
    vector<string> sources{"abc","cd"};
    vector<string> targets{"eee","ffff"};
    auto ans=sol.findReplaceString(S,indexes,sources,targets);
    DBG(ans);

    system("pause");
    return 0;
}
