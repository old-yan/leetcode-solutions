#include "utils.h"

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vi post[numCourses];
        vi pre(numCourses,0);
        queue<int>Q;
        for(auto&A:prerequisites){
            post[A[0]].pb(A[1]);
            pre[A[1]]++;
        }
        REP(i,numCourses)if(!pre[i])Q.push(i);
        int count=0;
        while(Q.size()){
            count++;
            auto i=Q.front();
            Q.pop();
            for(int a:post[i]){
                if(!--pre[a])Q.push(a);
            }
        }
        return count==numCourses;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int numCourses=2;
    vvi prerequisites{{1,0},{0,1}};
    auto ans=sol.canFinish(numCourses,prerequisites);
    DBG(ans);

    system("pause");
    return 0;
}
