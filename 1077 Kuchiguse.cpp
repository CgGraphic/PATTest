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
	int lineNum;
	cin >> lineNum;
	char charbuffer[300];
	cin.getline(charbuffer, 300);
	vector<string> strs;
	while (lineNum>0)
	{
		
		cin.getline(charbuffer, 300);
		strs.push_back(charbuffer);
		lineNum--;
	}

	int back_count = 0;
	string current_suffix;
	while (true)
	{
		if (strs.empty() || strs[0].size() <= back_count)
		{
			if (current_suffix.empty())
				cout << "nai" << endl;
			else
			{
				reverse(current_suffix.begin(), current_suffix.end());
				cout << current_suffix<<endl;
			}
			
			return 0;
		}
		char first_char = strs[0][strs[0].size()-1-back_count];
		for (int i = 1; i < strs.size(); i++)
		{
			if (strs[i].size() <= back_count || strs[i][strs[i].size() - 1 - back_count] != first_char)
			{
				if (current_suffix.empty())
					cout << "nai" << endl;
				else
				{
					reverse(current_suffix.begin(), current_suffix.end());
					cout << current_suffix<<endl;
				}
				return 0;
			}
		}
		current_suffix += first_char;
		back_count++;	
	}

	return 0;
}