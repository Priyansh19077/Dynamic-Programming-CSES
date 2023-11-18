/* Priyansh Agarwal*/
#include<bits/stdc++.h>

#define MOD 1000000007
 
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e6));
    // dp[i][j] = min steps to match the first i characters of first
    // string with first j characters of second string    

    // base case
    for(int i = 0; i <= n; i++){
        dp[i][0] = i; 
        // first string has i characters remaining
        // second string has finished
    }
    for(int j = 0; j <= m; j++){
        dp[0][j] = j;
        // second string has j characters remaining
        // first string has exhausted
    }
    
    for(int i = 1; i <= n; i++){ // O(n)
        for(int j = 1; j <= m; j++){ // O(m)
            char x = a[i - 1];
            char y = b[j - 1];
            
            // transition
            if(x == y){ // don't do anything
                dp[i][j] = dp[i - 1][j - 1];
            }else{ // replace character to match
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            
            // skip ith character or add one character after jth character
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            
            // skip jth character or add one character after ith character
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        }
    }
    
    // final subproblem
    cout << dp[n][m] << endl;
    return 0;
}
