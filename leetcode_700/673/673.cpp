#include "SegTree.h"
#include "utils.h"

class Solution {
    struct lengthCounter{
        int len,count;
        lengthCounter(int _len=0,int _counter=0):len(_len),count(_counter){}
    };
    static lengthCounter merge(lengthCounter&x,lengthCounter&y){
        if(x.len==y.len)return lengthCounter(x.len,x.count+y.count);
        return x.len>y.len?x:y;
    };
public:
    int findNumberOfLIS(vector<int>& nums) {
        static SegTree<lengthCounter>T(2000,merge);
        vi rnk=getrank2(nums);
        T.set(lengthCounter());
        REP(i,rnk.size()){
            auto p=T(0,rnk[i]-1);
            p.len++;
            chmax(p.count,1);
            T.step(rnk[i],p);
        }
        return T.data[1].count;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,2};
    auto ans=sol.findNumberOfLIS(nums);
    DBG(ans);

    system("pause");
    return 0;
}
