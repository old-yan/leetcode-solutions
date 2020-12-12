#include "utils.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>copy=strs;
        for(string&s:copy)sort(ALL(s));
        int idx[copy.size()];
        REP(i,copy.size())idx[i]=i;
        sort(idx,idx+copy.size(),[&](int x,int y)->bool{return copy[x]<copy[y];});
        vector<vector<string>>ans;
        for(int i=0,j;i<copy.size();i=j){
            for(j=i+1;j<copy.size()&&copy[idx[j]]==copy[idx[i]];j++);
            vector<string>temp(j-i);
            REP(k,j-i)temp[k]=strs[idx[i+k]];
            ans.pb(temp);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto ans=sol.groupAnagrams(strs);
    DBGVV(ans);

    system("pause");
    return 0;
}
