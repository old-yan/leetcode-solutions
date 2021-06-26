#include "utils.h"

class Solution {
public:
    //本题为经典离线处理题目，虽然ans和queries需要一一对应，但是不需要从前往后进行答复
    //易知,queries[i][1]较大时，拥有较小的选择范围；queries[i][1]较小时，拥有较大的选择范围
    //我们就按queries[i][1]从大到小进行答复，答复的同时，将可选的范围逐渐增大
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        //将queries下标按minSize降序排列
        vi idxes(queries.size());
        iota(ALL(idxes),0);
        sort(ALL(idxes),[&](int x,int y){return queries[x][1]>queries[y][1];});
        //将rooms按size降序排列
        sort(ALL(rooms),[&](vi&x,vi&y){return x[1]>y[1];});
        //用一个有序池子S表示目前的房间id选择范围
        set<int>S;
        //cur表示rooms目前准备放入池子的房间下标
        int cur=0;
        vi ans(queries.size());
        auto closer=[](int a,int b,int t){
            if(abs(a-t)!=abs(b-t))return abs(a-t)<abs(b-t);
            else return a<b;
        };
        for(int idx:idxes){
            auto&q=queries[idx];
            //按照当前query的minSize，扩充选择范围
            while(cur<rooms.size()&&rooms[cur][1]>=q[1])S.insert(rooms[cur++][0]);
            //若池子空，答复-1
            if(S.empty())ans[idx]=-1;
            else{
                //若池子非空，那么答复就是比prefer稍大或者稍小的某个id
                //由于池子是有序的，所以可以二分寻找（set自带lower_bound）
                int res=INT_MAX;
                auto it=S.lower_bound(q[0]);
                if(it!=S.end()&&closer(*it,res,q[0]))res=*it;
                if(it!=S.begin()){
                    --it;
                    if(closer(*it,res,q[0]))res=*it;
                }
                ans[idx]=res;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi rooms=makevvi("[[1,4],[2,3],[3,5],[4,1],[5,2]]");
    vvi que=makevvi("[[2,3],[2,4],[2,5]]");
    auto ans=sol.closestRoom(rooms,que);
    DBGV(ans);

    system("pause");
    return 0;
}
