#include "utils.h"

class Solution {
public:
    string longestPalindrome(string s) {
        string s2="^#";
        for(char c:s){s2+=c;s2+="#";}
        s2+='$';
        int middle,maxright=0,arm[s2.size()];
        int maxarm=0,maxarm_head;
        FOR(i,1,s2.size()-1){
            if(i<=maxright){
                int opp=middle*2-i;
                if(opp-arm[opp]<middle*2-maxright){
                    arm[i]=maxright-i;
                }
                else if(opp-arm[opp]==middle*2-maxright){
                    int l=i-arm[opp],r=i+arm[opp];
                    while(l>0&&r<s2.size()&&s2[l-1]==s2[r+1]){l--,r++;}
                    arm[i]=r-i;
                    if(r>maxright){
                        middle=i;
                        maxright=r;
                    }
                    if(arm[i]>maxarm){
                        maxarm=arm[i];
                        maxarm_head=l/2;
                    }
                }
                else arm[i]=arm[opp];
            }
            else{
                int l=i,r=i;
                while(l>0&&r<s2.size()&&s2[l-1]==s2[r+1]){l--,r++;}
                arm[i]=r-i;
                if(r>maxright){
                    middle=i;
                    maxright=r;
                }
                if(arm[i]>maxarm){
                    maxarm=arm[i];
                    maxarm_head=l/2;
                }
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
