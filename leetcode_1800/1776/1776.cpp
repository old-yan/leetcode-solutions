#include "utils.h"

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n=cars.size();
        vector<double>ans(n,-1);
        stack<int>S;
        REPR(i,n-1){
            while(S.size()){
                if(cars[S.top()][1]>=cars[i][1])S.pop();
                else{
                    double time=1.0*(cars[S.top()][0]-cars[i][0])/(cars[i][1]-cars[S.top()][1]);
                    if(ans[S.top()]<0||ans[S.top()]>=time){
                        ans[i]=time;
                        break;
                    }
                    else S.pop();
                }
            }
            S.push(i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi cars=makevvi("[[1,2],[2,1],[4,3],[7,2]]");
    auto ans=sol.getCollisionTimes(cars);
    DBGV(ans);

    system("pause");
    return 0;
}
