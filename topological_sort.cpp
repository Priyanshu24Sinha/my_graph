	#include<bits/stdc++.h>
    using namespace std;
    
    class solution
    {
    public:

    // void solve(int ind,vector<int> adj[],vector<int>&visited ){
        
    //  visited[ind]=1;
     
    //  for(auto it: adj[ind]){
    //     if(!visited[it]) solve(it, adj,visited); 
    //  }
        
    //   st.push(ind);
       
        
    // }

    //  stack<int>st;
   
    
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   // for bfs or kahn's algo
	   
	    
	    
	   // vector<int>visited(V,0);
	    
	   // for(int i=0; i<V; i++){
	   //    if(!visited[i]) solve(i,adj,visited);
	   // }
	    
	   // vector<int>ans;
	   // while(!st.empty()){
	   //     ans.push_back(st.top());
	        
	   //     st.pop();
	   // }
	  
	 
	    //return ans;
	    int n=V;
	   vector<int>ans;    
       vector<int>indegree(n,0);
       queue<int>q;
        
       for(int i=0; i<n; i++){
           
           for(auto it: adj[i]){
               indegree[it]++;
           }
       }
        
        for(int i=0; i<n; i++){
            if(indegree[i]==0)  q.push(i);
            
        }
        
        while(!q.empty()){
            
            int front_node=q.front();
            ans.push_back(front_node);
            
            q.pop();
            
            for(auto it: adj[front_node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
       return ans;
	    
	}
    };