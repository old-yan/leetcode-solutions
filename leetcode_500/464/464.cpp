#include "utils.h"

class Solution {
    int maxChoosableInteger;
    bitset<1<<20>visited;
    bitset<1<<20>can;
    bitset<20>material;
    int fun(int target){
        if(visited[material.to_ulong()])return can[material.to_ulong()];
        visited.set(material.to_ulong());
        int i=material._Find_first();
        while(i<maxChoosableInteger){
            int j=i+1;
            if(j>=target){
                can.set(material.to_ulong());
                return true;
            }
            material.reset(i);
            if(!fun(target-j)){
                material.set(i);
                can.set(material.to_ulong());
                return true;
            }
            else material.set(i);
            i=material._Find_next(i);
        }
        return false;
    }
public:
    bool canIWin(int _maxChoosableInteger, int desiredTotal) {
        maxChoosableInteger=_maxChoosableInteger;
        if(maxChoosableInteger*(maxChoosableInteger+1)/2<desiredTotal)return false;
        material.set();
        return fun(desiredTotal);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int maxChoosableInteger=5;
    int desiredTotal=11;
    auto ans=sol.canIWin(maxChoosableInteger,desiredTotal);
    DBG(ans);

    system("pause");
    return 0;
}
