#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define ARRLEN 10

void printIntArr(int arr[], size_t len);
void swap(int *a1, int *a2);
void bubbleSort(int arr[], size_t len);
void selectSort(int arr[], size_t len);
void insertSort(int arr[], size_t len);
void binaryInsertSort(int arr[], size_t len);
void mergeSort(int arr[], size_t len);
void mergeSort2(int arr[], int left, int right);
void quickSort2(int arr[], int left, int right);
void quickSort(int arr[], size_t len);

int main(int argc, char *argv[]) {
    int arr[ARRLEN];
    srand(time(NULL));

    for(int i=0;i<ARRLEN;i++) {//随机函数生成数组
        arr[i] = rand()%1000;
    }

    puts("原始数组为:");
    printIntArr(arr, ARRLEN);
     //bubbleSort(arr, ARRLEN);
     //puts("冒泡排序后的数组为:");
     //printIntArr(arr, ARRLEN);
     //puts("选择排序后的数组为:");
     //selectSort(arr, ARRLEN);
     //printIntArr(arr, ARRLEN);
    // insertSort(arr, ARRLEN);
    // puts("直接插入排序后的数组为:");
    // printIntArr(arr, ARRLEN);
    // binaryInsertSort(arr, ARRLEN);
    // puts("折半插入排序后的数组为:");
    // printIntArr(arr, ARRLEN);
     mergeSort(arr, ARRLEN);
     puts("归并排序后的数组为:");
     printIntArr(arr, ARRLEN);
    // arr_sort(arr,ARRLEN)
    // puts("希尔排序后的数组为:");
    // printIntArr(arr, ARRLEN);
    //quickSort(arr, ARRLEN);
    //puts("快速排序后的数组为:");
    //printIntArr(arr, ARRLEN);
}

//输出一个数组
void printIntArr(int arr[], size_t len) {
    for(int i=0;i<len;i++) {
        printf("%d ",arr[i]);
    }
    puts("");
}

//交换两个int元素
void swap(int *a1, int *a2) {
    int tmp = *a1;
    *a1 = *a2;
    *a2 = tmp;
}


//冒泡排序
void bubbleSort(int arr[], size_t len) {
    for(int i=0;i<len-1;i++) {
        for(int j=0;j<len-1-i;j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

//选择排序
void selectSort(int arr[], size_t len) {
    for(int i=0;i<len-1;i++) {
        int minIndex = i;
        for(int j=i+1;j<len;j++) {
            if(arr[j] < arr[minIndex]) {
                swap(&arr[j], &arr[minIndex]);
            }
        }
    }
}

//直接插入排序
void insertSort(int arr[], size_t len) {
    for(int i = 1;i<len;i++) {
        int key = arr[i];//先暂存i的值
        int j = i-1;
        while(j >=0 && key < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

//折半插入排序
void binaryInsertSort(int arr[], size_t len) {
    //对arr[i]的元素在[0, i]范围内排序
    for(int i=1;i<len;i++) {
        int key = arr[i];
        int begin = 0, end = i-1;
        while(begin <= end) {
            int mid = (begin + end)/2;
            if(key < arr[mid]) {
                end = mid - 1;
            }
            else begin = mid + 1;
        }
        //出循环后begin = end +1;
        //可能是begin = mid+1导致的，也可能是end = mid -1导致的
        //如果是begin = mid+1导致的，说明key > arr[mid] 而key又< arr[begin] 所以i要插入到mid+1的位置
        //如果是end = mid -1导致的，说明key < arr[mid] 而key又> arr[end] 所以i要插入到mid的位置
        //这两种情况下i其实都是插入到begin的位置
        int j;
        for(j=i-1;j>=begin;j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
}

//快速排序
void quickSort(int arr[], size_t len) {
    quickSort2(arr, 0, len-1);
}

void quickSort2(int arr[], int left, int right) {
    //如果数组长度为 1 ，则必然是有序的，直接返回
    if(left >= right) {
        return;
    }
    //以arr[left]为基准
    //双指针从首尾开始寻找key的位置
    int head = left, tail = right;
    int tmp;
    //直到head == tail,
    while(head < tail) {
        //从右边找一个小于 key 的值,必须要先找小于key的值
        while(head<tail && arr[tail] >= arr[left]) tail--;
        //从左边找一个大于 key 的值
        while(head < tail && arr[head] <= arr[left]) head++;
        //如果找到了的话交换
        if(head < tail) {
            
            swap(&arr[head], &arr[tail]);

            // tmp = arr[head];
            // arr[head] = arr[tail];
            // arr[tail] = tmp;
        }
    }
    swap(&arr[head], &arr[left]);
    
    // tmp = arr[left];
    // arr[left] = arr[head];
    // arr[head] = tmp;
    
    quickSort2(arr, left, head-1);
    quickSort2(arr, head+1, right);
}

//归并排序
void mergeSort(int arr[], size_t len) {
    mergeSort2(arr, 0, len-1);
}

void mergeSort2(int arr[], int left, int right) {
    //如果长度为1，直接返回
    if(left == right) {
        return;
    }
    else {//否则递归
        //如果left = 0,right = 1,则mid = 0；所以递归时应该是[left, mid] 和 [mid+1, right]
        int mid = (left+right)/2;
        mergeSort2(arr, left, mid);
        mergeSort2(arr, mid+1, right);
        //到这里说明两个子数列已经分别有序了，下面是合并两个有序序列
        int tmp[right-left+1];//存储结果的临时数组
        int p1 = left;//指向第一个数组的指针
        int p2 = mid+1;//指向第二个数组的指针
        int index = 0;//存放临时数组数据的下标
        //然后开始对比并将结果存入tmp数组
        while(p1<=mid && p2 <=right) {
            if(arr[p1] == arr[p2]) {
                tmp[index++] = arr[p1++];
                tmp[index++] = arr[p2++];
            }
            else if(arr[p1] > arr[p2]) {
                tmp[index++] = arr[p2++];
            }
            else if(arr[p1] < arr[p2]) {
                tmp[index++] = arr[p1++];
            }
        }
        //然后将剩余的元素存入tmp数组
        while(p1<=mid) {
            tmp[index++] = arr[p1++];
        }
        while(p2<=right) {
            tmp[index++] = arr[p2++];
        }
        //最后将临时数组的数据存入原数组中
        index = 0;
        for(int i=left;i<=right;i++) {
            arr[i] = tmp[index++];
        }
    }
}
//希尔排序
void arr_sort(int *p,int n)
{
    int step = 0;//步长
    int temp = 0;//用来保存第二段数据
    int i,j;
 
    for(step = n / 2;step > 0;step /= 2)
    {
        for(i = step;i < n;i++)
        {
            temp = p[i];
            for(j = i - step;j >= 0 && p[j] > temp;j -= step)
            {
                p[j + step] = p[j];
                //当满足条件时第一次j+step = i;后面的j+step = 上一次j的值
            }
            p[j + step] = temp;
        }
    }
}

