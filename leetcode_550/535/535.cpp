#include "utils.h"

class Solution {
    static unordered_map<int,string>M;
public:
    string encode(string longUrl) {
        int key;
        do{
            key=rand();
        }while(M.count(key));
        M[key]=longUrl;
        return i2s(key);
    }
    string decode(string shortUrl) {
        return M[s2i(shortUrl)];
    }
};

int main()
{
    cout<<boolalpha;

    string longUrl="https://leetcode.com/problems/design-tinyurl";
    Solution encoder;
    Solution decoder;
    string shortUrl=encoder.encode(longUrl);
    DBG(shortUrl);
    string ans=decoder.decode(shortUrl);
    DBG(ans);

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