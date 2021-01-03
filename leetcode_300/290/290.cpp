#include "utils.h"

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>v;
        int i,j;
        for(i=0;i<s.size();i=j+1){
            for(j=i+1;isalpha(s[j]);j++);
            v.pb(s.substr(i,j-i));
        }
        if(pattern.size()!=v.size())return false;
        unordered_map<char,string>M;
        unordered_map<string,char>M2;
        for(i=0;i<v.size();i++){
            if(M.count(pattern[i])){
                if(M[pattern[i]]!=v[i])return false;
            }
            else M[pattern[i]]=v[i];
            if(M2.count(v[i])){
                if(M2[v[i]]!=pattern[i])return false;
            }
            else M2[v[i]]=pattern[i];
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string pattern="abba";
    string s="dog cat cat dog";
    auto ans=sol.wordPattern(pattern,s);
    DBG(ans);

    system("pause");
    return 0;
}
