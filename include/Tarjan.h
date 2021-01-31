#include<vector>
#include<memory.h>
using namespace std;

//tarjan算法求割边
class tarjanBridge{
    typedef vector<vector<int>>::iterator vvii;
    vvii begin;
    vvii end;
    bool*isBridge;
    unordered_map<int,int>idmap;
    vector<int>DFN;
    vector<int>LOW;
    vector<int>*adj_point;
    vector<int>*adj_edge;
    int timestamp;
    int getid(int oldid){
        if(idmap.count(oldid))return idmap[oldid];
        else return idmap[oldid]=idmap.size();
    }
    int dfs(int cur,int from){
        if(DFN[cur]>=0)return DFN[cur];
        DFN[cur]=LOW[cur]=timestamp++;
        for(int i=0;i<adj_edge[cur].size();i++){
            int point=adj_point[cur][i],edge=adj_edge[cur][i];
            if(edge!=from){
                if(DFN[point]>=0)LOW[cur]=min(LOW[cur],DFN[point]);
                else{
                    int res=dfs(point,edge);
                    if(res>DFN[cur])isBridge[edge]=true;
                    LOW[cur]=min(LOW[cur],res);
                }
            }
        }
        return LOW[cur];
    }
public:
    tarjanBridge(vvii _begin,vvii _end,bool*_isBridge):begin(_begin),end(_end),isBridge(_isBridge){
        for(auto it=begin;it<end;++it){
            getid((*it)[0]);
            getid((*it)[1]);
        }
        DFN.resize(idmap.size(),-1);
        LOW.resize(idmap.size(),-1);
        adj_point=new vector<int>[idmap.size()];
        adj_edge=new vector<int>[idmap.size()];
        for(auto it=begin;it<end;++it){
            int i=getid((*it)[0]),j=getid((*it)[1]);
            if(i!=j){
                adj_point[i].emplace_back(j);
                adj_edge[i].emplace_back(it-begin);
                adj_point[j].emplace_back(i);
                adj_edge[j].emplace_back(it-begin);
            }
        }
    }
    void findBridge(){
        timestamp=0;
        for(int i=0;i<idmap.size();i++){
            if(DFN[i]<0)dfs(i,-1);
        }
    }
};

//tarjan算法求割点
class tarjanCut{
    typedef vector<vector<int>>::iterator vvii;
    vvii begin;
    vvii end;
    bool*isCut;
    int size;
    unordered_map<int,int>idmap;
    vector<int>iddict;
    vector<int>DFN;
    vector<int>LOW;
    vector<int>*adj_point;
    vector<int>*adj_edge;
    int timestamp;
    int getid(int oldid){
        if(idmap.count(oldid))return idmap[oldid];
        else{
            int newid=idmap[oldid]=idmap.size();
            iddict.emplace_back(oldid);
            return newid;
        }
    }
    int findoldid(int newid){
        return iddict[newid];
    }
    int dfs(int cur,int from){
        if(DFN[cur]>=0)return DFN[cur];
        DFN[cur]=LOW[cur]=timestamp++;
        for(int i=0;i<adj_edge[cur].size();i++){
            int point=adj_point[cur][i],edge=adj_edge[cur][i];
            if(edge!=from){
                if(DFN[point]>=0)LOW[cur]=min(LOW[cur],DFN[point]);
                else{
                    int res=dfs(point,edge);
                    if(res>=DFN[cur]){
                        if(from==-1)from--;
                        else isCut[findoldid(cur)]=true;
                    }
                    LOW[cur]=min(LOW[cur],res);
                }
            }
        }
        return LOW[cur];
    }
public:
    tarjanCut(vvii _begin,vvii _end,bool _isCut[]):begin(_begin),end(_end),isCut(_isCut){
        for(auto it=begin;it<end;++it){
            getid((*it)[0]);
            getid((*it)[1]);
        }
        size=idmap.size();
        DFN.resize(size,-1);
        LOW.resize(size,-1);
        adj_point=new vector<int>[size];
        adj_edge=new vector<int>[size];
        for(auto it=begin;it<end;++it){
            int i=getid((*it)[0]),j=getid((*it)[1]);
            if(i!=j){
                adj_point[i].emplace_back(j);
                adj_edge[i].emplace_back(it-begin);
                adj_point[j].emplace_back(i);
                adj_edge[j].emplace_back(it-begin);
            }
        }
    }
    void findCut(){
        timestamp=0;
        for(int i=0;i<size;i++){
            if(DFN[i]<0)dfs(i,-1);
        }
    }
};