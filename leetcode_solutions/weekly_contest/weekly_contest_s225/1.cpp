#include "utils.h"

class Solution {
public:
    string maximumTime(string time) {
        //本题千万不能从问号出发去做替换，而要从替换后的数字返回去找问号
        string ans;
        //从大到小试探小时
        for(int i=23;i>=0;i--){
            string hour=to_string(i);
            if(hour.size()==1)hour="0"+hour;
            string hour0=time.substr(0,2);
            bool same=true;
            for(int j=0;j<2;j++){
                if(hour0[j]!='?'&&hour[j]!=hour0[j])same=false;
            }
            if(same){
                ans+=hour;
                break;
            }
        }
        ans+=":";
        //从大到小试探分钟
        for(int i=59;i>=0;i--){
            string minute=to_string(i);
            if(minute.size()==1)minute="0"+minute;
            string minute0=time.substr(3,2);
            bool same=true;
            for(int j=0;j<2;j++){
                if(minute0[j]!='?'&&minute[j]!=minute0[j])same=false;
            }
            if(same){
                ans+=minute;
                break;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string time="1?:??";
    auto ans=sol.maximumTime(time);
    DBG(ans);

    system("pause");
    return 0;
}
