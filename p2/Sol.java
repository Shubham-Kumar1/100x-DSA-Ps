import java.util.*;

public class MaximumXOR {
    
    public static int findMaximumXOR(int[] nums, int k) {
        int max_xor = 0;
        int mask = 0;
        
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            Set<Integer> seen = new HashSet<>();
            
            for (int num : nums) {
                int prefix = num & mask;
                int target = max_xor | (1 << i);
                
                if (seen.contains(prefix)) continue;
                
                for (int seen_prefix : seen) {
                    if ((seen_prefix | prefix) < k) {
                        max_xor = target;
                        break;
                    }
                }
                
                seen.add(prefix);
            }
        }
        
        return max_xor;
    }
    
    public static void main(String[] args) {
        // Example usage
        int[] nums = {18, 7, 22, 15, 10};
        int k = 25;
        
        int result = findMaximumXOR(nums, k);
        System.out.println("Maximum XOR less than " + k + " is: " + result);
    }
}

