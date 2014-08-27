#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long x, long y)
{
	if (x > y)
	{
		return gcd(y, x);
	}

	if (x == 0)
		return y;
	return gcd(y%x, x);
}

long long LCM(long x, long y)
{
	return x*y / gcd(x, y);
}

struct Ration
{
	long long numerator;
	long long denominator;

	Ration operator + (const Ration & rhs)
	{
		Ration ret;
		ret.denominator = LCM(denominator, rhs.denominator);
		ret.numerator = (ret.denominator / denominator) * numerator + (ret.denominator / rhs.denominator) * rhs.numerator;
		long long the_gcd = gcd(ret.numerator, ret.denominator);
		ret.numerator /= the_gcd;
		ret.denominator /= the_gcd;
		return ret;

	}
	Ration()
	{
		numerator = 0;
		denominator = 1;
	}
};

int main()
{
	freopen("data.txt", "r", stdin);
	int num;
	scanf("%d\n", &num);
	Ration ret;
	while (num--)
	{
		Ration add;
		scanf("%lld/%lld ", &add.numerator, &add.denominator);
		ret = ret + add;
	}
	bool interger = false;
	if (abs(ret.numerator) > abs(ret.denominator) || ret.numerator == 0)
	{
		cout << ret.numerator / ret.denominator;
		ret.numerator %= ret.denominator;
		interger = true;
	}
	if (ret.numerator != 0)
	{
		if (interger)
			cout << " ";
		cout<< ret.numerator << "/" << ret.denominator;
	}
	cout << endl;

	return 0;
}