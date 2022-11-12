#include <bits/stdc++.h>

using namespace std;
const int MN = -1e8;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt", "r", stdin);

    long long n, m;
    cin >> n >> m;
    for(int i = 2; i <= m; ++i) {
        bool ran = false;
        for(int j = i - 1; j; j--) {
            long long mul = 1;
            long long jj = i - j;
            long long sum = 0;
            bool complete = true;
            for(int k = 0; k < n - 1; ++k) {
                if (m / i < mul) {
                    complete = false;
                    break;
                }
                mul *= i;
            }
            for(int k = 0; k < n; ++k) {
                sum += mul;
                if (sum > m) {
                    complete = false;
                    break;
                }
                if (k < n - 1) {
                    mul /= i;
                    mul *= jj;
                }
            }
            //cout << i << " " << j << " " << sum << endl;
            if (!complete)
                break;
            ran = true;
            if (!(m % sum)) {
                cout << j << " " << i << endl;
                return 0;
            }
        }
        if (!ran)
            break;
    }
    cout << "impossible" << endl;
    return 0;
}
