#define ll long long
const ll INF = 1e18; // make sure the max distace from any two points don't get bigger than this
int n,m;
vector<vector<pair<ll,ll>>> graph; //{vertice,weight}

vector<ll> dijkstra(int source) {
    // returns the shortest path from source to all nodes
    // O((n + m)logn)
    vector<ll> dist(n+1, INF);
    dist[source] = 0;
    
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, source});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& edge : graph[u]) {
            ll v = edge.first;
            ll w = edge.second;
            if (dist[u] + w < dist[v]) { // might overflow if the weights are big enough!!!!
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}