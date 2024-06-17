#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findMaximumXOR(vector<int>& nums, int k) {
    int max_xor = 0;
    int mask = 0;
    
    for (int i = 31; i >= 0; --i) {
        mask |= (1 << i);
        unordered_set<int> seen;
        
        for (int num : nums) {
            int prefix = num & mask;
            int target = max_xor | (1 << i);
            
            if (seen.count(prefix)) continue;
            
            for (int seen_prefix : seen) {
                if ((seen_prefix | prefix) < k) {
                    max_xor = target;
                    break;
                }
            }
            
            seen.insert(prefix);
        }
    }
    
    return max_xor;
}

int main() {
    // Example usage
    vector<int> nums = {18, 7, 22, 15, 10};
    int k = 25;
    
    int result = findMaximumXOR(nums, k);
    cout << "Maximum XOR less than " << k << " is: " << result << endl;
    
    return 0;
}

