import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String[] args)
	{
		Task task = new Task();
		task.solve();
	}
	static class Task
	{
		int n, m;
		int[] x, y;
		public void solve()
		{
			LLMReader br = new LLMReader();
			PrintWriter pw = new PrintWriter(System.out);
			n = br.nextInt();
			m = br.nextInt();
			x = new int[n];
			y = new int[m];
			int _i = 0;
			for (int i = 0; i < n; i++) x[i] = br.nextInt();
			TreeSet<Integer> ft = new TreeSet();
			TreeMap<Integer, Integer> wt = new TreeMap();
			for (int i = 0; i < n; i++)
			{
				ft.add(x[i]);
				wt.put(x[i], 0);
			}
			int its = 0;
			long ans = 0;
			while(true)
			{
				boolean out = false;
				TreeSet<Integer> nft = new TreeSet();
				for (int k : ft)
				{
					if (_i == m)
					{
						out = true;
						break;
					}
					ans += wt.get(k);
					if (its > 0) y[_i++] = k;
					if (!wt.containsKey(k + 1))
					{
						wt.put(k + 1, wt.get(k) + 1);
						nft.add(k + 1);
					}
					if (!wt.containsKey(k - 1))
					{
						wt.put(k - 1, wt.get(k) + 1);
						nft.add(k - 1);
					}
				}
				++its;
				ft = nft;
				if(out) break;
			}
			pw.println(ans);
			for(int i = 0; i < m; i++)
			{
				pw.print(y[i]);
				if(i < m-1) pw.print(" ");
			}
			pw.println();
			pw.flush();
			pw.close();
		}
	}
	static class LLMReader
	{
		BufferedReader br;
		StringTokenizer st;

		public LLMReader()
		{
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public LLMReader(String s) throws FileNotFoundException
		{
			br = new BufferedReader(new FileReader(new File(s)));
		}

		String next()
		{
			while (st == null || !st.hasMoreElements())
			{
				try
				{
					st = new StringTokenizer(br.readLine());
				} catch (IOException e)
				{
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt()
		{
			return Integer.parseInt(next());
		}

		long nextLong()
		{
			return Long.parseLong(next());
		}

		double nextDouble()
		{
			return Double.parseDouble(next());
		}

		String nextLine()
		{
			String str = "";
			try
			{
				str = br.readLine();
			} catch (IOException e)
			{
				e.printStackTrace();
			}
			return str;
		}
	}
}
