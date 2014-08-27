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
	//ifstream cin("data.txt");
	freopen("data.txt", "r", stdin);
	int N, K;
	scanf("%d%d", &N, &K);
	vector<string> students(N);
	vector<vector<string>> course(K, vector<string>());
	for (int i = 0; i < N; i++)
	{
		char buffer[6];
		scanf("%s", buffer);
		students[i] = buffer;
		int cnum = 0;
		scanf("%d", &cnum);
		for (int j = 0; j < cnum; j++)
		{
			int id;
			scanf("%d", &id);
			course[id-1].push_back(students[i]);
		}
	}
	for (int i = 0; i < K; i++)
	{
		printf("%d %d\n", i + 1, course[i].size());
		sort(course[i].begin(), course[i].end());
		for (int j = 0; j < course[i].size(); j++)
		{
			printf("%s\n", course[i][j].c_str());
		}
	}

}