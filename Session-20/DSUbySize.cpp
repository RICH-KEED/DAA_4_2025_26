#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n + 1, 1);
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unionBySize(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            if (size[root_i] < size[root_j])
                swap(root_i, root_j);
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
        }
    }
};

int main() {
    int V = 5;
    
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {3, 4}, {1, 2}};

    DSU dsu(V);
    bool cycleFound = false;

    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;

        int root_u = dsu.find(u);
        int root_v = dsu.find(v);

        if (root_u == root_v) {
            cout << "Cycle detected adding edge " << u << " - " << v << endl;
            cycleFound = true;
        } else {
            dsu.unionBySize(u, v);
        }
    }

    if (!cycleFound) {
        cout << "No cycle found." << endl;
    }

    return 0;
}
