#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int u, v;
    long long w;
};

int main() {
    int n, e;
    cin >> n >> e;

    vector<Edge> edge_list;
    for (int i = 0; i < e; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edge_list.push_back({u, v, w});
    }

    int s;
    cin >> s;

    vector<long long> dist(n + 1, INF);
    dist[s] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto &edge : edge_list) {
            int u = edge.u;
            int v = edge.v;
            long long w = edge.w;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    
    bool negative_cycle = false;
    for (auto &edge : edge_list) {
        int u = edge.u;
        int v = edge.v;
        long long w = edge.w;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            negative_cycle = true;
            break;
        }
    }

    if (negative_cycle) {
        cout << "Negative Cycle Detected" << endl;
    } else {
        int t;
        cin >> t;
        while (t--) {
            int d;
            cin >> d;
            if (dist[d] == INF) {
                cout << "Not Possible" << endl;
            } else {
                cout << dist[d] << endl;
            }
        }
    }

    return 0;
}