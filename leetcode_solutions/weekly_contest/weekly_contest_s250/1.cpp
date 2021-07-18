#include "utils.h"

class Solution {
public:
    //简单模拟，对每个单词进行检查
    int canBeTypedWords(string text, string brokenLetters) {
        set<char>broken(ALL(brokenLetters));
        auto list=split(text);
        int ans=0;
        for(string&s:list){
            //设置一个flag，表示是否可以打出完整单词
            bool flag=true;
            for(char c:s)
                if(broken.count(c))flag=false;
            if(flag)ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string text="hello world";
    string brokenLetters="ad";
    auto ans=sol.canBeTypedWords(text,brokenLetters);
    DBG(ans);

    system("pause");
    return 0;
}
