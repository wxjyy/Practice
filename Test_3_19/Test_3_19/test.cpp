#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
#include<string.h>
#include<assert.h>
/*
class Complex
{
	friend Complex operator+(int val, const Complex &c);
	friend ostream& operator<<(ostream &out, const Complex &c);
public:
	//
	//Complex(int real, int imag)
	//{
	//	m_real = real;
	//	m_imag = imag;
	//}
	//
	//初始化列表
	Complex(int real = 0, int imag = 0) :m_real(real), m_imag(imag)
	{}
	Complex& operator=(const Complex &c)
	{
		if (this != &c)
		{
			m_real = c.m_real;
			m_imag = c.m_imag;
		}
		return *this;
	}
	~Complex()
	{}
public:
	Complex operator+(int val)
	{
		return Complex(m_real + val, m_imag);
	}
	Complex operator+(const Complex &c)
	{
		//Complex tmp(m_real + c.m_real, m_imag + c.m_imag);
		//return tmp;
		return Complex(m_real + c.m_real, m_imag + c.m_imag);
	}
public:
	bool operator==(const Complex &c)
	{
		return (m_real == c.m_real && m_imag == c.m_imag);
	}
	bool operator!=(const Complex &c)
	{
		//return (m_real != c.m_real || m_imag != c.m_imag);
		return !(*this == c);
	}
private:
	int m_real;
	int m_imag;
};

Complex operator+(int val, const Complex &c)
{
	return Complex(c.m_real + val, c.m_imag);
}

ostream& operator<<(ostream &out, const Complex &c)
{
	out << c.m_real << "," << c.m_imag << endl;
	return out;
}
void main()
{
	Complex c1(1, 3), c2(2, 5), c3, c4;
	Complex c;
	c = c1 + c2;//c = c1.operator+(c2);
	c3 = c1 + 10;
	c4 = 10 + c1;
	cout << c << endl;//operator<<(cout, t)
}*/

//构造函数给对象中的成员变量赋初值
//class Date
//{
//public:
//	Date(int y, int m, int d)
//	{
//		m_year = y;
//		m_month = m;
//		m_day = d;
//	}
//private:
//	int m_year;
//	int m_month;
//	int m_day;
//};
//
////初始化列表
//class Date
//{
//public:
//	 Date(int y) :m_year(y)
//	{}
//private:
//	int m_year;
//	int m_month;
//	int m_day;
//};
//void main()
//{
//	Date d(2020);
//	d = 2021;
//}

//class A
//{
//public:
//	A(int a):_a1(a), _a2(_a1)
//	{}
//
//	void Print()
//	{cout << _a1 << " " << _a2 << endl;}
//private:
//	int _a2;
//	int _a1;
//};
//
//void main()
//{
//	A aa(1);
//	aa.Print();
//}

//class Date
//{
//friend ostream& operator<<(ostream& out, const Date &d);
//public:
//	Date(int y) :m_year(y)
//	{}
//private:
//	int m_year;
//	int m_month;
//	int m_day;
//};
//
//ostream& operator<<(ostream& out, const Date &d)
//{
//	out << d.m_year << endl;
//	return out;
//}
//
//void main()
//{
//	Date d(2021);
//	cout << d ;
//}
//
//class Int
//{
//	friend ostream& operator<<(ostream &out, Int &i);
//public:
//	Int(int i = 0) :m_i(i)
//	{}
//	~Int()
//	{}
//public:
//	Int operator+(const Int &i)
//	{
//		return Int(m_i + i.m_i);
//	}
//	Int operator-(const Int &i)
//	{
//		return Int(m_i - i.m_i);
//	}
//	Int operator*(const Int &i)
//	{
//		return Int(m_i * i.m_i);
//	}
//	Int operator/(const Int &i)
//	{
//		return Int(m_i / i.m_i);
//	}
//	Int operator%(const Int &i)
//	{
//		return Int(m_i % i.m_i);
//	}
//public:
//	Int& operator+=(const Int &i)
//	{
//		m_i += i.m_i;
//		return *this;
//	}
//public:
//	bool operator==(const Int &i)
//	{
//		return m_i == i.m_i;
//	}
//	bool operator!=(const Int &i)
//	{
//		return !(*this == i);
//	}
//public:
//	//++a
//	Int& operator++()
//	{
//		m_i++;
//		return *this;
//	}
//	//a++
//	Int operator++(int)
//	{
//		Int tmp(*this);
//		m_i++;
//		return tmp;
//	}
//	//--a
//	Int& operator--()
//	{
//		m_i--;
//		return *this;
//	}
//	Int operator--(int)
//	{
//		Int tmp(*this);
//		--*this;
//		return tmp;
//	}
//public:
//	//强制类型转换
//	operator int()
//	{
//		return m_i;
//	}
//private:
//	int m_i;
//};
//
//ostream& operator<<(ostream &out, Int &i)
//{
//	out << i.m_i;
//	return out;
//}
//
//void main()
//{
//	//Int i;
//	//cout << "i = " << i << endl;
//	//Int a = 2;
//	//Int b = 2;
//	//Int ret;
//	//ret = a % b;
//	//a += 10;
//	//cout << "ret = " << ret << endl;
//	//cout << a == b ;
//	Int a = 1;
//	Int v = a++;
//	int value = (int)a;
//	cout << "v = " << v << endl;
//	cout << "a = " << a << endl;
//}

