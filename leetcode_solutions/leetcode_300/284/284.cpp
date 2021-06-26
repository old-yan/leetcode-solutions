#include "utils.h"

class Iterator{
    vi data;
    int idx;
public:
    Iterator(const vector<int>& nums):data(nums),idx(0){}
    Iterator(const Iterator& iter):data(iter.data),idx(iter.idx){}
    int next(){return data[idx++];}
    bool hasNext() const{return idx<data.size();}
};

class PeekingIterator : public Iterator {
    bool haveCache;
    int cache;
public:
	PeekingIterator(const vector<int>&& nums) : Iterator(nums),haveCache(false){}
	int peek() {
        if(haveCache)return cache;
        else{
            cache=next();
            haveCache=true;
            return cache;
        }
	}
	virtual int next() {
        if(haveCache){
            haveCache=false;
            return cache;
        }
        else return Iterator::next();
	}
	virtual bool hasNext() const {
	    return haveCache||Iterator::hasNext();
	}
};

int main()
{
    cout<<boolalpha;

    PeekingIterator*obj=new PeekingIterator({1,2,3});
    DBG(obj->next());
	DBG(obj->peek());
	DBG(obj->next());
	DBG(obj->next());
	DBG(obj->hasNext());

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