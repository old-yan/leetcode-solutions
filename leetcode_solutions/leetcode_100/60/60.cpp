#include "utils.h"

class Solution {
public:
    string getPermutation(int n, int k) {
        set<int>S;
        REP(i,n)S.insert(i+1);
        string ans;
        while(S.size()){
            int j=factorial(S.size()-1);
            int pass=(k-1)/j;
            k=(k-1)%j+1;
            auto it=S.begin();
            advance(it,pass);
            ans+='0'+*it;
            S.erase(it);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    auto ans=sol.getPermutation(4,9);
    DBG(ans);

    system("pause");
    return 0;
}
