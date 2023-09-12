#include<iostream>
#include<cmath>
#include<string>
#include <fstream>
using namespace std;
ifstream fin; //������

class point
{
public:
	double x;
	double y;
	point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
	};

};
template<class T>
double length(T c1, T c2)
{
	double Length = sqrt(pow((c1.x - c2.x), 2) + pow((c1.y - c2.y), 2));
	return Length;
}
class figure
{
public:
	/*int ID;*/
	figure() {};
	virtual ~figure() {};
	virtual double area() = 0;//����������� ������� �������
	virtual void move(double x, double y) = 0;
	virtual void read(string path) = 0;
	virtual void print() = 0;
	virtual void show_specific() = 0;
	virtual void show_coord() = 0;
	bool compare(figure* temp)
	{
		if (this->area() > temp->area())
			return true;
		else
			return false;
	}
};


class triangle : public figure
{
private:
	point A;
	point B;
	point C;
public:
	//triangle(){};
	triangle(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0, double x3 = 0, double y3 = 0);
	double area() override;
	void move(double x, double y) override;
	void read(string path) override;
	void print() override;
	double perimeter();
	double A_cos();
	double B_cos();
	double C_cos();
	bool virozd();
	double height();
	void show_specific() override;
	void show_coord() override;

	friend istream& operator>>(istream& in, triangle& temp)
	{
		cout << "Enter xA: ";
		in >> temp.A.x;
		cout << "Enter yA: ";
		in >> temp.A.y;
		cout << "Enter xB: ";
		in >> temp.B.x;
		cout << "Enter yB: ";
		in >> temp.B.y;
		cout << "Enter xC: ";
		in >> temp.C.x;
		cout << "Enter yC: ";
		in >> temp.C.y;
		return in;
	}

};
triangle* add_triangle()
{
	triangle* temp = new triangle;
	cin >> *temp;
	return temp;
}
void triangle::show_specific()
{
	cout << "������� ����� " << area() << endl;
	cout << "�������� ����� " << perimeter() << endl;
	if (virozd())
		cout << "����������� ����������� "<< endl;
	else
		cout << "����������� �� ����������� " << endl;
	cout << "���� A ����� " << A_cos() << "�" << endl;
	cout << "���� B ����� " << B_cos() << "�" << endl;
	cout << "���� C ����� " << C_cos() << "�" << endl;
	cout << "������ ����� " << height() << endl;
}
void triangle::show_coord()
{
	cout << "���������� ����� "<< endl;
	cout << "A(" << A.x << ";" << A.y << ")" << endl;
	cout << "B(" << B.x << ";" << B.y << ")" << endl;
	cout << "C(" << C.x << ";" << C.y << ")" << endl;
}
double triangle::height()
{
	double AB = sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));
	double h = 2 * area() / AB;
	return h;
}
bool triangle::virozd()
{
	double AB = sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));
	double CA = sqrt(pow((C.x - A.x), 2) + pow((C.y - A.y), 2));
	double BC = sqrt(pow((C.x - B.x), 2) + pow((C.y - B.y), 2));
	double max = 0;

	if (AB > BC && AB > CA) 
		max = AB;
	if (BC > AB && BC > CA) 
		max = BC;
	if (CA > AB && CA > BC) 
		max = CA;

	if (max == perimeter() / 2)//���� �����������, �� ���������� ������� ����� �������������
		return true;
	else
		return false;

}
double triangle::perimeter()
{
	return sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2)) + sqrt(pow((C.x - A.x), 2) + pow((C.y - A.y), 2)) + sqrt(pow((C.x - B.x), 2) + pow((C.y - B.y), 2));
}
double triangle::A_cos()
{
	double result;
	double AB = sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));
	double CA = sqrt(pow((C.x - A.x), 2) + pow((C.y - A.y), 2));
	double BC = sqrt(pow((C.x - B.x), 2) + pow((C.y - B.y), 2));
	double cosA = (pow(AB, 2) + pow(CA, 2) - pow(BC, 2)) / (2 * AB * CA);
	result = 180 / 3.14 * acos(cosA);
	return result;
}
double triangle::B_cos()
{
	double result;
	double AB = sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));
	double CA = sqrt(pow((C.x - A.x), 2) + pow((C.y - A.y), 2));
	double BC = sqrt(pow((C.x - B.x), 2) + pow((C.y - B.y), 2));
	double cosB = (pow(AB, 2) + pow(BC, 2) - pow(CA, 2)) / (2 * AB * BC);
	result = 180 / 3.14 * acos(cosB);
	return result;
}
double triangle::C_cos()
{
	double result;
	double AB = sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));
	double CA = sqrt(pow((C.x - A.x), 2) + pow((C.y - A.y), 2));
	double BC = sqrt(pow((C.x - B.x), 2) + pow((C.y - B.y), 2));
	double cosC = (pow(CA, 2) + pow(BC, 2) - pow(AB, 2)) / (2 * CA * BC);
	result = 180 / 3.14 * acos(cosC);
	return result;
}
triangle::triangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	this->A.x = x1;
	this->A.y = y1;
	this->B.x = x2;
	this->B.y = y2;
	this->C.x = x3;
	this->C.y = y3;
}
double triangle::area()
{
	return (abs((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y))) / 2;
}
void triangle::move(double x, double y)
{
	this->A.x = A.x + x;
	this->A.y = A.y + y;
	this->B.x = B.x + x;
	this->B.y = B.y + y;
	this->C.x = C.x + x;
	this->C.y = C.y + y;
}
void triangle::read(string path)
{
	fin >> this->A.x;
	fin >> this->A.y;
	fin >> this->B.x;
	fin >> this->B.y;
	fin >> this->C.x;
	fin >> this->C.y;
}
void triangle::print()
{
	cout << "X1: " << this->A.x << endl;
	cout << "Y1: " << this->A.y << endl;
	cout << "X2: " << this->B.x << endl;
	cout << "Y2: " << this->B.y << endl;
	cout << "X3: " << this->C.x << endl;
	cout << "Y3: " << this->C.y << endl;

}




