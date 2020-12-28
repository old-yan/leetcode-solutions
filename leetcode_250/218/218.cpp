#include "utils.h"

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int,vector<int>>left,right;
        set<int>points;
        for(auto&A:buildings){
            points.insert(A[0]);
            left[A[0]].pb(A[2]);
            points.insert(A[1]);
            right[A[1]].pb(A[2]);
        }
        vvi ans;
        mset<int>pool{0};
        int now_height=0;
        for(int a:points){
            for(int b:left[a]){
                pool.insert(b);
            }
            for(int b:right[a]){
                pool.erase(pool.find(b));
            }
            if(*pool.rbegin()!=now_height){
                ans.pb(vi{a,*pool.rbegin()});
                now_height=*pool.rbegin();
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi buildings{{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    auto ans=sol.getSkyline(buildings);
    DBGVV(ans);

    system("pause");
    return 0;
}
