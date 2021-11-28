#include "utils.h"

class Solution {
public:
    //检查是否能够收集所有房屋的雨水，如果能，那么贪心放置水盆
    int minimumBuckets(string s) {
        int n=s.size();
        int ans=0;
        //检查是否有房屋不能被收集
        for(int i=0;i<n;i++){
            if(s[i]=='H' and (i-1<0 or s[i-1]!='.') and (s[i+1]!='.'))return -1;
        }
        //如果能收集，那么从前往后收集房屋
        for(int i=0;i<n;){
            if(s[i]=='H'){
                //如果当前为房屋，且下下个位置为房屋，那么一定是选取右边的水盆最好，然后跳到 3 个位置之后
                if(i+2<n and s[i+2]=='H')ans++,i+=3;
                //如果当前为房屋，且下下个位置不为房屋，那么这个房屋被左边或者右边收集都无所谓。跳到一个位置之后
                else ans++,i++;
            }
            //如果当前为水盆，跳过
            else i++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string street=".HHH.";
    auto ans=sol.minimumBuckets(street);
    DBG(ans);

    system("pause");
    return 0;
}