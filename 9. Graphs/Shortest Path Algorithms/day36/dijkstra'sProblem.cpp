// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

//Algorithm

The provided code implements Dijkstra's algorithm to find the shortest path in a weighted, undirected graph from vertex 1 to vertex n. Here's the logic of the code step by step:

1. **Graph Representation:**
   - An adjacency list `adj` is created to represent the graph, where `adj[i]` is a vector of pairs `(v, w)`, denoting an edge from vertex `i` to vertex `v` with weight `w`.

2. **Initialization:**
   - Initialize a priority queue `pq` to select nodes to explore based on the minimum distance.
   - Initialize two arrays:
     - `dist`, which stores the minimum distance from vertex 1 to all other vertices. Initialize `dist[1]` to 0 and all other distances to a large value (1e9) to represent infinity.
     - `parent`, which keeps track of the parent of each node in the shortest path tree. Initially, each node is its own parent.

3. **Dijkstra's Algorithm:**
   - Start with vertex 1 (the source) with a distance of 0 and push it into the priority queue.
   - While the priority queue is not empty:
     - Extract the node with the smallest distance from the priority queue.
     - For each adjacent node of the extracted node:
       - Calculate the distance to the adjacent node through the current node.
       - If this distance is shorter than the previously calculated distance, update the `dist` array and push the adjacent node into the priority queue with its new distance. Update the parent information as well.

4. **Path Reconstruction:**
   - Check if there is a path from vertex 1 to vertex n. If `dist[n]` is still equal to its initial value (1e9), return `-1` to indicate that no path exists.

5. **If a Path Exists:**
   - Reconstruct the shortest path from vertex 1 to vertex n using the `parent` array. Starting from vertex n, backtrace through the parents until reaching vertex 1 and store the path in the `path` vector.

6. **Return the Shortest Path:**
   - Reverse the `path` vector to obtain the correct order of vertices from vertex 1 to vertex n.
   - Return the `path` vector, which represents the shortest path from vertex 1 to vertex n.

In summary, this code efficiently finds the shortest path in an undirected, weighted graph using Dijkstra's algorithm and returns the path if it exists or `-1` if there is no path from vertex 1 to vertex n.
// Code with comments

// Create an adjacency list representation of a graph.
vector<pair<int, int>> adj[n + 1];

// Populate the adjacency list based on the input edges.
for (auto it : edges) {
    // For each edge (it), add information to both source and target vertices' adjacency lists.
    
    // Add to the source vertex's adjacency list.
    adj[it[0]].push_back({it[1], it[2]});
    
    // Since it's an undirected graph, add to the target vertex's adjacency list as well.
    // This ensures edges are represented in both directions.
    adj[it[1]].push_back({it[0], it[2]});
}

// Initialize a priority queue for Dijkstra's algorithm.
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

// Initialize arrays to store distance and parent information.
vector<int> dist(n + 1, 1e9);
vector<int> parent(n + 1);

// Initialize parent array with each node as its own parent.
for (int i = 1; i <= n; i++) parent[i] = i;

// Start from vertex 1 with distance 0 and add it to the priority queue.
dist[1] = 0;
pq.push({0, 1});

// Perform Dijkstra's algorithm to find the shortest path.
while (!pq.empty()) {
    auto it = pq.top();
    int node = it.second;
    int dis = it.first;
    pq.pop();
    
    // Explore neighbors and update distances and parents.
    for (auto it : adj[node]) {
        int adjNode = it.first;
        int edW = it.second;
        
        // If a shorter path is found, update distance and parent.
        if (dis + edW < dist[adjNode]) {
            dist[adjNode] = dis + edW;
            pq.push({dis + edW, adjNode});
            parent[adjNode] = node;
        }
    }
}

// Check if there is a path from vertex 1 to vertex n.
if (dist[n] == 1e9) return {-1};

// Reconstruct the shortest path.
vector<int> path;
int node = n;
while (parent[node] != node) {
    path.push_back(node);
    node = parent[node];
}

// Add the starting vertex (vertex 1) to the path.
path.push_back(1);

// Reverse the path to get it in the correct order.
reverse(path.begin(), path.end());

// Return the shortest path from vertex 1 to vertex n.
return path;

//without comments, src code
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[n+1];
        //creating the graph
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            //since the graph is undirected, we add both (u,v) and (v,u) 
            // and it[2] is the edge weight
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue< pair<int,int>, vector<pair<int,int>>, 
        greater<pair<int,int>> >pq;
        vector<int> dist(n+1,1e9);
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++) parent[i]=i;
        dist[1]=0;
        pq.push({0,1});
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            int dis=it.first;
            pq.pop();
            
            for(auto it: adj[node]){
                int adjNode=it.first;
                int edW=it.second;
                if(dis+edW<dist[adjNode]){
                    dist[adjNode]=dis+edW;
                    pq.push({dis+edW,adjNode});
                    parent[adjNode]=node;
                }
            }
        }
        if(dist[n]==1e9) return {-1};
        vector<int>path;
        int node=n;
        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
    }


