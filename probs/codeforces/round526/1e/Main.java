import java.util.*;
import java.io.*;

public class Main
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Rectangle[] rect = new Rectangle[n];
		for(int i = 0; i < n; i++)
		{
			long x, y, a;
			StringTokenizer st = new StringTokenizer(br.readLine());
			x = Long.parseLong(st.nextToken());
			y = Long.parseLong(st.nextToken());
			a = Long.parseLong(st.nextToken());
			rect[i] = new Rectangle(x, y, a);
		}
		br.close();
		Arrays.sort(rect, new Rectangle("TORILLA TAVATAAN"));
		ArrayDeque<Line> cur = new ArrayDeque<Line>();
		cur.addFirst(new Line(0, 0));
		long ans = 0;
		for(int i = 0; i < n; i++)
		{
			while(cur.size() >= 2 && cur.peekLast().find(rect[i].y) <= 
					nextLast(cur).find(rect[i].y))
			{
				cur.pollLast();
			}
			long val = cur.peekLast().find(rect[i].y) + rect[i].x * rect[i].y - rect[i].a;
			Line next = new Line(-rect[i].x, val);
			while(cur.size() >= 2 && cur.peekFirst().findIntersect(next) >=
					cur.peekFirst().findIntersect(nextFirst(cur)))
			{
				cur.pollFirst();
			}
			ans = Math.max(ans, val);
			cur.addFirst(next);
		}
		PrintWriter pw = new PrintWriter(System.out);
		pw.println(ans);
		pw.flush();
		pw.close();
	}

	public static Line nextLast(ArrayDeque<Line> cur)
	{
		Line first = cur.pollLast();
		Line des = cur.peekLast();
		cur.addLast(first);
		return des;
	}

	public static Line nextFirst(ArrayDeque<Line> cur)
	{
		Line first = cur.pollFirst();
		Line des = cur.peekFirst();
		cur.addFirst(first);
		return des;
	}

	private static class Rectangle implements Comparator<Rectangle>
	{
		public long x, y, a;
		public Rectangle(long x, long y, long a)
		{
			this.x = x;
			this.y = y;
			this.a = a;
		}
		public Rectangle(String unnecessaryInterjection)
		{ }

		public int compare(Rectangle here, Rectangle other)
		{
			return Long.compare(here.x, other.x);
		}
	}

	private static class Line
	{
		public long slope;
		public long inter;
		public Line(long m, long c)
		{
			slope = m;
			inter = c;
		}
		public long find(long x)
		{
			return slope * x + inter;
		}
		public double findIntersect(Line other)
		{
			return ((double)(other.inter - this.inter))/((double)(this.slope - other.slope));
		}
	}
}

