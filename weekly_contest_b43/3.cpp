#include "utils.h"

class Solution {
    int n;
    //数组a用来记录序列的具体样貌
    int a[50];
    //used用来在回溯过程中提示目前用过的数和没用到的数
    bool used[21]={0};
    bool dfs(int idx){
        if(idx==n*2-1){
            //回溯到最终位置时，说明回溯成功
            return true;
        }
        else{
            //如果当前下标被占用就往下个下标赶去
            if(a[idx]>=0){
                return dfs(idx+1);
            }
            else{
                //从n到2进行试探，试探失败后记得复原
                for(int j=n;j>1;j--){
                    if(!used[j]&&a[idx+j]<0){
                        used[j]=1;
                        a[idx]=a[idx+j]=j;
                        //当回溯成功时，不进行多余操作，直接return
                        if(dfs(idx+1))return true;
                        used[j]=0;
                        a[idx]=a[idx+j]=-1;
                    }
                }
                //试探1，试探失败后记得复原
                if(!used[1]){
                    used[1]=1;
                    a[idx]=1;
                    //当回溯成功时，不进行多余操作，直接return
                    if(dfs(idx+1))return true;
                    used[1]=0;
                    a[idx]=-1;
                }
                return false;
            }
        }
    }
public:
    vector<int> constructDistancedSequence(int _n) {
        n=_n;
        //将数组a初始化为全为-1
        memset(a,0xff,sizeof(a));
        dfs(0);
        return vector<int>(a,a+n*2-1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=20;
    auto ans=sol.constructDistancedSequence(n);
    DBGV(ans);

    system("pause");
    return 0;
}
