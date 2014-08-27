#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct Student
{
	int id;
	int Ge;
	int Gi;
	vector<int> applications;
};

bool cmp( const Student *  a, const Student*  b)
{
	if ((a->Ge + a->Gi) <= (b->Ge + b->Gi))
	{
		if ((a->Ge) <= (b->Ge))
		{
			return false;
		}
		return true;
	}
	return true;
}
bool sameRank(const Student * a, const Student * b)
{
	return (a->Ge == b->Ge) && (a->Gi == b->Gi);
}

bool sortId(const Student *  a, const Student*  b)
{
	return a->id < b->id;
}

int main()
{
	ifstream cin("data.txt");
	int student_num, school_num, choice_num;
	cin >> student_num >> school_num >> choice_num;
	vector<int> quatos(school_num,0);
	vector<vector<Student *>> school_recieved(school_num,vector<Student*>());
	vector<Student *> students;
	for (int i = 0; i < school_num; i++)
	{
		cin >> quatos[i];
	}
	for (int i = 0; i < student_num; i++)
	{
		Student * st = new Student;
		cin >> st->Ge >> st->Gi;
		st->id = i;
		st->applications.resize(choice_num);
		for (int j = 0; j < choice_num; j++)
			cin >> st->applications[j];
		students.push_back(st);
	}

	sort(students.begin(), students.end(), cmp);

	for (int i = 0; i < student_num; i++)
	{
		vector<int> & appli = students[i]->applications;
		for (int j = 0; j < appli.size(); j++)
		{
			int school_id = appli[j];
			if (school_recieved[school_id].size() < quatos[school_id])
			{
				school_recieved[school_id].push_back(students[i]);
				break;
			}
			else
			{
				if (quatos[school_id] != 0 && sameRank(school_recieved[school_id].back(), students[i]))
				{
					school_recieved[school_id].push_back(students[i]);
					break;
				}
					
			}
		}
	}

	for (int i = 0; i < school_num; i++)
	{
		sort(school_recieved[i].begin(), school_recieved[i].end(), sortId);
		for (int j = 0; j < school_recieved[i].size(); j++)
		{
			cout << school_recieved[i][j]->id;
			if (j != school_recieved[i].size() - 1)
				cout << " ";
		}
		cout << endl;
	}

	return 0;
	
	
}