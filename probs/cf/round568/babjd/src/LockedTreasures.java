import java.util.*;
import java.math.*;

public class LockedTreasures {

	static BigInteger bi, bi2, bi3;
	public static void main(String[] args) {
		int t;
		Scanner sc = new Scanner(System.in);
		t = sc.nextInt();
		while(t-- > 0) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			m--;
			bi = new BigInteger("1");
			bi2 = new BigInteger("1");
			bi3 = new BigInteger("1");
			for(int i = 2; i <= n; i++)
			{
				bi=bi.multiply(BigInteger.valueOf(i));
			}
			for(int i = 2; i <= m; i++)
			{
				bi2=bi2.multiply(BigInteger.valueOf(i));
			}
			for(int i = 2; i <= n-m; i++)
			{
				bi3=bi3.multiply(BigInteger.valueOf(i));
			}
			BigInteger fin = bi.divide(bi2.multiply(bi3));
			System.out.println(fin.toString());
		}
	}

}
