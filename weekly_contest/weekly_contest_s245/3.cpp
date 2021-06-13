#include "utils.h"

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a=0,b=0,c=0;
        for(auto&t:triplets){
            if(t[0]<=target[0]&&t[1]<=target[1]&&t[2]<=target[2]){
                chmax(a,t[0]);
                chmax(b,t[1]);
                chmax(c,t[2]);
            }
        }
        return a==target[0]&&b==target[1]&&c==target[2];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi tripltes=makevvi("[[2,5,3],[1,8,4],[1,7,5]]");
    vi target{2,7,5};
    auto ans=sol.mergeTriplets(tripltes,target);
    DBG(ans);

    system("pause");
    return 0;
}
