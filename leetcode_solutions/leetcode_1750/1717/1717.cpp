#include "utils.h"

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char a,b;
        int ans=0,profit;
        if(x>y){
            a='a',b='b',profit=x;
        }
        else{
            a='b',b='a',profit=y;
        }
        string ss;
        for(char c:s){
            if(c==a)ss+=c;
            else{
                if(c==b&&ss.size()&&ss.back()==a){
                    ss.pop_back();
                    ans+=profit;
                }
                else ss+=c;
            }
        }
        swap(a,b);
        profit=x+y-profit;
        string sss;
        for(char c:ss){
            if(c==a)sss+=c;
            else{
                if(c==b&&sss.size()&&sss.back()==a){
                    sss.pop_back();
                    ans+=profit;
                }
                else sss+=c;
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
    int x=4;
    int y=5;
    auto ans=sol.maximumGain(s,x,y);
    DBG(ans);

    system("pause");
    return 0;
}
