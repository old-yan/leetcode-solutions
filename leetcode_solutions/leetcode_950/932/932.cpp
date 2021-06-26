#include "utils.h"

class Solution {
    int data[1000];
    void fun(int begin[],int end[],int start_val,int inc){
        if(end-begin>1){
            auto mid=begin+(end-begin)/2;
            fun(begin,mid,start_val+inc,inc<<1);
            fun(mid,end,start_val,inc<<1);
        }
        else *begin=start_val;
    }
public:
    vector<int> beautifulArray(int N) {
        fun(data,data+N,1,1);
        return vi(data,data+N);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=5;
    auto ans=sol.beautifulArray(N);
    DBGV(ans);

    system("pause");
    return 0;
}
