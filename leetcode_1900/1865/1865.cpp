#include "utils.h"

class FindSumPairs {
    vi&v1,&v2;
    unordered_map<int,int>M;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2):v1(nums1),v2(nums2) {
        for(int a:v2)M[a]++;
    }
    void add(int index, int val) {
        if(!--M[v2[index]]){
            M.erase(v2[index]);
        }
        v2[index]+=val;
        M[v2[index]]++;
    }
    int count(int tot) {
        int ans=0;
        for(int a:v1){
            if(M.count(tot-a)){
                ans+=M[tot-a];
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;

    vi nums1{1,1,2,2,2,3};
    vi nums2{1,4,5,2,5,4};
	FindSumPairs*obj=new FindSumPairs(nums1,nums2);
	obj->count(7);
	obj->add(3,2);
	obj->count(8);
	obj->count(4);
	obj->add(0,1);
	obj->add(1,1);
	obj->count(7);

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