#include "utils.h"

class Solution {
    int n;
    vector<int>sons[100000];
public:
    //本题有多种做法，最简单的一种是：
    //  假定树中没有数字1，那么ans全是1
    //  事实是树中可能有1，所以需要把含有数字1的各级祖先都修改一下答案
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        n=parents.size();
        for(int i=0;i<n;i++){
            if(parents[i]>=0)sons[parents[i]].push_back(i);
        }
        //默认答案全是1
        vector<int>ans(n,1);
        //找到1的位置
        int one_pos=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==1)one_pos=i;
        }
        //如果树中没1，那么答案就是全1
        if(one_pos==-1)return ans;
        //如果树中有1，那么答案并非全1，从数字1的位置，逐步向上修改
        //wait表示等待名单
        bitset<100002>wait;
        //一开始将所有数字全部加入等待名单（0随意）
        wait.set();wait.reset(0);
        //此处add函数，将一颗树里的数字加入集合中，那么这个数字就从等待名单中删掉
        auto add=[&](int a){
            queue<int>Q{{a}};
            while(Q.size()){
                auto p=Q.front();
                Q.pop();
                wait.reset(nums[p]);
                for(int s:sons[p])Q.push(s);
            }
        };
        add(one_pos);
        //cursor表示当前保证集合中包含cursor-1及以下的数字
        int cursor=1;
        int cur=one_pos;
        while(true){
            //从等待名单中找到最小的等待数字
            cursor=wait._Find_next(cursor-1);
            //  另：经过实验，不需要从cursor往后找，从头开始找都能过！bitset永远的神
            //  cursor=wait._Find_first();
            ans[cur]=cursor;
            //直到来到整棵树的根，停止上溯
            if(parents[cur]==-1)break;
            //否则不断上溯，上溯的时候记得把兄弟结点的数字也放进集合里，这样这个集合才能表示当前树的所有数字
            for(int s:sons[parents[cur]])if(s!=cur){
                add(s);
            }
            wait.reset(nums[parents[cur]]);
            cur=parents[cur];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi parents{-1,0,1,0,3,3};
    vi nums{5,4,6,2,1,3};
    auto ans=sol.smallestMissingValueSubtree(parents,nums);
    DBGV(ans);

    system("pause");
    return 0;
}
