import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        // find the divisors of n, if it isn't just a prime being multiplied multiple times it should just be 1
        ArrayList<Long> divisors = new ArrayList<Long>();
        boolean[] kageOrz = new boolean[(int)Math.floor(Math.sqrt(n))+69];
        for(int i = 2; i <= Math.sqrt((double)n); i++)
        {
            if(!kageOrz[i] && n%i==0)
            {
                divisors.add((long)i);
                divisors.add(n/i);
            }
            for(int j = i; j <= Math.sqrt(n); j+=i)
            {
                kageOrz[j] = true;
            }
        }
        // divisors.add(1);
        divisors.add(n);
        Collections.sort(divisors);
        long p = divisors.get(0);
        // this is the smallest divisor.
        while(n != 1)
        {
            if(n%p == 0) n /= p;
            else
            {
                System.out.println(1);
                return;
            }
        }
        System.out.println(p);
    }
}
