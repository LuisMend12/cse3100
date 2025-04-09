#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    vector<int> coins = {2, 4, 7};  
    int max_amount = 13;  
    
    vector<bool> dp(max_amount + 1, false);
    dp[0] = true;  
    
    for (int coin : coins) {
        for (int amount = coin; amount <= max_amount; amount++) {
            if (dp[amount - coin]) {
                dp[amount] = true;
            }
        }
    }
    
    
    set<int> distinct_sums;
    for (int amount = 1; amount <= max_amount; amount++) {
        if (dp[amount]) {
            distinct_sums.insert(amount);
        }
    }
    
    
    cout << "The distinct amounts that can be formed are: ";
    for (int sum : distinct_sums) {
        cout << sum << " ";
    }
    cout << endl;
    
    cout << "Total number of distinct amounts: " << distinct_sums.size() << endl;

    return 0;
}
