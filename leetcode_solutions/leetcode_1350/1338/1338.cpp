#include "utils.h"

class Solution {
    int appear[100001]={0};
public:
    int minSetSize(vector<int>& arr) {
        for(int a:arr)appear[a]++;
        sort(ALL(arr),[&](int x,int y){
            if(appear[x]!=appear[y])return appear[x]>appear[y];
            else return x>y;
        });
        for(int i=0,j=0,k=0;i<arr.size();i=j,k++){
            while(j<arr.size()&&arr[j]==arr[i])j++;
            if(j>=arr.size()/2)return k+1;
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{3,3,3,3,5,5,5,2,2,7};
    auto ans=sol.minSetSize(arr);
    DBG(ans);

    system("pause");
    return 0;
}
