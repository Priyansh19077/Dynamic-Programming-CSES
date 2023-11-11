/* Priyansh Agarwal*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> val(n);
    vector<int> weight(n);
    
    for(int i = 0; i < n; i++){
        cin >> weight[i];
    }
    
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    // dp[i][j] = max value that can be attained from first i elements,
    // such that j weight is allowed to be used
    
    // base case
    // dp[0][k] = 0 for every k because we cannot add any more value
    // if 0 elements are left
    
    // dp[i][w] -> dp[i - 1][w], dp[i - 1][w - some value]
    
    for(int i = 1; i <= n; i++){
        for(int j = x; j >= 0; j--){
            // compute dp[i][j] here
            int w = weight[i - 1];
            int value = val[i - 1];
            
            // two choices
            //  - pick up ith element
            //  - skip ith element
            int pick = (j >= w ? dp[i - 1][j - w] + value : 0);
            int skip = dp[i - 1][j];
            // transition
            dp[i][j] = max(skip, pick); 
        }
    }
    
    // final subproblem
    cout << dp[n][x] << endl;
    return 0;
}