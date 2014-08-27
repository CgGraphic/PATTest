#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Node
{
	double val;
	double price;
	vector<Node *> children;
	Node()
	{
		val = 0;
	}
};

double ret = 0.0;
double unitPrice, rate;

void search(Node * root)
{
	if (root->children.empty())
	{
		ret += root->val * root->price;
		return;
	}
	for (int i = 0; i < root->children.size(); i++)
	{
		root->children[i]->price = root->price * (1.0 + rate / 100.0);
		search(root->children[i]);
	}
}

int main()
{
	freopen("data.txt", "r", stdin);
	int nummember;

	scanf("%d%lf%lf", &nummember, &unitPrice, &rate);
	vector<Node *> members(nummember);
	for (int i = 0; i < nummember; i++)
	{
		members[i] = new Node;
	}
	for (int i = 0; i < nummember; i++)
	{
		int count;
		scanf("%d", &count);
		if (count == 0)
		{
			double product_num;
			scanf("%lf", &product_num);
			members[i]->val = product_num;
		}
		else
		{
			for (int j = 0; j < count; j++)
			{
				int childrenId;
				scanf("%d", &childrenId);
				members[i]->children.push_back(members[childrenId]);
			}
		}

	}
	members[0]->price = unitPrice;
	search(members[0]);
	printf("%0.1lf\n",ret);
	return 0;
}