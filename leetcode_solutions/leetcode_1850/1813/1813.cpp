#include "utils.h"

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        auto v1=split(sentence1);
        auto v2=split(sentence2);
        if(v1.size()>=v2.size())v1.swap(v2);
        int pre,post;
        for(pre=0;pre<v1.size()&&v1[pre]==v2[pre];pre++);
        for(post=0;post<v1.size()&&v1[v1.size()-1-post]==v2[v2.size()-1-post];post++);
        return pre+post>=v1.size();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string sentence1="My name is Haley";
    string sentence2="My Haley";
    auto ans=sol.areSentencesSimilar(sentence1,sentence2);
    DBG(ans);

    system("pause");
    return 0;
}
