// Given an unrooted, unweighted tree of n nodes, traverse the tree from node 1 to node n. The path must go through nodes listed in the visitNodes array in any order.
// That is, the path
// • starts at node 1.
// • ends at node n.
// • can only travel from a node to an adjacent node.
// • can visit a node any number of times.
// • includes each of the nodes in visitNodes at least once.
// Return the length of the shortest of these paths.


#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

void dfs(int v, int u, unordered_map<int, vector<int>>& G, unordered_map<int, int>& parent, set<int>& visited) {
    if (visited.find(v) != visited.end()) return;
    parent[v] = u;
    visited.insert(v);
    for (int w : G[v]) {
        if (w == u) continue;
        dfs(w, v, G, parent, visited);
    }
}

int minimumTreePath(int n, vector<vector<int>>& edges, vector<int>& visitNodes) {
    unordered_map<int, int> parent;
    unordered_map<int, vector<int>> G;

    for (vector<int>& edge : edges) {
        int v = edge[0];
        int w = edge[1];
        G[v].push_back(w);
        G[w].push_back(v);
    }

    set<int> visited;

    dfs(1, -1, G, parent, visited);

    set<int> cores;
    int v = n;
    int res = -1;

    while (v != -1) {
        cores.insert(v);
        res += 1;
        v = parent[v];
    }

    for (int v : visitNodes) {
        int tmpres = 0;
        while (cores.find(v) == cores.end()) {
            cores.insert(v);
            tmpres += 2;
            v = parent[v];
        }
        res += tmpres;
    }

    return res;
}

int main() {
    int n = 7;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 6}, {3, 7}};
    vector<int> visitNodes = {2, 4, 5};

    int result = minimumTreePath(n, edges, visitNodes);
    cout << result << endl;

    return 0;
}

// python, 1 test case failed(hidden)
// from collections import defaultdict
// def solveLC(n, visitNodes, edges):
//     parent = defaultdict(lambda:-1)
//     G = defaultdict(list)
//     for v,w in edges:
//         G[v].append(w)
//         G[w].append(v)
//     visited = set()
//     def dfs(v, u):
//         if v in visited: return
//         parent[v] = u
//         visited.add(v)
//         for w in G[v]:
//             if w == u: continue
//             dfs(w, v)
//     dfs(1,-1)
//     cores = set()
//     v = n
//     res = -1
//     while v != -1:
//         cores.add(v)
//         res += 1
//         v = parent[v]
//     for v in visitNodes:
//         tmpres = 0
//         while v not in cores:
//             cores.add(v)
//             tmpres += 2
//             v = parent[v]
//         res += tmpres
//     return res