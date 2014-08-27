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


int main()
{
	freopen("data.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	vector<int> seq(N);
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		int val;
		scanf("%d", &val);
		seq[val] = i;
		if (val != i)
			count++;
	}

	int num = 0;
	int index = seq[0];
	
	int i = 1;
	for (; i < N; i++)
	{
		if (seq[i] != i)
			break;
	}
	int first_not_pos = i;

	while (count)
	{
		if (index != 0)
		{
			std::swap(index, seq[index]);
			num++;
			count--;
			if (index == 0)
				count--;
		}
		else
		{
			int i = first_not_pos;
			for (;i < N; i++)
			{
				if (seq[i] != i)
					break;
			}
			first_not_pos = i;
			std::swap(index, seq[i]);
			num++;
			count++;
		}
	}
	printf("%d\n", num);

}