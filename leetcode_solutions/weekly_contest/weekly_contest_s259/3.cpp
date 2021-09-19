#include "utils.h"

//cnt数组统计每个位置的点数
int cnt[1001][1001];
class DetectSquares {
    vector<pair<int,int>>v;
public:
    //本题模拟就可以过
    DetectSquares() {
        memset(cnt,0,sizeof(cnt));
    }
    void add(const vector<int>&point) {
        int x=point[0],y=point[1];
        if(cnt[x][y]==0)v.emplace_back(x,y);
        cnt[x][y]++;
    }
    int count(const vector<int>&point) {
        int x=point[0],y=point[1];
        long long ans=0;
        //遍历每个位置，尝试将其作为对角
        for(auto [i,j]:v){
            //长宽相等
            if(abs(i-x)!=abs(j-y))continue;
            //边长非零
            if(i==x)continue;
            //将三个点的数量乘起来，就是答案数
            long long num=1ll*cnt[i][j]*cnt[x][j]*cnt[i][y];
            ans+=num;
        }
        return ans;
    }
};
int main()
{
    cout<<boolalpha;

	DetectSquares*obj=new DetectSquares();
	obj->add({3,10});
	obj->add({11,2});
	obj->add({3,2});
	obj->count({11,10});
	obj->count({14,8});
	obj->add({11,2});
	obj->count({11,10});

    system("pause");
    return 0;
}
/*
使用如下正则替换将leetcode测试用例转换为代码
首先将leetcode测试样例复制到代码正文中，把换行符删除，两行合并为一行;
将如下替换使用一次(也可以自己手打)：

\["(.+?)"(.*?)\]\[\[(.*?)\](.*)\]
\t$1*obj=new $1($3);\n[$2][$4]

将如下替换连续使用：

\[,"(.+?)"(.*?)\]\[,\[(.*?)\](.*)\]
\tobj->$1($3);\n[$2][$4]

*/