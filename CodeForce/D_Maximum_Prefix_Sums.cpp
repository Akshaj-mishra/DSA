#include <iostream>
#include <string>
#include <vector>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<ll> a(n), b(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            cin >> b[i];

        bool ok = true;

        // b must be non-decreasing
        for (int i = 1; i < n; i++) {
            if (b[i] < b[i - 1]) {
                ok = false;
            }
        }

        vector<ll> ans(n);

        ll pref = 0;

        for (int i = 0; i < n && ok; i++) {

            if (i == 0 || b[i] > b[i - 1]) {

                ll need = b[i] - pref;

                if (s[i] == '1' && a[i] != need) {
                    ok = false;
                    break;
                }

                ans[i] = need;
                pref += need;

            } else {

                // b[i] == b[i-1]

                if (s[i] == '1') {

                    ans[i] = a[i];
                    pref += ans[i];

                    if (pref > b[i]) {
                        ok = false;
                    }

                } else {

                    ans[i] = -(ll)1e18;

                    pref += ans[i];
                }
            }
        }

        if (!ok) {
            cout << "No\n";
        } else {
            cout << "Yes\n";

            for (auto x : ans)
                cout << x << " ";

            cout << '\n';
        }
    }
}