#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

bool simulate(int M, int N, vector<int> & seq)
{
	stack<int> s;
	int push_ed = 0;
	int i = 0;
	while (i < N)
	{
		if (seq[i] > push_ed)
		{
			for (int j = push_ed + 1; j <= seq[i]; j++)
			{
				s.push(j);
				push_ed++;
			}
				
			if (s.size() > M)
				return false;
			s.pop();
			i++;
		}
		else if (s.empty() || s.top() != seq[i])
		{
			return false;
		}
		else if (s.top() == seq[i])
		{
			i++;
			s.pop();
		}
	}
	return true;
}

int main()
{
	ifstream cin("data.txt");
	int M, N, K;
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		vector<int> sequence(N);
		for (int j = 0; j < N; j++)
			cin >> sequence[j];
		bool ret = simulate(M, N, sequence);
		cout << (ret ? "YES" : "NO") << endl;
	}
}