#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
	freopen("data.txt", "r", stdin);
	int N;
	vector<int> D;
	int query;
	scanf("%d", &N);
	D.resize(N);
	vector<int> dist(N);
	int sumD = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &D[i]);
		dist[i] = sumD;
		sumD += D[i];
		
	}
	scanf("%d", &query);
	for (int i = 0; i < query; i++)
	{
		int id1, id2;
		scanf("%d%d", &id1, &id2);
		int min_id = std::min(id1, id2);
		int max_id = std::max(id1, id2);
		int curSum = dist[max_id - 1] - dist[min_id - 1];
		
		if (curSum <= sumD / 2)
			printf("%d\n", curSum);
		else
		{
			printf("%d\n", sumD - curSum);
		}
	
	}

}