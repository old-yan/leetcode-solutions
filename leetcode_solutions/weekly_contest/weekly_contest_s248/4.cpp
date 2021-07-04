#include "SuffixArray.h"
#include "utils.h"

class Solution {
    //counter用来计数，看覆盖的路径有没有m条
    //之所以不用bool数组是因为初始化太费时间，所以用更新时间戳的方法来做标记
    struct{
        int mark[100000]={0},num=0;
        int timestamp=0;
        void reset(){
            timestamp++;
            num=0;
        }
        void add(int i){
            if(mark[i]!=timestamp){
                mark[i]=timestamp;
                num++;
            }
        }
    }counter;
public:
    //这道题难度非常大，需要事先了解 【后缀数组】 这一数据结构
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int m=paths.size();
        //首先将所有的path都放到一个 vector 里面，同时记录每个元素作为开头的的最长字串长度、每个元素所属的path
        vector<int>all,maxlen,belong;
        for(int i=0;i<m;i++){
            for(int j=0;j<paths[i].size();j++){
                all.push_back(paths[i][j]);
                maxlen.push_back(paths[i].size()-j);
                belong.push_back(i);
            }
        }
        //用后缀数组对数组 all 进行处理，生成 sa,rk,height 数组
        SuffixArray<vector<int>,100000>SA(all);
        SA.getHeight();
        auto sa=SA.sa,h=SA.height;
        //二分找出最小的高度，使得 height 数组上比这个高度高的区间可以覆盖 [0~m-1] 原路径
        int low=0,high=all.size();
        while(low<high){
            int mid=(low+high+1)/2;
            bool flag=false;
            for(int i=0,j;i<all.size();i=j){
                counter.reset();
                for(j=i;j<all.size()&&(j==i||h[j]>=mid);j++){
                    if(maxlen[sa[j]]>=mid)counter.add(belong[sa[j]]);
                }
                if(counter.num==m){
                    flag=true;
                    break;
                }
            }
            if(flag)low=mid;
            else high=mid-1;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=5;
    vvi paths=makevvi("[[0,1],[1,0]]");
    auto ans=sol.longestCommonSubpath(n,paths);
    DBG(ans);

    system("pause");
    return 0;
}
