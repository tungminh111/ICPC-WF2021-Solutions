#include <math.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
#include <assert.h>

using namespace std;
#define double long double

const double eps = 1e-8;
int n, m;
vector<vector<pair<double, double>>> vertices;
vector<vector<double>> flights;

double dis(const pair<double, double>& p1, const pair<double, double>& p2) {
    pair<double, double> diff = {p2.first - p1.first, p2.second - p1.second};
    return sqrt(diff.first * diff.first + diff.second * diff.second);
}

pair<double, double> get_flat_intersect(
    const pair<double, double>& start_flat_p,
    const pair<double, double>& end_flat_p, const pair<double, double>& v) {
    assert(start_flat_p.first != end_flat_p.first);
    if (start_flat_p.second == end_flat_p.second) {
        return {v.first, start_flat_p.second};
    }

    pair<double, double> flat_p = {end_flat_p.first - start_flat_p.first,
                                   end_flat_p.second - start_flat_p.second};
    double slope_p = flat_p.second / flat_p.first;
    pair<double, double> flat_p_eq = {
        slope_p, start_flat_p.second - start_flat_p.first * slope_p};

    pair<double, double> flat_v = {slope_p, -1};
    double slope_v = flat_v.second / flat_v.first;
    pair<double, double> flat_v_eq = {slope_v, v.second - v.first * slope_v};

    double intersect_x = -(flat_v_eq.second - flat_p_eq.second) /
                         (flat_v_eq.first - flat_p_eq.first);
    pair<double, double> flat_intersect = {
        intersect_x, flat_v_eq.first * intersect_x + flat_v_eq.second};
    return flat_intersect;
}

double get_min_o(const vector<double>& f, const pair<double, double>& v) {
    if (f[0] == f[3])
        return get_min_o({f[1], f[0], f[2], f[4], f[3], f[5]},
                         {v.second, v.first});

    pair<double, double> start_flat_p = {f[0], f[1]};
    pair<double, double> end_flat_p = {f[3], f[4]};

    auto flat_intersect = get_flat_intersect(start_flat_p, end_flat_p, v);

    if (max(dis(flat_intersect, end_flat_p),
            dis(flat_intersect, start_flat_p)) > dis(start_flat_p, end_flat_p))
        return -1;

    double slope_z = (f[5] - f[2]) / (f[3] - f[0]);
    double intersect_z = f[2] + (flat_intersect.first - f[0]) * slope_z;

    double rad_o = atan(dis(v, flat_intersect) / intersect_z);
    return 180 / M_PI * rad_o;
}

double solve() {
    double ret = 0;
    for (int i = 0; i < n; ++i) {
        double ret_i = 91;
        for (const vector<double>& f : flights) {
            double ret_i_j = 0;

            for (const pair<int, int>& v : vertices[i]) {
                double min_o = get_min_o(f, v);
                if (min_o == -1) {
                    ret_i_j = -1;
                    break;
                }
                ret_i_j = max(ret_i_j, min_o);
            }

            if (ret_i_j == -1) {
                continue;
            }
            ret_i = min(ret_i, ret_i_j);
        }
        if (ret_i == 91) return -1;
        ret = max(ret, ret_i);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt", "r", stdin);

    cin >> n >> m;
    vertices = vector<vector<pair<double, double>>>(n);
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        vertices[i] = vector<pair<double, double>>(b);
        for (int j = 0; j < b; ++j) {
            cin >> vertices[i][j].first >> vertices[i][j].second;
        }
    }

    flights = vector<vector<double>>(m, vector<double>(6));
    for (int i = 0; i < m; ++i) {
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2] >>
            flights[i][3] >> flights[i][4] >> flights[i][5];
    }

    cout << setprecision(9) << fixed;
    double ret = solve();
    if (ret == -1) {
        cout << "impossible" << endl;
        return 0;
    }
    cout << ret << endl;
    return 0;
}
