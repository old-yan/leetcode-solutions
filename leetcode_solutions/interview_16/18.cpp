#include "utils.h"

class Solution {
public:
    bool patternMatching(string pattern, string value) {
        int a=count(ALL(pattern),'a'),b=pattern.size()-a;
        if(!a||!b){
            if(value.size()%pattern.size())return false;
            int each=value.size()/pattern.size();
            for(int i=each;i<value.size();i+=each){
                if(value.substr(i,each)!=value.substr(0,each))return false;
            }
            return true;
        }
        REP(l,value.size()+1){
            if(int(value.size())-a*l<0)break;
            if((int(value.size())-a*l)%b)continue;
            int r=(int(value.size())-a*l)/b;
            string sa,sb;
            int cursor=0;
            bool dif=false;
            for(char c:pattern){
                if(c=='a'){
                    if(sa.empty())
                        sa=value.substr(cursor,l);
                    else if(sa!=value.substr(cursor,l)){
                        dif=true;
                        break;
                    }
                    cursor+=l;
                }
                else{
                    if(sb.empty())
                        sb=value.substr(cursor,r);
                    else if(sb!=value.substr(cursor,r)){
                        dif=true;
                        break;
                    }
                    cursor+=r;
                }
            }
            if(!dif&&sa!=sb)return true;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string pattern="abba";
    string value="dogcatcatdog";
    auto ans=sol.patternMatching(pattern,value);
    DBG(ans);

    system("pause");
    return 0;
}
