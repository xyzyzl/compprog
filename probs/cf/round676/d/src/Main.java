/**
 * Problem: 1421D-Hexagons
 * Solution: O(1) casework
 * Why it's hard: casework
 */

import java.util.*;
import java.io.*;

public class Main
{
	static class Hexagons
	{
		public void solve(Scanner rd)
		{
			PrintWriter pw = new PrintWriter(System.out);
			long x = rd.nextLong();
			long y = rd.nextLong();
			long[] c = new long[8];
			for(int i = 1; i < 7; i++)
			{
				c[i] = rd.nextLong();
			}
			c[0] = c[6];
			c[7] = c[0];
			for(int i = 1; i < 7; i++)
			{
				c[i] = Math.min(c[i - 1] + c[i + 1], c[i]);
			}
			long ans = Long.MAX_VALUE;
			if(x >= 0)
			{
				if(y >= x)
				{
					ans = Math.min(ans, (c[1]*x) + c[2]*(y-x));
				}
				if(y <= x && y >= 0)
				{
					ans = Math.min(ans, (c[1]*y) + c[6]*(x-y));
				}
				if(y <= 0)
				{
					ans = Math.min(ans, (c[6]*x) + c[5]*(-y));
				}
				if(y <= x)
				{
					ans = Math.min(ans, (c[1]*x) + c[5]*(x-y));
				}
				if(y >= 0)
				{
					ans = Math.min(ans, (c[6]*x) + c[2]*y);
				}
			} else
			{
				if(y >= 0)
				{
					ans = Math.min(ans, (c[3]*(-x)) + c[2]*y);
				}
				if(y >= x && y <= 0)
				{
					ans = Math.min(ans, (c[4]*(-y)) + c[3]*(y-x));
				}
				if(y <= x)
				{
					ans = Math.min(ans, (c[4]*(-x)) + c[5]*(x-y));
				}
				if(y <= 0)
				{
					ans = Math.min(ans, (c[3]*(-x)) + c[5]*(-y));
				}
				if(y >= x)
				{
					ans = Math.min(ans, (c[4]*(-x)) + c[2]*(y-x));
				}
			}
			pw.println(ans);
			pw.flush();
		}
	}

	public static void main(String[] args) throws IOException
	{
		Scanner rd = new Scanner(System.in);
		int t = rd.nextInt();
		Hexagons hex = new Hexagons();
		while(t-- > 0) hex.solve(rd);
	}

}
