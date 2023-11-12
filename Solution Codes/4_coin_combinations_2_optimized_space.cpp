/* Priyansh Agarwal*/
#include<bits/stdc++.h>

#define MOD 1000000007
 
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
 
    // dp[i][k] = number of ways to construct sum k
    // such that all coins before coin[i] are unusable
    
    // dp[i][k] -> dp[i + 1][k], dp[i][k - ci] 
    
    vector<int> nextState(x + 1, 0); // dp[n][k]
    nextState[0] = 1; // dp[n][0] = 1;
 
    for(int i = n - 1; i >= 0; i--){
        vector<int> currentState(x + 1, 0); // dp[i][k]
        currentState[0] = 1;
        for(int sum = 1; sum <= x; sum++){
            int skipping = nextState[sum];
            int picking = 0;
            if(a[i] <= sum){
                picking = currentState[sum - a[i]];
            }
            currentState[sum] = (skipping + picking) % MOD;
        }
        // curentState[k] = dp[i][k]
        // nextState[k] = dp[i + 1][k]
        nextState = currentState;
    }
    cout << nextState[x] << endl;
    return 0;
}
