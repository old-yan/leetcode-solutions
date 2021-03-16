#include "utils.h"

class Solution {
    bool find(vvi&obstacles,int i,int j){
        int low=0,high=obstacles.size();
        while(low<high){
            int mid=(low+high)/2;
            if(obstacles[mid][0]>i||(obstacles[mid][0]==i&&obstacles[mid][1]>=j))high=mid;
            else low=mid+1;
        }
        return low<obstacles.size()&&obstacles[low][0]==i&&obstacles[low][1]==j;
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int i=0,j=0,k=0;
        int ans=0;
        sort(ALL(obstacles));
        for(int c:commands){
            if(c==-1)k=(k+3)%4;
            else if(c==-2)k=(k+1)%4;
            else{
                while(c--){
                    if(find(obstacles,i+di[k],j+dj[k]))break;
                    i+=di[k];
                    j+=dj[k];
                    chmax(ans,i*i+j*j);
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi commands{4,-1,3};
    vvi obstacles=makevvi("[]");
    auto ans=sol.robotSim(commands,obstacles);
    DBG(ans);

    system("pause");
    return 0;
}
