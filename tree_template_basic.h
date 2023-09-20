const int N = 2e5 + 5;
vector<vector<int>> adj;
bool vis[N];
int n;
// usage: init()
void addedge(int a, int b){
	--a,--b;
	adj[a].push_back(b);
	adj[b].push_back(a);
}
 
void init(int m = n-1){
	// m = no. of edges
	for (int i = 0; i < n+1; ++i)
	{
		vis[i] = 0;
	}
	adj.resize(n);
	adj.clear();
	for (int i = 1; i <= m; ++i)
	{
		int a,b;
		cin >> a >> b;
		addedge(a,b);
	}
}