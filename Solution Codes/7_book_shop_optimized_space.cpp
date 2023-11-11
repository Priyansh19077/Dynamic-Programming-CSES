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
    
    vector<int> prev(x + 1, 0);
    // dp[i][j] = max value that can be attained from i elements,
    // such that j weight is allowed to be used
    
    // base case
    // dp[0][k] = 0 for every k because we cannot add any more value
    // if 0 elements are left
    
    for(int i = 1; i <= n; i++){
        vector<int> curr(x + 1);
        // dp[i][j] = curr[j]
        // dp[i - 1][j] = prev[j]
        for(int j = 0; j <= x; j++){
            // compute dp[i][j] here
            int w = weight[i - 1];
            int value = val[i - 1];
            
            // two choices
            //  - pick up ith element
            //  - skip ith element
            int pick = (j >= w ? prev[j - w] + value : 0); // dp[i-1][j-w]
            int skip = prev[j]; // dp[i - 1][j]
            // transition
            // dp[i][j]
            curr[j] = max(skip, pick); 
        }
        prev = curr;
    }
    
    // final subproblem
    cout << prev[x] << endl;
    return 0;
}