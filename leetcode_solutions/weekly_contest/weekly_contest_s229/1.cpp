#include "utils.h"

class Solution {
public:
    //简单模拟
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        string ans;
        while(true){
            if(i<word1.size()){
                ans+=word1[i++];
            }
            else{
                ans+=word2.substr(j);
                break;
            }
            if(j<word2.size()){
                ans+=word2[j++];
            }
            else{
                ans+=word1.substr(i);
                break;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string word1="ab";
    string word2="pqrs";
    auto ans=sol.mergeAlternately(word1,word2);
    DBG(ans);

    system("pause");
    return 0;
}
