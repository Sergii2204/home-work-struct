#include<iostream>
#include<string>
#include<iomanip>
#include<time.h>
#include <conio.h>
#include<fstream>
#include <windows.h>
using namespace std;
//�������� ��������� ������� ������� ���� ����� ��� ��������.
struct Date
{
	int day;
	int mouth;
	int year;
	void Filldate(int min, int max)//������� ������� ��������� ������� ��������� ����� ���� ����� � ��� �������� 
	{
		day = 1 + rand() % 31;
		mouth = 1 + rand() % 12;
		year = min + (rand() % (max - min));
	}
	void Printdate()//������� ������� ������� ���� ����� ��� ��������
	{
		
		cout << "*\t\t\t\t\t\t\  *\n*\t  day" << "  " << day << "  " << "mouth" << "  " << mouth << "  " << "year" << " " << year<<"\t\t  *" << endl;
	}
};
//��������� ������� ������� ���������
struct Student
{
	string FirstName;
	string lastName;
	float Avg;
		Date date;
		bool Vidminnuk;
		bool Pilgovik;
		int marks[10];

		void MarksRendom()//������� �������� ������ ��������
		{
			int const size = 10;
			int a = rand() % 10;
			if (a == 0)
			{
				Vidminnuk = true;
				for (int i = 0; i < size; i++)
				{
					marks[i] = 10 + rand() % (10 - 12);

				}
			}
			else
			{
				Vidminnuk = false;
				for (int i = 0; i < size; i++)
				{
					marks[i] = rand() % 12 + 1;
				}

			}

		}
		void MarksPrint()//������� ������� ������ ��������
		{
			
			int const size = 10;
			for (int i = 0; i < size; i++)
			{
				cout << marks[i] << " ";
			}

			
		}
		void SerBal()//������� ������� ������� ��� ������������ ��������
		{
			int sum = 0;
			for (int i = 0; i < 10; i++)
			{
				sum += marks[i];
			}
			Avg = sum / 10.0;
		}
		void FillPilgovik()//������� ������� ������� ���������
		{

			int a = rand() % 10;
			if (a == 0)
			{
				Pilgovik=true;
			}
			else
			{
				Pilgovik = false;
			}
		}

	void FillSudent()//������� �������� ��������
	{
		string sn[10] = { "����������", "������", "������", "�����", "�������", "������", "��������", "�������", "���������", "�������" };
		string n[10] = { "������", "����", "�������", "���������", "������", "������", "�����", "���������", "������", "�����" };
		int a, d;
		a = rand() % 9;
		d = rand() % 9;
		FirstName = sn[a];
		lastName = n[d];
		date.Filldate(1984, 2020);
		MarksRendom();
		SerBal();
		FillPilgovik();

	}
	void PrintStudent()//������� ������� ��������
	{
			cout << "*\t\t         \t\t\t  *\n*\t\t\t\t\t\t  *\n" << "*\t\t"<< FirstName <<"  "<< lastName<<"\t\t     *"<<endl;
			date.Printdate();
			cout << "\n������       ";
			MarksPrint();
			cout << endl<<endl;
	}
};
//��������� ������� ������� �������
struct Teacher
{
	string FirstName;
	string lastName;
	int Datedate;
	Date date;
	void FillTeacher()//������� ������� �������� �������
	{
	string fi[3] = { "������", "�����", "�����"};
	string la[3] = { "������", "����", "�������"};
	int w, e;
	w = rand() % 2;
	e = rand() % 2;
	FirstName = fi[w];
	lastName = la[e];
	date.Filldate(1950,2020);
	}
	void PrintTeacher()//������� ������� ��������
	{
		cout << "***************************************************\n*\t\t\t\t\t\t  *\n";
		cout << "*\t\tTEACHER  \t\t\t  *\n*\t\t\t\t\t\t  *\n"<< "*\t\t" << FirstName << " " << lastName<<"\t\t\t  *" << endl;
		date.Printdate();
		cout << "*\t\t\t\t\t\t  *\n***************************************************\n\n";
	}
};
//��������� ������� ������� ������
struct Group
{
	string Name;
	Teacher Teacher;
	Student Student[5];
	int counter = 0;
	float Avg=0;
	void FillGroup(string name)//������� ������� ������� ������
	{
		Name = name;
		Teacher.FillTeacher();
		int const size = 5;
		for (int i = 0; i < size; i++)
		{
		Student[i].FillSudent();
		Avg += Student[i].Avg;
		}
		Avg = Avg / 5.0;
	}
	void PrintGroup()//������� ������� ������� ������
	{
		cout << "***************************************************\n*\t\t\t\t\t\t  *\n";
		cout << "*\t\tGroup" << "  " << Name <<"\t\t\t  *" << endl;
		cout << "*\t\t\t\t\t\t  *\n***************************************************\n\n";
			Teacher.PrintTeacher();
			int const size = 5;
			for (int i = 0; i < size; i++)
			{
				Student[i].PrintStudent();
			}
	}
};
void ScoolBoyExcellent(Group* Name)//������� ������� ��������� � ���������� �� ����������
{
	int a = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j <5; j++)
		{
			if (Name[i].Student[j].Vidminnuk)
			{
				Name[i].Student[j].PrintStudent();
				a++;
			}

		}
	}
	cout << "���������� ���������� =  " << a << endl;
}

