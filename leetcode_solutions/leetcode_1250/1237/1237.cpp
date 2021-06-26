#include "utils.h"

class CustomFunction {
    int id;
public:
    CustomFunction(int _id):id(_id){}
    int f(int x, int y){
        if(id==1)return x+y;
        else if(id==2)return x*y;
        else if(id==3)return x*x+y;
        else if(id==4)return x+y*y;
        else if(id==5)return x*x+y*y;
        else if(id==6)return x*x+2*x*y+y*y;
        else if(id==7)return pow(x,3)+pow(y,3);
        else if(id==8)return x*x*y;
        else if(id==9)return x*y*y;
        else return -1;
    }
};

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vvi ans;
        int begin=[&](){
            int low=1,high=1001;
            while(low<high){
                int mid=(low+high)/2;
                if(customfunction.f(mid,1000)<=z)low=mid+1;
                else high=mid;
            }
            return low;
        }();
        int end=[&](){
            int low=begin,high=1001;
            while(low<high){
                int mid=(low+high)/2;
                if(customfunction.f(mid,1)<=z)low=mid+1;
                else high=mid;
            }
            return low;
        }();
        FOR(i,begin,end){
            int j=[&](){
                int low=1,high=1000;
                while(low<high){
                    int mid=(low+high)/2;
                    if(customfunction.f(i,mid)>=z)high=mid;
                    else low=mid+1;
                }
                return low;
            }();
            if(customfunction.f(i,j)==z)ans.pb({int(i),j});
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    CustomFunction cf(1);
    int z=5;
    auto ans=sol.findSolution(cf,z);
    DBGVV(ans);

    system("pause");
    return 0;
}
