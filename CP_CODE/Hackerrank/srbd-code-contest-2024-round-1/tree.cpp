#include <iostream>  
#include <vector>  
#include <cstring>  

using namespace std;  

const int MAX_N = 100000; // Maximum number of cities  
vector<int> graph[MAX_N + 1];  
int parent[MAX_N + 1];  
int depth[MAX_N + 1];  
bool visited[MAX_N + 1];  

// DFS to build parent and depth arrays  
void dfs(int node, int par, int d) {  
    visited[node] = true;  
    parent[node] = par;  
    depth[node] = d;  

    for (int neighbor : graph[node]) {  
        if (!visited[neighbor]) {  
            dfs(neighbor, node, d + 1);  
        }  
    }  
}  

// Finding LCA (Lowest Common Ancestor) of u and v  
int lca(int u, int v) {  
    while (depth[u] > depth[v]) {  
        u = parent[u];  
    }  
    while (depth[v] > depth[u]) {  
        v = parent[v];  
    }  
    while (u != v) {  
        u = parent[u];  
        v = parent[v];  
    }  
    return u;  
}  

// Function to find the middle city  
int find_middle_city(int u, int v) {  
    int common_ancestor = lca(u, v);  
    int distance_u = depth[u] - depth[common_ancestor];  
    int distance_v = depth[v] - depth[common_ancestor];  
    int total_distance = distance_u + distance_v;  

    // Determine the middle city based on the total distance  
    int mid_distance = (total_distance % 2 == 0) ? (total_distance / 2) : (total_distance / 2 + 1);  

    // Move from u towards the common ancestor  
    int current = u;  
    while (mid_distance > 0) {  
        current = parent[current];  
        mid_distance--;  
    }  

    return current;  
}  

int main() {  
    ios::sync_with_stdio(false);  
    cin.tie(nullptr);  

    int test_cases;  
    cin >> test_cases;  

    while (test_cases--) {  
        int n;  
        cin >> n;  

        // Clear the graph and visited array for the new test case  
        for (int i = 1; i <= n; i++) {  
            graph[i].clear();  
            visited[i] = false;  
        }  

        for (int i = 0; i < n - 1; i++) {  
            int u, v;  
            cin >> u >> v;  
            graph[u].push_back(v);  
            graph[v].push_back(u);  
        }  

        // Run DFS from node 1 (or any arbitrary root)  
        dfs(1, -1, 0);  

        int q;  
        cin >> q;  

        while (q--) {  
            int u, v;  
            cin >> u >> v;  
            cout << find_middle_city(u, v) << '\n';  
        }  
    }  

    return 0;  
}