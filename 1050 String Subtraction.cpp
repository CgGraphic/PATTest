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
	char buffer[10005];
	cin.getline(buffer, 10005);
	string s1 = buffer;
	cin.getline(buffer, 10005);
	string s2 = buffer;

	
	vector<int> hash(258,0);
	for (int i = 0; i < s2.size(); i++)
	{
		hash[s2[i]]++;
	}
	for (int i = 0; i < s1.size(); i++)
	{
		if (hash[s1[i]] == 0)
			printf("%c", s1[i]);
	}
	printf("\n");

}