#include "utils.h"

class Solution {
public:
    //分情况讨论
    string maxValue(string n, int x) {
        //如果注定是个负数，那就让绝对值越小，最终的值越大
        //那么，插进去的位置必须满足：左边没有比我大的数。（否则我可取而代之）
        //而且，在满足上个条件的情况下，我要尽量靠右边（一旦左移就有变小的风险）
        if(n[0]=='-'){
            int cnt[10]={0};
            for(char c:n)if(isdigit(c))cnt[c-'0']++;
            if(accumulate(cnt+x+1,cnt+10,0)==0)return n+char('0'+x);
            REPR(i,n.size()-1){
                if(isdigit(n[i]))cnt[n[i]-'0']--;
                if(accumulate(cnt+x+1,cnt+10,0)==0)return n.substr(0,i)+char('0'+x)+n.substr(i);
            }
            return "";
        }
        //如果是个正数，绝对值就要尽量大
        //插进去的位置必须满足：左边没有比我小的数。（否则我可取而代之）
        //而且，在满足上个条件的情况下，我要尽量靠左边（一旦右移就有变小的风险）
        else{
            REP(i,n.size()){
                if(x>n[i]-'0'){
                    return n.substr(0,i)+char('0'+x)+n.substr(i);
                }
            }
            return n+char('0'+x);
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string n="-13";
    int x=2;
    auto ans=sol.maxValue(n,x);
    DBG(ans);

    system("pause");
    return 0;
}
