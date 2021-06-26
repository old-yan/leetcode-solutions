#include "utils.h"

class Solution {
public:
    //按题意模拟
    string evaluate(string s, vector<vector<string>>& knowledge) {
        //哈希表存储字符串映射
        unordered_map<string,string>M;
        for(auto&a:knowledge){
            M[a[0]]=a[1];
        }
        string ans;
        for(int i=0;i<s.size();i++){
            //如果当前字符为左括号，就把括号里的内容提取出来
            if(s[i]=='('){
                string ss;
                while(s[++i]!=')')ss+=s[i];
                if(M.count(ss))ans+=M[ss];
                else ans+='?';
            }
            else ans+=s[i];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="(name)is(age)yearsold";
    vector<vector<string>>knowledge{
        {"name","bob"},{"age","two"}
    };
    auto ans=sol.evaluate(s,knowledge);
    DBG(ans);

    system("pause");
    return 0;
}
