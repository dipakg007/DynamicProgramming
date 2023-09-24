#include <bits/stdc++.h>
using namespace std;

int recursion(int index, vector<int>& arr) {
    if (index == 0)
        return 0;
    int right = INT_MAX;
    int left = recursion(index - 1, arr) + abs(arr[index] - arr[index - 1]);
    if (index > 1)
        right = recursion(index - 2, arr) + abs(arr[index] - arr[index - 2]);
    return min(left, right);
}

int memoization(int index, vector<int>& arr, vector<int>& dp) {
    if (index == 0)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int right = INT_MAX;
    int left = memoization(index - 1, arr, dp) + abs(arr[index] - arr[index - 1]);
    if (index > 1)
        right = memoization(index - 2, arr, dp) + abs(arr[index] - arr[index - 2]);
    return dp[index] = min(left, right);
}

int tabulation(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 0);
    for (int i = 1; i < n; i++) {
        int firstStep = dp[i - 1] + abs(arr[i] - arr[i - 1]);
        int secondStep = INT_MAX;
        if (i > 1)
            secondStep = dp[i - 2] + abs(arr[i] - arr[i - 2]);
        dp[i] = min(firstStep, secondStep);
    }
    return dp[n - 1];
}

int optimizedTabulation(vector<int>& arr) {
    int n = arr.size();
    int previ = 0, prev2i = 0, curi;
    for (int i = 1; i < n; i++) {
        int firstStep = previ + abs(arr[i] - arr[i - 1]);
        int secondStep = INT_MAX;
        if (i > 1)
            secondStep = prev2i + abs(arr[i] - arr[i - 2]);
        curi = min(firstStep, secondStep);
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

    /*
        To test use this imput format
        1
        6
        30 10 60 10 60 50
        Expected output: 40
    */

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
        cout << tabulation(arr);
        // Time complexity : O(n)
        // Space Complexity: O(n) dp array space
        */


        // Optimized Tabulation
        cout << optimizedTabulation(arr);
        // Time complexity : O(n)
        // Space Complexity: O(1)

    }
    return 0;

}
