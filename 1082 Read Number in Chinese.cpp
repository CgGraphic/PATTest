#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> digits(10);


vector<string> danwei(4);



vector<string> getString(int num)
{
	if (num >= 10000)
		return vector<string>();
	
	int pow_num = 3;
	bool last_zero = true;
	vector<string> ret;
	while (num > 0)
	{
		int val = pow(10, pow_num);
		int di = num / val;
		if (di > 0)
		{
			ret.push_back(digits[di]);
			if (danwei[pow_num].empty() == false)
			ret.push_back(danwei[pow_num]);
			num %= val;
			last_zero = false;
			
		}
		else if (di == 0 && num != 0 && last_zero == false)
		{
			ret.push_back(digits[0]);
			last_zero = true;
		}
		pow_num--;
		
	}
	return ret;
}

void print(vector<string>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i];
		if (i != vec.size() - 1)
			cout << " ";

	}
	cout << endl;
}

int main()
{
	digits[0] = "ling";
	digits[1] = "yi";
	digits[2] = "er";
	digits[3] = "san";
	digits[4] = "si";
	digits[5] = "wu";
	digits[6] = "liu";
	digits[7] = "qi";
	digits[8] = "ba";
	digits[9] = "jiu";

	danwei[0] = "";
	danwei[1] = "Shi";
	danwei[2] = "Bai";
	danwei[3] = "Qian";

	vector<string> yiwan(3);
	yiwan[0] = "";
	yiwan[1] = "Wan";
	yiwan[2] = "Yi";

	int num;
	ifstream cin("data.txt");
	cin >> num;
	int pow_num = 2;
	bool neg = num < 0 ?true : false;
	vector<string> ret;
	
	num = abs(num);
	if (num == 0)
	{
		cout << "ling" << endl;
		return 0;
	}
		
	while (num != 0)
	{
		int val_digit = pow(10, pow_num * 4);
		vector<string> cur = getString(num / val_digit);
		num %= val_digit;
		
		ret.insert(ret.end(), cur.begin(), cur.end());
		if (cur.empty() == false && yiwan[pow_num].empty() == false)
			ret.push_back(yiwan[pow_num]);
		if (num < pow(10, (pow_num)* 4-1) && num != 0 &&ret.empty() == false)
			ret.push_back("ling");
		pow_num--;
		
	}
	if (neg)
		cout << "Fu ";
	print(ret);
	




}