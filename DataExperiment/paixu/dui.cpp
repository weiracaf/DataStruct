#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MaxLen 9                //���ʵ���󳤶�
#define Radix  27               //����rdΪ27,�ֱ��Ӧ' ','a',��'z'
typedef char String[MaxLen+1];
typedef struct node
{
    String word;
    struct node *next;
} LinkNode;
void DispWord(String R[],int n) //�������
{
    int i;
    printf("  ");
    for (i=0; i<n; i++)
        printf("[%s] ",R[i]);
    printf("\n");
}
void PreProcess(String R[],int n)
//�Ե��ʽ���Ԥ����,�ÿո����β����MaxLen��
{
    int i,j;
    for (i=0; i<n; i++)
    {
        if (strlen(R[i])<MaxLen)
        {
            for (j=strlen(R[i]); j<MaxLen; j++)
                R[i][j]=' ';
            R[i][j]='\0';
        }
    }
}
void EndProcess(String R[],int n)
//�ָ�����,ɾ��Ԥ����ʱ����β���ո�
{
    int i,j;
    for (i=0; i<n; i++)
    {
        for (j=MaxLen-1; R[i][j]==' '; j--);
        R[i][j+1]='\0';
    }
}
void Distribute(String R[],LinkNode *head[],LinkNode *tail[],int j,int n)
//���ؼ��ֵĵ�j���������з���,����˹���ʱ������һ��Ϊ��
{
    int i,k;
    LinkNode *p;
    for (i=0; i<n; i++)         //����ɨ��R[i],�������
    {
        if (R[i][j]==' ')       //�ո�ʱ����0�Ŷ�����,'a'ʱ����1�Ŷ�����,��
            k=0;
        else
            k=R[i][j]-'a'+1;
        p=(LinkNode *)malloc(sizeof(LinkNode)); //�����½��
        strcpy(p->word,R[i]);
        p->next=NULL;
        if (head[k]==NULL)
        {
            head[k]=p;
            tail[k]=p;
        }
        else
        {
            tail[k]->next=p;
            tail[k]=p;
        }
    }
}
void Collect(String R[],LinkNode *head[])
//���ν����ǿն����еļ�¼�ռ�����
{
    int k=0,i;
    LinkNode *p;
    for (i=0; i<Radix; i++)
        for (p=head[i]; p!=NULL; p=p->next)
            strcpy(R[k++],p->word);
}
void RadixSort(String R[],int n)    //��R[0..n-1]���л�������
{
    LinkNode *head[Radix],*tail[Radix]; //����Radix������
    int i,j;
    for (i=MaxLen-1; i>=0; i--)             //�ӵ�λ����λ��d��������
    {
        for (j=0; j<Radix; j++)
            head[j]=tail[j]=NULL;           //�����ÿ�
        Distribute(R,head,tail,i,n);        //��i�˷���
        Collect(R,head);                    //��i���ռ�
    }
}
int main()
{
    int n=6;
    String R[]= {"ccle","ant","and","do","do it","abandon"};
    printf("����ǰ:\n");
    DispWord(R,n);
    PreProcess(R,n);
    RadixSort(R,n);
    EndProcess(R,n);
    printf("������:\n");
    DispWord(R,n);
    printf("\n");
    return 0;
}