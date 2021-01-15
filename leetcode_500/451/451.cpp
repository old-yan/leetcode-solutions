#include "utils.h"

class Solution {
public:
    string frequencySort(string s) {
        int num[128]={0};
        for(char c:s)num[c]++;
        auto comp=[&](char x,char y){return num[x]<num[y];};
        priority_queue<char,vector<char>,decltype(comp)>Q(comp);
        REP(i,128)Q.push(i);
        string ans;
        while(Q.size()){
            char c=Q.top();
            Q.pop();
            REP(i,num[c])ans+=c;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="Aabb";
    auto ans=sol.frequencySort(s);
    DBG(ans);

    system("pause");
    return 0;
}
