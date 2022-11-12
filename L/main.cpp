#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <vector>

using namespace std;
const int MN = -1e9;
int n, m;
vector<pair<int, int>> x_list;
vector<vector<char>> a;

struct Trie {
    struct Node {
        Node() {}

        shared_ptr<Node> addChild(const pair<int, int>& p, const int& x) {
            auto itr = children.find(x);
            if (itr == children.end()) {
                return children[x] = make_shared<Node>();
            }
            return itr->second;
        }

        int solve(const int& lst, int& mx, vector<pair<int, int>>& mx_list) {
            if (sz == 1) {
                // cout << pos.first << " " << pos.second << " " << depth <<
                // endl;
                if (lst > mx) {
                    mx = lst;
                    mx_list.clear();
                }
                if (lst == mx) mx_list.emplace_back(pos);
                return lst;
            }
            int ret = 0;
            int max_key = children.rbegin()->first;
            int last_key = 0;
            for (auto& [k, v] : children) {
                ret += v->solve(k == max_key ? last_key : k, mx, mx_list);
                last_key = k;
            }
            return ret;
        }

        map<int, shared_ptr<Node>> children;
        int sz = 0;
        pair<int, int> pos;
    };

    Trie() { root = make_shared<Node>(); }

    void addVector(const pair<int, int>& p, const vector<int>& s) {
        auto cur = root;
        for (const int& c : s) {
            cur = cur->addChild(p, c);
            ++cur->sz;
            cur->pos = p;
        }
        ++sz;
    }

    pair<double, pair<int, vector<pair<int, int>>>> solve() {
        int mx = 0;
        vector<pair<int, int>> mx_list;
        int sum = root->solve(0, mx, mx_list);
        return {(double)sum / sz, {mx, mx_list}};
    }

    int sz = 0;
    shared_ptr<Node> root;
};

unique_ptr<Trie> tree;

void read() {
    //freopen("input.txt", "r", stdin);

    cin >> m >> n;

    a = vector<vector<char>>(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j]; 
            if (a[i][j] == 'X') 
                x_list.emplace_back(i, j);
        }
    }

    tree = make_unique<Trie>();
}

template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U>& l, const std::pair<T, U>& r) {
    return {l.first + r.first, l.second + r.second};
}
template <typename T, typename U>
std::pair<T, U> operator-(const std::pair<T, U>& l, const std::pair<T, U>& r) {
    return {l.first - r.first, l.second - r.second};
}

const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const vector<pair<int, int>> corner = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

int get_step(const pair<int, int>& diff) {
    return max(abs(diff.first), abs(diff.second));
}

int get_edge(const pair<int, int>& diff) {
    int step = get_step(diff);
    if (step == 0) return 3;
    vector<bool> conditions = {diff.first == -step && diff.second > -step,
                               diff.first > -step && diff.second == step,
                               diff.first == step && diff.second < step,
                               diff.first < step && diff.second == -step};
    for (int i = 0; i < 4; ++i)
        if (conditions[i]) return i;
    return 5;
}

int get_index(const pair<int, int>& p, const pair<int, int>& x_p) {
    auto diff = x_p - p;
    if (diff.first == 0 && diff.second == 0) 
        return 0;

    int step = get_step(diff);
    int ret = (step * 2 - 1) * (step * 2 - 1) - 1;

    int edge = get_edge(diff);

    if (edge) ret += (step * 2) * edge;

    auto corn = corner[edge];
    pair<int, int> rem = {diff.first - step * corn.first,
                          diff.second - step * corn.second};

    ret += abs(rem.first) + abs(rem.second);
    return ret;
}

void build() {
    vector<int> s;
    for (int pos_x = 0; pos_x < n; ++pos_x)
        for (int pos_y = 0; pos_y < m; ++pos_y) {
            s.clear();

            pair<int, int> pos = {pos_x, pos_y};

            for (auto x_p : x_list) {
                s.emplace_back(get_index(pos, x_p)); 
            }
            sort(s.begin(), s.end());

            //cout <<"DEBUG" << endl;
            //cout << pos.first << " " << pos.second << endl;
            //for (auto c : s) cout << c << " ";
            //cout << endl;

            tree->addVector(pos, s);
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    read();

    build();

    auto res = tree->solve();
    cout << setprecision(6) << fixed;
    cout << res.first << endl;
    cout << res.second.first << endl;

    auto& mx_list = res.second.second;
    for (auto& p : mx_list) p.first = n - p.first;

    sort(mx_list.begin(), mx_list.end());
    int cnt = 0;
    for (auto& p : mx_list) {
        if (cnt) cout << " ";
        ++cnt;
        cout << "(" << p.second + 1 << "," << p.first << ")";
    }
    cout << endl;
}
