#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <map>


using namespace std;

int charToIndex(char C)
{
	if (C <= '9' && C >= '0')
	{
		return C - '0';
	}
	else if (C <= 'Z' && C >= 'A')
	{
		return 10 + C - 'A';
	}
	else if (C <= 'z' && C >= 'a')
	{
		return 36 + C - 'a';
	}
	else
	{
		return -1;
	}
}

bool isCharacter(char c)
{
	if (c <= 'Z' && c >= 'A')
		return true;
	if (c <= 'z' && c >= 'a')
		return true;

	return false;
}

int toHour(char c)
{
	if (c <= '9' &&c >= '0')
		return c - '0';
	if (c <= 'N' && c >= 'A')
		return 10 + c - 'A';
}

int main()
{
	ifstream cin("data.txt");
	string s1,s2,s3,s4;
	cin >> s1 >> s2 >> s3 >> s4;
	vector<int> map_char(70);
	for (int i = 0; i < s1.size(); i++)
	{
		int index = charToIndex(s1[i]);
		if (index != -1)
			map_char[index]++;
	}

	string weeks[7];
	weeks[0] = "MON";
	weeks[1] = "TUE";
	weeks[2] = "WED";
	weeks[3] = "THU";
	weeks[4] = "FRI";
	weeks[5] = "SAT";
	weeks[6] = "SUN";

	char Day = 0;
	char hour = 0;
	int count = 0;
	for (int i = 0; i < s2.size(); i++)
	{
		int index = charToIndex(s2[i]);
		if (index != -1 && map_char[index] != 0)
		{
			count++;
			if (Day == 0 && s2[i] <='Z' && s2[i] >='A')
			{
				Day = s2[i];
			}

			if (count == 2&& hour ==0 && ((s2[i] <= 'N' &&s2[i] >= 'A') || (s2[i] <= '9' &&s2[i] >= '0')))
			{
				hour = s2[i];
			
			}
		}

	}

	vector<int> s_hash(70);
	for (int i = 0; i < s3.size();i++)
	{
		int index = charToIndex(s3[i]);
		if (index != -1)
			s_hash[index]++;
	}
	int minu = 0;
	for (int i = 0; i < s4.size(); i++)
	{
		int index = charToIndex(s4[i]);
		if (index != -1 && s_hash[index] != 0 && isCharacter(s4[i]))
		{
			minu = i;
			break;
		}
	}


	printf("%s %02d:%02d\n", weeks[Day - 'A'], toHour(hour), minu);

}