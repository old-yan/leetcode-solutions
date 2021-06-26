#include "utils.h"

class MovieRentingSystem {
    struct node{
        int shop,movie,price;
        bool operator<(const node&other)const{
            return tie(price,shop,movie)<tie(other.price,other.shop,other.movie);
        }
    };
    unordered_map<int,set<node>>movies;
    map<pair<int,int>,int>prices;
    set<node>rentout;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto&e:entries){
            movies[e[1]].insert(node{e[0],e[1],e[2]});
            prices[{e[0],e[1]}]=e[2];
        }
    }
    vector<int> search(int movie) {
        vi ans;
        for(auto it:movies[movie]){
            ans.pb(it.shop);
            if(ans.size()==5)break;
        }
        return ans;
    }
    void rent(int shop, int movie) {
        node cur{shop,movie,prices[{shop,movie}]};
        movies[movie].erase(cur);
        rentout.insert(cur);
    }
    void drop(int shop, int movie) {
        node cur{shop,movie,prices[{shop,movie}]};
        movies[movie].insert(cur);
        rentout.erase(cur);
    }
    vector<vector<int>> report() {
        vvi ans;
        for(auto it:rentout){
            ans.pb({it.shop,it.movie});
            if(ans.size()==5)break;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;

    vvi entries=makevvi("[[0,1,5],[0,2,6],[0,3,7],[1,1,4],[1,2,7],[2,1,5]]");
	MovieRentingSystem*obj=new MovieRentingSystem(3,entries);
	obj->search(1);
	obj->rent(0,1);
	obj->rent(1,2);
	obj->report();
	obj->drop(1,2);
	obj->search(2);

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