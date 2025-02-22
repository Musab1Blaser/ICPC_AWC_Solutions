#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int find(vector<int>& dsu, int i) {
    if (dsu[i] != i) {
        dsu[i] = find(dsu, dsu[i]);
    }
    return dsu[i];
}

bool join(vector<int>& dsu, vector<int>& sz, int i, int j) {
    int a = find(dsu, i);
    int b = find(dsu, j);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        dsu[b] = a;
        return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> c(n, vector<int>(n));
        bool valid = true;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                cin >> c[i][j];
            }
            if (c[i][0] != 1) valid = false;
        }
        
        if (!valid) {
            cout << "-1\n";
            continue;
        }
        
        vector<vector<int>> dsus(n);
        vector<vector<int>> szs(n);
        vector<int> ccs(n, 1);
        set<pair<int, int>> edges, non_edges;
        
        for (int j = 0; j < n; j++) {
            dsus[j].resize(n - j);
            szs[j].resize(n - j, 1);
            for (int i = 0; i < n - j; i++) {
                dsus[j][i] = i;
            }
        }
        
        for (int k = 1; k < n; k++) {
            for (int i = 0; i < n - k; i++) {
                ccs[i]++;
                for (int j = 0; j < k - 1; j++) {
                    if (find(dsus[i + 1], j) == find(dsus[i + 1], k - 1)) {
                        ccs[i] -= join(dsus[i], szs[i], j + 1, k);
                    }
                }
                
                if (c[i][k] != ccs[i]) {
                    ccs[i] -= join(dsus[i], szs[i], 0, k);
                    edges.insert({i + 1, i + k + 1});
                } else if (find(dsus[i], 0) != find(dsus[i], k)) {
                    non_edges.insert({i + 1, i + k + 1});
                }
                
                if (c[i][k] != ccs[i]) valid = false;
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (edges.size() < (size_t)m && non_edges.find({j + 1, i + 1}) == non_edges.end()) {
                    edges.insert({j + 1, i + 1});
                }
            }
        }
        
        if (!valid || edges.size() != (size_t)m) {
            cout << "-1\n";
        } else {
            vector<pair<int, int>> edge_list(edges.begin(), edges.end());
            sort(edge_list.begin(), edge_list.end());
            for (auto& edge : edge_list) {
                cout << edge.first << " " << edge.second << "\n";
            }
        }
    }
    return 0;
}