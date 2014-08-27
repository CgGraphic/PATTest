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

struct Node 
{
	int addr;
	int key;
	int next;
	bool operator<(const Node & rhs) const
	{
		return key < rhs.key;
	}
};

bool cmp(const Node * a, const Node * b)
{
	return a->key < b->key;
}

int main()
{
	freopen("data.txt", "r", stdin);
	int N,head;
	scanf("%d%d", &N, &head);
	vector<Node * > map_node(200005, NULL);
	for (int i = 0; i < N; i++)
	{
		Node * node = new Node;
		scanf("%d%d%d", &node->addr, &node->key, &node->next);
		map_node[node->addr + 100000] = node;
	}

	vector<Node*> lists;
	int curaddr = head;
	while (curaddr != -1)
	{
		if (map_node[curaddr + 100000] != NULL)
		{
			lists.push_back(map_node[curaddr + 100000]);
			curaddr = map_node[curaddr + 100000]->next;
		}else
			break;

	}

	sort(lists.begin(), lists.end(),cmp);

	printf("%d",lists.size());
	for (int i = 0; i < lists.size(); i++)
	{
		printf(" %05d\n", lists[i]->addr);
		

		printf("%05d %d", lists[i]->addr,lists[i]->key);

	}
	printf(" -1\n");
	return 0;





}