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
	int id;
	int weight;
	vector<Node *> childrens;
};

bool cmp(const Node * a, const Node * b)
{
	return a->weight > b->weight;
}

void print(vector<int> & seq)
{
	for (int i = 0; i < seq.size() - 1; i++)
	{
		printf("%d ", seq[i]);
	}
	printf("%d\n", seq[seq.size() - 1]);
}

void search(Node * root, vector<int>& curseq, int target,int curweight)
{
	int cur_weight = curweight + root->weight;
	if (cur_weight == target && root->childrens.empty())
	{
		curseq.push_back(root->weight);
		print(curseq);
		return;
	}
	
	
	if (cur_weight > target)
		return;

	curseq.push_back(root->weight);
	int size = curseq.size();
	for (int i = 0; i < root->childrens.size(); i++)
	{
		search(root->childrens[i], curseq, target, cur_weight);
		curseq.resize(size);
	}
}

int main()
{
	freopen("data.txt", "r", stdin);
	int N, NL;
	int target;
	scanf("%d%d%d", &N, &NL, &target);
	vector<Node*> nodes(N);
	for (int i = 0; i < N; i++)
	{
		Node * node = new Node;
		scanf("%d", &node->weight);
		node->id = i;
		nodes[i] = node;	
	}

	for (int i = 0; i < NL; i++)
	{
		int id,ch_num;
		scanf("%d%d", &id, &ch_num);
		for (int j = 0; j < ch_num; j++)
		{
			int ch_id;
			scanf("%d", &ch_id);
			nodes[id]->childrens.push_back(nodes[ch_id]);
		}
		sort(nodes[id]->childrens.begin(), nodes[id]->childrens.end(), cmp);
	}

	vector<int> temp;
	search(nodes[0], temp, target, 0);

}