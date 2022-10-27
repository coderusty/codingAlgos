//prim's algorithm implementation
// brute - force

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    //adjacency list
    vector<pair<int,int>> adj[n];
    int x,y,weight;

    for(int i=0;i<m;i++){
        cin>>x>>y>>weight;
        adj[x].push_back(make_pair(y,weight));
        adj[y].push_back(make_pair(x,weight));
    }

    int parent[n], key[n];
    bool mst[n];
    for(int i=0;i<n;i++){
        key[i]=INT_MAX; mst[i]=false, parent[i]=-1;
    }

    key[0]=0;
    for(int i=0;i<n-1;i++){
        int mini=INT_MAX, u;
        for(int v=0;v<n;v++){
            if(mst[v]==false && key[v]<mini){
                mini=key[v], u=v;
            }
        }
        mst[u]=true;
        for(auto it: adj[u]){
            int v=it.first;
            int weight=it.second;
            if(mst[v]==false && weight<key[v]){
                parent[v]=u, key[v]=weight;
            }
        }
    }
    int sum=0;
    for(int i=1;i<n;i++){
        if(key[i]!=INT_MAX) sum+=key[i];
    }
    cout<<"Minimum cost: :"<<sum<<endl;
    /*for(int i=1;i<n;i++){
        cout<<i<<" is Child of"<< " parent " <<parent[i]<<endl;
    }*/
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
