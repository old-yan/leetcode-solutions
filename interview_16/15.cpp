#include "utils.h"

class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        int appear[128]={0};
        for(char c:solution)appear[c]++;
        int good=0,bad=0;
        REP(i,4){
            if(guess[i]==solution[i]){
                appear[guess[i]]--;
                guess[i]=' ';
                good++;
            }
        }
        REP(i,4){
            if(appear[guess[i]]){
                appear[guess[i]]--;
                bad++;
            }
        }
        return {good,bad};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string solution="RGBY";
    string guess="GGRR";
    auto ans=sol.masterMind(solution,guess);
    DBGV(ans);

    system("pause");
    return 0;
}
