#include "utils.h"

class Solution {
    int bigger(int num){
        int a[32],b=0;
        for(int i=31;i>=0;i--)a[i]=num>>(31-i)&1;
        if(!next_permutation(a,a+32))return -1;
        for(int i=0;i<32;i++)b+=(1<<(31-i))*a[i];
        return b>num?b:-1;
    }
    int smaller(int num){
        int a[32],b=0;
        for(int i=31;i>=0;i--)a[i]=num>>(31-i)&1;
        if(!prev_permutation(a,a+32))return -1;
        for(int i=0;i<32;i++)b+=(1<<(31-i))*a[i];
        return b<num?b:-1;
    }
public:
    vector<int> findClosedNumbers(int num) {
        int big=bigger(num),small=smaller(num);
        return {big,small};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=2;
    auto ans=sol.findClosedNumbers(num);
    DBGV(ans);

    system("pause");
    return 0;
}
