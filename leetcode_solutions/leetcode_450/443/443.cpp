#include "utils.h"

class Solution {
public:
    int compress(vector<char>& chars) {
        vi next=next_different(chars);
        int ans;
        for(int i=0,j=0;i<next.size();i=next[i]){
            chars[j++]=chars[i];
            string count=i2s(next[i]-i);
            if(count!="1"){
                for(char c:count){
                    chars[j++]=c;
                }
            }
            ans=j;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<char>chars{'a','a','b','b','c','c','c'};
    auto ans=sol.compress(chars);
    DBG(ans);

    system("pause");
    return 0;
}
