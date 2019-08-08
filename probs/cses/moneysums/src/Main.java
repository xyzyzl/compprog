import java.util.*;

public class Main
{
	private static int n;
	private static int[] x, dp;
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		x = new int[n];
		int max_n = 0;
		for(int i = 0; i < n; i++)
		{
			x[i] = sc.nextInt();
			max_n += x[i];
		}
		dp = new int[max_n+1];
		dp[0] = 1;
		for(int i = 1; i <= max_n; i++)
		{
			for(int y : x)
			{
				if(i-y >= 0) dp[i] = dp[i-y];
			}
		}
		ArrayList<Integer> l = new ArrayList<Integer>();
		for(int i = 1; i <= max_n; i++)
		{
			if(dp[i] > 0) l.add(i);
		}
		System.out.println(l.size());
		for(int b : l) System.out.print(b + " ");
	}
}
