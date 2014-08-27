#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int getpropSize(int userSize)
{
	if (userSize < 4 && userSize >=2)
		return userSize;
	else if (userSize < 2)
	{
		return 2;
	}
	int prim = 5;
	for (; prim < 100000;prim+=2)
	{
		int sqrt_prim = sqrt(prim);
		bool flag = true;
		for (int j = 2; j <= sqrt_prim; j++)
		{
			if (prim % j == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag && prim > userSize)
		{
			return prim;
		}
	}


}

int main()
{
	ifstream cin("data.txt");
	int user_size, input_num;
	cin >> user_size >> input_num;
	int mSize = getpropSize(user_size);
	vector<bool> storeValue(mSize, false);

	while (input_num >0)
	{
		int val;
		cin >> val;
		int num_probe = 0;
		while (num_probe < mSize)
		{
			int hash_index = (val + num_probe*num_probe) % mSize;
			if (storeValue[hash_index] == false)
			{
				cout << hash_index;
				if (input_num != 1)
					cout << " ";
				storeValue[hash_index] = true;
				break;
			}
			num_probe++;
		}
		if (num_probe == mSize)
		{
			cout << "-";
			if (input_num != 1)
				cout << " ";
		}
		input_num--;
	}
	cout << endl;


}