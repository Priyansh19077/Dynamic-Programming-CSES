/* Priyansh Agarwal*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int maxSum = 1e5;
    vector<vector<bool>> dp(n + 1, vector<bool>(maxSum + 1, false));
    // dp[i][j] = true or false based on whether or not it is possible
    // to generate a subset with sum = j in the first i elements
    
    // base case, if there are no elements, the only sum possible
    // to generate = 0
    dp[0][0] = true;
    
    for(int i = 1; i <= n; i++){
        int val = arr[i - 1];
        for(int j = 0; j <= maxSum; j++){
            // find dp[i][j] here
            dp[i][j] = dp[i - 1][j];
            if(j - val >= 0){
                dp[i][j] = dp[i][j] || dp[i - 1][j - val];
            }
        }
    }
    int total = 0;
    for(int i = 1; i <= maxSum; i++){
        if(dp[n][i]){
            total++;
        }
    }
    cout << total << endl;
    for(int i = 1; i <= maxSum; i++){
        if(dp[n][i]){
            cout << i << " ";
        }
    }
}
