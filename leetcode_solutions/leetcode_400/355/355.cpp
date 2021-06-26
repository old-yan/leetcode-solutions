#include "utils.h"

class Twitter {
    class user{
    public:
        vector<int>data;
        vector<int>timestamp;
        set<int>followee;
        void follow(int other){
            followee.insert(other);
        }
        void unfollow(int other){
            followee.erase(other);
        }
    };
    user u[501];
    int count=0;
public:
    Twitter() {
        REP(i,501)u[i].follow(i);
    }
    void postTweet(int userId, int tweetId) {
        u[userId].data.push_back(tweetId);
        u[userId].timestamp.push_back(count++);
    }
    vector<int> getNewsFeed(int userId) {
        auto comp=[&](pair<int,int>&x,pair<int,int>&y){return u[x.first].timestamp[x.second]<u[y.first].timestamp[y.second];};
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)>Q(comp);
        for(int a:u[userId].followee){
            if(u[a].data.size()){
                Q.push(make_pair(a,u[a].data.size()-1));
            }
        }
        vi ans;
        while(Q.size()&&ans.size()<10){
            auto p=Q.top();
            Q.pop();
            ans.pb(u[p.first].data[p.second]);
            if(p.second--){
                Q.push(p);
            }
        }
        DBGV(ans);
        return ans;
    }
    void follow(int followerId, int followeeId) {
        u[followerId].follow(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId)u[followerId].unfollow(followeeId);
    }
};

int main()
{
    cout<<boolalpha;

    Twitter*obj=new Twitter();
	obj->postTweet(1,5);
	obj->postTweet(2,3);
	obj->postTweet(1,101);
	obj->postTweet(2,13);
	obj->postTweet(2,10);
	obj->postTweet(1,2);
	obj->postTweet(1,94);
	obj->postTweet(2,505);
	obj->postTweet(1,333);
	obj->postTweet(2,22);
	obj->postTweet(1,11);
	obj->postTweet(1,205);
	obj->postTweet(2,203);
	obj->postTweet(1,201);
	obj->postTweet(2,213);
	obj->postTweet(1,200);
	obj->postTweet(2,202);
	obj->postTweet(1,204);
	obj->postTweet(2,208);
	obj->postTweet(2,233);
	obj->postTweet(1,222);
	obj->postTweet(2,211);
	obj->getNewsFeed(1);
	obj->follow(1,2);
	obj->getNewsFeed(1);
	obj->unfollow(1,2);
	obj->getNewsFeed(1);

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