void Excellent(Group* Name)//������� ������� ����� �������� ������
{
	int index = 0;
	int max = 0;
	for (int i = 0; i < 3; i++)
	{
		if (max < Name[i].Avg)
		{
			max = Name[i].Avg;
			index = i;
		}

	}
	cout << "\n������� � �������� ������ ����� �������� �� ������\n";
	Name[index].Teacher.PrintTeacher();
	
}
void Excellentgrups(Group* Name)//�������� ������� �����
{
	int index = 0;
	int min = Name[0].Avg;
	for (int i = 0; i < 3; i++)
	{
		if (min > Name[i].Avg)
		{
			min = Name[i].Avg;
			index = i;
		}
	}
	cout << "\n\t������ � ������ �������������\n\n";
	cout<<"\t\t"<<Name[index].Name<<endl;
}

void GotBackinOneDay(Group* Name)//������� ������� �������� � ������� ���� �������� � ���� ����
{
	int GetGotBackinOneDay = Name[0].Student[0].date.day;
	cout << "\t���� � ������� ���� �������� � ���� ����" << endl;
	for (int a = 0; a < 3; a++)
	{
		for (int s = 0; s < 5; s++)
		{
			GetGotBackinOneDay = Name[a].Student[s].date.day;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (GetGotBackinOneDay == Name[i].Student[j].date.day && j!=s)
					{
						Name[i].Student[j].PrintStudent();
						Name[a].Student[s].PrintStudent();
					}
				}
			}
		}
	}
}

void GetMinDate(Group* Name)//������� ������� ������� ������ �������� ��������
{
	int intex = 0;
	
	int maxDateYear = Name[0].Student[0].date.year;
	int maxDateM = Name[0].Student[0].date.mouth;
	int maxDated = Name[0].Student[0].date.day;
	Student* arr1 = new Student[15];
	for (int i = 0, s = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++, s++)
		{
			arr1[s] = Name[i].Student[j];
		}
	}
	for (int i = 0; i < 14; i++)
	{
		if (maxDateYear > arr1[i+1].date.year)
		{
			maxDateYear = arr1[i + 1].date.year;
			intex = i+1;
		}
		else
		{
			if (maxDateYear == arr1[i + 1].date.year)
			{
				if (maxDateM > arr1[i + 1].date.mouth)
				{
					maxDateM = arr1[i + 1].date.mouth;
					intex = i + 1;
				}
				else if (maxDateM == arr1[i + 1].date.mouth)
				{
					if (maxDated > arr1[i + 1].date.day)
					{
						maxDated = arr1[i + 1].date.day;
						intex = i + 1;
					}
				}
			}
		}
	}
	cout << "\n\t\t����� ������� ������ �� ������\n\n";
	arr1[intex].PrintStudent();

}
void Seredne(Group* Name)//������� ������� ������� �������� � ������� ������� ��� ������ 8,5
{
	int a = 0;
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (Name[i].Student[j].Avg>8.5)
			{
				a++;
			}
		}
	}
	cout << "\n\t���������� �������� ��� ������� ������ 8.5  =" << " " << a << endl;
}

