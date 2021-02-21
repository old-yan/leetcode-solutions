#include "utils.h"

class Solution {
public:
    //每当知道ans[i]时，可以根据左边的球数，右边的球数，当前的球数（0或1），递归求得ans[i+1]
    //所以只有ans[0]需要O(n)时间获得
    //之后的ans[i]均可以O(1)获得
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>ans;
        int left=0,right=0,cur=0,cnt=0;
        if(boxes[0]=='1')cur++;
        for(int i=1;i<n;i++){
            if(boxes[i]=='1'){
                right++;
                cnt+=i;
            }
        }
        ans.pb(cnt);
        for(int i=1;i<n;i++){
            left+=cur;
            if(boxes[i]=='1'){
                cur=1;
                right--;
            }
            else cur=0;
            cnt=cnt+left-right-cur;
            ans.pb(cnt);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string b="001011";
    auto ans=sol.minOperations(b);
    DBGV(ans);

    system("pause");
    return 0;
}
