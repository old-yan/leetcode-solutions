#include "utils.h"

class Solution {
public:
    //本题显然不能用模拟，那么如何节省时间呢？那就是利用重复计算
    //比如我们曾经从 点3 到达 点5，现在从 点5 回到 点3 ，那么我们一定得从 点3 再次到达 点5，才能往6、7、8...走
    //既然如此，我们第二次走3->5的路，就不要再重新推了
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n=nextVisit.size();
        //time[i]表示第一次到达点 i 的时间
        long long time[n];
        long long curtime=0;
        for(int cur=0;cur<n;cur++){
            curtime=(curtime+1)%MOD;
            time[cur]=curtime;
            //目前只是第一次到 cur
            //只有偶数次到 cur 才能往右走
            //我们必须返回next，然后从next再走一次之前走过的 next->out 的路
            int next=nextVisit[cur];
            curtime+=(curtime-time[next]+MOD)+1;
            curtime%=MOD;
            //现在的curtime才是第二次到cur的时间
        }
        //最后记住减一，因为我是按到达0的时间为1来算的
        return (time[n-1]+MOD-1)%MOD;
    }
    //一个小问题，time[next]表示的是到next的第一次时间，为什么必须用 curtime和time[next] 做差？
    //用 curtime和到next的第二次时间做差行不行？
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>nextVisit{0,1,2,0};
    auto ans=sol.firstDayBeenInAllRooms(nextVisit);
    DBG(ans);

    system("pause");
    return 0;
}