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

void solve()
{
     int n;
    cin >> n;
    vi k(n);
    vii l(n);
    for loop cin >> k[i];
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        l[a - 1].pb(b - 1);
        l[b - 1].pb(a - 1);
    }
    int mn = min_element(all(k)) - k.begin();
    vector<bool> vst(n, false);
    vi order;
    deque<int> bfs;
    order.pb(mn);
    vst[mn] = true;
    bfs.pb(mn);
    while (!bfs.empty()) {
        int node = bfs.front();
        bfs.pop_front();
        for (int nb : l[node]) {
            if (!vst[nb]) {
                vst[nb] = true;
                order.pb(nb);
                bfs.pb(nb);
            }
        }
    }
    vi ans(order.begin() + 1, order.end());
    reverse(ans.begin(), ans.end());
    for (int &i : ans) {
        i += 1;
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        if (i > 0) cout << ' ';
        if(f) cout << ans[i];
    }
    nx;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t; cin >> t; while (t--) solve(); return 0;
}