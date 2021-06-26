#include "utils.h"

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n=arr.size();
        stack<int>S;
        REPR(i,n-1){
            if(S.empty()||arr[S.top()]>=arr[i]){
                while(S.size()&&arr[S.top()]==arr[i])S.pop();
                S.push(i);
            }
            else{
                int p;
                while(S.size()&&arr[S.top()]<arr[i]){
                    p=S.top();
                    S.pop();
                }
                swap(arr[i],arr[p]);
                break;
            }
        }
        return arr;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,9,4,6,7};
    auto ans=sol.prevPermOpt1(arr);
    DBGV(ans);

    system("pause");
    return 0;
}
