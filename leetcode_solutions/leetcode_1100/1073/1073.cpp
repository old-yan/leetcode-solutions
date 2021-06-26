#include "utils.h"

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        reverse(ALL(arr1));
        reverse(ALL(arr2));
        arr1.resize(max(arr1.size(),arr2.size()));
        REP(i,arr1.size()){
            if(i<arr2.size())arr1[i]+=arr2[i];
        }
        for(int i=0;i<arr1.size();i++){
            if(i+1<arr1.size()&&arr1[i+1]>=1&&arr1[i]>=2){
                arr1[i]-=2;
                arr1[i+1]--;
            }
            if(arr1[i]<2)continue;
            if(i+1>=arr1.size())arr1.pb(0);
            arr1[i+1]++;
            if(i+2>=arr1.size())arr1.pb(0);
            arr1[i+2]++;
            arr1[i]%=2;
        }
        while(arr1.size()>1&&arr1.back()==0)arr1.pop_back();
        reverse(ALL(arr1));
        return arr1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr1{1,1,1,1,1};
    vi arr2{1,0,1};
    auto ans=sol.addNegabinary(arr1,arr2);
    DBGV(ans);

    system("pause");
    return 0;
}
