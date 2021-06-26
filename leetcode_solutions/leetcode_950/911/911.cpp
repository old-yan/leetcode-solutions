#include "utils.h"

class TopVotedCandidate {
    vi*tm;
    vi choice;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        tm=&times;
        int len[persons.size()],cur=0;
        memset(len,0,sizeof(len));
        REP(i,times.size()){
            if(++len[persons[i]]>=len[cur]){
                cur=persons[i];
            }
            choice.pb(cur);
        }
    }
    int q(int t) {
        int low=0,high=tm->size()-1;
        while(low<high){
            int mid=(low+high+1)/2;
            if((*tm)[mid]<=t)low=mid;
            else high=mid-1;
        }
        return choice[low];
    }
};

int main()
{
    cout<<boolalpha;

    vi persons{0,1,1,0,0,1,0};
    vi times{0,5,10,15,20,25,30};
	TopVotedCandidate*obj=new TopVotedCandidate(persons,times);
	obj->q(3);
	obj->q(12);
	obj->q(25);
	obj->q(15);
	obj->q(24);
    obj->q(8);

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