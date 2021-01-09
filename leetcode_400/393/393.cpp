#include "utils.h"

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        for(int i=0;i<data.size();i++){
            int ones=0;
            REPR(j,7){
                if(!(data[i]&(1<<j)))break;
                ones++;
            }
            if(ones==1||ones>4)return false;
            else if(ones){
                while(--ones){
                    if(++i==data.size())return false;
                    if(data[i]&(1<<6))return false;
                    if(!(data[i]&(1<<7)))return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi data{197, 130, 1};
    auto ans=sol.validUtf8(data);
    DBG(ans);

    system("pause");
    return 0;
}