//class String
//{
//public:
//	String(const char *str = "")
//	{
//		m_data = (char*)malloc(strlen(str)+1);
//		assert(m_data != NULL);
//		strcpy(m_data, str);
//	}
//	//深拷贝
//	String(const String &s)
//	{
//		m_data = (char*)malloc(strlen(s.m_data) + 1);
//		assert(m_data != NULL);
//		strcpy(m_data, s.m_data);
//	}
//	//深赋值
//	String& operator=(const String &s)
//	{
//		if (this != &s)
//		{
//			free(m_data);
//			m_data = (char*)malloc(strlen(s.m_data) + 1);
//			assert(m_data != NULL);
//			strcpy(m_data, s.m_data);
//		}
//		return *this;
//	}
//	~String()
//	{
//		free(m_data);
//		m_data = nullptr;
//	}
//private:
//	char* m_data;
//};
//
//void main()
//{
//	char* str = "hello c++";
//	String s(str);
//	String s1(s);
//}

class Date
{
	friend ostream& operator<<(ostream &out, const Date &d);
public:
	bool IsLeap(int year)
	{
		return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	}
	int GetMonthDay(int year, int month)
	{
		int days[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && IsLeap(year))
			month = 0;
		return days[month];
	}
	//今天是今年的第几天
	int GetDayByYMD(int year, int month, int day)
	{
		int days = 0;
		for (int i = 1; i < month; ++i)
		{
			days += GetMonthDay(year, i);
		}
		days += day;
		return days;
	}
	int GetWeekByYMD(int year, int month, int day)
	{

	}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}
	Date(const Date &d)
	{
		m_year = d.m_year;
		m_month = d.m_month;
		m_day = d.m_day;
	}
	Date& operator=(const Date &d)
	{
		if (this != &d)
		{
			m_year = d.m_year;
			m_month = d.m_month;
			m_day = d.m_day;
		}
		return *this;
	}
	~Date()
	{}
public:
	Date operator+(int day)
	{
		Date tmp = *this;
		int days = GetMonthDay(tmp.m_year, tmp.m_month);
		while (tmp.m_day + day > days)
		{
			tmp.m_month++;
			if (tmp.m_month > 12)
			{
				tmp.m_year++;
				tmp.m_month = 1;
			}
			day -= days;
			days = GetMonthDay(tmp.m_year, tmp.m_month);
		}
		tmp.m_day += day;
		return tmp;
	}
	Date& operator+=(int day)
	{
		*this = *this + day;
		return *this;
	}
	Date operator-(int day)
	{
		Date tmp = *this;
		while (day >= tmp.m_day)
		{
			tmp.m_month--;
			if (tmp.m_month < 1)
			{
				tmp.m_year--;
				tmp.m_month = 12;
			}
			day -= tmp.m_day;
			tmp.m_day = GetMonthDay(tmp.m_year, tmp.m_month);
		}
		if (day < tmp.m_day)
		{
			tmp.m_day -= day;
		}
		return tmp;
	}
	Date& operator-=(int day)
	{
		*this = *this - day;
		return *this;
	}
	//++a
	Date& operator++()
	{
		m_day++;
		int days = GetMonthDay(m_year, m_month);
		if (m_day > days)
		{
			m_day = 1;
			m_month++;
			if (m_month > 12)
			{
				m_month = 1;
				m_year++;
			}
		}
		return *this;
	}
	//a++
	Date operator++(int)
	{
		Date tmp = *this;
		++(*this);
		return tmp;

	}
	//--a
	Date& operator--()
	{
		m_day--;
		if (m_day < 1)
		{
			m_month--;
			if (m_month<1)
			{
				m_year--;
				m_month = 12;
			}
			m_day = GetMonthDay(m_year, m_month);
		}
		return *this;
	}
	//a--
	Date operator--(int)
	{
		Date tmp = *this;
		--*this;
		return tmp;
	}
	bool operator>(const Date &d)
	{
		return (m_year > d.m_year)
			|| (m_year == d.m_year && m_month > d.m_month)
			|| (m_year == d.m_year && m_month == d.m_month && m_day > d.m_day);
	}
	bool  operator<=(const Date &d)
	{
		return !(*this > d);
	}
	bool operator<(const Date &d)
	{
		return (m_year < d.m_year)
			|| (m_year == d.m_year && m_month < d.m_month)
			|| (m_year == d.m_year && m_month == d.m_month && m_day < d.m_day);
	}
	bool  operator>=(const Date &d)
	{
		return !(*this < d);
	}
	bool operator==(const Date &d)
	{
		return (m_year == d.m_year && m_month == d.m_month && m_day == d.m_day);
	}
	bool operator!=(const Date &d)
	{
		return !(*this == d);
	}
private:
	int m_year;
	int m_month;
	int m_day;
};

ostream& operator<<(ostream &out, const Date &d)
{
	out << d.m_year << "-" << d.m_month << "-" << d.m_day << endl;
	return out;
}

void main()
{
	Date d1(2021, 3, 1);
	cout << d1 << endl;
	//++d1;
	//cout << d1 << endl;
	d1--;
	//d1 -= 62;
	cout << d1 << endl;

}

//void main()
//{
//	Date d1(2021, 5, 25);
//	Date d2(2021, 4, 25);
//	if (d1 == d2)
//		cout << "Equal" << endl;
//	else if (d1>d2)
//		cout << "d1 > d2" << endl;
//	else
//		cout << "d1 < d2" << endl;
//}