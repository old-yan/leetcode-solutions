#include "utils.h"

class Solution {
    vi*pointer;
    vi idx;
public:
    Solution(vector<int>& nums) {
        idx.resize(nums.size());
        iota(ALL(idx),0);
        sort(ALL(idx),[&](int x,int y)->bool{return nums[x]<nums[y];});
        pointer=&nums;
    }
    int pick(int target) {
        int lb,rb;
        {
            int low=0,high=idx.size();
            while(low<high){
                int mid=(low+high)/2;
                if((*pointer)[idx[mid]]>=target)high=mid;
                else low=mid+1;
            }
            lb=low;
        }
        {
            int low=0,high=idx.size();
            while(low<high){
                int mid=(low+high)/2;
                if((*pointer)[idx[mid]]>target)high=mid;
                else low=mid+1;
            }
            rb=low;
        }
        return idx[rand()%(rb-lb)+lb];
    }
};

int main()
{
    cout<<boolalpha;

    vi nums{1,2,3,3,3};
	Solution*obj=new Solution(nums);
	obj->pick(3);

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