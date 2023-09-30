Algorithm for priority queue method:

Dijkstra's algorithm is a shortest-path algorithm used to find the shortest distance between a source node and all other nodes in a weighted graph. 
When implementing Dijkstra's algorithm using a priority queue (which is typically implemented as a min-heap), you can follow these steps:

Initialize distances: Set the distance of the source node to 0 and all other nodes to infinity. Create a priority queue to store nodes and their distances.

Add the source node to the priority queue with a distance of 0.

While the priority queue is not empty:
a. Extract the node with the minimum distance from the priority queue (the one with the smallest distance).
b. For each neighbor of the extracted node:
i. Calculate the tentative distance from the source node to the neighbor through the extracted node.
ii. If this tentative distance is smaller than the current distance of the neighbor, update the neighbor's distance.
iii. Add the neighbor to the priority queue with its updated distance.

Repeat step 3 until all nodes have been processed or until you reach the target node if you're finding the shortest path to a specific node.

The distances assigned to each node after the algorithm's completion represent the shortest distances from the source node to all other nodes in the graph.

Time: O(V + E log V) time, where V is the number of vertices and E is the number of edges in the graph. 

Code: (RTE on gfg)
// problem link: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
  public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dist(V);
        for(int i=0;i<V;i++){
            dist[i]=1e9;
        }
        
        dist[S]=0; //distance from source node to itself is 0
        pq.push({0,S}); //pushing the distance, node to priority queue
        
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            
            for(auto it: adj[node]){
                int edgeWeight=it[1];
                int adjNode=it[0];

                if(dis+edgeWeight<dist[adjNode]){
                    dist[adjNode]=dis+edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
