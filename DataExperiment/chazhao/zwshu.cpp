#include <stdio.h>

int findMedian(int[],int,int,int[],int,int);

int main() {

    int n;
    int a[10],b[10];

    printf("请输入序列长度:");       //输入序列长度
    scanf("%d",&n);
    printf("请输入长度为%d的两个序列:\n",n);        //输入两个等长序列
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d",&b[i]);
    }

    int x = findMedian(a, 0, n-1, b, 0, n-1);
    printf("%d\n",x);      //输出所有数的中位数
    

    return 0;
}

int findMedian(int a[],int i,int j,int b[],int m,int n) {       //主要思想：分别取两个序列1，2（假设为升序序列）的中位数a，b，如果a<b，说明序列1中位数左边的序列肯定不为所有数的中位数，就在下一次递归中删去左边部分；同理，说明序列2中位数右边的序列肯定不为所有数的中位数。
    
    int p = ( i + j ) / 2;      //取中位数
    int q = ( m + n ) / 2;
    
    if( a[p] == b[q] ) {       //当两个序列的中位数相等时即所有数的中位数
        return a[p];
    }
    
    if( j == i && n == m ) {     //当两个序列最后只剩一个数，取x较小值作为所有数的中位数
        if( a[i] < b[m] ) return a[i];
        else return b[m];
    }

    
    if ( a[p] < b[q] ) {      //当a<b,在下一次递归中删去a的左边部分，b的右边部分
        if( j-1 == i )       //值得注意的是，因为数组的下标都是整数，所以取中位数的下标只能为首下标与尾下标的向下取整，导致了当两个序列分别剩两个数的时候，取平均数永远无法改变导致死循环。举例，当序列1还剩3，4两个数，中位数为3，序列2还剩6，7两个数，中位数为7时，因为3<7，所以下次递归的序列应该为序列1：4，序列2：6，但由于取整的原因序列1的下标无法指向4，导致出错。
            p += 1;
        return findMedian(a, p, j, b, m, q);
        
    }else if( a[p] > b[q] ) {      //当a>b,在下一次递归中删去a的右边部分，b的左边部分
        if( n-1 == m )
            q += 1; 
        return findMedian(a, i, p, b, q, n);
        
    }
    
    return 0;
}
