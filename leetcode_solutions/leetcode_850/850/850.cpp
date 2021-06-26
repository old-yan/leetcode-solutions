#include "utils.h"

class Solution {
    vi height_list,line_list;
    int depth[100]={0};
    int inc[200][100]={0};
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        for(auto&rec:rectangles){
            height_list.pb(rec[1]);
            height_list.pb(rec[3]);
            line_list.pb(rec[0]);
            line_list.pb(rec[2]);
        }
        sort(ALL(height_list));
        height_list.resize(unique(ALL(height_list))-height_list.begin());
        sort(ALL(line_list));
        line_list.resize(unique(ALL(line_list))-line_list.begin());
        for(auto&rec:rectangles){
            int x0=lower_bound(ALL(line_list),rec[0])-line_list.begin();
            int y0=lower_bound(ALL(height_list),rec[1])-height_list.begin();
            int x1=lower_bound(ALL(line_list),rec[2])-line_list.begin();
            int y1=lower_bound(ALL(height_list),rec[3])-height_list.begin();
            inc[x0][y0]++;
            inc[x0][y1]--;
            inc[x1][y0]--;
            inc[x1][y1]++;
        }
        ll ans=0;
        REPR(i,line_list.size()-1){
            line_list[i]-=i?line_list[i-1]:line_list[i];
        }
        REP(i,height_list.size()-1){
            height_list[i]=i+1==height_list.size()?0:height_list[i+1]-height_list[i];
        }
        REP(i,line_list.size()){
            int incre=0;
            REP(j,height_list.size()){
                if(depth[j]>0){
                    ans=(ans+(ll)height_list[j]*line_list[i])%MOD;
                }
                incre+=inc[i][j];
                depth[j]+=incre;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi rectangles=makevvi("[[0,0,1000000000,1000000000]]");
    auto ans=sol.rectangleArea(rectangles);
    DBG(ans);

    system("pause");
    return 0;
}
