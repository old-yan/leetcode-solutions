#include "utils.h"

class Solution {
    struct Counter{
        vector<long long>presum;
        Counter(vector<vector<int>>&fruits){
            presum.reserve(fruits.size()+1);
            presum.push_back(0);
            for(auto &fruit:fruits){
                presum.push_back(presum.back()+fruit[1]);
            }
        }
        long long query(int left,int right){
            return presum[right+1]-presum[left];
        }
    };
public:
    //我们肯定是要获得一个区间，而这个区间范围有个特点，就是两端的大小正相关
    //换句话说，如果我们把区间左端不断右移，那么右端肯定也在不断右移（不可能左移）
    //那事情就好办了，双指针解决
    //找到一个区间之后，用前缀和做差求出区间和
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        Counter C(fruits);
        auto is_ok=[&](int l,int r){
            if(l>r)return false;
            l=fruits[l][0];
            r=fruits[r][0];
            if(r<=startPos)return startPos-l<=k;
            else if(l>=startPos)return r-startPos<=k;
            else return min(startPos-l+r-l,r-startPos+r-l)<=k;
        };
        //找到 startPos-k 右侧的第一个点作为起始区间的左端
        int l=lower_bound(fruits.begin(),fruits.end(),vector<int>{startPos-k})-fruits.begin();
        int r=l;
        long long ans=0;
        //如果当前区间合法，那么不妨把右端尽量拓展
        while(l<fruits.size() and is_ok(l,r)){
            while(r+1<fruits.size() and is_ok(l,r+1))r++;
            //拓展之后求区间和
            ans=max(ans,C.query(l,r));
            //区间左端右移
            ++l;r=max(r,l);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<int>>pairs=makevvi("[[2,8],[6,3],[8,6]]");
    int startPos=5;
    int k=4;
    auto ans=sol.maxTotalFruits(pairs,startPos,k);
    DBG(ans);

    system("pause");
    return 0;
}