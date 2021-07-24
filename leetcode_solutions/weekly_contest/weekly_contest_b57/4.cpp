#include "utils.h"

class Solution {
public:
    //本题需要对单调栈的做法非常敏感
    vector<int> canSeePersonsCount(vector<int>& heights) {
        //代码基本上就是求 rightBigger 的代码
        //在每个位置 pop 出的元素，一定可以被当地所看到：
        //  首先，pop 的元素小于 i 处元素
        //  其次，pop的元素 和 i 之间，一定没有比 pop 出的元素更高的，否则它早就 pop 了
        //在每个位置可以看到的、且比 i 小的元素，一定会在 i 处 pop ：
        //  首先，这种元素左边没有比自己大的。所以自从它入队一定没有 pop
        //  其次，这种元素比 i 小，所以此时一定 pop
        stack<int>S;
        vector<int>ans(heights.size(),0);
        for(int i=heights.size()-1;i>=0;i--){
            while(S.size()&&heights[S.top()]<=heights[i]){
                S.pop();
                ans[i]++;
            }
            // 特判 rightSmaller 元素。它也可以被 i 看到
            if(S.size()){
                ans[i]++;
            }
            S.push(i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi heights{10,6,8,5,11,9};
    auto ans=sol.canSeePersonsCount(heights);
    DBGV(ans);

    system("pause");
    return 0;
}
