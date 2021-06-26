#include "utils.h"

class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size()==1&&target[0]!=1)return false;
        priority_queue<int>Q;
        ll sum=0;
        for(int a:target){
            Q.push(a);
            sum+=a;
        }
        while(true){
            auto p=Q.top();
            Q.pop();
            if(p==1)break;
            ll rest=sum-p;
            if(p<=rest)return false;
            if(rest==1)p=1;
            else{
                p%=rest;
                if(!p)return false;
            }
            sum=rest+p;
            Q.push(p);
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi target{9,3,5};
    auto ans=sol.isPossible(target);
    DBG(ans);

    system("pause");
    return 0;
}
