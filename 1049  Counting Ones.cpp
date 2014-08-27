#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ifstream cin("data.txt");
	int val;
	cin >> val;
	vector<long long> digits_num;
	digits_num.push_back(1);
	for (int i = 1; i < 10; i++)
	{
		long long yi_num = digits_num[i - 1] * 10 + pow(10, i);
		//cout << yi_num << " ";
		digits_num.push_back(yi_num);
	}


	int count = 0;
	while (pow(10,count+1) <= val)
	{
		count++;
	}
	long long ret = 0;
	while (val)
	{
		if (val < 10)
		{
			ret += 1;
			break;
		}
			
		int power = pow(10, count);
		int digit = val / power;
		switch (digit)
		{
		case 1:
		{
				  ret += (val %power + 1);
				  if (count != 0)
				  {
					  ret += digits_num[count-1];
				  }
		}break;
		case 0:
			break;
		default:
		{
				   ret += digits_num[count-1] * (digit) + pow(10,count);

						
				  
		}
			break;
		}
	
		val %= power;
		count--;
	}
	cout << ret << endl;



	return 0;
}