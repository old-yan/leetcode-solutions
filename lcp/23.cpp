#include "utils.h"

class Solution {
    bool check(int n,int k,vi&target){
        vi v(n);
        iota(ALL(v),1);
        vi res;
        while(res.size()<n){
            vi v2;
            for(int i=1;i<v.size();i+=2)v2.pb(v[i]);
            for(int i=0;i<v.size();i+=2)v2.pb(v[i]);
            if(v2.size()<k)res.insert(res.end(),ALL(v2));
            else{
                REP(i,k)res.pb(v2[i]);
                v=vi(v2.begin()+k,v2.end());
            }
        }
        return res==target;
    }
public:
    bool isMagic(vector<int>& target) {
        int n=target.size();
        vi v;
        REP(i,n/2)v.pb(i*2+2);
        REP(i,(n+1)/2)v.pb(i*2+1);
        int k;
        for(k=0;k<target.size()&&target[k]==v[k];k++);
        return k&&check(target.size(),k,target);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi target{2,4,3,1,5};
    auto ans=sol.isMagic(target);
    DBG(ans);

    system("pause");
    return 0;
}
