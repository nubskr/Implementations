const int N = 1e5 + 10;
int vis[N];

// for grid shit
bool check(int i,int j){
	return (i>=0 && i<n && j>=0 && j<m);
}

void bfs(int source){
	queue<int> q;
	q.push(source);
	int now = source;
	while(!q.empty()){
		vis[now] = 1;
		now = q.front();
		// put all the adjacent shit inside queue
		q.pop();
		for(auto i: adj[now]){
			if(!vis[i]){
				q.push(i);
			}
		}
	}
}