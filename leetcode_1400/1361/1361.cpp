#include "utils.h"

class Solution {
    bitset<10000>b;
    bool traverse(int cur,vi&leftChild,vi&rightChild){
        if(b[cur])return false;
        b.set(cur);
        if(leftChild[cur]>=0&&!traverse(leftChild[cur],leftChild,rightChild))return false;
        if(rightChild[cur]>=0&&!traverse(rightChild[cur],leftChild,rightChild))return false;
        return true;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        for(int a:leftChild)if(a>=0)b.set(a);
        for(int a:rightChild)if(a>=0)b.set(a);
        if(b.count()!=n-1)return false;
        int root;
        for(root=0;b[root];root++);
        b.reset();
        return traverse(root,leftChild,rightChild)&&b.count()==n;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=4;
    vi leftChild{1,-1,3,-1};
    vi rightChild{2,-1,-1,-1};
    auto ans=sol.validateBinaryTreeNodes(n,leftChild,rightChild);
    DBG(ans);

    system("pause");
    return 0;
}
