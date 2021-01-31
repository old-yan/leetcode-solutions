#include "utils.h"

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        //利用bucket_count数组记录每个桶内数量
        int bucket_count[1000]={0};
        multiset<int>S;
        for(int i=lowLimit;i<=highLimit;i++){
            string s=to_string(i);
            int sum=0;
            for(char c:s)sum+=c-'0';
            //删掉老数量
            S.erase(S.find(bucket_count[sum]));
            //插入新数量
            S.insert(++bucket_count[sum]);
        }
        return *S.rbegin();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int lowlimit=1;
    int highlimit=100;
    auto ans=sol.countBalls(lowlimit,highlimit);
    DBG(ans);

    system("pause");
    return 0;
}
