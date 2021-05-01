#include "utils.h"

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vi ans;
        REP(i,restaurants.size()){
            int veg=restaurants[i][2],p=restaurants[i][3],d=restaurants[i][4];
            if(veganFriendly&&!veg)continue;
            if(p>maxPrice)continue;
            if(d>maxDistance)continue;
            ans.pb(i);
        }
        sort(ALL(ans),[&](int x,int y){
            if(restaurants[x][1]!=restaurants[y][1])return restaurants[x][1]>restaurants[y][1];
            else return restaurants[x][0]>restaurants[y][0];
        });
        for(int&a:ans)a=restaurants[a][0];
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi restaurants=makevvi("[[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]]");
    int veganFriendly=1;
    int maxPrice=50;
    int maxDistance=10;
    auto ans=sol.filterRestaurants(restaurants,veganFriendly,maxPrice,maxDistance);
    DBGV(ans);

    system("pause");
    return 0;
}
