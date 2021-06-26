#include "utils.h"

class Solution {
    vvi zero_one;
    vi next;
    int ans=0;
    void dfs(int cur,int curnum,int m,int n){
        if(cur==zero_one.size()){
            chmax(ans,curnum);
        }
        else{
            curnum++;
            m-=zero_one[cur][0];
            if(m<0)return;
            n-=zero_one[cur][1];
            if(n<0)return;
            for(int i=cur+1;;){
                dfs(i,curnum,m,n);
                if(i<zero_one.size())i=next[i];
                else break;
            }
        }
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        zero_one.resize(strs.size(),vi(2,0));
        REP(i,strs.size()){
            for(char c:strs[i]){
                if(c=='0')zero_one[i][0]++;
                else zero_one[i][1]++;
            }
        }
        sort(ALL(zero_one));
        next.resize(zero_one.size());
        for(int i=0,j;i<zero_one.size();){
            for(j=i+1;j<zero_one.size()&&zero_one[j][0]==zero_one[i][0];j++);
            while(i<j)next[i++]=j;
        }
        for(int i=0;i<zero_one.size();i=next[i])dfs(i,0,m,n);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>strs{
        "10", "0001", "111001", "1", "0"
    };
    int m=5;
    int n=3;
    auto ans=sol.findMaxForm(strs,m,n);
    DBG(ans);

    system("pause");
    return 0;
}
