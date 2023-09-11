// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
 bool isCyclic(int V, vector<int> adj[]) {
        // code here
        //topo sort's code pasted
        int indegree[V]={0};
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
        int cnt=0;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        cnt++;
	        // node is in toposort, so remove it from indegree
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0) q.push(it);
	        }
	    }
	    //additional
	    if(cnt==V) return false;
	    else return true;
    }