#include "utils.h"

class Solution {
    string ans;
    //双指针方法进行判断 t 是否在 s 中，注意要判断 k 轮
    bool check(string t,string&s,int k){
        int cursor=0;
        for(int i=0;i<k;i++){
            for(char c:t){
                int idx=s.find(c,cursor);
                if(idx<0)return false;
                cursor=idx+1;
            }
        }
        return true;
    }
    void dfs(string t,string&s,int k){
        for(char c='z';c>='a';c--){
            if(check(t+c,s,k)){
                if((t+c).size()>ans.size())ans=t+c;
                dfs(t+c,s,k);
            }
        }
    }
public:
    //注意到 n<k*8 说明答案字符串长度最多为 7
    //可以尝试暴搜
    string longestSubsequenceRepeatedK(string s, int k) {
        dfs("",s,k);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="letsleetcode";
    int k=2;
    auto ans=sol.longestSubsequenceRepeatedK(s,k);
    DBG(ans);

    system("pause");
    return 0;
}