#include "utils.h"

class Solution {
public:
    //模拟题
    vector<int> memLeak(int memory1, int memory2) {
        int time=1;
        while(true){
            if(memory1>=memory2){
                if(memory1<time)break;
                memory1-=time;
            }
            else{
                if(memory2<time)break;
                memory2-=time;
            }
        }
        return {time,memory1,memory2};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int memory1=8;
    int memory2=11;
    auto ans=sol.memLeak(memory1,memory2);
    DBGV(ans);

    system("pause");
    return 0;
}
