#include "utils.h"

class Solution {
public:
    //排序+双指针
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        //先按降序排序
        sort(ALLR(properties));
        //然后双指针，为什么双指针？
        //  因为如果一个一个处理的话，和当前攻击力相同的人的防御力比当前较大，会被算进答案里，但是这不该算进去
        //  双指针是一种处理方案，将攻击力相同的一批人统一处理，让它们不互相干扰

        //maxpre记录前缀最大防御
        int maxpre=0;
        int ans=0;
        for(int i=0,j;i<properties.size();i=j){
            //先查询对于j，之前有没有防御比j的防御大的，有的话j就算进答案
            for(j=i;j<properties.size()&&properties[j][0]==properties[i][0];j++){
                if(maxpre>properties[j][1])ans++;
            }
            //统计完答案之后，再用这一批的防御来更新最大防御
            for(j=i;j<properties.size()&&properties[j][0]==properties[i][0];j++){
                if(maxpre<properties[j][1])maxpre=properties[j][1];
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi properties=makevvi("[[5,5],[6,3],[3,6]]");
    auto ans=sol.numberOfWeakCharacters(properties);
    DBG(ans);

    system("pause");
    return 0;
}
