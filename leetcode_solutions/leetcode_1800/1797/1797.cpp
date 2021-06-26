#include "utils.h"

class AuthenticationManager {
    int timeToLive,cnt;
    unordered_map<string,int>dieTime;
    queue<pair<string,int>>todie;
public:
    AuthenticationManager(int _timeToLive):timeToLive(_timeToLive),cnt(0){}
    void generate(string tokenId, int currentTime) {
        dieTime[tokenId]=currentTime+timeToLive;
        todie.emplace(tokenId,dieTime[tokenId]);
        cnt++;
    }
    void renew(string tokenId, int currentTime) {
        if(!dieTime.count(tokenId))return;
        if(dieTime[tokenId]<=currentTime)return;
        dieTime[tokenId]=currentTime+timeToLive;
        todie.emplace(tokenId,dieTime[tokenId]);
    }
    int countUnexpiredTokens(int currentTime) {
        while(todie.size()&&todie.front().second<=currentTime){
            if(todie.front().second==dieTime[todie.front().first]){
                cnt--;
            }
            todie.pop();
        }
        return cnt;
    }
};

int main()
{
    cout<<boolalpha;

	AuthenticationManager*obj=new AuthenticationManager(5);
	obj->renew("aaa",1);
	obj->generate("aaa",2);
	obj->countUnexpiredTokens(6);
	obj->generate("bbb",7);
	obj->renew("aaa",8);
	obj->renew("bbb",10);
	obj->countUnexpiredTokens(15);

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