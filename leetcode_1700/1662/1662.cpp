#include "utils.h"

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i1=0,i2=0,j1=0,j2=0;
        while(i1<word1.size()&&i2<word2.size()){
            if(word1[i1][j1]!=word2[i2][j2])return false;
            if(!word1[i1][++j1]){
                ++i1;
                j1=0;
            }
            if(!word2[i2][++j2]){
                ++i2;
                j2=0;
            }
        }
        return i1==word1.size()&&i2==word2.size();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>word1{"ab","c"};
    vector<string>word2{"a","bc"};
    auto ans=sol.arrayStringsAreEqual(word1,word2);
    DBG(ans);

    system("pause");
    return 0;
}
