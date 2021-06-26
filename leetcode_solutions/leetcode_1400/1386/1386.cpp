#include "utils.h"

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(ALL(reservedSeats));
        int row=0;
        int ans=0;
        for(int i=0;i<reservedSeats.size();){
            row++;
            int cur=reservedSeats[i][0];
            int seats[10]={0};
            while(i<reservedSeats.size()&&reservedSeats[i][0]==cur){
                seats[reservedSeats[i++][1]-1]=1;
            }
            if(!accumulate(seats+1,seats+9,0))ans+=2;
            else if(!accumulate(seats+1,seats+5,0)||!accumulate(seats+3,seats+7,0)||!accumulate(seats+5,seats+9,0))ans++;
        }
        return ans+(n-row)*2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    vvi reservedSeats=makevvi("[[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]");
    auto ans=sol.maxNumberOfFamilies(n,reservedSeats);
    DBG(ans);

    system("pause");
    return 0;
}
