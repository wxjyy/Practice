#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>

# if 0
//size_t strlen(const char* str)
//�ټ�������ʽ
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
//��ָ��-ָ��
 size_t my_strlen(const char* str)
{
	 assert(str);
	 char* start = str;
	 while (*str) //while(*str++){;}�����7����Ϊ*str��\0��Ϊ�٣����ٽ���whileѭ����Ȼ��str��++��ָ��\0�����λ��
				  //while(*++str){;}����ȷ�ģ�strָ��fʱ��str��++��ָ��\0���ٽ����ã�Ϊ������ѭ������ʱstr����ָ��\0
	 {
		 str++;
	 }
	 return str - start;
}
 //�۵ݹ�
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
//����ֵ��Ŀ��ռ����ʼ��ַ
//Դ�ַ���������\0(��0,��\0��ASCIIֵΪ0��)��������Ȼ��һֱ���󿽱���ֱ������\0
//Ŀ��ռ䲻���ǳ���������ɱ�
//int main()
//{
//	char arr[] = "xxxxxx";
//	char* p = "abc";
//	strcpy(arr, p);
//	printf("%s\n", arr);
//	//�ַ�������\0ҲҪ������ȥ
//	//arr[]:a b c \0 x x
//	//��ӡ�����abc
//}
# if 0
//ģ��ʵ��
char* my_strcpy(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;
	while (*dest++ = *src++)//*srcΪ\0ʱ������*dest��while������Ϊ�٣�dest��src��++ָ��\0���λ��
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
//��source��destination��\0��λ�ÿ�ʼ����
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
//VS������
# if 0
int my_strcmp(const char* s1, const char* s2)
{
	assert(s1 && s2);
	while (*s1 == *s2)
	{
		if (*s1 == '\0')//һֱ�ȵ����һ��\0�ˣ�˵�������ַ������
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
//��׼
int my_strcmp(const char* s1, const char* s2)
{
	assert(s1 && s2);
	while (*s1 == *s2)
	{
		if (*s1 == '\0')//һֱ�ȵ����һ��\0�ˣ�˵�������ַ������
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
	//���Դ�ַ�����"abc"������<num(6)���򿽱���"abc"����Ŀ�����׷��\0��ֱ��num��
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
//ģ��ʵ��strstr
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
		printf("�Ҳ���\n");
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