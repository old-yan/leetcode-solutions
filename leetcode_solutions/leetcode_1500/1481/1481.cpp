#include "utils.h"

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(ALL(arr));
        priority_queue<int>Q;
        for(int i=0,j;i<arr.size();i=j){
            for(j=i+1;j<arr.size()&&arr[j]==arr[i];j++);
            Q.push(j-i);
        }
        int ans=0;
        while(k<arr.size()){
            ans++;
            k+=Q.top();
            Q.pop();
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{5,5,4};
    int k=1;
    auto ans=sol.findLeastNumOfUniqueInts(arr,k);
    DBG(ans);

    system("pause");
    return 0;
}
