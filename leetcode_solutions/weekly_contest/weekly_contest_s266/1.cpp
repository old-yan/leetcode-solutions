#include "utils.h"

class Solution {
    bool check(string&s){
        int cnt[128]={0};
        for(char c:s)cnt[c]++;
        //检查是否缺少某种元音字符
        if(!cnt['a'])return false;
        if(!cnt['e'])return false;
        if(!cnt['i'])return false;
        if(!cnt['o'])return false;
        if(!cnt['u'])return false;
        //检查是否有多余的非元音字符
        if(cnt['a']+cnt['e']+cnt['i']+cnt['o']+cnt['u']!=s.size())return false;
        return true;
    }
public:
    //一看数据范围，就可以两重 for 循环通过
    int countVowelSubstrings(string word) {
        int ans=0;
        for(int i=0;i<word.size();i++){
            for(int j=1;i+j<=word.size();j++){
                string sub=word.substr(i,j);
                if(check(sub)){
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string word="cuaieuouac";
    auto ans=sol.countVowelSubstrings(word);
    DBG(ans);

    system("pause");
    return 0;
}