#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<int> x, y, z, deg, cap, from, to;
vector<char> s;

int solve(const int& o, const int& k) {
    // cout << o << " " << k << endl;
    if (k > cap[o]) return -1;
    if (o == 1) return k;
    int node = from[o];

    if (s[node] == 'S') {
        int new_k = k * 2 - (y[node] == o);
        return solve(x[node], new_k);
    }
    int cap_x = cap[x[node]];
    int cap_y = cap[y[node]];
    int min_cap = min(cap_x, cap_y);

    if (k <= (min_cap << 1))
        return solve(k & 1 ? x[node] : y[node], k + 1 >> 1);

    int new_k = k - min_cap;
    if (cap_x == min_cap) return solve(y[node], new_k);
    return solve(x[node], new_k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt", "r", stdin);

    int n, m, qry;
    cin >> m >> n >> qry;

    s = vector<char>(n + 1);
    x = vector<int>(n + 1);
    y = vector<int>(n + 1);
    z = vector<int>(n + 1);
    deg = vector<int>(n + 1);

    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] >> x[i] >> y[i] >> z[i];
        mx = max<int>({mx, x[i], y[i], z[i]});
    }

    cap = vector<int>(mx + 1);
    from = vector<int>(mx + 1);
    to = vector<int>(mx + 1);

    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'S') {
            from[y[i]] = from[z[i]] = i;
            to[x[i]] = i;
            deg[i] = 1;
            continue;
        }
        from[z[i]] = i;
        to[x[i]] = to[y[i]] = i;
        deg[i] = 2;
    }

    cap[1] = m;
    queue<int> q;
    q.emplace(to[1]);
    deg[to[1]] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        int total_cap =
            s[node] == 'S' ? cap[x[node]] : cap[x[node]] + cap[y[node]];
        if (s[node] == 'S') {
            cap[y[node]] = total_cap + 1 >> 1;
            int l_node = to[y[node]];
            --deg[l_node];
            if (!deg[l_node]) q.push(l_node);

            cap[z[node]] = total_cap >> 1;
            int r_node = to[z[node]];
            --deg[r_node];
            if (!deg[r_node]) q.push(r_node);

            continue;
        }
        cap[z[node]] = total_cap;
        int c_node = to[z[node]];
        --deg[c_node];
        if (!deg[c_node]) q.push(c_node);
    };

    for (int i = 0; i < qry; ++i) {
        int x, y;
        cin >> x >> y;
        if (x > mx) {
            cout << "none" << endl;
            continue;
        }

        int ret = solve(x, y);
        if (ret == -1) {
            cout << "none" << endl;
            continue;
        }
        cout << ret << endl;
    }

    return 0;
}
