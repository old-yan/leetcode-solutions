#include "utils.h"

class Solution {
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
    string findLongestWord(string s, vector<string>& d) {
        string ans;
        for(string&c:d){
            if(contain(c,s)){
                if(ans.size()<c.size()||(ans.size()==c.size()&&ans>c))ans=c;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abpcplea";
    vector<string>d={"ale","apple","monkey","plea"};
    auto ans=sol.findLongestWord(s,d);
    DBG(ans);

    system("pause");
    return 0;
}
