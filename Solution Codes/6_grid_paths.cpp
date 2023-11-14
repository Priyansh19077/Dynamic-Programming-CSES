/* Priyansh Agarwal*/
#include<bits/stdc++.h>

#define MOD 1000000007
 
using namespace std;

int main(){
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    vector<vector<int>> dp(n, vector<int>(n));
    // dp[i][j] = number of ways to go from (i, j) to (n-1, n-1)
    
    // base case
    if(arr[n - 1][n - 1] == '.')
        dp[n - 1][n - 1] = 1;
    else
        dp[n - 1][n - 1] = 0;
    
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == n - 1)
                continue;
            if (arr[i][j] == '*')
                dp[i][j] = 0;
            else
            {
                int ans1 = i < n - 1 ? dp[i + 1][j] : 0;
                int ans2 = j < n - 1 ? dp[i][j + 1] : 0;
                // transition
                dp[i][j] = (ans1 + ans2) % MOD;
            }
        }
    }
    
    //final subproblem
    cout << dp[0][0] << endl;    
    return 0; 
}
