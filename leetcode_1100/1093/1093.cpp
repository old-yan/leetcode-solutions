#include "SegTree.h"
#include "utils.h"

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> ans;
        ans.pb(find_if(ALL(count),[](int x){return x>0;})-count.begin());
        ans.pb(255-(find_if(ALLR(count),[](int x){return x>0;})-count.rbegin()));
        int total=accumulate(ALL(count),0);
        ans.pb([&](){
            double res=0;
            REP(i,256)res+=i*count[i];
            return res/total;
        }());
        SegTree<int>T(count,0,[](int x,int y){return x+y;});
        ans.pb(total%2?T.find_nth(total/2):(T.find_nth(total/2-1)+T.find_nth(total/2))/2.0);
        ans.pb(max_element(ALL(count))-count.begin());
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi count{0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    auto ans=sol.sampleStats(count);
    DBGV(ans);

    system("pause");
    return 0;
}
