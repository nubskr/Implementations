// range minimum query
#include <bits/stdc++.h>
using namespace std;
#define vi vector <int>
#define pi pair <int, int>
typedef long long ll;
vector <int> tree, a;
 
void build (int v, int start, int end)
{
    if (start == end) tree[v] = a[start]; 
    else
    {
        int mid = (start + end)/2;
        build(2*v, start, mid);
        build(2*v + 1, mid + 1, end);
        tree[v] = min(tree[2*v], tree[2*v + 1]);
    }
}
 
int search (int v, int start, int end, int l, int r)
{
    if (l > end || r < start) return (1 << 30);
    
    if (l <= start && r >= end) return tree[v];
    int mid = (start + end)/2;
    return min(search(2*v, start, mid, l, r), search(2*v + 1, mid + 1, end, l, r));
}
 
void update (int v, int start, int end, int index, int x)
{
    if (start == end) tree[v] = x;
    else
    {
        int mid = (start + end)/2;
        if (index <= mid) update(2*v, start, mid, index, x);
        else update(2*v + 1, mid + 1, end, index, x);
        tree[v] = min(tree[2*v], tree[2*v + 1]);
    }
}
 
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    a.resize(n + 1);
    tree.resize(4*n);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
        
    build(1, 1, n);
    
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> y >> z;
        x = 2;
        if (x == 1) update(1, 1, n, y, z);
        else cout << search(1, 1, n, y, z) << endl;
    }
}