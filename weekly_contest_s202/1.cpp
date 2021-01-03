#include "utils.h"

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        //按照每种箱子的单位载货量，降序排序
        sort(boxTypes.begin(),boxTypes.end(),[&](vector<int>&x,vector<int>&y)->bool{return x[1]>y[1];});
        int ans=0;
        for(int i=0;i<boxTypes.size();i++){
            int j=boxTypes[i][0];
            while(truckSize&&j--){
                truckSize--;
                ans+=boxTypes[i][1];
            }
            //若买箱子的名额用完，就中断
            if(!truckSize)break;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi boxTypes{
        {5,10},{2,5},{4,7},{3,9}
    };
    int truckSize=10;
    auto ans=sol.maximumUnits(boxTypes,truckSize);
    DBG(ans);

    system("pause");
    return 0;
}
