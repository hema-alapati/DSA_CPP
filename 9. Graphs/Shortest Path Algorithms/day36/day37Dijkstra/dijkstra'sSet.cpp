vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>>st; //distance,node
        vector<int> dist(V, 1e9);
        
        st.insert({0,S});
        dist[S]=0;
        
        while(!st.empty()){
            auto it=*(st.begin());
            int node=it.second;
            int dis=it.first;
            st.erase(it);
            
            for(auto it: adj[node]){
                //node, weight
                int adjNode=it[0];
                int edjW=it[1];
                
                if(dis+edjW<dist[adjNode]){
                    //erase if existed
                    if(dist[adjNode]!=1e9){
                        st.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode]=dis+edjW;
                    st.insert({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
