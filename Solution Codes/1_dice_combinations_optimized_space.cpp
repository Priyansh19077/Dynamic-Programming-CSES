/* Priyansh Agarwal*/
#include<bits/stdc++.h>
 
#define MOD 1000000007

using namespace std;

int main(){
    int n;
    cin >> n;
 
    vector<int> prev = {1}; // only contains dp[0]
    
    for(int i = 1; i <= n; i++){
        // finding dp[i] or number of ways to make a sum of i
        // dp[i] = summation of all the previous states
        int current = 0;
        for(int j : prev){
            current = (current + j) % MOD;
        }
        
        prev.push_back(current);
        // if previous contains more than 6 elements
        // discard the first element
        
        if(prev.size() > 6){
            prev.erase(prev.begin());
        } 
    }
    
    //finally the last element of prev would be dp[n]
    cout << prev.back() << endl;
    return 0;
}