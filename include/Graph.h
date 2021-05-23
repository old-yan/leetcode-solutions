#include <iostream>
#include <vector>
#include <memory.h>
#include <tuple>
using namespace std;

struct DirectedGraph{
};
struct UndirectedGraph{
    #define VNUM 100000
    #define ENUM 200000
    int v,e;
    int fi[VNUM];
    int ne[ENUM],to[ENUM],dis[ENUM],ecnt;
    int mindis[VNUM];
    void reset(int v,int e){
        memset(fi,0xff,sizeof(fi));
        for(auto a:{ne,to,dis}){
            memset(a,0xff,ENUM*sizeof(int));
        }
        ecnt=0;
    }
    void addEdge(int _from,int _to,int _dis){
        tie(ne[ecnt],fi[_from],to[ecnt])={fi[_from],ecnt,_to};ecnt++;
        tie(ne[ecnt],fi[_to],to[ecnt])={fi[_to],ecnt,_from};ecnt++;
    }
    void Dijkstra(int source){
        memset(mindis,0x3f,sizeof(mindis));
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q;
        mindis[source]=0;
        Q.emplace(0,source);
        while(Q.size()){
            auto [curd,cur]=Q.top();
            Q.pop();
            if(curd!=mindis[cur])continue;
            for(int _=fi[cur];~_;_=ne[_]){
                int j=to[_],d=dis[_];
                if(mindis[j]>curd+d){
                    mindis[j]=curd+d;
                    Q.emplace(mindis[j],j);
                }
            }
        }
    }
};
struct UndirectedGraph{
    #define VNUM 500
    #define ENUM 130000
    int v,e;
    int dis[VNUM][VNUM];
    void reset(int _v){
        v=_v;
        memset(dis,0x3f,sizeof(dis));
    }
    void addEdge(int _from,int _to,int _dis){
        dis[_from][_to]=dis[_to][_from]=_dis;
    }
    void Floyd(){
        for(int k=0;k<v;k++){
            for(int i=0;i<v;i++){
                for(int j=0;j<v;j++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
    }
};


//已知二分图结点分布的情况下，建图求最大匹配
struct BipartiteGraph{
    #define VNUM 32
    #define ENUM 256
    int na=0,nb=0;
    int pa[VNUM],pb[VNUM],fa[VNUM],fb[VNUM];
    int ne[ENUM],to[ENUM],ecnt;
    void reset(int _na,int _nb){
        for(auto a:{pa,pb,fa,fb})memset(a,0xff,VNUM*sizeof(int));
        for(auto a:{ne,to})memset(a,0xff,ENUM*sizeof(int));
        tie(na,nb)={_na,_nb};
        ecnt=0;
    }
    void addEdge(int a,int b){
        tie(ne[ecnt],fa[a],to[ecnt])={fa[a],ecnt,b};ecnt++;
        //tie(ne[ecnt],fb[b],to[ecnt])={fb[b],ecnt,a};ecnt++;
    }
    int maxMatch(){
        int cnt=0,from[VNUM],Q[VNUM];
        for(int i=0;i<na;i++)if(pa[i]<0){
            bool visita[VNUM]={0};
            int h=0,t=0,cur=-1;
            visita[i]=true,Q[t++]=i;
            while(h<t&&cur<0){
                auto p=Q[h++];
                for(int _=fa[p];~_;_=ne[_]){
                    int q=to[_];
                    if(pb[q]<0){from[q]=p,cur=q,cnt++;break;}
                    else if(!visita[pb[q]]){from[q]=p,visita[pb[q]]=true,Q[t++]=pb[q];}
                }
            }
            while(~cur){
                pb[cur]=from[cur];
                swap(cur,pa[from[cur]]);
            }
        }
        return cnt;
    }
};