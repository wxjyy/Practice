#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



/*struct stu
{
	char name[20];
	int age;
	char id[20];
}s1,s2;*/ //s1,s2是全局变量，而s是局部变量，它们都是struct stu类型的结构体变量

/*typedef struct stu
{
	char name[20];
	int age;
	char id[20];
}stu; */ //stu是类型名,在main函数中就可以这样定义结构体变量：stu s;和struct stu s;一样

# if 0
struct B
{
	int a;
	char b;
	double c;
}s;

struct stu //结构体类型（跟int、float、double一样）
{
	char name[20]; //成员列表，成员变量：name,age,id
	int age;
	char id[20];
	struct B s;
};
void print1(struct stu s)
{
	printf("%s\n", s.name);
	printf("%d\n", s.age);
	printf("%s\n", s.id);
	printf("%d\n", s.s.a);
	printf("%c\n", s.s.b);
	printf("%.2lf\n", s.s.c);//%lf小数点后6位  %.2lf小数点后两位
}
void print2(struct stu* ps)
{
	printf("%s\n", ps->name);
	printf("%d\n", ps->age);
	printf("%s\n", ps->id);
	printf("%d\n", ps->s.a);
	printf("%c\n", ps->s.b);
	printf("%.2lf\n", ps->s.c);//%lf小数点后6位  %.2lf小数点后两位
}
int main()
{
	struct stu s = { "万欣", 22, "2001210159", 1, 'a', 3.14 };//类型为struct stu的结构体变量s
	print1(s);
	print2(&s);
	return 0;
}
# endif
//结构体传参时，要传结构体的地址


