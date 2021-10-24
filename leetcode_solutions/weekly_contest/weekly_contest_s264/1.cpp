#include "utils.h"
#include <sstream>

class Solution {
    int ans=0;
    //按照题意模拟，只有通过所有的检查才可以ans++
    void solve(string&t){
        for(char c:t)if(isdigit(c))return;
        if(count(t.begin(),t.end(),'-')>1)return;
        if(count(t.begin(),t.end(),'-')==1){
            int index=t.find('-');
            bool left=false,right=false;
            for(int i=0;i<index;i++){
                if(islower(t[i]))left=true;
            }
            if(!left)return;
            for(int i=index+1;i<t.size();i++){
                if(islower(t[i]))right=true;
            }
            if(!right)return;
        }
        for(int i=0;i+1<t.size();i++){
            if(t[i]=='!' or t[i]==',' or t[i]=='.')return;
        }
        ans++;
    }
public:
    //使用字符串流，将 s 变成类似 cin 的东西，然后读取字符串，这样就可以方便地去掉空格
    int countValidWords(string s) {
        stringstream ss(s);
        string t;
        while(ss>>t){
            solve(t);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="he bought 2 pencils, 3 erasers, and 1  pencil-sharpener.";
    auto ans=sol.countValidWords(s);
    DBG(ans);

    system("pause");
    return 0;
}