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
	
	int M, N;
	scanf("%d%d", &M, &N);
	int count = 0;
	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int val;
			scanf("%d", &val);
			if (count == 0)
			{
				ret = val;
				count++;
			}
			else if (ret != val)
			{
				count--;
			}
			else if (ret == val)
			{
				count++;
			}
			
		}
	}
	cout << ret;
}