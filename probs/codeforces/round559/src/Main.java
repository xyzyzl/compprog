import java.util.*;

public class Main
{
	private static int n, m;
	private static ArrayList<Long> b, g, f;

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		b = new ArrayList<Long>();
		g = new ArrayList<Long>();
		f = new ArrayList<Long>();
		long min = 0;
		for (int i = 0; i < n; i++)
		{
			b.add(sc.nextLong());
			f.add((long) m - 1); // f(b) = amount of times that boy b can be raised
			min += m * b.get(i);
		}
		long wc = 0;
		for (int i = 0; i < m; i++)
		{
			g.add(sc.nextLong());
			wc += g.get(i);
		}
		Collections.sort(b);
		Collections.sort(g);
		if (b.get(n - 1) > g.get(0))
		{
			System.out.println(-1);
			return;
		}
		Collections.reverse(b);
		Collections.reverse(g);
		int i = 0, j = 0;
		min = (min + wc - m * b.get(0));
		// But if everything is greater, then the minimum will change
		if (g.get(m - 1) > b.get(0)) min += (b.get(0) - b.get(1)); // there will still be m-1 instances of the largest
		System.out.println(min);
	}
}