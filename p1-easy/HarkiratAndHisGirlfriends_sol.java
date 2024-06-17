import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt(); // Number of test cases
        
        while (t-- > 0) {
            int n = sc.nextInt(); // Number of girlfriends
            int q = sc.nextInt(); // Number of queries
            
            Map<String, Integer> mp = new HashMap<>(); // HashMap to store gifts sum for each girlfriend
            
            for (int i = 0; i < n; ++i) {
                String gf_name = sc.next();
                int no_of_gifts = sc.nextInt();
                int sum = 0;
                
                for (int j = 0; j < no_of_gifts; ++j) {
                    int price = sc.nextInt();
                    sum += price;
                }
                mp.put(gf_name, sum);
            }
            
            while (q-- > 0) {
                String query_gf = sc.next();
                System.out.println(mp.getOrDefault(query_gf, 0));
            }
        }
        sc.close();
    }
}