void PilgovikStudent(Group* Name)//������� ������� ���������� ����������
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (Name[i].Student[j].Pilgovik == true)
			{
				Name[i].counter++;
			}
		}
	}
	int index = 0;
	int max = Name[0].counter;
	for (int i = 0; i < 3; i++)
	{
			if (max < Name[i].counter)
			{
				max = Name[i].counter;
				index = i;
			}
		
	}
	cout << " \n\n\n\t\t\t���������� ���������� �� ������ \n\n";
	cout<<" \t\t\t\t "<<Name[index].counter<<" �������\n";
}

void printgroup(Group* Name)
{
	for (int i = 0; i < 3; i++)
	{
		Name[i].PrintGroup();
	}
}
void SetColor(int col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

void SetPos(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void Size_Console(int x, int y)
{
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { x, y };
	SMALL_RECT src = { -30, 5, crd.X , crd.Y };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);
}
int Menu(string menu_items[], int SIZE) {
	int key = 0;
	int code;
	do {
		key = (key + SIZE) % SIZE;
		for (int i = 0; i < SIZE; i++)
		{
			SetPos(15, 15 + i);
			if (key == i)
			{
				cout << " "; SetColor(6); cout << menu_items[i]; SetColor(3); cout << " " << endl; SetColor(15);
			}
			else
			{
				cout << " "; cout << menu_items[i]; cout << " " << endl;
			}
		}
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}




void main()
{

	srand(time(0));
	setlocale(LC_ALL, "rus");
	int marks[10];
	int arr1[15];
	Date date;
	int intex;
	string g[3] = { "1.�����","2.�����","3,�����" };
	Group* Name = new Group[3];
	{
		int const size = 3;
		for (int i = 0; i < size; i++)
		{
			Name[i].FillGroup(g[i]);
		}
	}
	Student* students = new Student[5];
	{
		for (int i = 0; i <5; i++)
		{
			students[i].FillSudent();
		}
	}
	Teacher* teacher = new Teacher[3];
	{
		
		int const size = 3;
		for (int i = 0; i < size; i++)
		{
			teacher[i].FillTeacher();
			
		}

	}
	       /* for (int i = 0; i < 3; i++)
			{
				Name[i].PrintGroup();
			}*/
	Size_Console(45, 35);
	int m = 0;
	do
	{
	string menu[] = { "����� ����� � ��������","������� ���� ����������","������� ������� ������ � ������ �������������","������� ������ � ������ �������������","������� ����� ������� �������� � ���� ����","������� �������� �������","������� �������� ������� ����� ������� ��� ������ 8,5","������� ���������� ����������","�����" };
	m = Menu(menu, size(menu));

	if (m == 0)
	{
		printgroup(Name);
	}
	if (m == 1)
	{
	 ScoolBoyExcellent(Name);
	}
	if (m == 2)
	{
     Excellent(Name);
	}
	if (m == 3)
	{
    Excellentgrups(Name);
	}
	if (m == 4)
	{
    GotBackinOneDay(Name);
	}
	if (m == 5)
	{
    GetMinDate(Name);
	}
	if (m == 6)
	{
    Seredne(Name);
	}
	if (m == 7)
	{
    PilgovikStudent(Name);
	}

	cout << "\n\n\t\t\t�����\n\n";
		system("pause");
		system("cls");
	} while (m != 8);
system("pause");
}