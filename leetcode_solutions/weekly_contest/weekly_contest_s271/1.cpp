#include "utils.h"

class Solution {
public:
    //简单模拟即可
    int countPoints(string rings) {
        unordered_set<char>S[10];
        for(int i=0;i<rings.size();i+=2){
            char c=rings[i];
            int j=rings[i+1]-'0';
            S[j].insert(c);
        }
        return count_if(S,S+10,[](auto&x){return x.size()==3;});
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string rings="B0R0G0R9R0B0G0";
    auto ans=sol.countPoints(rings);
    DBG(ans);

    system("pause");
    return 0;
}