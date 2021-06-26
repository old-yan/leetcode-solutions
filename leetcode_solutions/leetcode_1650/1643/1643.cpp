#include "utils.h"

class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int m=destination[0],n=destination[1];
        int restm=m,restn=n;
        string ans;
        REP(i,m+n){
            if(!restm)ans.pb('H');
            else if(!restn)ans.pb('V');
            else{
                ll half=combination(restm+restn-1,restn-1);
                if(half>=k){
                    ans.pb('H');
                    restn--;
                }
                else{
                    ans.pb('V');
                    restm--;
                    k-=half;
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

    vi destination{2,3};
    int k=1;
    auto ans=sol.kthSmallestPath(destination,k);
    DBG(ans);

    system("pause");
    return 0;
}
