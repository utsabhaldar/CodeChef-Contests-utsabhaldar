#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, X, Y;
        cin >> N >> X >> Y;
        
        int ans = 0;
        for (int type2 = 0; type2 * 2 <= N; ++type2) {
            int type1 = N - type2 * 2;
            int current_money = type1 * X + type2 * Y;
            if (current_money > ans) {
                ans = current_money;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
