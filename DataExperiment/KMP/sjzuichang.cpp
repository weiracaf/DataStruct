#include <stdio.h>
#define MaxSize 100
typedef struct {
	char data[MaxSize]; //串中字符
	int length; //串长
} SqString; //声明顺序串类型

void init(SqString &s)
{
	s.length=0;
}

int insert(SqString &s,char a)
{
	if(s.length>=MaxSize)
		return 0;//溢出返回 
	s.data[s.length++]=a;
  return 1;
}

void print(SqString s)
{
	for(int i=0;i<s.length;i++)
		printf("%c",s.data[i]);
	s.data[s.length]='\0';//这个语句也可以写在主函数里，那样的话只用调用一次 

}

void Longest_substrings(SqString s,SqString &sub)
{
	int i,j,k,length,loc=0;
	for(i=0;i<s.length;i++)
	{		
		for(j=i+1;j<s.length;)
		{
			if(s.data[i]==s.data[j])
			{
				length=1;
				for(k=1;s.data[i+k]==s.data[j+k];k++)
					length++;
				if(length>sub.length)
				//这里取不取等号决定了是否为第一个最长重复子串
				{
					sub.length=length;					
					loc=i;
				}
				j+=length;
			}
			else  j++;
		}
	}
	for(i=loc,j=0;i<sub.length+loc;i++,j++)
	{
		sub.data[j]=s.data[i];
	}	
}

int main()
{   
	char a[100];
	SqString str1,sub1;
	init(str1);	init(sub1);
	printf("输入串:");
	//gets(a);
	scanf("%s",a);
	for(int i=0;a[i]!='\0';i++)
	{
		insert(str1,a[i]);
	}
	printf("求最长重复子串:\n");
	printf("原串:");
	//puts(str1.data);
	printf("%s",str1.data);
	Longest_substrings(str1,sub1);
	printf("\n最长重复子串:");
	print(sub1);
}

