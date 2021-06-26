#include "utils.h"

class Solution {
    struct{
        int lower[26]={0},upper[26]={0};
        int single_lower=0,single_upper=0;
        void add(char c){
            if(islower(c)){
                if(!lower[c-'a']++){
                    if(upper[c-'a'])single_upper--;
                    else single_lower++;
                }
            }
            else{
                if(!upper[c-'A']++){
                    if(lower[c-'A'])single_lower--;
                    else single_upper++;
                }
            }
        }
        void remove(char c){
            if(islower(c)){
                if(!--lower[c-'a']){
                    if(upper[c-'a'])single_upper++;
                    else single_lower--;
                }
            }
            else{
                if(!--upper[c-'A']){
                    if(lower[c-'A'])single_lower++;
                    else single_upper--;
                }
            }
        }
        void clear(){
            memset(lower,0,sizeof(lower));
            memset(upper,0,sizeof(upper));
            single_upper=single_lower=0;
        }
    }T;
public:
    string longestNiceSubstring(string s) {
        string ans;
        REP(i,s.size()){
            T.clear();
            FOR(j,i,s.size()){
                T.add(s[j]);
                if(!T.single_lower&&!T.single_upper){
                    if(j-i+1>ans.size()){
                        ans=s.substr(i,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="YazaAay";
    auto ans=sol.longestNiceSubstring(s);
    DBG(ans);

    system("pause");
    return 0;
}
