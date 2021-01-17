#include "utils.h"

class Solution {
    vector<string>strs;
    bool contain(string&s,string&other){
        if(s.empty())return true;
        for(int i=0,j=0;i<other.size();i++){
            if(other[i]==s[j]){
                j++;
                if(j==s.size())return true;
            }
        }
        return false;
    }
public:
    int findLUSlength(vector<string>&_strs) {
        strs=_strs;
        int ans=0;
        REPR(i,10){
            REP(j,strs.size()){
                if(strs[j].size()==i){
                    bool iscontained=false;
                    REP(i,strs.size()){
                        if(i!=j&&contain(strs[j],strs[i])){
                            iscontained=true;
                            break;
                        }
                    }
                    if(!iscontained)return i;
                }
            }
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>strs{"aba","cdc","eae"};
    auto ans=sol.findLUSlength(strs);
    DBG(ans);

    system("pause");
    return 0;
}
