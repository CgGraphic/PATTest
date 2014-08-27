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
	freopen("data.txt", "r", stdin);
	int N, money;
	scanf("%d %d", &N, &money);
	vector<int> coin(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &coin[i]);
	}
	sort(coin.begin(), coin.end());
	int left = 0,right = N-1;
	while (left < right)
	{
		int val = coin[left] + coin[right];
		if (val == money)
		{
			printf("%d %d\n", coin[left], coin[right]);
			return 0;
		}
		else if (val < money)
			left++;
		else
		{
			right--;
		}
	}
	printf("No Solution\n");
	return 0;

}