#ifdef CREGEX
#include <regex.h>
struct Regex{
    regex_t obj;
    regmatch_t pm[10];
    char z[10]={0};
    Regex(const char c[],int extend=1,int icase=2,int nosub=8){regcomp(&obj,c,0);}
    //~Regex(){regfree(&obj);}
    bool match(const char c[]){
        return !regexec(&obj,c,1,pm,0)&&!pm[0].rm_so&&!c[pm[0].rm_eo];
    }
    pair<bool,string> search(const char c[]){
        if(int code=regexec(&obj,c,1,pm,0)){
            regerror(code,&obj,z,20);
            return {false,z};
        }
        else return {true,string(c+pm[0].rm_so,c+pm[0].rm_eo)};
    }
};
#else
#include <regex>
using namespace std;
struct Regex{
    regex obj;
    smatch res;
    Regex(const char c[]):obj(c){}
    //~Regex(){}
    bool match(const char c[]){
        return regex_match(c,obj);
    }
    pair<bool,string> search(const char *c){
        string tmp=c;
        if(regex_search(tmp,res,obj))return {true,res.str()};
        else return {false,""};
    }
};
#endif