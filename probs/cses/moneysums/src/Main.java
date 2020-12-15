import java.util.*;

public class Main
{
	private static int n;
	private static int[] x;
	private static int[][] dp;
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		x = new int[n+1];
		int max_n = 0;
		for(int i = 1; i <= n; i++)
		{
			x[i] = sc.nextInt();
			max_n += x[i];
		}
		dp = new int[n+1][max_n+1];
		dp[0][0] = 1;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 0; j <= max_n; j++) dp[i][j] = dp[i-1][j];
			for(int j = x[i]; j <= max_n; j++)
			{
				if(dp[i][j] != 1) dp[i][j] = dp[i-1][j-x[i]];
			}
		}
		ArrayList<Integer> l = new ArrayList<Integer>();
		for(int i = 1; i <= max_n; i++) if(dp[n][i] == 1) l.add(i);
		System.out.println(l.size());
		for(int x : l) System.out.print(x + " ");
	}
}
