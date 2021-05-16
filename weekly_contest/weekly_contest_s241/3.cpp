#include "utils.h"

class FindSumPairs {
    vi&nums1;
    vi&nums2;
    unordered_map<int,int>M;
public:
    //将nums2数字的分布，放到哈希表里
    FindSumPairs(vector<int>& _nums1, vector<int>& _nums2):nums1(_nums1),nums2(_nums2) {
        for(int a:nums2)M[a]++;
    }
    //修改nums2时，同步修改哈希表
    void add(int index, int val) {
        if(!--M[nums2[index]]){
            M.erase(nums2[index]);
        }
        nums2[index]+=val;
        M[nums2[index]]++;
    }
    //统计时，针对nums1的每一项，寻找nums2中的补数
    //因为有哈希表，所以寻找步数很方便
    int count(int tot) {
        int res=0;
        for(int a:nums1){
            if(M.count(tot-a)){
                res+=M[tot-a];
            }
        }
        return res;
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