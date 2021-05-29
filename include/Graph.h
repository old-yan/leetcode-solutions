#include <iostream>
#include <vector>
#include <memory.h>
#include <tuple>
#include <functional>
#include <queue>
using namespace std;

#define VNUM 100000
#define ENUM 100000
template<class T=int>struct UndirectedGraph{
    int n,fi[VNUM];
    int ne[ENUM*2],from[ENUM*2],to[ENUM*2],ecnt;
    T w[ENUM*2];
    void reset(int _v){
        n=_v,ecnt=0,memset(fi,0xff,n*sizeof(int));
    }
    void addEdge(int a,int b,T _w=1){
        tie(ne[ecnt],fi[a],from[ecnt],to[ecnt],w[ecnt])={fi[a],ecnt,a,b,_w};ecnt++;
        tie(ne[ecnt],fi[b],from[ecnt],to[ecnt],w[ecnt])={fi[b],ecnt,b,a,_w};ecnt++;
    }
};
template<class T=int>struct DirectedGraph{
    int n,fi[VNUM],indeg[VNUM];
    int ne[ENUM],from[ENUM],to[ENUM],ecnt;
    T w[ENUM];
    void reset(int _v){
        n=_v,ecnt=0,memset(fi,0xff,n*sizeof(int)),memset(indeg,0,n*sizeof(int));
    }
    void addEdge(int a,int b,T _w=1){
        tie(ne[ecnt],fi[a],from[ecnt],to[ecnt],w[ecnt])={fi[a],ecnt,a,b,_w};ecnt++,indeg[b]++;
    }
};
template<class T=int>struct FlowNetwork{
    int n,fi[VNUM];
    int ne[ENUM*2],from[ENUM*2],to[ENUM*2],ecnt;
    T w[ENUM*2];
    void reset(int _v){
        n=_v,ecnt=0,memset(fi,0xff,n*sizeof(int));
    }
    void addEdge(int a,int b,T _w){
        tie(ne[ecnt],fi[a],from[ecnt],to[ecnt],w[ecnt])={fi[a],ecnt,a,b,_w};ecnt++;
        tie(ne[ecnt],fi[b],from[ecnt],to[ecnt])={fi[b],ecnt,b,a};w[ecnt++]=0;
    }
};
template<class T,class Graph>void dijkstra(int source,T dist[],const Graph&A){
    memset(dist,0x3f,A.n*sizeof(T));
    typedef pair<T,int> pti;static priority_queue<pti,vector<pti>,greater<pti>>Q;
    Q.emplace(dist[source]=0,source);
    while(Q.size()){
        auto [curd,cur]=Q.top();Q.pop();
        if(curd!=dist[cur])continue;
        for(int _=A.fi[cur];~_;_=A.ne[_]){
            int j=A.to[_];T d=A.w[_];
            if(dist[j]>curd+d)dist[j]=curd+d,Q.emplace(dist[j],j);
        }
    }
}
template<class T,class Graph>void spfa(int source,T dist[],const Graph&A){
    memset(dist,0x3f,A.n*sizeof(T));
    static deque<int>Q;
    static bool inque[VNUM];
    memset(inque,0,A.n*sizeof(bool));
    dist[source]=0,Q.emplace_back(source),inque[source]=true;
    auto keep=[&](){if(Q.size()>1&&dist[Q.front()]>dist[Q.back()])swap(Q.front(),Q.back());};
    while(Q.size()){
        auto cur=Q.front();T curd=dist[cur];Q.pop_front(),inque[cur]=false,keep();
        for(int _=A.fi[cur];~_;_=A.ne[_]){
            int j=A.to[_];T d=A.w[_];
            if(dist[j]>curd+d){
                dist[j]=curd+d;
                if(!inque[j])Q.emplace_back(j),inque[j]=true,keep();
            }
        }
    }
}
template<class V,class T,class Graph>void BFS(V source,T dist[],const Graph&A){
    memset(dist,0x3f,A.n*sizeof(T));
    static queue<pair<T,int>>Q;
    if constexpr(is_same<V,int>::value)Q.emplace(dist[source]=0,source);
    else for(auto a:source)Q.emplace(dist[a]=0,a);
    while(Q.size()){
        auto [curd,cur]=Q.front();Q.pop();
        if(curd!=dist[cur])continue;
        for(int _=A.fi[cur];~_;_=A.ne[_]){
            int j=A.to[_];T d=A.w[_];
            if(dist[j]>curd+d)dist[j]=curd+d,Q.emplace(dist[j],j);
        }
    }
}
template<class T,class Graph>void floyd(vector<vector<T>>&dist,const Graph&A){
    for(auto&_:dist)fill(_.begin(),_.end(),0x3f3f3f3f);
    for(int i=0;i<A.ecnt;i++)dist[A.from[i]][A.to[i]]=A.w[i];
    for(int k=0;k<A.n;k++)for(int i=0;i<A.n;i++)for(int j=0;j<A.n;j++)dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}
