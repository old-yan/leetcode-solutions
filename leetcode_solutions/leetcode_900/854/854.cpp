#include "utils.h"

class Solution {
    int rest[7][7]={0};
    long loops[49];
    int loopssize;
    int from[7];
    int len[7];
    char conflict[49];
    int Q[7],h,t;
    bitset<64>min_loop;
public:
    int kSimilarity(string A, string B) {
        cout<<"A.size()="<<A.size()<<'\n';
        cout<<"B.size()="<<B.size()<<'\n';
        int n=A.size();
        int dif=0;
        for(int i=0;i<n;i++){
            if(A[i]!=B[i]){
                dif++;
                rest[A[i]-'a'][B[i]-'a']++;
            }
        }
        int loop=0;
        int minlooplen;
        while(true){
            minlooplen=INT_MAX-1;
            for(int start=0;start<7;start++){
                for(int end=0;end<7;end++){
                    if(rest[start][end]){
                        rest[start][end]--;
                        fill(from,from+7,-1);
                        from[end]=INT_MAX;
                        fill(len,len+7,INT_MAX);
                        len[end]=0;
                        h=0,t=0;
                        Q[t++]=end;
                        while(h<t){
                            auto&p=Q[h++];
                            for(int i=0;i<7;i++){
                                if(rest[p][i]&&from[i]<0){
                                    from[i]=p;
                                    len[i]=len[p]+1;
                                    Q[t++]=i;
                                }
                            }
                        }
                        rest[start][end]++;
                        if(len[start]<=minlooplen){
                            if(len[start]<minlooplen)loopssize=0;
                            minlooplen=len[start];
                            long&curloop=loops[loopssize++];
                            curloop=1ll<<(end*7+start);
                            for(int i=start;i!=end;i=from[i]){
                                curloop|=1ll<<(i*7+from[i]);
                            }
                        }
                    }
                }
            }
            if(minlooplen==INT_MAX-1)break;
            memset(conflict,0,loopssize*sizeof(int));
            for(int i=0;i<loopssize;i++){
                for(int j=0;j<i;j++){
                    if(loops[i]&loops[j]){
                        conflict[i]++;
                        conflict[j]++;
                    }
                }
            }
            min_loop=loops[min_element(conflict,conflict+loopssize)-conflict];
            for(int i=min_loop._Find_first();i<64;i=min_loop._Find_next(i)){
                rest[i%7][i/7]--;
            }
            loop++;
        }
        cout<<"dif="<<dif<<'\n';
        cout<<"loop="<<loop<<'\n';
        return dif-loop;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string A="bda ebc fca";
    string B="dab bce caf";
    auto ans=sol.kSimilarity(A,B);
    DBG(ans);

    system("pause");
    return 0;
}