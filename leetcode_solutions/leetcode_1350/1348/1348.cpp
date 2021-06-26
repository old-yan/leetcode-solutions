#include "utils.h"

class TweetCounts {
    unordered_map<string,multiset<int>>M;
public:
    TweetCounts() {}
    void recordTweet(string tweetName, int time) {
        M[tweetName].emplace(time);
    }
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vi ans;
        int interval=(freq=="day"?86400:(freq=="hour"?3600:60));
        auto&times=M[tweetName];
        auto find=times.lower_bound(startTime);
        for(int begin=startTime;begin<=endTime;begin+=interval){
            int end=min(begin+interval,endTime+1);
            int cnt=0;
            while(find!=times.end()&&*find<end){
                cnt++;
                find++;
            }
            ans.pb(cnt);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;

	TweetCounts*obj=new TweetCounts();
	obj->recordTweet("tweet3",0);
	obj->recordTweet("tweet3",60);
	obj->recordTweet("tweet3",10);
	obj->getTweetCountsPerFrequency("minute","tweet3",0,59);
	obj->getTweetCountsPerFrequency("minute","tweet3",0,60);
	obj->recordTweet("tweet3",120);
	obj->getTweetCountsPerFrequency("hour","tweet3",0,210);

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