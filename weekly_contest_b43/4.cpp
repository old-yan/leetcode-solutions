#include "utils.h"

//本题思路：
//树中结点有个性质，若祖a，孙b
//则a在pairs中的出现次数一定大于等于b在pairs中的出现次数
//且当等号成立时ab可互换位置
class Solution {
    //邻接矩阵
    bool connected[501][501]={0};
    //邻接表
    vector<int> v[501];
public:
    int checkWays(vector<vector<int>>& pairs) {
        for(auto&A:pairs){
            int i=A[0],j=A[1];
            v[i].push_back(j);
            v[j].push_back(i);
            connected[i][j]=connected[j][i]=true;
        }
        //将出现过的结点送入idx数组
        vector<int> idx;
        for(int i=1;i<=500;i++){
            if(v[i].size()){
                idx.push_back(i);
                connected[i][i]=1;
            }
        }
        //按照出现次数升序排序
        sort(idx.begin(),idx.end(),[&](int x,int y)->bool{return v[x].size()<v[y].size();});
        //equal标志，用来记录是否出现过“出现次数相同”的祖孙结点
        bool equal=false;
        //root_count标志，用来记录没有父结点的结点数
        int root_count=0;
        for(int i=0;i<idx.size();i++){
            int j;
            //用j遍历，找出“出现次数大于等于i的结点，可能就是父结点
            for(j=i+1;j<idx.size()&&!connected[idx[i]][idx[j]];j++);
            //如果有找到，检验是不是父结点：将自己的所有邻居和idx[j]判断邻接关系
            if(j<idx.size()){
                if(v[idx[i]].size()==v[idx[j]].size()){
                    equal=true;
                }
                for(int a:v[idx[i]]){
                    //idx[j]要么和idx[i]同级（也就是可替换），要么比idx[i]高级，总之必须与idx[i]的邻居为邻
                    if(!connected[a][idx[j]])return 0;
                }
            }
            else root_count++;
        }
        if(root_count>1)return 0;
        if(equal)return 2;
        else return 1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi pairs{
        {5,13},{1,10},{11,15},{6,10},{3,13},{13,14},{7,13},{1,6},{11,13},{2,11},{9,11},{1,8},{2,14},{1,11},{6,11},{2,13},{11,12},{2,7},{3,11},{7,14},{7,9},{10,11},{3,14},{10,15},{4,12},{5,7},{5,11},{4,11},{11,14},{6,15},{7,11},{9,13},{3,5},{1,15},{2,5},{3,7},{5,14}
    };
    auto ans=sol.checkWays(pairs);
    DBG(ans);

    system("pause");
    return 0;
}
