#include "utils.h"

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool allow[128]={0};
        for(char c:allowed)allow[c]=true;
        int ans=0;
        for(string&s:words){
            bool flag=true;
            for(char c:s){
                if(!allow[c]){
                    flag=false;
                    break;
                }
            }
            if(flag)ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string allowed="ab";
    vector<string>words{"ad","bd","aaab","baa","badab"};
    auto ans=sol.countConsistentStrings(allowed,words);
    DBG(ans);

    system("pause");
    return 0;
}
