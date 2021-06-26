#include "utils.h"

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n=s.size()/2;
        string ans;
        REP(start,n*2){
            if(start%mygcd(n*2,b))continue;
            string cur=s.substr(start)+s.substr(0,start);
            int turn=[&](){
                char old=cur[1];
                int turn=0;
                FOR(i,1,10){
                    if('0'+(old-'0'+i*a)%10<'0'+(old-'0'+turn)%10)turn=i*a;
                }
                return turn;
            }();
            REP(j,n)cur[j*2+1]='0'+(cur[j*2+1]-'0'+turn)%10;
            if(b%2){
                turn=[&](){
                    char old=cur[0];
                    int turn=0;
                    FOR(i,1,10){
                        if('0'+(old-'0'+i*a)%10<'0'+(old-'0'+turn)%10)turn=i*a;
                    }
                    return turn;
                }();
                REP(j,n)cur[j*2]='0'+(cur[j*2]-'0'+turn)%10;
            }
            if(ans.empty()||cur<ans)ans=cur;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="5525";
    int a=9;
    int b=2;
    auto ans=sol.findLexSmallestString(s,a,b);
    DBG(ans);

    system("pause");
    return 0;
}
