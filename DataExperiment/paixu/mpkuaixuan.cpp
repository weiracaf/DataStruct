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

    for(int i=0;i<ARRLEN;i++) {//���������������
        arr[i] = rand()%1000;
    }

    puts("ԭʼ����Ϊ:");
    printIntArr(arr, ARRLEN);
     //bubbleSort(arr, ARRLEN);
     //puts("ð������������Ϊ:");
     //printIntArr(arr, ARRLEN);
     //puts("ѡ������������Ϊ:");
     //selectSort(arr, ARRLEN);
     //printIntArr(arr, ARRLEN);
    // insertSort(arr, ARRLEN);
    // puts("ֱ�Ӳ�������������Ϊ:");
    // printIntArr(arr, ARRLEN);
    // binaryInsertSort(arr, ARRLEN);
    // puts("�۰��������������Ϊ:");
    // printIntArr(arr, ARRLEN);
     mergeSort(arr, ARRLEN);
     puts("�鲢����������Ϊ:");
     printIntArr(arr, ARRLEN);
    // arr_sort(arr,ARRLEN)
    // puts("ϣ������������Ϊ:");
    // printIntArr(arr, ARRLEN);
    //quickSort(arr, ARRLEN);
    //puts("��������������Ϊ:");
    //printIntArr(arr, ARRLEN);
}

//���һ������
void printIntArr(int arr[], size_t len) {
    for(int i=0;i<len;i++) {
        printf("%d ",arr[i]);
    }
    puts("");
}

//��������intԪ��
void swap(int *a1, int *a2) {
    int tmp = *a1;
    *a1 = *a2;
    *a2 = tmp;
}


//ð������
void bubbleSort(int arr[], size_t len) {
    for(int i=0;i<len-1;i++) {
        for(int j=0;j<len-1-i;j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

//ѡ������
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

//ֱ�Ӳ�������
void insertSort(int arr[], size_t len) {
    for(int i = 1;i<len;i++) {
        int key = arr[i];//���ݴ�i��ֵ
        int j = i-1;
        while(j >=0 && key < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

//�۰��������
void binaryInsertSort(int arr[], size_t len) {
    //��arr[i]��Ԫ����[0, i]��Χ������
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
        //��ѭ����begin = end +1;
        //������begin = mid+1���µģ�Ҳ������end = mid -1���µ�
        //�����begin = mid+1���µģ�˵��key > arr[mid] ��key��< arr[begin] ����iҪ���뵽mid+1��λ��
        //�����end = mid -1���µģ�˵��key < arr[mid] ��key��> arr[end] ����iҪ���뵽mid��λ��
        //�����������i��ʵ���ǲ��뵽begin��λ��
        int j;
        for(j=i-1;j>=begin;j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
}

//��������
void quickSort(int arr[], size_t len) {
    quickSort2(arr, 0, len-1);
}

void quickSort2(int arr[], int left, int right) {
    //������鳤��Ϊ 1 �����Ȼ������ģ�ֱ�ӷ���
    if(left >= right) {
        return;
    }
    //��arr[left]Ϊ��׼
    //˫ָ�����β��ʼѰ��key��λ��
    int head = left, tail = right;
    int tmp;
    //ֱ��head == tail,
    while(head < tail) {
        //���ұ���һ��С�� key ��ֵ,����Ҫ����С��key��ֵ
        while(head<tail && arr[tail] >= arr[left]) tail--;
        //�������һ������ key ��ֵ
        while(head < tail && arr[head] <= arr[left]) head++;
        //����ҵ��˵Ļ�����
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

//�鲢����
void mergeSort(int arr[], size_t len) {
    mergeSort2(arr, 0, len-1);
}

void mergeSort2(int arr[], int left, int right) {
    //�������Ϊ1��ֱ�ӷ���
    if(left == right) {
        return;
    }
    else {//����ݹ�
        //���left = 0,right = 1,��mid = 0�����Եݹ�ʱӦ����[left, mid] �� [mid+1, right]
        int mid = (left+right)/2;
        mergeSort2(arr, left, mid);
        mergeSort2(arr, mid+1, right);
        //������˵�������������Ѿ��ֱ������ˣ������Ǻϲ�������������
        int tmp[right-left+1];//�洢�������ʱ����
        int p1 = left;//ָ���һ�������ָ��
        int p2 = mid+1;//ָ��ڶ��������ָ��
        int index = 0;//�����ʱ�������ݵ��±�
        //Ȼ��ʼ�ԱȲ����������tmp����
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
        //Ȼ��ʣ���Ԫ�ش���tmp����
        while(p1<=mid) {
            tmp[index++] = arr[p1++];
        }
        while(p2<=right) {
            tmp[index++] = arr[p2++];
        }
        //�����ʱ��������ݴ���ԭ������
        index = 0;
        for(int i=left;i<=right;i++) {
            arr[i] = tmp[index++];
        }
    }
}
//ϣ������
void arr_sort(int *p,int n)
{
    int step = 0;//����
    int temp = 0;//��������ڶ�������
    int i,j;
 
    for(step = n / 2;step > 0;step /= 2)
    {
        for(i = step;i < n;i++)
        {
            temp = p[i];
            for(j = i - step;j >= 0 && p[j] > temp;j -= step)
            {
                p[j + step] = p[j];
                //����������ʱ��һ��j+step = i;�����j+step = ��һ��j��ֵ
            }
            p[j + step] = temp;
        }
    }
}

