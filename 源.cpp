#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <ctime>
using namespace std;
int max;
class student {
public:
	string name, ID;
	int math;
	int english;
	int chinese;
	int history;
	int zongfen;
};
class student1 {
private:
	student a[50];
	int n;

public:
	void input();//输入
	void Delete();//删除
	void show();//显示
	void add();//增加
	void change();//改变
	void sort();//排序
	void save();//保存
	void search();//查找
	void analysis();//分析
};
void student1::input() {
	int i ;
	ifstream infile("f1.txt", ios::in);
	if (!infile) {
		cerr << "读入错误！" << endl;
		exit(1);
	}
	for (int i=0; i < max; i++) {
		infile >> a[i].ID >> a[i].name >> a[i].chinese >> a[i].math >> a[i].english >> a[i].history;
	}
}
void student1::show() {
	cout << "学号" << '\t' << "        姓名" << '\t' << "语文" << '\t' << "数学" << '\t' << "英语" << '\t' << "历史" << '\t' << "  总分" << endl;
	int i = 0;
	do
	{
		a[i].zongfen = a[i].chinese + a[i].math + a[i].english + a[i].history;
		cout << a[i].ID << '\t' << a[i].name << '\t' << a[i].chinese << '\t' << a[i].math << '\t' << a[i].english << '\t' << a[i].history << '\t' << a[i].zongfen << endl;
		i++;
	} while (i != max);
}
void student1::search() {
	string s;
	int t,o;
	do
	{
		cout << "使用什么查询：姓名【1】学号【2】";
		cin >> o;
		if (o== 1) {
			int i = 0;
			a[i].zongfen = a[i].chinese + a[i].math + a[i].english + a[i].history;
			cout << "请输入学生姓名：";
			cin >> s;
			for (i; i < max; i++) {
				if (a[i].name == s)
					cout << a[i].ID << '\t' << a[i].name << '\t' << a[i].chinese << '\t' << a[i].math << '\t' << a[i].english << '\t' << a[i].history << '\t' << a[i].zongfen << endl;
			}
		}
		if (o == 2) {
			int i = 0;
			a[i].zongfen = a[i].chinese + a[i].math + a[i].english + a[i].history;
			cout << "请输入学生的学号：";
			cin >> s;
			for (i; i < max; i++) {
				if (a[i].ID == s)
					cout << a[i].ID << '\t' << a[i].name << '\t' << a[i].chinese << '\t' << a[i].math << '\t' << a[i].english << '\t' << a[i].history << '\t' << a[i].zongfen << endl;
			}
		}
		cout << "是否继续查找：是【1】否【0】";
		cin >> t;
	} while (t);
}
void student1::change() {
	string s;
	int i = 0, l;
	do {
		cout << "输入要更改的学生学号：";
		cin >> s;
		int j;
		for (i = 0; i < max; i++)
		{
			if (a[i].ID == s)
			{
				cout << a[i].ID << '\t' << a[i].name << '\t' << a[i].chinese << '\t' << a[i].math << '\t' << a[i].english << '\t' << a[i].history << endl;
				cout << "输出要更改的科目:语文（1），数学（2），英语（3），历史（4）；";
				cin >> j;
				if (j == 1)
				{
					cout << "输入要改的分数：";
					cin >> a[i].chinese;
				}
				if (j == 2)
				{
					cout << "输入要改的分数：";
					cin >> a[i].math;
				}
				if (j == 3)
				{
					cout << "输入要改的分数：";
					cin >> a[i].english;
				}
				if (j == 4)
				{
					cout << "输入要改的分数：";
					cin >> a[i].history;
				}

				cout << a[i].ID << '\t' << a[i].name << '\t' << a[i].chinese << '\t' << a[i].math << '\t' << a[i].english << '\t' << a[i].history << endl;
				cout << "是否继续修改：是【1】否【0】";
				cin >> l;
			}
		}
	} while (l);
}
void student1::add()
{
	int h;
	do {

		cout << "请输入学生的姓名：";
		cin >> a[max].name;
		cout << "输入学生学号：";
		cin >> a[max].ID;
		cout << "请输入学生语文，数学，英语，历史成绩：";
		cin >> a[max].chinese >> a[max].math >> a[max].english >> a[max].history;
		cout << a[max].ID << '\t' << a[max].name << '\t' << a[max].chinese << '\t' << a[max].math << '\t' << a[max].english << '\t' << a[max].history << '\t' << endl;
		max = max + 1;
		cout << "是否继续添加？是（1）否（0）";
		cin >> h;
	} while (h);
}
void student1::sort() {
	int k, l;
	for (k = 0; k < max; k++)
		a[k].zongfen = a[k].chinese + a[k].math + a[k].english + a[k].history;
	do {
		int c;
		cout << "请输入想要排序的科目：";
		cout << "语文【1】数学【2】英语【3】历史【4】总分【5】";
		cin >> c;
		if (c == 1) {
			for (int i = 0; i < max; i++)
				for (int j = 0; j < max; j++)
					if (a[j].chinese < a[j + 1].chinese)
					{
						int p = 49;
						a[p] = a[j];
						a[j] = a[j + 1];
						a[j + 1] = a[p];
					}
			for (int i = 0; i < max; i++)
				cout << a[i].ID << '\t' << a[i].name << '\t' << a[i].chinese << '\t' << a[i].math << '\t' << a[i].english << '\t' << a[i].history << '\t' << a[i].zongfen << endl;
		}
		if (c == 2) {
			for (int i = 0; i < max; i++)
				for (int j = 0; j < max; j++)
					if (a[j].math < a[j + 1].math)
					{
						int p = 49;
						a[p] = a[j];
						a[j] = a[j + 1];
						a[j + 1] = a[p];
					}
			for (int i = 0; i < max; i++)
				cout << a[i].ID << '\t' << a[i].name << '\t' << a[i].chinese << '\t' << a[i].math << '\t' << a[i].english << '\t' << a[i].history << '\t' << a[i].zongfen << endl;
		}
		if (c == 3) {
			for (int i = 0; i < max; i++)
				for (int j = 0; j < max; j++)
					if (a[j].english < a[j + 1].english)
					{
						int p = 49;
						a[p] = a[j];
						a[j] = a[j + 1];
						a[j + 1] = a[p];
					}
			for (int i = 0; i < max; i++)
				cout << a[i].ID << '\t' << a[i].name << '\t' << a[i].chinese << '\t' << a[i].math << '\t' << a[i].english << '\t' << a[i].history << '\t' << a[i].zongfen << endl;
		}
		if (c == 4) {
			for (int i = 0; i < max; i++)
				for (int j = 0; j < max; j++)
					if (a[j].history < a[j + 1].history)
					{
						int p = 49;
						a[p] = a[j];
						a[j] = a[j + 1];
						a[j + 1] = a[p];
					}
			for (int i = 0; i < max; i++)
				cout << a[i].ID << '\t' << a[i].name << '\t' << a[i].chinese << '\t' << a[i].math << '\t' << a[i].english << '\t' << a[i].history << '\t' << a[i].zongfen << endl;
		}
		if (c == 5) {
			for (int i = 0; i < max; i++)
				for (int j = 0; j < max; j++)
					if (a[j].zongfen < a[j + 1].zongfen)
					{
						int p = 49;
						a[p] = a[j];
						a[j] = a[j + 1];
						a[j + 1] = a[p];
					}
			for (int i = 0; i < max; i++)
				cout << a[i].ID << '\t' << a[i].name << '\t' << a[i].chinese << '\t' << a[i].math << '\t' << a[i].english << '\t' << a[i].history << '\t' << a[i].zongfen << endl;
		}
		cout << "是否继续排序：是【1】否【0】";
		cin >> l;
	} while (l);
}
void student1::save() {
	ofstream outfile("f1.txt", ios::out);
	if (!outfile) {
		cerr << "保存失败" << endl;
		exit(1);
	}
	/*outfile << "学号" << '\t' << "姓名" << '\t' << "语文" << '\t' << "数学" << '\t' << "英语" << '\t' << "历史" << endl;*/
	for (int i = 0; i < max; i++) {
		outfile << a[i].ID << '\t' << a[i].name << '\t' << a[i].chinese << '\t' << a[i].math << '\t' << a[i].english << '\t' << a[i].history << endl;
	}
	outfile.close();
}
void student1::Delete() {
	string s;
	int t, p, i = 0, r;
	do {
		cout << "请输入学生的学号：";
		cin >> s;
		for (i; i <max; i++) {
			if (a[i].ID == s)
			{
				cout << a[i].ID << '\t' << a[i].name << '\t' << a[i].chinese << '\t' << a[i].math << '\t' << a[i].english << '\t' << a[i].history << '\t' << endl;
				r = i;
			}
		}
		cout << "是否删除：是【1】否【0】";
		cin >> t;
		if (t == 1)
		{
			for (r; r + 1 < max; r++)
			{
				a[r] = a[r + 1];
			}
			max = max - 1;
		}
		cout << "是否继续删除：是【1】否【0】";
		cin >> p;
	} while (p);
}
void student1::analysis(){
	for (int i = 0; i < max; i++)
	{
		a[i].zongfen = a[i].chinese + a[i].english + a[i].history + a[i].math;
	}
	int choice;
	cout << "请选择科目：语文【1】数学【2】英语【3】历史【4】总分【5】";
	cin >> choice;
	if (choice == 1)
	{
		int j = 0;
		float zong1 = 0;
		do 
		{
			zong1 = zong1 + a[j].chinese;
			j++;
		} while (j < max);
		cout << "语文总分为" << zong1 << endl;
		cout << "语文平均分为:" << zong1 / max << endl;
		do {
			int t, m, n;
			float k = 0;
			cout << "输入评判分数：";
			cin >> m;
			for (t = 0; t < max; t++)
			{
				if (a[t].chinese > m)
					k++;
			}
			cout << "超过评判分数人数为：" << k << endl;
			cout << "比例为：" << k / max << endl;
			cout << "是否使用别的评判分数评判：是【1】否【2】";
			cin >> n;
		} while (n == 1);
	}
	if (choice == 2)
	{
		int j = 0;
		float zong1 = 0;
		do
		{
			zong1 = zong1 + a[j].math;
			j++;
		} while (j < max);
		cout << "数学总分为" << zong1 << endl;
		cout << "数学平均分为:" << zong1 / max << endl;
		do {
			int t, m, n;
			float k = 0;
			cout << "输入评判分数：";
			cin >> m;
			for (t = 0; t < max; t++)
			{
				if (a[t].math > m)
					k++;
			}
			cout << "超过评判分数人数为：" << k << endl;
			cout << "比例为：" << k / max << endl;
			cout << "是否使用别的评判分数评判：是【1】否【2】";
			cin >> n;
		} while (n == 1);
	}
	if (choice == 3)
	{
		int j = 0;
		float zong1 = 0;
		do
		{
			zong1 = zong1 + a[j].english;
			j++;
		} while (j < max);
		cout << "英语总分为" << zong1 << endl;
		cout << "英语平均分为:" << zong1 / max << endl;
		do {
			int t, m, n;
			float k = 0;
			cout << "输入评判分数：";
			cin >> m;
			for (t = 0; t < max; t++)
			{
				if (a[t].english > m)
					k++;
			}
			cout << "超过评判分数人数为：" << k << endl;
			cout << "比例为：" << k / max << endl;
			cout << "是否使用别的评判分数评判：是【1】否【2】";
			cin >> n;
		} while (n == 1);
	}
	if (choice == 4)
	{
		int j = 0;
		float zong1 = 0;
		do
		{
			zong1 = zong1 + a[j].history;
			j++;
		} while (j < max);
		cout << "历史总分为" << zong1 << endl;
		cout << "历史平均分为:" << zong1 / max << endl;
		do {
			int t, m, n;
			float k = 0;
			cout << "输入评判分数：";
			cin >> m;
			for (t = 0; t < max; t++)
			{
				if (a[t].history > m)
					k++;
			}
			cout << "超过评判分数人数为：" << k << endl;
			cout << "比例为：" << k / max << endl;
			cout << "是否使用别的评判分数评判：是【1】否【2】";
			cin >> n;
		} while (n == 1);
	}
	if (choice == 5)
	{
		int j = 0;
		float zong1 = 0;
		do
		{
			zong1 = zong1 + a[j].zongfen;
			j++;
		} while (j < max);
		cout << "总分为" << zong1 << endl;
		cout << "平均分为:" << zong1 / max << endl;
		do {
			int t, m, n;
			float k = 0;
			cout << "输入评判分数：";
			cin >> m;
			for (t = 0; t < max; t++)
			{
				if (a[t].zongfen > m)
					k++;
			}
			cout << "超过评判分数人数为：" << k << endl;
			cout << "比例为：" << k / max << endl;
			cout << "是否使用别的评判分数评判：是【1】否【2】";
			cin >> n;
		} while (n == 1);
	}
}
int main()
{
	cout << "输入人数：";
	cin >> max;
	student1 s;
	s.input();
	cout << "请选择你想实现的功能：" << endl;
	cout << "显示成绩【1】" << endl;
	cout << "添加成绩【2】" << endl;
	cout << "搜索成绩【3】" << endl;
	cout << "改变成绩【4】" << endl;
	cout << "成绩排序【5】" << endl;
	cout << "成绩删除【6】" << endl;
	cout << "成绩分析【7】" << endl;
	cout << "成绩输出【8】" << endl;
	int Choice;
	do
	{
		cin >> Choice;
		switch (Choice)
		{
		case 0:break;
		case 1:s.show(); break;
		case 2:s.add(); break;
		case 3:s.search(); break;
		case 4:s.change(); break;
		case 5:s.sort(); break;
		case 6:s.Delete(); break;
		case 7:s.analysis(); break;
		case 8:s.save(); break;
		}
		cout << "是否继续执行：是【1】否【0】";
		cin >> Choice;
		cout << "请选择你想实现的功能：" << endl;
		cout << "显示成绩【1】" << endl;
		cout << "添加成绩【2】" << endl;
		cout << "搜索成绩【3】" << endl;
		cout << "改变成绩【4】" << endl;
		cout << "成绩排序【5】" << endl;
		cout << "成绩删除【6】" << endl;
		cout << "成绩分析【7】" << endl;
		cout << "成绩输出【8】" << endl;
	} while (Choice != 0);
	return 0;
}