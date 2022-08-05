#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int n;

inline string readAndCheckAnswer(InStream& in)
{
	string s = in.readLine("[A-Z]{2,100}");
	if(s != "YES" && s != "NO")
	{
		in.quitf(_wa, "what are you printing??????");
	}
	if(s == "NO")
	{
		return s;
	}
	int p, q;
	int s1=0, s2=0;
	p = in.readInt();
	for(int i = 0; i < p; i++)
	{
		int t = in.readInt();
		s1 += t;
	}
	q = in.readInt();
	for(int i = 0; i < q; i++)
	{
		int t = in.readInt();
		s2 += t;
	}
	if(s1 != s2)
	{
		in.quitf(_wa, "two sums %d and %d aren't equal", s1, s2);
	}
	return s;
}

int main(int argc, char* argv[])
{
	registerTestlibCmd(argc, argv);
	n = inf.readInt();
	string ja = readAndCheckAnswer(ans);
	string pa = readAndCheckAnswer(ouf);
	if(ja != pa)
	{
		quitf(_wa, "stop gaslighting lebron james.....");
	}
	quitf(_ok, "lebron james thanks you");
}