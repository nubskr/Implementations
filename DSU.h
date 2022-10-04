struct DSU
{
    /*
    initiate using: DSU dsu(n);
    here n = no. of nodes
    */
    vector<int> siz;
    vector<int> parent;
    void init(int v) {
        parent[v] = v;
        siz[v] = 1;
    }
    int Find(int v) {
        if (v == parent[v])
            return v;
        return Find(parent[v]);
    }
    void Unite(int a, int b) {
        a = Find(a);
        b = Find(b);
        if (a != b) {
            if (siz[a] < siz[b])
                swap(a, b);
            parent[b] = a;
            siz[a] += siz[b];
        }
    }
    DSU (int n)
    {
        parent.resize(n);
        siz.resize(n);
        for (int i = 0; i<n; i++) init(i);
    }
};
