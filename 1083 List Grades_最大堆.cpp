#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>


using namespace std;

struct  Student
{
	string name;
	string id;
	int grade;
	bool operator <(const Student & rhs) const
	{
		return grade < rhs.grade;
	}
};


int main()
{
	ifstream cin("data.txt");
	int student_num;
	cin >> student_num;
	int min_grade, max_grade;
	priority_queue<Student> q;
	for (int i = 0; i < student_num; i++)
	{
		Student s;
		cin >> s.name >> s.id >> s.grade;
		q.push(s);
	}

	cin >> min_grade >> max_grade;
	bool no = true;
	while (q.empty() == false)
	{
		if (q.top().grade >= min_grade && q.top().grade <= max_grade)
		{
			no = false;
			cout << q.top().name << " " << q.top().id << endl;
		}
		q.pop();
	}
	cout << (no ? "NONE" : "");
	
}
