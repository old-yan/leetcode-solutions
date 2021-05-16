#include "utils.h"

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int>M1,M2;
        for(char c:word1)M1[c]++;
        for(char c:word2)M2[c]++;
        if(M1.size()!=M2.size())return false;
        multiset<int>S1,S2;
        for(auto it1=M1.begin(),it2=M2.begin();it1!=M1.end();++it1,++it2){
            if(it1->first!=it2->first)return false;
            S1.insert(it1->second);
            S2.insert(it2->second);
        }
        return S1==S2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string word1="abc";
    string word2="bca";
    auto ans=sol.closeStrings(word1,word2);
    DBG(ans);

    system("pause");
    return 0;
}
