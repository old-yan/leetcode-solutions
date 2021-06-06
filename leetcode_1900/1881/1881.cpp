#include "utils.h"

class Solution {
public:
    string maxValue(string n, int x) {
        if(n[0]=='-'){
            FOR(i,1,n.size()){
                if(n[i]>'0'+x){
                    n.insert(n.begin()+i,'0'+x);
                    return n;
                }
            }
            return n+char('0'+x);
        }
        else{
            REP(i,n.size()){
                if(n[i]<'0'+x){
                    n.insert(n.begin()+i,'0'+x);
                    return n;
                }
            }
            return n+char('0'+x);
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string n="-13";
    int x=2;
    auto ans=sol.maxValue(n,x);
    DBG(ans);

    system("pause");
    return 0;
}
