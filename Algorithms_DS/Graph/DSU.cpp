#include<bits/stdc++.h>
using namespace std;

class DSU{

private:
    vector<int> rank,parent,size;
public:
    //contructor 1
    DSU(int n){
        rank.resize(n+1,0); 
        parent.resize(n+1);
        size.resize(n+1,1);
        for (int i = 0;i<=n;i++){
            parent[i] = i;
        }
    }
    int FUP(int node){
        if (node == parent[node]) return node;
        return parent[node] = FUP(parent[node]);
    }
    void UBR(int u,int v){
        int pu = FUP(u),pv = FUP(v);
        if (pu == pv) return;

        if (rank[pu]<rank[pv]) parent[pu] = pv;
        else if (rank[pu]>rank[pv]) parent[pv] = pu;
        else{
            parent[pv] = pu;
            rank[pu]++;
        }    
    }
    void UBS(int u,int v){
        int pu = FUP(u),pv = FUP(v);
        if (pu == pv) return;
        if (size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

};

int main(){
    
    DSU ds(7);
    //either use UBR || UBS
    ds.UBS(1,2);
    ds.UBS(2,3);
    ds.UBS(4,5);
    ds.UBS(6,7);
    ds.UBS(5,6);
    
//if 3 and 7 are present in a component or not

    if (ds.FUP(3) == ds.FUP(7)) cout<<"Yes";
    else cout<<"No";
    
    cout<<"\n";
    
    ds.UBS(3,7);
    
    if (ds.FUP(3) == ds.FUP(7)) cout<<"Yes";
    else cout<<"No";
    
    return 0;
}