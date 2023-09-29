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
