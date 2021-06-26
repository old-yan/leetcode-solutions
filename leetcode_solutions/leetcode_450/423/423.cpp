#include "utils.h"

class Solution {
public:
    string originalDigits(string s) {
        int num[26]={0};
        int count[10]={0};
        bool visited[10]={0};
        int unvisited=10;
        vector<string>number{"zero","one","two","three","four","five","six","seven","eight","nine","ten"};
        for(char c:s)num[c-'a']++;
        while(unvisited){
            for(char c='a';c<='z';c++){
                int appeared=0;
                int last=-1
                REP(i,10){
                    if(!visited[i]){
                        for(char d:number[i]){
                            if(c==d){
                                appeared++;
                                last=i;
                                break;
                            }
                        }
                    }
                }
                if(appeared==1){
                    int n=0;
                    for(char d:number[last])if(c==d)n++;
                    count[last]=num[c-'a']/n;
                    visited[last]=true;
                    unvisited--;
                    for(char d:number[last])num[d-'a']-=count[last];
                    break;
                }
            }
        }
        string ans;
        REP(i,10){
            REP(j,count[i])ans+='0'+i;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="owoztneoer";
    auto ans=sol.originalDigits(s);
    DBG(ans);

    system("pause");
    return 0;
}
