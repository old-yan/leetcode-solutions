#include "utils.h"

class Solution {
public:
    //这种问题，首先应该考虑高位，因为高位的变化比低位的变化影响要大得多
    //用一个 start 标志，来标记目前是否已经开始替换
    //一旦开始替换就不能停，停的时候就没有下一次替换机会了，所以break
    string maximumNumber(string num, vector<int>& ch) {
        bool start=true;
        for(char &c:num){
            char d='0'+ch[c-'0'];
            if(start){
                //开始后只替换更大的或者维持不变的
                if(d>=c)c=d;
                else break;
            }
            else{
                //没开始的时候，忽略那些更小的或者维持不变的
                if(d<=c)continue;
                else if(d>c)start=true,c=d;
            }
        }
        return num;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string num="132";
    vi change{9,8,5,0,3,6,4,2,6,8};
    auto ans=sol.maximumNumber(num,change);
    DBG(ans);

    system("pause");
    return 0;
}
