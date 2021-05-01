#include "utils.h"

class Solution {
    int cnt[10]={0},cnt2[3]={0},sum;
    int getDrop(){
        if(sum%3==0)return 0;
        else if(sum%3==1)return cnt2[1]?1:(cnt2[2]>=2?2:10000000);
        else return cnt2[2]?1:(cnt2[1]>=2?2:10000000);
    }
public:
    string largestMultipleOfThree(vector<int>& digits) {
        for(int a:digits){
            cnt[a]++;
            cnt2[a%3]++;
            sum+=a;
        }
        string ans;
        REPR(i,9){
            while(cnt[i]){
                cnt[i]--;
                cnt2[i%3]--;
                int drop1=getDrop();
                sum-=i;
                int drop2=getDrop()+1;
                if(drop1<=drop2){
                    ans+=char('0'+i);
                    sum+=i;
                }
            }
        }
        if(ans[0]=='0')return "0";
        else return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi digits{9,8,8,6};
    auto ans=sol.largestMultipleOfThree(digits);
    DBG(ans);

    system("pause");
    return 0;
}
