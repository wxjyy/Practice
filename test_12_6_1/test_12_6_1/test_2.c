#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



/*struct stu
{
	char name[20];
	int age;
	char id[20];
}s1,s2;*/ //s1,s2��ȫ�ֱ�������s�Ǿֲ����������Ƕ���struct stu���͵Ľṹ�����

/*typedef struct stu
{
	char name[20];
	int age;
	char id[20];
}stu; */ //stu��������,��main�����оͿ�����������ṹ�������stu s;��struct stu s;һ��

# if 0
struct B
{
	int a;
	char b;
	double c;
}s;

struct stu //�ṹ�����ͣ���int��float��doubleһ����
{
	char name[20]; //��Ա�б���Ա������name,age,id
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
	printf("%.2lf\n", s.s.c);//%lfС�����6λ  %.2lfС�������λ
}
void print2(struct stu* ps)
{
	printf("%s\n", ps->name);
	printf("%d\n", ps->age);
	printf("%s\n", ps->id);
	printf("%d\n", ps->s.a);
	printf("%c\n", ps->s.b);
	printf("%.2lf\n", ps->s.c);//%lfС�����6λ  %.2lfС�������λ
}
int main()
{
	struct stu s = { "����", 22, "2001210159", 1, 'a', 3.14 };//����Ϊstruct stu�Ľṹ�����s
	print1(s);
	print2(&s);
	return 0;
}
# endif
//�ṹ�崫��ʱ��Ҫ���ṹ��ĵ�ַ


