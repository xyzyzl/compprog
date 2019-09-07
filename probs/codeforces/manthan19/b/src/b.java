import java.util.Scanner;
import java.util.TreeMap;

public class b {
    public static void main(String[] args)
    {
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int[] a = new int[n];
        TreeMap<Integer, Integer> tm = new TreeMap<Integer, Integer>();
        for(int i = 0; i < n; i++)
        {
            a[i] = sc.nextInt();
            tm.put(a[i], 0);
        }

        // boolean nice = true;
        int jw = 0, ans = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++)
        {
            boolean nice = true;
            tm.clear();
            for(int j = 0; j < i; j++) {
                
                if(tm.get(a[i]) > 1)
                {
                    nice = false;
                    break;
                }
            }
            for(int j = n-1; j >= i; j--)
            {
                if(!tm.containsKey(a[j]))
                {
                    // nice = false; this is not needed
                    jw = j;
                    // break;
                } else break;
                tm.put(a[j], 1);
            }
            if(nice)
            {
                ans = Math.min(ans, jw-i);
            }
        }
        System.out.println(ans);
    }

}
