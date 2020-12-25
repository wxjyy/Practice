#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

# if 0
#include <ctype.h>
int main()
{
	char arr[] = "I have A pen";
	int i = 0;
	while (arr[i])
	{
		if (isupper(arr[i]))
		{
			arr[i] = tolower(arr[i]);
		}
		i++;
	}
	printf("%s\n", arr);
	return 0;
}
# endif

//void* memcpy(void* destination, const void* source, size_t num)
//strcpyֻ�ܿ����ַ�������memcpy���Կ�����������
# if 0
#include <string.h>
#include <assert.h>
void* my_memcpy(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;
		++(char*)dest;
		++(char*)src;
	}
	return ret;
}
int main()
{
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8};
	int arr2[5] = { 0 };
	my_memcpy(arr1+4, arr1+2, 16);//��arr1�е�5��Ԫ�أ���20���ֽڣ�������arr2��ȥ
	return 0;
}
# endif

//void* memmove(void* destination, const void* source, size_t num)
#include <string.h>
#include <assert.h>
void* my_memmove(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	if (dest < src)
	{
		//ǰ->��
		while (num--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
	}
	else
	{
		//��->ǰ
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return ret;
}
int main()
{
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	my_memmove(arr1 + 4, arr1 + 2, 16);//��arr1�е�5��Ԫ�أ���20���ֽڣ�������arr2��ȥ
	return 0;
}
