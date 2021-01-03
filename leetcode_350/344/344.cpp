#include "utils.h"

class Solution {
public:
    void reverseString(vector<char>& s) {
        //reverse(ALL(s));
        REP(i,s.size()/2){
            swap(s[i],s[s.size()-1-i]);
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<char>s{'h','e','l','l','o'};
    sol.reverseString(s);
    DBGV(s);

    system("pause");
    return 0;
}
