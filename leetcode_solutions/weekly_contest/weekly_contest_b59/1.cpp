#include "utils.h"

class Solution {
public:
    //每次遇到新字母的时候，两种选择：一种向左转一种向右转，取最短路就行
    int minTimeToType(string word) {
        int cur=0;
        int ans=0;
        for(char c:word){
            int d=c-'a';
            ans+=min((d+26-cur)%26,(cur+26-d)%26);
            cur=d;
        }
        return ans+word.size();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string word="zjpc";
    auto ans=sol.minTimeToType(word);
    DBG(ans);

    system("pause");
    return 0;
}
