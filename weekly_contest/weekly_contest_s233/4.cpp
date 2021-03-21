#include "utils.h"

//二叉字典树按照每个数字二进制从高位到低位，对该数字进行保存，本题的树高度设为15就够用（1<<15==32768)
struct BiTrie {
    #define TRIEN 3
    int data[50000][TRIEN]={0},used,low,high,a,res;
    BiTrie(int _low,int _high):used(1),low(_low),high(_high){}
    void insert(int num){
        int cur=0;
        //从高位到低位，按照是0还是1往下分叉保存
        //每个结点，下标0、1保存子结点位置，下标2对本子树的数字数量进行累加
        //所以插入一个数时，路径上的所有结点的下标2都要++
        for(int i=15;i>=0;i--){
            data[cur][2]++;
            int&next=data[cur][num>>i&1];
            if(!next)next=used++;
            cur=next;
        }
        data[cur][2]++;
    }
    //cur表示当前结点位置，i表示当前要检查的二进制位，sum表示i位之前的异或结果
    void dfs(int cur,int i,int sum){
        //到达叶结点
        if(i<0){
            res+=data[cur][2];
        }
        else{
            //没到叶结点，就往下走，两条路分别判断
            for(int j:{0,1}){
                int&child=data[cur][j];
                if(!child)continue;
                int ssum=sum+(a>>i&1^j?1<<i:0);
                //如果异或和的前i位的已经被low和high的前i位包夹，那么这个子树里的数统统满足要求
                if(ssum>>i>low>>i&&ssum>>i<high>>i){
                    res+=data[child][2];
                }
                //如果异或和的前i位和low和high的前i位只是相同，那么这个子树里的数并不全满足要求，需要往下走着瞧
                else if(ssum>>i==low>>i||ssum>>i==high>>i)dfs(child,i-1,ssum);
            }
        }
    }
    //find函数寻找与a异或的结果落在[low,high]区间的数量
    int find(int _a){
        res=0;
        a=_a;
        dfs(0,15,0);
        return res;
    }
};

class Solution {
public:
    //本题需要使用二叉字典树，先把所有数插到树里，再对每个数字判断树中和自己进行异或可以落在[low,high]区间内的数字数量
    int countPairs(vector<int>& nums, int low, int high) {
        int n=nums.size();
        int ans=0;
        BiTrie T(low,high);
        for(int a:nums){
            T.insert(a);
            ans+=T.find(a);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi v{1,4,2,7};
    auto ans=sol.countPairs(v,2,6);
    DBG(ans);

    system("pause");
    return 0;
}
