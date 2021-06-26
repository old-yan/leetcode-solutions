#include "utils.h"

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int pre[numCourses];
        memset(pre,0,sizeof(pre));
        vi post[numCourses];
        for(auto&A:prerequisites){
            pre[A[0]]++;
            post[A[1]].pb(A[0]);
        }
        queue<int>Q;
        REP(i,numCourses){
            if(!pre[i])Q.push(i);
        }
        vi ans;
        while(Q.size()){
            auto a=Q.front();
            Q.pop();
            ans.pb(a);
            for(int b:post[a]){
                if(!--pre[b]){
                    Q.push(b);
                }
            }
        }
        if(ans.size()==numCourses)return ans;
        else return {};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int numCourses=4;
    vvi prerequisites{{1,0},{2,0},{3,1},{3,2}};
    auto ans=sol.findOrder(numCourses,prerequisites);
    DBGV(ans);

    system("pause");
    return 0;
}
