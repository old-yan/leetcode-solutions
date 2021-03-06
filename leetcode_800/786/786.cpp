#include "utils.h"

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double low=0,high=1;
        int n=arr.size();
        int smaller;
        pair<int,int>closest;
        while(low<high){
            double mid=(low+high)/2;
            smaller=0;
            closest={0,1};
            for(int i=0,j=1;i<n;i++){
                while(j<n&&double(arr[i])/arr[j]>=mid)j++;
                smaller+=n-j;
                if(j<n&&double(arr[i])/arr[j]>double(closest.first)/closest.second){
                    closest={arr[i],arr[j]};
                }
            }
            if(smaller>k)high=mid;
            else if(smaller<k)low=mid;
            else break;
        }
        return {closest.first,closest.second};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,2,3,5};
    int k=3;
    auto ans=sol.kthSmallestPrimeFraction(arr,k);
    DBGV(ans);

    system("pause");
    return 0;
}
