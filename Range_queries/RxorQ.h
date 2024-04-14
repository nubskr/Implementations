struct SegmentTree {
    #define ll long long
    /*Ranged xor queries(0 based indexed)

    Usage: SegmentTree stree(v)
    */
    vector<ll> tree;
    int n;

    SegmentTree(vector<ll>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr);
    }

    void build(vector<ll>& arr) {
        build(arr, 1, 0, n - 1);
    }

    void build(vector<ll>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        }
    }

    void update(int idx, ll val) {
        update(idx, val, 1, 0, n - 1);
    }

    void update(int idx, ll val, int node, int start, int end) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(idx, val, 2 * node, start, mid);
            } else {
                update(idx, val, 2 * node + 1, mid + 1, end);
            }
            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        }
    }

    ll query(int l, int r) {
        return query(l, r, 1, 0, n - 1);
    }

    ll query(int l, int r, int node, int start, int end) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        ll left_xor = query(l, r, 2 * node, start, mid);
        ll right_xor = query(l, r, 2 * node + 1, mid + 1, end);
        return left_xor ^ right_xor;
    }
};