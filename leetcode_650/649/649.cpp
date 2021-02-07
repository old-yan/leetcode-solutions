#include "utils.h"

class Solution {
public:
    string predictPartyVictory(string senate) {
        int num[128]={0};
        for(char c:senate)num[c]++;
        int banR=0,banD=0;
        while(num['R']&&num['D']){
            for(char&c:senate){
                if(c=='R'){
                    if(banR){
                        banR--;
                        c=' ';
                        num['R']--;
                    }
                    else banD++;
                }
                else if(c=='D'){
                    if(banD){
                        banD--;
                        c=' ';
                        num['D']--;
                    }
                    else banR++;
                }
            }
        }
        return num['R']?"Radiant":"Dire";
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string senate="RDDRDRRRDD";
    auto ans=sol.predictPartyVictory(senate);
    DBG(ans);

    system("pause");
    return 0;
}
