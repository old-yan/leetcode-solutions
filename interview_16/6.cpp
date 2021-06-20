#include "utils.h"

class Solution {
public:
    int smallestDifference(vector<int>& A, vector<int>& B) {
        sort(ALL(A));
        sort(ALL(B));
        int cursor=0;
        ll ans=INT_MAX;
        for(int b:B){
            while(cursor<A.size()&&A[cursor]<b)cursor++;
            if(cursor<A.size())chmin(ans,(ll)A[cursor]-b);
            if(cursor)chmin(ans,(ll)b-A[cursor-1]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{1, 3, 15, 11, 2};
    vi B{23, 127, 235, 19, 8};
    auto ans=sol.smallestDifference(A,B);
    DBG(ans);

    system("pause");
    return 0;
}
