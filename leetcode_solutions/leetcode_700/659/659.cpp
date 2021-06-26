#include "utils.h"

class Solution {
    map<int,int>M;
public:
    bool isPossible(vector<int>& nums) {
        auto use=[&](int val){
            auto find=M.find(val);
            if(!--find->second)M.erase(find);
        };
        for(int a:nums)M[a]++;
        while(M.size()){
            int a=M.begin()->first;
            use(a);
            if(!M.count(a+1))return false;
            use(a+1);
            if(!M.count(a+2))return false;
            use(a+2);
            for(int val=a+3;;val++){
                if(!M.count(val)||(M.count(val-1)&&M[val]<=M[val-1]))break;
                else use(val);
            }
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,3,4,5};
    auto ans=sol.isPossible(nums);
    DBG(ans);

    system("pause");
    return 0;
}
