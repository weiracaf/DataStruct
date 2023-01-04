#include <stdio.h>
#define MaxSize 100
typedef struct {
	char data[MaxSize]; //�����ַ�
	int length; //����
} SqString; //����˳������

void init(SqString &s)
{
	s.length=0;
}

int insert(SqString &s,char a)
{
	if(s.length>=MaxSize)
		return 0;//������� 
	s.data[s.length++]=a;
  return 1;
}

void print(SqString s)
{
	for(int i=0;i<s.length;i++)
		printf("%c",s.data[i]);
	s.data[s.length]='\0';//������Ҳ����д��������������Ļ�ֻ�õ���һ�� 

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
				//����ȡ��ȡ�Ⱥž������Ƿ�Ϊ��һ����ظ��Ӵ�
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
	printf("���봮:");
	//gets(a);
	scanf("%s",a);
	for(int i=0;a[i]!='\0';i++)
	{
		insert(str1,a[i]);
	}
	printf("����ظ��Ӵ�:\n");
	printf("ԭ��:");
	//puts(str1.data);
	printf("%s",str1.data);
	Longest_substrings(str1,sub1);
	printf("\n��ظ��Ӵ�:");
	print(sub1);
}

