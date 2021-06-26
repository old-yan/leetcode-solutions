#include "utils.h"

class Solution {
    int temp[100];
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n=arr.size();
        vi ans;
        FORR(val,n,1){
            int pos;
            for(pos=0;arr[pos]!=val;pos++);
            if(pos==val-1)continue;
            ans.pb(pos+1);
            ans.pb(val);
            memcpy(temp,&arr[pos+1],(val-1-pos)*sizeof(int));
            memmove(&arr[val-1-pos],&arr[0],(pos+1)*sizeof(int));
            memcpy(&arr[0],temp,(val-1-pos)*sizeof(int));
            reverse(&arr[0],&arr[val-1-pos]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{3,2,4,1};
    auto ans=sol.pancakeSort(arr);
    DBGV(ans);

    system("pause");
    return 0;
}

//  a   b   c   d   e   f   g
//  d   c   b   a   e   f   g
//  g   f   e   a   b   c   d
