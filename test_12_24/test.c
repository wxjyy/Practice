#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>

# if 0
//size_t strlen(const char* str)
//①计数器方式
size_t my_strlen(const char* str)
{
	assert(str);
	size_t count = 0;
	while (*str!='\0')
	{
		count++;
		str++;
	}
	return count;
}
//②指针-指针
 size_t my_strlen(const char* str)
{
	 assert(str);
	 char* start = str;
	 while (*str) //while(*str++){;}结果是7，因为*str是\0后，为假，不再进入while循环，然后str再++，指向\0后面的位置
				  //while(*++str){;}是正确的，str指向f时，str先++，指向\0，再解引用，为假跳出循环，此时str还是指向\0
	 {
		 str++;
	 }
	 return str - start;
}
 //③递归
size_t my_strlen(const char* str)
{
	assert(str);
	if (*str == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + my_strlen(str + 1);//a bcdef -> a b cdef -> a b c def -> a b c d ef -> a b c d e f
	}
}
int main()
{
	char arr[] = "abcdef";
	printf("%d\n", my_strlen(arr));
	return 0;
}
# endif


// char* strcpy(char* destination, const char* source)
//返回值是目标空间的起始地址
//源字符串必须以\0(或0,（\0的ASCII值为0）)结束，不然会一直往后拷贝，直到遇到\0
//目标空间不能是常量，必须可变
//int main()
//{
//	char arr[] = "xxxxxx";
//	char* p = "abc";
//	strcpy(arr, p);
//	printf("%s\n", arr);
//	//字符串最后的\0也要拷贝过去
//	//arr[]:a b c \0 x x
//	//打印结果：abc
//}
# if 0
//模拟实现
char* my_strcpy(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;
	while (*dest++ = *src++)//*src为\0时，赋给*dest后，while（）里为假，dest和src再++指向\0后的位置
	{
		;
	}
	return ret;
}
int main()
{
	char arr[] = "xxxxxx";
	char* p = "abc";
	my_strcpy(arr, p);
	printf("%s\n", arr);
	return 0;
}
# endif

//char* strcat(char* destination, const char* source)
//将source从destination中\0的位置开始拷贝
# if 0
char* my_strcat(char* dest, const char* src)
{
	char* ret = dest;
	while (*++dest)
	{
		;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr[20] = "hello";
	my_strcat(arr, "world");
	printf("%s\n", arr);
}
# endif

//int strcmp(const char* str1, const char* str2)
//VS环境下
# if 0
int my_strcmp(const char* s1, const char* s2)
{
	assert(s1 && s2);
	while (*s1 == *s2)
	{
		if (*s1 == '\0')//一直比到最后一对\0了，说明两个字符串相等
		{
			return 0;
		}
		s1++;
		s2++;
	}
	if (*s1 > *s2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
//标准
int my_strcmp(const char* s1, const char* s2)
{
	assert(s1 && s2);
	while (*s1 == *s2)
	{
		if (*s1 == '\0')//一直比到最后一对\0了，说明两个字符串相等
		{
			return 0;
		}
		s1++;
		s2++;
	}
	return *s1 - *s2;
}
# endif

# if 0
char* my_strncpy(char* dest, const char* src, size_t num)
{
	char* start = dest;
	while (num && (*dest++ = *src++))
	{
		num--;
	}
	if (num)
	{
		while (num--)
			{
				*dest++ = '\0';
			}
	}
	return start;
}
int main()
{
	char arr1[] = "xxxxxxxx";
	char* p = "abc";
	printf("%s\n", my_strncpy(arr1, p, 6));
	//如果源字符串（"abc"）长度<num(6)，则拷贝完"abc"后，在目标后面追加\0，直到num个
	return 0;
}
# endif

# if 0
char* my_strncat(char* dest, const char* src, size_t num)
{
	char* start = dest;
	while (*dest)
	{
		dest++;
	}
	while (num--)
	{
		if (!(*dest++ = *src++))
		{
			return start;
		}
	}
	*dest = '\0';
}
int main()
{
	char arr1[20] = "abc\0xxxx";
	char arr2[] = "def";
	printf("%s\n",my_strncat(arr1, arr2, 5));
	return 0;
}
# endif

# if 0
//模拟实现strstr
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	char* tag = str1;
	while (*tag)
	{
		char* s1 = tag;
		char* s2 = str2;
		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return tag;
		tag++;
	}
	return NULL; 
}
int main()
{
	char* str1 = "abbbcdef";
	char* str2 = "bbc";
	char* ret = my_strstr(str1, str2);
	if (ret == NULL)
	{
		printf("找不到\n");
	}
	else
		printf("%s\n", ret);
	return 0;
}
# endif

//char* strtok(char* str, const char* sep)
int main()
{
	char arr[] = "451018425@qq.com";
	char buf[20] = { 0 };
	strcpy(buf, arr);
	char* sep = "@.";
	char* ret = NULL;
	for (ret = strtok(buf, sep); ret != NULL; ret = strtok(NULL, sep))
	{
		printf("%s\n", ret);
	}
	return 0;
}