template<class T>T EK(int source,int target,FlowNetwork<T>&A){
    T sum=0;
    static int trace[VNUM],Q[VNUM];static T flow[VNUM];
    while(true){
        memset(flow,0,A.n*sizeof(T));
        int h=0,t=0;
        flow[source]=0x3f3f3f3f,Q[t++]=source;
        while(h<t){
            auto p=Q[h++];
            for(int _=A.fi[p];~_;_=A.ne[_])
                if(A.w[_]&&!flow[A.to[_]])
                    flow[A.to[_]]=min(flow[p],A.w[_]),trace[A.to[_]]=_,Q[t++]=A.to[_];
            if(flow[target])break;
        }
        if(!flow[target])break;
        sum+=flow[target];
        for(int cur=target;cur!=source;cur=A.from[trace[cur]])
            A.w[trace[cur]]-=flow[target],A.w[trace[cur]^1]+=flow[target];
    }
    return sum;
}
template<class T>T Dinic(int source,int target,FlowNetwork<T>&A){
    T sum=0;
    static int depth[VNUM],cur[VNUM],Q[VNUM];
    auto bfs=[&](){
        memset(depth,0xff,A.n*sizeof(int));
        int h=0,t=0;depth[source]=0,Q[t++]=source;
        while(h<t)
            for(int _=A.fi[Q[h++]];~_;_=A.ne[_])
                if(A.w[_]&&depth[A.to[_]]<0)depth[A.to[_]]=depth[Q[h-1]]+1,Q[t++]=A.to[_];
        return depth[target]>=0;
    };
    function<T(int,int)>dfs=[&](int p,int cap){
        if(p==target||!cap)return cap;
        T flow=0,f;
        for(int&_=cur[p];~_&&cap;_=A.ne[_])
            if(depth[p]+1==depth[A.to[_]]&&(f=dfs(A.to[_],min(cap,A.w[_])))>0)
                A.w[_]-=f,A.w[_^1]+=f,flow+=f,cap-=f;
        return flow;
    };
    while(bfs())memcpy(cur,A.fi,A.n*sizeof(int)),sum+=dfs(source,INT_MAX);
    return sum;
}
template<class T>T ISAP(int source,int target,FlowNetwork<T>&A){
    T sum=0;
    static int depth[VNUM],cur[VNUM],num[VNUM],trace[VNUM];static T flow[VNUM];
    memset(depth,0xff,A.n*sizeof(int));
    int h=0,t=0;depth[target]=0,cur[t++]=target;
    while(h<t)
        for(int _=A.fi[cur[h++]];~_;_=A.ne[_])
            if(A.w[_^1]&&depth[A.to[_]]<0)depth[A.to[_]]=depth[cur[h-1]]+1,cur[t++]=A.to[_];
    if(depth[source]<0)return 0;
    memset(num,0,(depth[cur[t-1]]+1)*sizeof(int));
    for(int i=0;i<A.n;i++)if(depth[i]>=0)num[depth[i]]++;
    memcpy(cur,A.fi,A.n*sizeof(int));
    flow[source]=0x3f3f3f3f;
    for(int x=source;depth[source]<A.n;){
        if(x==target){
            for(T f=flow[target];x!=source;x=A.from[trace[x]])
                A.w[trace[x]]-=f,A.w[trace[x]^1]+=f;
            sum+=flow[target];
        }
        for(int&_=cur[x];~_;_=A.ne[_])
            if(A.w[_]&&depth[x]==depth[A.to[_]]+1){
                trace[A.to[_]]=_,flow[A.to[_]]=min(A.w[_],flow[x]),x=A.to[_];break;
            }
        if(!~cur[x]){
            if(!--num[depth[x]])break;
            cur[x]=A.fi[x],depth[x]=A.n;
            for(int _=A.fi[x];~_;_=A.ne[_])
                if(A.w[_])depth[x]=min(depth[x],depth[A.to[_]]+1);
            num[depth[x]]++;
            if(x!=source)x=A.from[trace[x]];
        }
    }
    return sum;
}
struct Utarjan{
    int DFN[VNUM],LOW[VNUM];
    bool isCut[VNUM];
    template<class T>void solve(const UndirectedGraph<T>&A){
        memset(DFN,0xff,A.n*sizeof(int));
        memset(LOW,0xff,A.n*sizeof(int));
        memset(isCut,0,A.n*sizeof(bool));
        int timestamp;
        function<void(int,int)>dfs=[&](int cur,int from){
            DFN[cur]=LOW[cur]=timestamp++;
            for(int _=A.fi[cur];~_;_=A.ne[_])if(_>>1!=from){
                int j=A.to[_];
                if(DFN[j]>=0)LOW[cur]=min(LOW[cur],DFN[j]);
                else{
                    dfs(j,_>>1);
                    if(LOW[j]<DFN[cur])LOW[cur]=min(LOW[cur],LOW[j]);
                    else if(!~from)from--;else isCut[cur]=true;
                }
            }
        };
        for(int i=0;i<A.n;i++)if(DFN[i]<0)timestamp=0,dfs(i,-1);
    }
    bool isBridge(int a,int b){return LOW[a]>DFN[b]||LOW[b]>DFN[a];}
}utj;
struct tarjan{
    int DFN[VNUM],LOW[VNUM],color[VNUM],color_num,n;
    template<class T>void solve(const DirectedGraph<T>&A){
        color_num=0;n=A.n;
        memset(DFN,0xff,n*sizeof(int));
        memset(LOW,0xff,n*sizeof(int));
        memset(color,0xff,n*sizeof(int));
        static int stack[VNUM];
        int timestamp=0,l=0;
        function<void(int)>dfs=[&](int cur){
            DFN[cur]=LOW[cur]=timestamp++;
            stack[l++]=cur;
            for(int _=A.fi[cur];~_;_=A.ne[_]){
                int j=A.to[_];
                if(DFN[j]>=0)LOW[cur]=min(LOW[cur],DFN[j]);
                else dfs(j),LOW[cur]=min(LOW[cur],LOW[j]);
            }
            if(LOW[cur]==DFN[cur]){
                while(color[cur]<0)color[stack[--l]]=color_num;
                color_num++;
            }
        };
        for(int i=0;i<n;i++)if(DFN[i]<0)dfs(i);
    }
    vector<vector<int>>scc(){
        vector<int>cnt(color_num,0);
        for(int i=0;i<n;i++)cnt[color[i]]++;
        vector<vector<int>>groups(color_num);
        for(int i=0;i<color_num;i++)groups[i].reserve(cnt[i]);
        for(int i=0;i<n;i++)groups[color[i]].emplace_back(i);
        return groups;
    }
}tj;
struct topo{
    int rest[VNUM];
    vector<int>seq;
    bool visited[VNUM];
    template<class T>void solve(const DirectedGraph<T>&A){
        memcpy(rest,A.indeg,A.n*sizeof(int));
        memset(visited,0,A.n*sizeof(bool));
        seq.clear();seq.reserve(A.n);
        for(int i=0;i<A.n;i++)if(!rest[i])seq.emplace_back(i),visited[i]=true;
        for(int i=0;i<seq.size();i++)
            for(int _=A.fi[seq[i]];~_;_=A.ne[_]){
                int j=A.to[_];
                if(!--rest[j])seq.emplace_back(j),visited[j]=true;
            }
    }
}tp;

