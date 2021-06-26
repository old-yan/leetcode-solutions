#include "utils.h"

class Solution {
    vi fun(vi&A,int h,int t){
        vi v(1<<(t-h),0);
        REP(i,1<<(t-h)){
            REP(j,t-h){
                if(i&(1<<j)){
                    v[i]+=A[h+j];
                }
            }
        }
        return v;
    }
public:
    bool splitArraySameAverage(vector<int>&A) {
        int n=A.size(),half=n/2;
        if(n==1)return false;
        int ave=accumulate(ALL(A),0);
        for(int&a:A)a=a*n-ave;
        auto v1=fun(A,0,half);
        auto v2=fun(A,half,n);
        unordered_map<int,int>M;
        FOR(i,1,v1.size()-1)M[v1[i]]++;
        if(M.count(0))return true;
        bool first_zero=true;
        for(int a:v2){
            if(!a){
                if(first_zero)first_zero=false;
                else return true;
            }
            else if(M.count(-a))return true;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{18,0,16,2};
    auto ans=sol.splitArraySameAverage(A);
    DBG(ans);

    system("pause");
    return 0;
}
