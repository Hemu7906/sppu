#include <bits/stdc++.h>
using namespace std;

int func(int ind, int w, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    if (ind < 0) return 0;

    if (dp[ind][w] != -1) {
        return dp[ind][w];
    }

    int ans;
    if (wt[ind] > w) {
        ans = func(ind - 1, w, wt, val, dp);
    } else {
        ans = max(val[ind] + func(ind - 1, w - wt[ind], wt, val, dp), func(ind - 1, w, wt, val, dp));
    }

    return dp[ind][w] = ans;
}

int main() {
    int n;
    int w;
    cin >> n;
    vector<int> val(n), wt(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i] >> wt[i];
    }
    cin >> w;

    vector<vector<int>> dp(n, vector<int>(w + 1, -1));

    cout << "The Maximum value of items the thief can steal is " << func(n - 1, w, wt, val, dp);

    return 0;
}
