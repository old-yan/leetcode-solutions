#include "utils.h"

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        sort(ALL(logs));
        vi ans(k);
        for(int i=0,j;i<logs.size();i=j){
            int cnt=0;
            for(j=i;j<logs.size()&&logs[j][0]==logs[i][0];j++){
                if(j==i||logs[j][1]!=logs[j-1][1])cnt++;
            }
            ans[cnt-1]++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi logs=makevvi("[[0,5],[1,2],[0,2],[0,5],[1,3]]");
    int k=5;
    auto ans=sol.findingUsersActiveMinutes(logs,k);
    DBGV(ans);

    system("pause");
    return 0;
}
