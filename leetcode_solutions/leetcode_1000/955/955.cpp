#include "utils.h"

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m=strs.size(),n=strs[0].size();
        string T[n];
        REP(i,m){
            REP(j,n){
                T[j]+=strs[i][j];
            }
        }
        int rnk[m];
        fill(rnk,rnk+m,0);
        int ans=0;
        REP(j,n){
            bool del=false;
            FOR(i,1,m){
                if(rnk[i]==rnk[i-1]&&T[j][i]<T[j][i-1]){
                    del=true;
                    break;
                }
            }
            if(del)ans++;
            else{
                int oldrnk[m];
                memcpy(oldrnk,rnk,sizeof(rnk));
                FOR(i,1,m){
                    if(oldrnk[i]==oldrnk[i-1]&&T[j][i]==T[j][i-1])rnk[i]=rnk[i-1];
                    else rnk[i]=rnk[i-1]+1;
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>strs{
        "zyx","wvu","tsr"
    };
    auto ans=sol.minDeletionSize(strs);
    DBG(ans);

    system("pause");
    return 0;
}
