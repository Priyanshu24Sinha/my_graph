	#include<bits/stdc++.h>
    using namespace std;
    
class solution
{
    public:
    
    int find(int i, vector<int>&parent){
        if(i==parent[i]) return i;
        
        return parent[i]=find(parent[i],parent);
    }
    
    void uunion(int i, int j, vector<int>&parent, vector<int>&rank){
        
        int parent_i=find(i,parent);
        int parent_j=find(j,parent);
        
        if(parent_i==parent_j) return ;
        
        if(rank[parent_i]>rank[parent_j]){
            parent[parent_j]=parent_i;
        }
        else if(rank[parent_j]>rank[parent_i]){
            parent[parent_i]=parent_j;
        }
        else{
            parent[parent_i]=parent_j;
            rank[parent_j]+=1;
        }
        
        
    }
    
    
	int detectCycle(int V, vector<int>adj[])
	{
	    vector<int>parent(V);
	    for(int i=0; i<V; i++){
	        parent[i]=i;
	    }
	    vector<int>rank(V,0);
	    
	    for(int i=0; i<V; i++ ){
	        for(auto v: adj[i]){
	            if(i<v){
	            int u_par=find(i,parent);
	            int v_par=find(v,parent);
	            if(u_par==v_par) return 1;
	            uunion(i,v,parent,rank);
	        }}
	    }
	    return false;
	}
};