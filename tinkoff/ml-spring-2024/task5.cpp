#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    
    vector<vector<char>> a(n, vector<char>(3));
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }
    
    vector<vector<ll>> dp(n, vector<ll>(3, 0));
    
    for(ll j = 0; j < 3; ++j) {
        if(a[0][j] == 'W') {
            dp[0][j] = -1;
        } else if (a[0][j] == 'C') {
            dp[0][j] = 1;
        }
    }
    
    for(ll i = 1; i < n; ++i) {
        for(ll j = 0; j < 3; ++j) {
            if(a[i][j] == 'W') {
                dp[i][j] = -1;
                continue;
            }
            for(ll k = -1; k <= 1; ++k) {
                if(j + k >= 0 && j + k < 3 && dp[i - 1][j + k] != -1) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + k] + (a[i][j] == 'C'));
                }
            }
            if(dp[i][j] == 0) {
                dp[i][j] = -1;
            }
        }
    }
    
    ll ans = -1;
    for (ll j = 0; j < 3; ++j) {
        ans = max(ans, dp[n - 1][j]);
    }
    
    cout << ans << endl;

    return 0;
}