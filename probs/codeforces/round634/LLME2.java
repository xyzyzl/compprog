import java.util.*;
import java.io.*;
 
public class LLME2 {
    //Solution by Sathvik Kuthuru
    public static void main(String[] args) {
        FastReader scan = new FastReader();
        try
        {
            scan = new FastReader("hack.txt");
        } catch(FileNotFoundException e)
        {
            e.printStackTrace();
        }
        PrintWriter out = new PrintWriter(System.out);
        Task solver = new Task();
        int t = scan.nextInt();
        for(int tt = 1; tt <= t; tt++) solver.solve(tt, scan, out);
        out.close();
    }
 
    static class Task {
 
        public void solve(int testNumber, FastReader scan, PrintWriter out) {
            int n = scan.nextInt(), max = 200;
            int[][] prefix = new int[n + 1][max + 1];
            ArrayList<Integer>[] val = new ArrayList[max + 1];
            for(int i = 0; i <= max; i++) val[i] = new ArrayList<>();
            for(int i = 1; i <= n; i++) {
                int a = scan.nextInt();
                val[a].add(i);
                prefix[i][a]++;
                for(int j = 1; j <= max; j++) prefix[i][j] += prefix[i - 1][j];
            }
            int best = 1;
            for(int i = 1; i <= max; i++) {
                for(int size = 0; size < val[i].size() / 2; size++) {
                    int curr = 0;
                    int start = val[i].get(size) + 1, end = val[i].get(val[i].size() - size - 1) - 1;
                    for(int k = 1; k <= max; k++) curr = Math.max(curr, prefix[end][k] - prefix[start - 1][k]);
                    best = Math.max(best, curr + (size + 1) * 2);
                }
            }
            out.println(best);
        }
    }
 
    static void shuffle(int[] a) {
        Random get = new Random();
        for (int i = 0; i < a.length; i++) {
            int r = get.nextInt(a.length);
            int temp = a[i];
            a[i] = a[r];
            a[r] = temp;
        }
    }
 
    static void shuffle(long[] a) {
        Random get = new Random();
        for (int i = 0; i < a.length; i++) {
            int r = get.nextInt(a.length);
            long temp = a[i];
            a[i] = a[r];
            a[r] = temp;
        }
    }
 
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
 
        public FastReader(String s) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(new File(s)));
        }
 
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
 
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
 
}