#undef VNUM
#undef ENUM

//已知二分图结点分布的情况下，建图求最大匹配。匈牙利算法，时间复杂度不如Dinic
struct BipartiteGraph{
    #define VNUM 1000
    #define ENUM 1000
    int na=0,nb=0;
    int Pa[VNUM],Pb[VNUM],fa[VNUM];
    int ne[ENUM],from[ENUM],to[ENUM],ecnt;
    bool visit[VNUM];
    void reset(int _na,int _nb){
        tie(na,nb)={_na,_nb};ecnt=0;
        for(auto a:{Pa,fa})memset(a,0xff,na*sizeof(int));
        for(auto a:{Pb})memset(a,0xff,nb*sizeof(int));
    }
    void addEdge(int a,int b){
        tie(ne[ecnt],from[ecnt],to[ecnt],fa[a])={fa[a],a,b,ecnt};ecnt++;
    }
    int maxMatch(){
        function<bool(int)>dfs=[&](int cur){
            if(visit[cur])return false;
            visit[cur]=true;
            for(int _=fa[cur];~_;_=ne[_]){
                int j=to[_];
                if(Pb[j]<0||dfs(Pb[j])){
                    Pb[j]=cur,Pa[cur]=j;return true;
                }
            }
            return false;
        };
        int cnt=0;
        for(int i=0;i<na;i++)if(Pa[i]<0){
            memset(visit,0,na*sizeof(bool)),cnt+=dfs(i);
        }
        return cnt;
    }
}bpg;