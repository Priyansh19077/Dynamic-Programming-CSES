/* Priyansh Agarwal*/
#include<bits/stdc++.h>

#define MOD 1000000007
 
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));
    // dp[i][j] = min number of cuts to break a block 
    // of i * j into squares
    
    
    // dp[i][j] -> dp[i - some value][j], dp[i][j - some value]
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            // i is the height
            // j is the width
            if(i == j){
                dp[i][j] = 0; // no further breaking required
                continue;
            }
            // making a horizontal cut
            for(int h = 1; h <= i - 1; h++){
                dp[i][j] = min(dp[i][j], dp[h][j] + dp[i - h][j] + 1);
            }
            
            // making a vertical cut
            for(int v = 1; v <= j - 1; v++){
                dp[i][j] = min(dp[i][j], dp[i][v] + dp[i][j - v] + 1);
            }
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}
