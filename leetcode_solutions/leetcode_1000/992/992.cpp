#include "utils.h"

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        unordered_map<int,int>M1,M2;
        int ans=0;
        for(int i=0,j=0,k=0;i<A.size();i++){
            while(M1.size()<K&&j<A.size()){
                M1[A[j++]]++;
            }
            if(M1.size()<K)break;
            while(M2.size()<=K){
                if(k<A.size())M2[A[k++]]++;
                else{
                    k=A.size()+1;
                    break;
                }
            }
            ans+=k-j;
            if(!--M1[A[i]])M1.erase(A[i]);
            if(!--M2[A[i]])M2.erase(A[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{1,2,1,3,4};
    int K=3;
    auto ans=sol.subarraysWithKDistinct(A,K);
    DBG(ans);

    system("pause");
    return 0;
}
