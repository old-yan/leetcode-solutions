#include "utils.h"

class Solution {
    bool used[30000]={0};
public:
    int minKBitFlips(vector<int>& A, int K) {
        for(int i=0,cur=0;i<A.size();i++){
            if(i-K>=0&&used[i-K])cur--;
            if((A[i]+cur)%2==0){
                if(i<=A.size()-K){
                    cur++;
                    used[i]=true;
                }
                else return -1;
            }
        }
        return accumulate(used,used+A.size(),0);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{0,0,0,1,0,1,1,0};
    int K=3;
    auto ans=sol.minKBitFlips(A,K);
    DBG(ans);

    system("pause");
    return 0;
}
