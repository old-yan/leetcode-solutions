#include "utils.h"

class Solution {
public:
    //其实这道题很简单，就是每次把sums分成两组，两组之间对应值的差相等，这个差就是原数组的一个数。
    //但是问题来了，两个组的差，是前者减后者，还是后者减前者？答案是，哪一组有0就以那组为基准
    //  为什么呢？
    //  首先sums中一定有0，因为原数组的空子集和为0；
    //  然后，sums每次砍掉一半，最后砍得就剩一个数字的时候，那个数字必须是0，才合理，因为只剩一个数字的时候说明没有元素可选了，那必须是0
    vector<int> recoverArray(int n, vector<int>& sums) {
        vi ans;
        sort(ALL(sums));
        while(ans.size()<n){
            bool used[sums.size()];
            memset(used,0,sizeof(used));
            //两个数组，作为分开后的容器
            vi v0,v1;
            //此时sums是有序的
            //不妨以前两个数的差作为差
            int d=sums[1]-sums[0];
            //双指针算法，将sums拆分成两个数组
            for(int i=0,j=1;;i++,j++){
                //找到一个没用过的i
                while(i<sums.size()&&used[i])i++;
                if(i==sums.size())break;
                //找到一个合适的j
                while(j<=i||sums[j]!=sums[i]+d)j++;
                v0.pb(sums[i]);
                v1.pb(sums[j]);
                used[i]=used[j]=true;
            }
            //如果v0有0，那就以d作为原数组的一个数，保留v0
            if(binary_search(ALL(v0),0)){
                ans.pb(d);
                sums=v0;
            }
            //如果v0没0，那就以-d作为原数组的一个数，保留v1
            else{
                ans.pb(-d);
                sums=v1;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=4;
    vi sums{0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8};
    auto ans=sol.recoverArray(n,sums);
    DBGV(ans);

    system("pause");
    return 0;
}
