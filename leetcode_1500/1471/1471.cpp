#include "utils.h"

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n=arr.size();
        nth_element(arr.begin(),arr.begin()+(n-1)/2,arr.end());
        int mid=arr[(n-1)/2];
        nth_element(arr.begin(),arr.begin()+k,arr.end(),[&](int x,int y){
            if(abs(x-mid)!=abs(y-mid))return abs(x-mid)>abs(y-mid);
            else return x>y;
        });
        arr.resize(k);
        return arr;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,2,3,4,5};
    int k=2;
    auto ans=sol.getStrongest(arr,k);
    DBGV(ans);

    system("pause");
    return 0;
}
