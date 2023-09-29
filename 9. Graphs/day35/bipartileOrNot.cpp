// https://practice.geeksforgeeks.org/problems/bipartite-graph/1
// https://www.youtube.com/watch?v=-vu34sct1g8
private:
    bool check(int start, int V, vector<int>adj[],int color[]){
        queue<int>q;
	    q.push(start);
	    color[start]=0;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        
	        for(auto it: adj[node]){
	            if(color[it]==-1){
	                color[it]=!color[node];
	                q.push(it);
	            }
	            else if(color[it]==color[node]){
	                return false;
	            }
	        }
	    }
	    return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    for(int i=0;i<V;i++) color[i]=-1;	
      // check for connected components
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(check(i,V,adj,color)==false){
	                return false;
	            }
	        }
	    }
	    return true;
	}


// DFS

private:
    bool dfs(int node, int col, int color[],vector<int>adj[]){
        color[node]=col;
        
        for(auto it: adj[node]){
            if(color[it]==-1){
                if(dfs(it,!col,color,adj)==false) return false;
            }
            else if(color[it]==col){
                return false;
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int color[V];
	    for(int i=0;i<V;i++) color[i]=-1;
	    
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(dfs(i,0,color,adj)==false) return false;
	        }
	    }
	    return true;
	}
