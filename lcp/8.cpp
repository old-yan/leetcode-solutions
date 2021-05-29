#include "utils.h"

class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        int n=requirements.size();
        vi ans(n,-1);
        vector<pair<int,int>>v0,v1,v2;
        REP(j,n){
            v0.emplace_back(requirements[j][0],j);
            v1.emplace_back(requirements[j][1],j);
            v2.emplace_back(requirements[j][2],j);
        }
        sort(ALL(v0));
        sort(ALL(v1));
        sort(ALL(v2));
        int cursor0=0,cursor1=0,cursor2=0,cur0=0,cur1=0,cur2=0;
        while(cursor0<n&&v0[cursor0].first<=cur0){
            chmax(ans[v0[cursor0++].second],0);
        }
        while(cursor1<n&&v1[cursor1].first<=cur1){
            chmax(ans[v1[cursor1++].second],0);
        }
        while(cursor2<n&&v2[cursor2].first<=cur2){
            chmax(ans[v2[cursor2++].second],0);
        }
        REP(j,increase.size()){
            cur0+=increase[j][0];
            cur1+=increase[j][1];
            cur2+=increase[j][2];
            while(cursor0<n&&v0[cursor0].first<=cur0){
                chmax(ans[v0[cursor0++].second],int(j+1));
            }
            while(cursor1<n&&v1[cursor1].first<=cur1){
                chmax(ans[v1[cursor1++].second],int(j+1));
            }
            while(cursor2<n&&v2[cursor2].first<=cur2){
                chmax(ans[v2[cursor2++].second],int(j+1));
            }
        }
        while(cursor0<n){
            ans[v0[cursor0++].second]=-1;
        }
        while(cursor1<n){
            ans[v1[cursor1++].second]=-1;
        }
        while(cursor2<n){
            ans[v2[cursor2++].second]=-1;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi increase=makevvi("[[2,8,4],[2,5,0],[10,9,8]]");
    vvi requirements=makevvi("[[2,11,3],[15,10,7],[9,17,12],[8,1,14]]");
    auto ans=sol.getTriggerTime(increase,requirements);
    DBGV(ans);

    system("pause");
    return 0;
}
