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
	bool operator <(const Student & rhs)
	{
		return grade < rhs.grade;
	}
};

bool cmpStudent(const Student * a, const Student * b)
{
	return a->grade < b->grade;
}

/*
find the target index that all the i > index has a grad >= target_grade
*/
int lowerBound(vector<Student *> & students, int target_grade)
{
	// 如过最小的都大于或者等于 target 那么小于taget_node 的应该在-1
	if (students[0]->grade >= target_grade)
		return -1;


	int left = 0;
	int right = students.size() - 1;
	int mid = (right + left + 1) / 2;
	while (left < right)
	{
		
		if (students[mid]->grade < target_grade)
		{
			left = mid;
		}
		else
		{
			right = mid - 1;
		}
		mid = (right + left + 1) / 2;
	}
	return mid;

}

int upperBound(vector<Student *> & students, int target_grade)
{
	//如果students中最大的那个数仍然小于target_node，那么显然upperbound的索引在student.size()
	if (students[students.size()-1]->grade <= target_grade)
		return students.size();

	int left = 0;
	int right = students.size() - 1;
	int mid = (right + left) / 2;
	while (left <right)
	{
		
		if (students[mid]->grade > target_grade)
		{
			right = mid;
		}
		else
		{
			left = mid+1;
		}
		mid = (right + left) / 2;
	}
	return mid;

}

int main()
{
	ifstream cin("data.txt");
	int student_num;
	cin >> student_num;
	int min_grad, max_grade;
	vector<Student *> students(student_num);
	for (int i = 0; i < student_num; i++)
	{
		Student * st = new Student;
		cin >> st->name >> st->id >> st->grade;
		students[i] = st;
	}
	cin >> min_grad >> max_grade;
	sort(students.begin(), students.end(), cmpStudent);

	if (student_num == 0)
	{
		cout << "None" << endl;
	}

	int lower = lowerBound(students,min( min_grad,max_grade))+1;
	int up = upperBound(students, max(max_grade,min_grad))-1;
	
	if (lower > up || lower>=students.size() ||up < 0)
	{
		cout << "None" << endl;
	}
	else
	{
		for (int i = up; i >= lower; i--)
		{
			cout << students[i]->name << " " << students[i]->id << endl;
		}
	}
}
