#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    vector<int> coins = {2, 4, 7};  // The coin denominations
    int max_amount = 13;  // The largest possible amount we are interested in
    
    // Create a boolean DP array to track possible sums
    vector<bool> dp(max_amount + 1, false);
    dp[0] = true;  // base case: 0 can always be formed (by using no coins)
    
    // For each coin, update the DP array
    for (int coin : coins) {
        for (int amount = coin; amount <= max_amount; amount++) {
            if (dp[amount - coin]) {
                dp[amount] = true;
            }
        }
    }
    
    // Collect all the amounts that can be formed
    set<int> distinct_sums;
    for (int amount = 1; amount <= max_amount; amount++) {
        if (dp[amount]) {
            distinct_sums.insert(amount);
        }
    }
    
    // Output the result
    cout << "The distinct amounts that can be formed are: ";
    for (int sum : distinct_sums) {
        cout << sum << " ";
    }
    cout << endl;
    
    cout << "Total number of distinct amounts: " << distinct_sums.size() << endl;

    return 0;
}
