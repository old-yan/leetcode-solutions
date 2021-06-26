#include "utils.h"

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.size();
        string ans;
        unordered_map<string,string>M;
        for(auto&k:knowledge){
            M[k[0]]=k[1];
        }
        for(int i=0,j;i<n;){
            if(s[i]!='(')ans+=s[i++];
            else{
                j=s.find(')',i);
                string ss=s.substr(i+1,j-i-1);
                if(M.count(ss))ans+=M[ss];
                else ans+="?";
                i=j+1;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="(name)is(age)yearsold";
    vector<vector<string>>knowledge={
        {"name","bob"},
        {"age","two"}
    };
    auto ans=sol.evaluate(s,knowledge);
    DBG(ans);

    system("pause");
    return 0;
}
