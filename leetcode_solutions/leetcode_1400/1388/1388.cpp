#include "Heap.h"
#include "utils.h"

class Solution {
    int value[500],prev[500],next[500];
    bool can[500];
    void del(int cur){
        next[prev[cur]]=next[cur];
        prev[next[cur]]=prev[cur];
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size()/3;
        memcpy(value,&slices[0],n*3*sizeof(int));
        REP(i,n*3){
            value[i]=slices[i];
            prev[i]=(i+n*3-1)%(n*3);
            next[i]=(i+1)%(n*3);
        }
        fill(can,can+n*3,true);
        BiHeap<int>H([&](int x,int y){return value[x]<value[y];});
        REP(i,n*3)H.push(i);
        int ans=0,cnt=0;
        while(cnt<n){
            auto p=H.top();
            if(!can[p]){
                H.pop();
            }
            else{
                ans+=value[p];
                cnt++;
                value[p]=value[prev[p]]+value[next[p]]-value[p];
                can[prev[p]]=false;
                del(prev[p]);
                can[next[p]]=false;
                del(next[p]);
                H.sink(p);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi slices{1,2,3,4,5,6};
    auto ans=sol.maxSizeSlices(slices);
    DBG(ans);

    system("pause");
    return 0;
}
