#include "utils.h"

class Solution {
public:
    string maximumTime(string time) {
        REPR(hour,23){
            REPR(second,59){
                char c[6];
                sprintf(c,"%02d:%02d",hour,second);
                bool same=true;
                REP(i,5){
                    if(c[i]!=time[i]&&time[i]!='?'){
                        same=false;
                        break;
                    }
                }
                if(same)return c;
            }
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string time="2?:?0";
    auto ans=sol.maximumTime(time);
    DBG(ans);

    system("pause");
    return 0;
}
