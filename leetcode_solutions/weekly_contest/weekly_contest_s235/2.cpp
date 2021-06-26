#include "utils.h"

class Solution {
    int cnt[100001]={0};
public:
    //先对logs进行排序，就可以让用户名一样的凑在一块，然后遍历每个用户，统计他的唯一分钟
    //“唯一”，需要去重，就用unordered_set
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        sort(logs.begin(),logs.end());
        for(int i=0,j;i<logs.size();i=j){
            unordered_set<int>S;
            for(j=i;j<logs.size()&&logs[j][0]==logs[i][0];j++){
                S.insert(logs[j][1]);
            }
            cnt[S.size()]++;
        }
        return vector<int>(cnt+1,cnt+k+1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi logs=makevvi("[[1,1],[2,2],[2,3]]");
    int k=4;
    auto ans=sol.findingUsersActiveMinutes(logs,k);
    DBGV(ans);

    system("pause");
    return 0;
}
