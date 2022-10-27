// krushkal's algorithm implementation
// brute- force
#include<bits/stdc++.h>
using namespace std;
struct node{
int u;
int v;
int wt;
node(int f,int s,int w){
    u=f;
    v=s;
    wt=w;
}
};
bool cmp(node a,node b){
    return a.wt<b.wt;
}
int findPar(int u, vector<int> &parent){
    if(u==parent[u]) return u;
    return findPar(parent[u],parent);
}
void Union(int u,int v,vector<int> &parent,vector<int> &Rank){
    u=findPar(u,parent);
    v=findPar(v,parent);
    if(Rank[u]<Rank[v]) parent[u]=v;
    else if(Rank[v]<Rank[u]) parent[v]=u;
    else parent[v]=u,Rank[u]++;
}
int main(){
    int n,m;
    cin>>n>>m;

    vector<node> edges;

    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(node(u,v,wt));
    }
        sort(edges.begin(),edges.end(),cmp);
        vector<int> parent(n);
        for(int i=0;i<n;i++) parent[i]=i;
        vector<int>Rank(n,0);
        int cost=0;
         vector<pair<int,int>> mst;

        for(auto it:edges){
            if(findPar(it.v , parent)!=findPar(it.u,parent)){
                cost+=it.wt;
                mst.push_back({it.u,it.v});
                Union(it.u,it.v,parent,Rank);
            }
        }

    cout<<"Minimum cost: :"<<cost<<endl;
    for(auto it: mst){
        cout<<it.first<<" is Child of"<< " parent " <<it.second<<endl;
    }
    return 0;
}

/*Input Taken
5 6
0 1 2
0 4 6
1 2 3
1 3 5
1 4 8
2 3 7
*/

/*
6 9
0 1 3
0 3 4
0 2 1
1 3 5
1 4 3
2 3 5
2 5 3
3 5 6
4 5 2
*/
