#include "utils.h"

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n=machines.size();
        int sum=0;
        for(int a:machines)sum+=a;
        if(sum%n)return -1;
        int ave=sum/n;
        int ans=0;
        vi goleft(n,0);
        vi goright(n,0);
        int cursum=0;
        REP(i,n){
            if(cursum<i*ave)goleft[i]=i*ave-cursum;
            if(cursum+machines[i]>(i+1)*ave)goright[i]=cursum+machines[i]-(i+1)*ave;
            cursum+=machines[i];
            if(goleft[i]&&goright[i])chmax(ans,goleft[i]+goright[i]);
            else if(goleft[i])chmax(ans,goleft[i]);
            else if(goright[i])chmax(ans,goright[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi machines{1,0,5};
    auto ans=sol.findMinMoves(machines);
    DBG(ans);

    system("pause");
    return 0;
}
