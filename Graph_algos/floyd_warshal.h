const int N = 1000;
int n,m;
const long long INF = 1e18;
int min_dist[N][N];// Initialize with INF

/*
when you take inputs, make sure to update the min_dis[u][v] = min(min_dis[u][v],w)
*/ 

void floyd_warshall(){
    // shortest path b/w any two nodes 
    // O(n^2)
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long new_dist = min_dist[i][k] + min_dist[k][j];
                if (new_dist < min_dist[i][j]) {
                    min_dist[i][j] = min_dist[j][i] = new_dist;
                }
            }
        }
    }
}