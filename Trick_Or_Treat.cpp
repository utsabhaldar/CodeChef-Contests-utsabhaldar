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
#define loop      (int i = 0; i < N; i++)
#define lop       (int j = 0; j < N; j++)
#define bits(x)   (int)__builtin_popcount(x)
const int mod = 1e9 + 7;
#define no cout<<"No"<<endl
#define ys cout<<"Yes"<<endl
void yes(bool t) { cout<<(t ? "YES" : "NO")<<endl; }

/**********SOLUTION**********/

void solve()
{
    int N, M;
    cin >> N >> M;
    vi A(N), B(N);
    ump a, b;
    
    for loop {
        cin >> A[i];
        a[A[i] % M]++;
    }
    
    for loop {
        cin >> B[i];
        b[B[i] % M]++;
    }
    
    int cnt = 0;
    
    for (const auto& f : a) {
        int tmp = (M - f.first) % M;
        if (b.find(tmp) != b.end()) {
            cnt += f.second * b[tmp];
        }
    }
    
    cout << cnt << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t; cin >> t; while (t--) solve(); return 0;
}