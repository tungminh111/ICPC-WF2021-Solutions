#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1067;
int n, m, k;

bool is_valid(pair<int, int> p) {
    return p.first >= 0 && p.first < n && p.second >= 0 && p.second < m;
}

struct Direction{
    Direction() {}
    Direction(int x, int y): x(x), y(y) {}

    void add_molecules(const pair<int, int>& p) {
        molecules.emplace(p);
    }

    bool has_molecule(const pair<int, int>& p) {
        return molecules.find(p) != molecules.end();
    }

    pair<int, int> sub(const pair<int, int>& p) {
        return {p.first - x, p.second - y};
    }

    void rev() {
        set<pair<int, int>> new_molecules;
        for(auto& m: molecules) {
            pair<int, int> new_m = {m.first - x, m.second - y};
            new_molecules.emplace(m.first - x, m.second - y);
        }
        x = -x;
        y = -y;
        molecules = new_molecules;
    }

    int x, y;
    set<pair<int, int>> molecules;
};
vector<Direction> dir;

void read() {
    //freopen("input.txt", "r", stdin);

    cin >> m >> n >> k;
    dir = vector<Direction>(k);
    for(int i = 0; i < k; ++i) {
        cin >> dir[i].y >> dir[i].x;
        int b;
        cin >> b;
        for(int j = 0; j < b; ++j) {
            int x, y;
            cin >> x >> y;
            dir[i].add_molecules({y - 1, x - 1});
        }
    }
}

set<pair<int, int>> solve(queue<pair<int, int>>& q) {
    set<pair<int, int>> filled;
    auto is_filled = [&filled](const pair<int, int>& p) {
        return filled.find(p) != filled.end();
    };

    for(auto& d: dir) {
        for(auto& m: d.molecules) if (is_valid(m)) {
            q.emplace(m);
            filled.emplace(m);
        }
    }

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        for(auto& d: dir) {
            auto new_p = d.sub(p);
            if (!is_valid(new_p)) continue;
            if (!d.has_molecule(p) && !is_filled(new_p)) {
                filled.emplace(new_p);
                q.emplace(new_p);
            }
        }
    }

    return filled;
}

void rev() {
    for(auto& d: dir) d.rev();
}

void print(const set<pair<int, int>>& filled, const vector<int>& vals) {
    vector<vector<char>> res(n, vector<char>(m, vals[0]));

    for(auto& p: filled) {
        res[p.first][p.second] = vals[1];
    }

    for(auto& r: res) {
        for(auto& c: r) cout << c;
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    read();

    queue<pair<int, int>> empty_q;
    print(solve(empty_q), {'.', '#'});
    cout << endl;

    rev();

    queue<pair<int, int>> outside;
    for(int i = -n; i < 2 * n; ++i)
        for(int j = -m; j < 2 * m; ++j)
            if (!is_valid({i, j})) outside.emplace(i, j);

    print(solve(outside), {'#', '.'});

    return 0;
}
