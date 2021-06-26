#include "utils.h"

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int>M;
        for(int a:A){
            for(int b:B){
                M[a+b]++;
            }
        }
        int ans=0;
        for(int c:C){
            for(int d:D){
                ans+=M[-c-d];
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{1,2};
    vi B{-2,-1};
    vi C{-1,2};
    vi D{0,2};
    auto ans=sol.fourSumCount(A,B,C,D);
    DBG(ans);

    system("pause");
    return 0;
}
