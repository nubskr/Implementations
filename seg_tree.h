// RMQ
#include <bits/stdc++.h>
using namespace std;

vector <int> stree, a;

int merge(int x,int y){
    return min(x,y);
}

void build(int v, int start, int end)
{
    if (start == end) stree[v] = a[start]; 
    else
    {
        int mid = (start + end)/2;
        build(2*v, start, mid);
        build(2*v + 1, mid + 1, end);
        stree[v] = merge(stree[2*v],stree[2*v + 1]);
    }
}
 
int query(int v, int start, int end, int l, int r)
{
    // PAY ATTENTION HERE
    if (l > end || r < start) return (1 << 30);
    
    if (l <= start && r >= end) return stree[v];
    int mid = (start + end)/2;
    return merge(query(2*v, start, mid, l, r), query(2*v + 1, mid + 1, end, l, r));
}
 
void update(int v, int start, int end, int index, int x)
{
    if (start == end) stree[v] = x;
    else
    {
        int mid = (start + end)/2;
        if (index <= mid) update(2*v, start, mid, index, x);
        else update(2*v + 1, mid + 1, end, index, x);
        stree[v] = merge(stree[2*v],stree[2*v + 1]);
    }
}
 
int main() 
{
    int n, m;
    cin >> n >> m;
    a.resize(n + 1);
    stree.resize(4*n);
    // a must be 1 indexed
    for (int i = 1; i <= n; i++)
        cin >> a[i];
        
    build(1, 1, n);
    
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> y >> z;
        x = 2;
        if (x == 1) update(1, 1, n, y, z);
        else cout << query(1, 1, n, y, z) << endl;
    }
}
