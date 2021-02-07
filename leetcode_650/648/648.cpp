#include "Trie.h"
#include "utils.h"

// class Solution {
//     //动态Trie树做法
//     typedef DynamicTrie Trie;
// public:
//     string replaceWords(vector<string>& dictionary, string sentence) {
//         Trie T;
//         for(auto&word:dictionary)T.insert(word);
//         string ans;
//         for(int i=0,j;i<sentence.size();i=j+1){
//             j=sentence.find_first_of(' ',i);
//             if(j<0)j=sentence.size();
//             string word=sentence.substr(i,j-i);
//             Trie*p=&T;
//             int len=0;
//             while(len<word.size()){
//                 if(p->signal==1){
//                     ans+=word.substr(0,len)+" ";
//                     break;
//                 }
//                 if(!(p=p->child[word[len]-'a'])){
//                     ans+=word+" ";
//                     break;
//                 }
//                 len++;
//             }
//             if(len==word.size())ans+=word+" ";
//         }
//         ans.pop_back();
//         return ans;
//     }
// };
class Solution {
    //静态Trie树做法
    typedef StaticTrie Trie;
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie T;
        for(auto&word:dictionary)T.insert(word);
        string ans;
        for(int i=0,j;i<sentence.size();i=j+1){
            j=sentence.find_first_of(' ',i);
            if(j<0)j=sentence.size();
            string word=sentence.substr(i,j-i);
            int idx=0;
            int len=0;
            while(len<word.size()){
                if(idx&&T[idx][26]){
                    ans+=word.substr(0,len)+" ";
                    break;
                }
                if(!(idx=T[idx][word[len]-'a'])){
                    ans+=word+" ";
                    break;
                }
                len++;
            }
            if(len==word.size())ans+=word+" ";
        }
        ans.pop_back();
        return ans;
    }
};



int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>dictionary{"cat","bat","rat"};
    string sentence="the cattle was rattled by the battery";
    auto ans=sol.replaceWords(dictionary,sentence);
    DBG(ans);

    system("pause");
    return 0;
}
