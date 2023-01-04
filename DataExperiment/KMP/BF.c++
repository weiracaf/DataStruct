#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//串普通模式匹配算法的实现函数，其中B为伪主串，A为伪自串
 int mate(char * B,char *A){
    int i =1,j=0;
    while(i<strlen(B) && j<strlen(A)){
        if(B[i]==A[j]){
            i++;
            j++;
        }else{
            i=i-j+1;//当前i的位置减去j回到开始的位置，然后加1，往后进一位
            j=0;
        }
    }
    //跳出循环有两种可能，i=strlen(B)说明已经遍历完主串，匹配失败；j=strlen(A),说明子串遍历完成，在主串中成功匹配
    if(j==strlen(A)){
        return i-strlen(A)+1;
    }
    //运行到此为止，i==strlen(B)的情况
    return 0;
}
int main()
{
    char *a=(char *)"ababcabcacbab";
    char *b=(char *)"abcac";
    int number=mate(a,b);
    printf("%d",number);
    return 0;
}

