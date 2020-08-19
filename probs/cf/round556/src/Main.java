import java.util.*;
		import java.io.*;

public class Main
{

	private static int n, arr[];

	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		arr = new int[n];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
		int o=0, t=0;
		for (int i = 0; i < n; i++)
		{
			if(arr[i]==1) o++;
			else t++;
		}
		if(t==0) for(int i = 0; i < n; i++) System.out.print(1 + " ");
		else
		{
			if(o==0) for(int i = 0; i < n; i++) System.out.print(2 + " ");
			else
			{
				System.out.print("2 1 ");
				t--;
				o--;
				for(int i = 0; i < t; i++) System.out.print("2 ");
				for(int i = 0; i < o; i++) System.out.print("1 ");
			}
		}
	}
}
