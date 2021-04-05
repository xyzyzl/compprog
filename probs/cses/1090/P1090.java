import java.util.*;
import java.io.*;

public class P1090
{
	public static void main(String[] args) throws IOException
	{
		int n, x;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		Scanner sc = new Scanner(System.in);
		int[] a = new int[n];
		for(int i = 0; i < n; i++) a[i] = sc.nextInt();
		Arrays.sort(a);
		int l = 0, r = n-1;
		int ans = 0;
		while(l <= r)
		{
			System.err.println(l + " " + r);
			if(l == r)
			{
				ans++;
				break;
			}
			if(a[l] + a[r] <= x)
			{
				l++;
				r--;
			} else
			{
				r--;
			}
			ans++;
		}
		System.out.println(ans);
	}
}
