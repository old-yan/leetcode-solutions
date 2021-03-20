#include "utils.h"

//哈希表M记录每个string销毁的时间
//队列Q依序存放每个string和销毁的时间
class AuthenticationManager {
    int timeToLive;
    unordered_map<string,int>M;
    queue<pair<string,int>>Q;
public:
    AuthenticationManager(int _timeToLive):timeToLive(_timeToLive) {}
    void generate(string tokenId, int currentTime) {
        M[tokenId]=currentTime+timeToLive;
        Q.emplace(tokenId,currentTime+timeToLive);
    }
    //popold函数用来将currentTime之前要销毁的string销毁掉
    void popold(int currentTime){
        while(Q.size()&&Q.front().second<=currentTime){
            auto [s,t]=Q.front();
            Q.pop();
            //注意队列中取出的s和t可能是过时的旧版本，可能这个s被续了命，所以需要做判断
            if(M[s]==t)M.erase(s);
            else continue;
        }
    }
    void renew(string tokenId, int currentTime) {
        popold(currentTime);
        if(M.count(tokenId)){
            M[tokenId]=currentTime+timeToLive;
            Q.emplace(tokenId,currentTime+timeToLive);
        }
    }
    int countUnexpiredTokens(int currentTime) {
        popold(currentTime);
        return M.size();
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