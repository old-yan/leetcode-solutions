#include "utils.h"

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        //如果x>y就第一轮优先取"ab",第二轮取"ba"
        //反之就先取"ba",再取"ab"
        char a=x>y?'a':'b';
        char b=x>y?'b':'a';
        if(x<=y)swap(x,y);
        bool visited[s.size()];
        memset(visited,0,sizeof(visited));
        int ans=0;
        {   //第一轮需要栈来记录匹配的下标，记录visited
            stack<int>S;
            REP(i,s.size()){
                //遇到非a非b字符，相当于隔离符，清空栈
                if(s[i]!=a&&s[i]!=b){
                    while(S.size())S.pop();
                }
                else if(s[i]==a)S.push(i);
                else if(s[i]==b){
                    if(S.size()){
                        visited[S.top()]=true;
                        visited[i]=true;
                        S.pop();
                        ans+=x;
                    }
                }
            }
        }
        {   //第二轮不需要维护visited数组了，反正没有第三轮
            //所以不需要具体的栈，只需要记录栈长来判断有没有存货
            int stacklen=0;
            REP(i,s.size()){
                //遇到非a非b字符，相当于隔离符，清空栈
                if(s[i]!=a&&s[i]!=b)stacklen=0;
                //第一轮消掉的字符pass掉
                if(visited[i])continue;
                if(s[i]==b)stacklen++;
                else if(s[i]==a){
                    if(stacklen){
                        stacklen--;
                        ans+=y;
                    }
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

    string s="cdbcbbaaabab";
    int x=4,y=5;
    auto ans=sol.maximumGain(s,x,y);
    DBG(ans);

    system("pause");
    return 0;
}
