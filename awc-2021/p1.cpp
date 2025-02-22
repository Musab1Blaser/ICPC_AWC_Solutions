// TLEs on CodeDrills - not sure if error in code or platform


#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& dsu, int i){
    if (dsu[i] != i) dsu[i] = find(dsu, dsu[i]);
    return dsu[i];
}

int join(vector<int>& dsu, vector<int>& sz, vector<int>& bipartite, int i, int j){
    if (find(dsu, i) != find(dsu, j)){
        if (sz[dsu[i]] > sz[dsu[j]]){
            bipartite[dsu[i]] &= bipartite[dsu[j]];
            sz[dsu[i]] += sz[dsu[j]];
            dsu[dsu[j]] = dsu[i];
        } else {
            bipartite[dsu[j]] &= bipartite[dsu[i]];
            sz[dsu[j]] += sz[dsu[i]];
            dsu[dsu[i]] = dsu[j];
        }
        return -1;
    }
    return 0;
}

int color(unordered_map<int, vector<int>>& graph, vector<int>& colors, vector<int>& bipartite, int s, int c, vector<int>& dsu){
    queue<int> frontier;
    set<int> visited;
    frontier.push(s);
    visited.insert(s);
    colors[s] = c;
    while (frontier.size()){
        int v = frontier.front();
        frontier.pop();
        for (int u : graph[v]){
            if (visited.count(u)){
                if (colors[u] == colors[v]) {
                    bipartite[find(dsu, v)] = 0;
                    frontier = {};
                    break;
                }
            }
            else {
                colors[u] = 3 - colors[v];
                frontier.push(u);
                visited.insert(u);
            }
        }
    }
    return bipartite[find(dsu, s)];
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < n; i++) graph[i] = {};

    vector<int> dsu (n);
    vector<int> sz (n, 1);
    vector<int> colors (n, 0);
    vector<int> bipartite (n, 1);

    for (int i = 0; i < n; i++) dsu[i] = i;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[--u].push_back(--v);
        graph[v].push_back(u);
        join(dsu, sz, bipartite, u, v);
    } 

    long long non_bi_components = 0;
    long long bi_components = 0;
    for (int i = 0; i < n; i++)
        if (colors[i] == 0) {
            int tmp = color(graph, colors, bipartite, i, 1, dsu); // dsu for setting bipartite of dsu[i] to 0 - initially set to 1
            bi_components += tmp;
            non_bi_components += 1-tmp;
        }    

    for (int i = 0; i < q; i++){
        int c;
        cin >> c;
        if (c == 1) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            int comp1 = find(dsu, u);
            int comp2 = find(dsu, v);
            if (comp1 == comp2){
                if (bipartite[comp1] && colors[u] == colors[v]) {
                    bipartite[comp1] = 0;
                    bi_components--;
                    non_bi_components++;
                } 
            }
            else if (bipartite[comp1] && bipartite[comp2]){
                if (sz[comp1] > sz[comp2])
                    color(graph, colors, bipartite, v, 3 - colors[u], dsu);
                else
                    color(graph, colors, bipartite, u, 3 - colors[v], dsu);
                bi_components--;
            } else if (bipartite[comp1] + bipartite[comp2] == 1){
                bi_components--;
            } else {
                non_bi_components--;
            }
            graph[u].push_back(v);
            graph[v].push_back(u);

            join(dsu, sz, bipartite, u, v);
        } else {
            int k;
            cin >> k;
            long long ans = non_bi_components + bi_components*(1LL << k);
            cout << ans << endl;
        }
    } 
}