#include "utils.h"

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        REP(i,int(arr.size())-m*k+1){
            bool flag=true;
            REP(j,m*k){
                if(arr[i+j]!=arr[i+j%m]){
                    flag=false;
                    break;
                }
            }
            if(flag)return true;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,2,4,4,4,4};
    int m=1;
    int k=3;
    auto ans=sol.containsPattern(arr,m,k);
    DBG(ans);

    system("pause");
    return 0;
}
