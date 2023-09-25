#include <bits/stdc++.h>
using namespace std;

int recursion(int index, vector<int>& arr) {
    if (index == 0)
        return arr[index];
    if (index < 0)
        return 0;
    int pick = arr[index] + recursion(index - 2, arr);
    int notPick = 0 + recursion(index - 1, arr);
    return max(pick, notPick);
}

int memoization(int index, vector<int>& arr, vector<int>& dp) {
    if (index == 0)
        return arr[index];
    if (index < 0)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int pick = arr[index] + memoization(index - 2, arr, dp);
    int notPick = 0 + memoization(index - 1, arr, dp);
    return dp[index] = max(pick, notPick);
}

int tabulation(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    for (int i = 1; i < n; i++) {
        int pick = arr[i];
        if (i > 1)
            pick += dp[i - 2];
        int notPick = 0 + dp[i - 1];
        dp[i] = max(pick, notPick);
    }
    return dp[n - 1];
}


int optimizedTabulation(vector<int>& arr) {
    int n = arr.size();
    int previ = arr[0], prev2i, curi;
    for (int i = 1; i < n; i++) {
        int pick = arr[i];
        if (i > 1)
            pick += prev2i;
        int notPick = 0 + previ;
        curi = max(pick, notPick);
        prev2i = previ;
        previ = curi;
    }
    return previ;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        /*
        // Recursion method call
        cout << recursion(n - 1, arr) << endl;
        // Time complexity : O(2^n)
        // Space Complexity: O(2^n) stack space
        */

        /*
        // Memoization
        vector<int> dp(n + 1, -1);
        memoization(n - 1, arr, dp);
        cout << dp[n - 1] << endl;
        // Time complexity : O(n)
        // Space Complexity: O(n) stack space + O(n) dp array space
        */

        /*
        // Tabulation
        cout << tabulation(arr) << endl;
        // Time complexity : O(n)
        // Space Complexity: O(n) dp array space
        */

        // Optimized Tabulation
        cout << optimizedTabulation(arr) << endl;
        // Time complexity : O(n)
        // Space Complexity: O(1)


    }
    return 0;

}
