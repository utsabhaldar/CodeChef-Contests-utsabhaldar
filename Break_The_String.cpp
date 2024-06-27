#include <bits/stdc++.h>
using namespace std;
#define int       long long
#define ff        first
#define ss        second
#define pb        push_back
#define all(x)    (x).begin(), (x).end()
#define pii       pair<int,int>
#define vi        vector<int>
#define vii       vector<vector<int>>
#define vs        vector<string>
#define mp        map<int,int>
#define ump       unordered_map<int,int>
#define ust       unordered_set<int>
#define st        set<int>
#define nx        cout<<"\n"
#define loop      (int i = 0; i < n; i++)
#define lop       (int j = 0; j < n; j++)
#define bits(x)   (int)__builtin_popcount(x)
const int mod = 1e9 + 7;
bool f=true;
#define no cout<<"No"<<endl
#define ys cout<<"Yes"<<endl
void yes(bool t) { cout<<(t ? "YES" : "NO")<<endl; }

/**********SOLUTION**********/

vi fn(string s) {
    int n = s.size();
    vi z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t; cin >> t; while (t--){
        string s;
        cin >> s;
        int n = s.size();
        if (n & 1) {
            cout << 0 << "\n";
            continue;
        }

        vi z1 = fn(s);
        vi r;

        for loop {
            int ln = i;
            if (ln <= z1[i]) {
                r.pb(i);
            }
        }

        reverse(all(s));
        vi z2 = fn(s);
        vi sr;

        for loop {
            int ln = i;
            if (ln <= z2[i]) {
                sr.pb(n - i - 1);
            }
        }

        ust s_set(all(sr));
        int ans = 0;

        for (int i : r) {
            int end = 2 * i;
            int size = (n - 1) - (end) + 1;
            size = size / 2;
            int coord = (n - 1) - size;
            if (s_set.count(coord)) {
                ans += 1;
            }
        }

        if(f) cout << ans << "\n";
    } 
    return 0;
}