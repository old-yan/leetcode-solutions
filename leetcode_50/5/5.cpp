#include "utils.h"

class Solution {
public:
    string longestPalindrome(string s) {
        vi arm=getarm(s);
        int maxarm=0,maxarm_head;
        REP(i,arm.size()){
            if(chmax(maxarm,arm[i])){
                maxarm_head=(i-arm[i])/2;
            }
        }
        return s.substr(maxarm_head,maxarm);
    }
};

int main()
{
    Solution sol;
    
    string s="aerezzeusnilemacaronimaisanitratetartinasiaminoracamelinsuezxzze";
    auto ans=sol.longestPalindrome(s);
    DBG(ans);
    
    system("pause");
    return 0;
}
