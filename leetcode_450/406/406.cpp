#include "SegTree.h"
#include "utils.h"

SegTree<int> T(2000,[](int x,int y){return x+y;});
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        T.set(vi(people.size(),1));
        vi idx(people.size());
        iota(ALL(idx),0);
        sort(ALL(idx),[&](int x,int y)->bool{return people[x][0]<people[y][0]||(people[x][0]==people[y][0]&&people[x][1]>people[y][1]);});
        vvi ans(people.size());
        for(int i:idx){
            int k=people[i][1];
            int pos=T.find_nth(k);
            T.set(pos,0);
            ans[pos]=people[i];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi people{
        {7,0},{4,4},{7,1},{5,0},{6,1},{5,2}
    };
    auto ans=sol.reconstructQueue(people);
    DBGVV(ans);

    system("pause");
    return 0;
}
