#include "utils.h"

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n=A.size();
        for(auto&row:A){
            for(int i=0,j=n-1;i<j;i++,j--){
                if(row[i]==row[j]){
                    row[i]=!row[i];
                    row[j]=!row[j];
                }
            }
            if(n%2)row[n/2]=!row[n/2];
        }
        return A;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi A=makevvi("[[1,1,0],[1,0,1],[0,0,0]]");
    auto ans=sol.flipAndInvertImage(A);
    DBGVV(ans);

    system("pause");
    return 0;
}
