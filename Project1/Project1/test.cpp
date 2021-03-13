#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

//int main()
//{
//	int a;
//	double b;
//	char c;
//
//	cin >> a >> b >> c;
//	cout << a << " " << b << " " << c << endl;
//	cout << "hello world!" << endl;
//	return 0;
//}

//void Func(int a, int b = 10, int c = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}

//int main()
//{
//	Func(0);
//	return 0;
//}

//void test()
//{
//	int a = 10;
//	int& b = a;
//	cout << &a << endl;
//	cout << &b << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}

//namespace N
//{
//	int a = 10;
//	int b = 20;
//
//	int Add(int x, int y)
//	{
//		return x + y;
//	}
//}
//
//using namespace N;
//int main()
//{
//	printf("%d\n", a);
//	Add(1, 2);
//	return 0;
//}

//void Func(int a = 0)
//{
//	cout << "a = " << a << endl;
//}
//int main()
//{
//	Func();
//	Func(10);
//}

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//double Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	Add(1, 2);
//	return 0;
//}

//void Func(int a = 10)
//{
//	cout << a << endl;
//}
//
//void Func(int a)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	Func(100);
//}

struct student
{
	char name[20];
	int age;
};

////变量的引用
//int a = 10;
//int &b = a;
//
////结构体变量的引用
//student stu;
//student &rstu = stu;
//
////数组的引用
//int ar[3] = { 1, 2, 3 };
//int(&br)[3] = ar;
//
////指针的引用
//int* ptr = &a;
//int*&q = ptr;

//void swap(int &x, int &y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//void main()
//{
//	int a = 10;
//	int b = 20;
//	cout << a << " " << b << endl;
//	swap(a, b);
//	cout << a << " " << b << endl;
//}

//int& fun(int a, int b)
//{
//	static int v = a + b;
//	return v;
//}
//
//void main()
//{
//	int res = fun(10, 20);
//	cout << "res = " << res << endl;
//}

//int test()
//{
//	return 10;
//}

//int main()
//{
//	int ar[10] = { 0 };
//	auto br = ar;
//	auto(&rar) = ar;
//
//	cout << typeid(br).name() << endl;
//	cout << typeid(rar).name() << endl;
//
//	return 0;
//}

//void test()
//{
//	int ar[] = { 1, 2, 3, 4, 5 };
//	for (auto& e : ar)//不用创建临时变量，效率更高
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (auto e : ar)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//}
//int main()
//{
//	test();
//	return 0;
//}