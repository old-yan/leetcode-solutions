#include "utils.h"

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low=0,high=arr.size()-k;
        auto worse=[x](int y,int z){
            return abs(y-x)>abs(z-x)||y-x==abs(z-x);
        };
        while(low<high){
            int mid=(low+high)/2;
            if(mid+k==arr.size()||worse(arr[mid+k],arr[mid]))high=mid;
            else low=mid+1;
        }
        return vi(&arr[low],&arr[low]+k);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,2,3,4,5};
    int k=4;
    int x=-1;
    auto ans=sol.findClosestElements(arr,k,x);
    DBGV(ans);

    system("pause");
    return 0;
}
