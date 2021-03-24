#include "utils.h"

class Solution {
    int ans[500000],len=0;
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();
        int cur[32]={0},curlen=1;
        for(int a:arr){
            if(a){
                int i,j;
                cur[curlen++]=0;
                for(i=0;i<curlen&&(cur[i]&a)==a;i++);
                for(j=i;i<curlen;i++){
                    cur[j]=cur[i]|a;
                    if(!j||cur[j]!=cur[j-1]){
                        ans[len++]=cur[j++];
                    }
                }
                curlen=j;
            }
            else ans[len++]=0;
        }
        sort(ans,ans+len);
        return unique(ans,ans+len)-ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,2,4};
    auto ans=sol.subarrayBitwiseORs(arr);
    DBG(ans);

    system("pause");
    return 0;
}
