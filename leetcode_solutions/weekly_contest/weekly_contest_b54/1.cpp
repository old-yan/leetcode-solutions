#include "utils.h"

class Solution {
public:
    //可以通过差分，获取[0~50]区间上每个点被几个range覆盖
    //然后线性查找[left,right]区间，看有没有没被覆盖的

    //差分思想的理解：假如你是民政局，知道了一群人的生卒年份，怎么查询某一年有几个人活着？
    //可以从前往后遍历，每年加上生的人，减去卒的人，就可以按顺序填好每一年的人数
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int A[52]={0};
        for(auto&r:ranges){
            A[r[0]]++;
            A[r[1]+1]--;
        }
        partial_sum(A,A+52,A);
        return !count(A+left,A+right+1,0);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi ranges=makevvi("[[1,2],[3,4],[5,6]]");
    int left=2;
    int right=5;
    auto ans=sol.isCovered(ranges,left,right);
    DBG(ans);

    system("pause");
    return 0;
}
