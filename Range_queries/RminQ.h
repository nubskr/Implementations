
struct RMQ {
    #define ll long long
    /*Range minimum query(0 based indexing)
    
    Usage: RMQ stree(v)
    */
    vector<ll> tree;
    int n;

    RMQ(vector<ll>& arr) {
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
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
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
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    ll query(int l, int r) {
        return query(l, r, 1, 0, n - 1);
    }

    ll query(int l, int r, int node, int start, int end) {
        if (r < start || end < l) {
            return LLONG_MAX; // For long long
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        ll left_min = query(l, r, 2 * node, start, mid);
        ll right_min = query(l, r, 2 * node + 1, mid + 1, end);
        return min(left_min, right_min);
    }
};