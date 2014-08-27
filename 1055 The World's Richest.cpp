#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include<functional>  


using namespace std;

struct Person
{
	string name;
	int age;
	int worth;
	
};


bool cmp (const Person * b,const Person * a)
{
	if (a->worth != b->worth)
	{
		return b->worth > a->worth;
	}
	else
	{
		if (a->age != b->age)
			return b->age < a->age;
		return b->name < a->name;
	}
}
int main()
{
	freopen("data.txt", "r", stdin);
	int N, Q;
	scanf("%d%d", &N, &Q);
	vector<Person *> people;
	for (int i = 0; i < N; i++)
	{
		Person * p = new Person;
		char buffer[10];
		scanf("%s%d%d", buffer, &p->age, &p->worth);
		p->name = buffer;
		people.push_back(p);
	}
	sort(people.begin(), people.end(), cmp);

	int filter[100000];
	int filternum = 0;
	int agerCount[205] = { 0 };
	for (int i = 0; i < people.size(); i++)
	{
		if (++agerCount[people[i]->age] <= 100)
			filter[filternum++] = i;
	}

	for (int i = 0; i < Q; i++)
	{
		int num, minAge, maxAge;
		scanf("%d%d%d", &num, &minAge, &maxAge);
		bool first = true;
		printf("Case #%d:\n", i + 1);
		int j = 0;
		while (num >0 && j < filternum)
		{
			Person * p = people[filter[j]];
			int age = p->age;
			if (age <= maxAge && age >= minAge)
			{
				printf("%s %d %d\n", p->name.c_str(), p->age, p->worth);
				first = false;
				num--;
			}
			j++;
		}
		if (first)
			printf("None\n");
		
	}

	return 0;
}