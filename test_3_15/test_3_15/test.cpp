#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//class Test
//{
//public:
//	Test(int data = 0)  //Test(Test *const this, int data = 0)
//	{
//		m_data = data;
//		cout << "Create Test Obj:" << this << endl;
//	}
//	Test(const Test &t)
//	{
//		m_data = t.m_data;
//		cout << "Copy Create Test Obj:" << this << endl;
//	}
//	Test& operator=(const Test &t)//Test& operator=(Test *const this, const Test &t)
//	{
//		cout << "Assign," << this << ":" << &t << endl;
//		if (this != &t)//判断自己是否给自己赋值
//		{
//			m_data = t.m_data;
//		}
//		return *this;
//	}
//	~Test()
//	{
//		cout << "Free Test Obj :" << this << endl;
//	}
//private:
//	int m_data;
//};
//
//void main()
//{
//	Test t1(10);  //t.Test(10) ==> Test(&t,10)
//	Test t2 = t1;  //t2.Test(t1) ==> Test(&t2,t1)
//	Test t3;
//	t3 = t2;  //t3.operator(t2) ==> operator(&t3, t2)
//}


//class Test
//{
//public:
//	Test(int data = 0)  //Test(Test *const this, int data = 0)
//	{
//		m_data = data;
//		cout << "Create Test Obj:" << this << endl;
//	}
//	Test(const Test &t)  //Test(Test *const this, const Test &t)
//	{
//		m_data = t.m_data;
//		cout << "Copy Create Test Obj:" << this << endl;
//	}
//	~Test()
//	{
//		cout << "Free Test Obj :" << this << endl;
//	}
//public:
//	int GetData()const
//	{
//		return m_data;
//	}
//private:
//	int m_data;
//};
//
//Test fun(Test x)
//{
//	int value = x.GetData();
//	Test tmp(value);
//	return tmp;
//}
//
//void main()
//{
//	Test t1(10); 
//	Test t2 = t1;  //Test t2(t1) ==> t2.Test(t1) ==> Test(&t2, t1)
//	fun(t2);
//}

//class String
//{
//public:
//	String(const char *str = " ")
//	{
//		m_data = (char*)malloc(strlen(str) + 1);
//		strcpy(m_data, str);
//	}
//	~String()
//	{
//		free(m_data);
//		m_data = nullptr;
//	}
//private:
//	char *m_data;
//};
//void main()
//{
//	char ar[] = "hello cpp";
//	String str(ar);
//}

class Test
{
public:
	Test(int data = 0)  //Test(Test *const this, int data = 0)
	{
		m_data = data;
		cout << "Create Test Obj:" << this << endl;
	}
	Test(const Test &t)  //Test(Test *const this, const Test &t)
	{
		m_data = t.m_data;
		cout << "Copy Create Test Obj:" << this << endl;
	}
	Test& operator=(const Test &t)
	{
		cout << "Assign :" << this << ":" << &t << endl;
		if (this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	~Test()
	{
		cout << "Free Test Obj :" << this << endl;
	}
public:
	int GetData()const
	{
		return m_data;
	}
private:
	int m_data;
};

Test fun(const Test &x)
{
	int value = x.GetData();
	return Test(value);
}

void main()
{
	Test t1(10); 
	Test t2 = fun(t1);
}