#include "utils.h"

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vvi ans;
        for(int i=0,j=0;i<firstList.size()&&j<secondList.size();i++){
            while(j<secondList.size()&&secondList[j][1]<firstList[i][0])j++;
            while(j<secondList.size()&&secondList[j][1]<=firstList[i][1]){
                ans.pb({max(firstList[i][0],secondList[j][0]),secondList[j][1]});
                j++;
            }
            if(j<secondList.size()&&secondList[j][0]<=firstList[i][1]){
                ans.pb({max(firstList[i][0],secondList[j][0]),firstList[i][1]});
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi firstList=makevvi("[[0,2],[5,10],[13,23],[24,25]]");
    vvi secondList=makevvi("[[1,5],[8,12],[15,24],[25,26]]");
    auto ans=sol.intervalIntersection(firstList,secondList);
    DBGVV(ans);

    system("pause");
    return 0;
}
