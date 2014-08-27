#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	ifstream cin("data.txt");
	int userNum;
	int maxLevel;
	cin >> userNum >> maxLevel;
	vector<vector<int>> follow(userNum, vector<int>());
	vector<bool> visited(userNum, true);
	int i = 0;
	while (i < userNum)
	{
		int follow_num;
		cin >> follow_num;
		for (int j = 0; j < follow_num; j++)
		{
			int userid;
			cin >> userid;
			follow[userid - 1].push_back(i);
		}
		i++;
	}

	int query_num;
	cin >> query_num;
	while (query_num > 0)
	{
		int query_id;
		cin >> query_id;
		if (query_id < 1 || query_id >userNum)
		{
			cout << 0<<endl;
			continue;
		}
		query_id--;
		visited.assign(userNum, false);
		visited[query_id] = true;
		int count = 0;
		queue<int> need_to_visited;
		
		need_to_visited.push(query_id);
		need_to_visited.push(-1);
		int cur_level = 0;
		while (need_to_visited.empty() == false && cur_level < maxLevel)
		{
			int val = need_to_visited.front();
			need_to_visited.pop();
			if (val == -1)
			{
				cur_level++;
				need_to_visited.push(-1);
				continue;
			}

			for (int i = 0; i < follow[val].size(); i++)
			{
				int followed_id = follow[val][i];
				if (visited[followed_id] == false)
				{
					visited[followed_id] = true;
					need_to_visited.push(followed_id);
					count++;
				}
			}
			
		}
		query_num--;
		cout << count<<endl;
			
	}


}