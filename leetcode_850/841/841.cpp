#include "utils.h"

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        bitset<1000>unlock;
        queue<int>Q;
        unlock.set(0);
        Q.push(0);
        while(Q.size()){
            auto p=Q.front();
            Q.pop();
            for(int a:rooms[p]){
                if(!unlock[a]){
                    unlock.set(a);
                    Q.push(a);
                }
            }
        }
        return unlock.size()==n;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi rooms=makevvi("[[1],[2],[3],[]]");
    auto ans=sol.canVisitAllRooms(rooms);
    DBG(ans);

    system("pause");
    return 0;
}
