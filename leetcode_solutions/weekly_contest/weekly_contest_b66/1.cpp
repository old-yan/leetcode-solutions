#include "utils.h"

class Solution {
public:
    //简单枚举某一个数组即可，可以使用count函数
    int countWords(vector<string>& words1, vector<string>& words2) {
        int ans=0;
        for(auto&word:words1){
            if(count(words1.begin(),words1.end(),word)!=1)continue;
            if(count(words2.begin(),words2.end(),word)!=1)continue;
            ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words1{"leetcode","is","amazing","as","is"};
    vector<string>words2{"amazing","leetcode","is"};
    auto ans=sol.countWords(words1,words2);
    DBG(ans);

    system("pause");
    return 0;
}