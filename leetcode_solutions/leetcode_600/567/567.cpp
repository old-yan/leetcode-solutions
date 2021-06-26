#include "utils.h"

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int num[128]={0};
        int non_zero=0;
        for(char c:s1){
            if(!num[c]++)non_zero++;
        }
        for(int i=0;i<s2.size();i++){
            if(!num[s2[i]]--)non_zero++;
            else if(!num[s2[i]])non_zero--;
            if(i>=s1.size()){
                if(!num[s2[i-s1.size()]]++)non_zero++;
                else if(!num[s2[i-s1.size()]])non_zero--;
            }
            if(!non_zero)return true;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s1="ab";
    string s2="eidbaooo";
    auto ans=sol.checkInclusion(s1,s2);
    DBG(ans);

    system("pause");
    return 0;
}
