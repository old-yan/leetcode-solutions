#include "utils.h"

class Solution {
public:
    string removeDuplicates(string S) {
        string ans;
        for(char c:S){
            if(ans.size()&&ans.back()==c)ans.pop_back();
            else ans.pb(c);
        }
        return ans;
    }
};


int main()
{
    cout<<boolalpha;
    Solution sol;

    

    system("pause");
    return 0;
}
