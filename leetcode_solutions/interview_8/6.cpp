#include "utils.h"

class Solution {
    void give(vi&A,vi&C,vi&B,int num){
        if(num==1){
            C.pb(A.back());
            A.pop_back();
        }
        else{
            give(A,B,C,num-1);
            C.pb(A.back());
            A.pop_back();
            give(B,C,A,num-1);
        }
    }
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        give(A,C,B,A.size());
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{2,1,0};
    vi B;
    vi C;
    sol.hanota(A,B,C);

    system("pause");
    return 0;
}
