#include "utils.h"

class Solution {
public:
    bool buddyStrings(string a, string b) {
        int num_a[26]={0},num_b[26]={0};
        for(char c:a)num_a[c-'a']++;
        for(char c:b)num_b[c-'a']++;
        REP(i,26)if(num_a[i]!=num_b[i])return false;
        int dif=0;
        REP(i,a.size())if(a[i]!=b[i])dif++;
        if(dif>2||dif==1)return false;
        else if(!dif){
            REP(i,26)if(num_a[i]>1)return true;
            return false;
        }
        else return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string a="ab";
    string b="ba";
    auto ans=sol.buddyStrings(a,b);
    DBG(ans);

    system("pause");
    return 0;
}
