#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll; // Pair of (neighbor, weight)
typedef vector<pll> vpll; // Vector of pairs

#define fl(i, m, n) for (ll i = m; i < n; i++)

bool canReach(ll source, ll destination, ll max_weight, const vector<vpll> &graph) {
    vector<bool> visited(graph.size(), false);
    queue<ll> q;

    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        ll node = q.front();
        q.pop();

        if (node == destination) {
            return true;
        }

        for (const auto &edge : graph[node]) {
            ll neighbor = edge.first; // Neighbor node
            ll weight = edge.second; // Edge weight
            if (!visited[neighbor] && weight <= max_weight) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return false;
}

ll minStressLevel(ll N, const vector<tuple<ll, ll, ll>> &edges, ll source, ll destination) {
    vector<vpll> graph(N); // Adjacency list

    vector<ll> weights;
    for (const auto &edge : edges) {
        ll u = get<0>(edge);
        ll v = get<1>(edge);
        ll w = get<2>(edge);
        
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
        weights.push_back(w);
    }

    // Binary search over the weights
    ll left = 1, right = *max_element(weights.begin(), weights.end());
    ll result = -1;

    while (left <= right) {
        ll mid = (left + right) / 2;
        if (canReach(source, destination, mid, graph)) {
            result = mid;
            right = mid - 1; // Try to find a smaller maximum weight
        } else {
            left = mid + 1; // Increase the weight limit
        }
    }

    return result;
}

int main() {
    ll N = 5; // Number of nodes
    vector<tuple<ll, ll, ll>> edges = {
        {0, 1, 4},
        {0, 2, 2},
        {1, 2, 5},
        {1, 3, 1},
        {2, 3, 3},
        {3, 4, 6}
    };
    ll source = 0; // Source node
    ll destination = 4; // Destination node
    
    ll result = minStressLevel(N, edges, source, destination);
    
    cout << result << endl; // Output the minimum stress level or -1 if no path exists

    return 0;
}