class parallelogram : public figure
{
private:
	point A;
	point B;
	point C;
	point D;
public:
	//triangle(){};
	parallelogram(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0, double x3 = 0, double y3 = 0);
	double area() override;
	void move(double x, double y) override;
	void read(string path) override;
	void print() override;
	double find_D_Y();
	double find_D_X();
	double perimeter();
	double A_ang();
	double B_ang();
	double paral_length();
	double paral_width();
	double height();
	void show_specific() override;
	void show_coord() override;

	friend istream& operator>>(istream& in, parallelogram& temp)
	{
		cout << "Enter xA: ";
		in >> temp.A.x;
		cout << "Enter yA: ";
		in >> temp.A.y;
		cout << "Enter xB: ";
		in >> temp.B.x;
		cout << "Enter yB: ";
		in >> temp.B.y;
		cout << "Enter xC: ";
		in >> temp.C.x;
		cout << "Enter yC: ";
		in >> temp.C.y;
		temp.D.x = temp.find_D_X();
		temp.D.y = temp.find_D_Y();
		return in;
	}

};
parallelogram* add_parallelogram()
{
	parallelogram* temp = new parallelogram;
	cin >> *temp;
	return temp;
}
double parallelogram::paral_length()//����� ���������������
{
	double AB = sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));
	double BC = sqrt(pow((C.x - B.x), 2) + pow((C.y - B.y), 2));
	double max = 0;

	if (AB > BC)
		return AB;
	else
		return BC;
}
double parallelogram::paral_width()//������ ���������������
{
	double AB = sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));
	double BC = sqrt(pow((C.x - B.x), 2) + pow((C.y - B.y), 2));
	double max = 0;

	if (AB > BC)
		return BC;
	else
		return AB;
}
double parallelogram::area()
{
	return abs((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y));
}
double parallelogram::height()
{
	double AB = sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));
	double h = area() / AB;
	return h;
}
double parallelogram::perimeter()
{
	return 2*(length(A, B) + length(B, C));
}
double parallelogram::find_D_X()
{
	point O;
	O.x = (A.x + C.x) / 2;
	O.y = (A.y + C.y) / 2; 
	double D_x = 2 * O.x - B.x;
	return D_x;
}
double parallelogram::find_D_Y()
{
	point O;
	O.x = (A.x + C.x) / 2;
	O.y = (A.y + C.y) / 2;
	double D_y = 2 * O.y - B.y;
	return D_y;

}
double parallelogram::A_ang()
{
	double result;
	double AB = sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));
	double DA = sqrt(pow((D.x - A.x), 2) + pow((D.y - A.y), 2));
	double BD = sqrt(pow((D.x - B.x), 2) + pow((D.y - B.y), 2));
	double cosA = (pow(AB, 2) + pow(DA, 2) - pow(BD, 2)) / (2 * AB * DA);
	result = 180 / 3.14 * acos(cosA);
	return result;
}
double parallelogram::B_ang()
{
	double result;
	double AB = sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));
	double CA = sqrt(pow((C.x - A.x), 2) + pow((C.y - A.y), 2));
	double BC = sqrt(pow((C.x - B.x), 2) + pow((C.y - B.y), 2));
	double cosB = (pow(AB, 2) + pow(BC, 2) - pow(CA, 2)) / (2 * AB * BC);
	result = 180 / 3.14 * acos(cosB);
	return result;
}
void parallelogram::show_specific()
{
	cout << "������� ����� " << area() << endl;
	cout << "�������� ����� " << perimeter() << endl;
	cout << "����� A � C ����� " << A_ang() << "�" << endl;
	cout << "���� B � D ����� " << B_ang() << "�" << endl;
	cout << "����� ��������������� ����� " << paral_length() << endl;
	cout << "������ ��������������� ����� " << paral_width() << endl;
	cout << "������ ����� " << height() << endl;
	cout << "����� ��������� AC " << length(A, C) << endl;
	cout << "����� ��������� BD " << length(B, D) << endl;
}
void parallelogram::show_coord()
{
	cout << "���������� ����� " << endl;
	cout << "A(" << A.x << ";" << A.y << ")" << endl;
	cout << "B(" << B.x << ";" << B.y << ")" << endl;
	cout << "C(" << C.x << ";" << C.y << ")" << endl;
	cout << "D(" << D.x << ";" << find_D_Y() << ")" << endl;
}
parallelogram::parallelogram(double x1, double y1, double x2, double y2, double x3, double y3)
{
	this->A.x = x1;
	this->A.y = y1;
	this->B.x = x2;
	this->B.y = y2;
	this->C.x = x3;
	this->C.y = y3;
}
void parallelogram::move(double x, double y)
{
	this->A.x = A.x + x;
	this->A.y = A.y + y;
	this->B.x = B.x + x;
	this->B.y = B.y + y;
	this->C.x = C.x + x;
	this->C.y = C.y + y;
}
void parallelogram::read(string path)
{
	fin >> this->A.x;
	fin >> this->A.y;
	fin >> this->B.x;
	fin >> this->B.y;
	fin >> this->C.x;
	fin >> this->C.y;
}
void parallelogram::print()
{
	cout << "X1: " << this->A.x << endl;
	cout << "Y1: " << this->A.y << endl;
	cout << "X2: " << this->B.x << endl;
	cout << "Y2: " << this->B.y << endl;
	cout << "X3: " << this->C.x << endl;
	cout << "Y3: " << this->C.y << endl;

}

void main()
{
	setlocale(LC_ALL, "Rus");

	figure* F[2];

	F[0] = add_triangle();
	F[0]->show_coord();
	F[0]->show_specific();

	cout << endl;

	F[1] = add_parallelogram();
	F[1]->show_coord();
	F[1]->show_specific();

	cout << endl;

	if (F[0]->compare(F[1]))
		cout << "������� ������������ ������ ������� ���������������";
	else
		cout << "������� ��������������� ������ ������� ������������";

	cout << endl;
	system("pause");
}