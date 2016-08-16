#include <iostream>
#include "CodeHeader.h"
using namespace std;

int main() {
    cout << "huzihao!" << endl;
    return 0;
}
//插入排序
//基本思想：将一个记录插入到已排序好的有序表中，
//从而得到一个新的、记录数增1的有序表，
//即先将序列的第t个记录看成是一个有序的子序列，
//然后以2个记录逐个进行插入，直至整个序列有序为止。
void InsertSort(int arr[], int len ){
    if(len < 0)
        return;
    for (int i = 0; i < len; ++i) {
        if(arr[i] < arr[i-1]){
            int temp = arr[i];//保存arr[i]的值，方便进位
            arr[i] = arr[i-1];//arr[i-1]进位到arr[i]位置留出空位
            int j = i-1;//标志当前移位位置
            while(temp < arr[j-1] && j>0){//防止第一位没得移直接插
                arr[j] = arr[j-1];
                j--;
            }
            arr[j] = temp;//找到插入位置
        }
    }
}
//哈希排序
//思想：先将整个序列分割成若干序列进行插入排序，待整个序列的子序列均有序时，进行插入排序
//重要就是选择一个增量序列,同插入排序的区别就是增加一个增量序列d,递归直到d=1
void HashSort(int arr[], int len, int d){
    if(len < 0)
        return;
    for (int i = d; i < len; ++i) {
        if(arr[i] < arr[i-d]) {
            int temp = arr[i];//保存arr[i]的值，方便进位
            arr[i] = arr[i - d];//arr[i-1]进位到arr[i]位置留出空位
            int j = i - d;//标志当前移位位置
            while (temp < arr[j - 1] && j > 0) {//防止第一位没得移直接插
                arr[j] = arr[j - 1];
                j--;
            }
            arr[j] = temp;//找到插入位置
        }
        while(d > 0){
            return HashSort(arr, len, d/2);
        }
    }
}
//简单选择排序
//思想：在要排序的数组中，选出最小的一个与第1个元素交换，然后再剩下的元素中找到最小的同第2个交换，
//直到第N-1个数和第N个数
void SelectSort(int arr[], int len){
    if(len < 0)
        return;
    for (int i = 0; i < len-1; ++i) {
        for (int j = i+1; j < len; ++j) {
            if(arr[j] < arr[i])
                swap(arr[j],arr[i]);
        }
    }
}
//二元选择排序：每次遍历的时候同时保存最大值和最小值
void DoubleSelectSort(int arr[], int len){
    if(len < 0)
        return;
    int i, j, min, max;
    for (int i = 0; i <= n/2; ++i) {
        for (int j = i+1; j <= n-i; ++j) {
            if(arr[j] < arr[i]){
                min=j;
                continue;
            }
            if(arr[j] > arr[i]){
                max=j;
                continue;
            }
        }
    }
    swap(arr[max],arr[n-i]);
    swap(arr[min],arr[i-1]);
}
//冒泡排序
//思想：在要排序的一组数中，对当前还未排好序的范围内的全部数，由上而下相邻的数比较，
//大数下沉，较小数的位置上冒
void PopSort(int arr[], int len){
    for (int i = 0; i < len-1; ++i) {
        for (int j = 0; j < len-i-1; ++j) {
         if(arr[j]< arr[j+1])
             swap(arr[j],arr[j+1]);
        }
    }
}
//冒泡算法改进：
//1.加入标志变量exchange，用于标记某一趟排序过程中是否有数据交换，如果排序中某一趟并没有数据交换
//说明此时序列已经全部排序完成；
//2.设置一标志变量POS，用于记录每趟排序汇总最后一次进行交换的位置，
//由于POS位置之后的记录均已交换到位，故下次排序只需要扫描到POS即可
void PosPopSort(int arr[], int len){
    int pos=len-1;
    int i=pos;
    while(i > 0){//直至没有交换发生
        for (int j = 0; j < i; ++j) {//没有交换的话j=0,pos=0；
            if(arr[j]< arr[j+1]){
                swap(arr[j],arr[j+1]);
                pos=j;//记录当前交换的位置
            }
        }
        i=pos;//最后交换的位置赋给i
    }
}
//3.传统的冒泡排序中每一趟排序操作只能找到一个最大值或最小值，
//考虑利用在每一趟排序中进行正向和反向的两遍冒泡排序方法一次可以得到两个最终值
//最大值和最小值，从而使排序躺数几乎减少到一半
void DoublePopSort(int arr[], int len ){
    int low = 0;
    int high = len-1;
    while (low < high){
        for (int i = low; i < high; ++i) {
            if(arr[i] > arr[i+1]) {
                swap(arr[i], arr[i + 1]);
                high--;//正向冒泡找最大值
            }
        }
        for (int j = high; j > low; --j) {
            if(arr[j] < arr[j-1]) {
                swap(arr[j], arr[j - 1]);
                low++;//反向冒泡找最小值
            }
        }
    }
}
//堆排序是一种树形选择排序
//堆的定义：所有非叶结点值均大于或小于子女值；
//思想：1.如何将n个待排序数构造成堆；2.输出堆顶元素后怎样调整剩下的n-1个元素成为新的堆；
//首先讨论，输出堆顶后如何调整
//1.设有M个元素的堆，输出堆顶元素后，剩下M-1个元素，将堆底元素送入堆顶（堆底和堆顶交换），堆破坏
//2.将根结点与左右子树中较小的元素进行交换；
//3.若与左子树交换：如果左子树堆被破坏，即左子树不满足堆的性质，返回2；
//4.若与右子树交换，同理；
//5.继续对不满足堆性质的子树进行交换直至叶结点；
//创建初始堆过程
//建堆方法：对初始序列建堆过程就是反复筛选过程
//1.n个结点的完全二叉树，则最后一个结点是n/2个结点的子树
//2.筛选从第n/2个结点为根的子树开始，该子树成为堆
//3.之后向前一次对各结点为根的子树进行筛选，使之成为堆，直至根结点；
void HeapAjust(int arr[],int n,int len){
    int child = 2*n + 1;//已知arr[]中除了arr[n]外均满足堆定义，arr[n]的左孩子为arr[2*n + 1]
    while(child < len){
        if(arr[child] < arr[child+1] && (child+1<len)){
            child++;
        }//判断左右子树的大小，返回较大的孩子
        if(arr[n] < arr[child]){//比较待调整结点与较大孩子的大小
            swap(arr[n], arr[child]);//小于孩子则交换
            n = child;//待调整结点更新为较大孩子
            child = 2*n +1;//更新孩子结点
        }
        else
        { break;}//直至成为堆
    }
}
void BuiltHeap(int arr[],int len){
    for (int i = (len-1)/2; i >= 0 ; --i) {//最后一个有孩子的结点位置
        HeapAjust(arr,i,len);
    }
}
void HeapSort(int arr[],int len){
    BuiltHeap(arr,len);//初始堆
    for (int i = len-1; i >0 ; --i) {//从最后一个元素开始对序列调整
        swap(arr[0],arr[i]);//交换堆顶元素和堆中最后一个元素
        HeapAjust(arr,0,i);//调整堆
    }
}
//快速排序
//思想：1.选择一个基准元素，通常选择首或尾元素；
//2.通过一趟排序将待排序元素分割成独立的两个部分，左部均比基准元素小，右部均比它大；
//3.此时基准元素在其排序好的正确位置；
//4.然后分别对这两个部分的元素用同样的方法进行排序，直至有序；
int Position(int arr[],int low, int high){
    int prikey = arr[low];//基准元素
    while(low < high){//从表的两端交替的向中间扫描
        while(low < high && arr[high] >= prikey)//高位向中间扫描
            --high;//固定Low,扫描到交换
        swap(arr[low],arr[high]);
        while(low < high && arr[low] <= prikey)//低位向中间扫描
            ++low;//固定high,扫描到交换
        swap(arr[low],arr[high]);
    }
    return low;//返回基准元素的正确位置
}
void QuickSort(int arr[],int low, int high){
    if(low < high){
        int key = Position(arr,low,high);
         QuickSort(arr,low,key-1);
         QuickSort(arr,key+1,high);
    }
}
//快排被认为在同等数量级的排序算法中最好的，但若初始序列按关键码有序或基本有序时，
//快排会退化为冒泡排序，通常基准元素用三者取中法；
//
//归并排序
//思想：将两个或以上的有序表合并成一个新的有序表，即把待排序列分为若干个序列，
//每个子序列都是有序的，然后合并整体有序
void Merge(int arr1[],arr2[],int i,int m,int n){
    int j,k;
    for (j = m+1 , k = i;i <=m&&j <=n; ++k){
        if(arr1[i] <=arr1[j]){
            arr2[k] = arr1[i];
            ++i;
        }
        else{
            arr2[k] = arr1[j];
            ++j;
        }
        while(i <=m)
            arr2[k++] = arr1[i++];
        while(j <=n)
            arr2[k++] = arr1[j++];
    }
}
//非递归，1个元素的表总是有序的，所以对N个元素待排序列，每个元素可以看成1的有序子表，
//对子表两两合并成n/2个表，所的子表最后一个子表长度可能为1，其余子表为2，再重复直至全部有序；
void MergeSort(int *r,int *rf,int length){
    int len=1;//初始步长设为1
    int *q=r;
    int *temp;
    while(len<length) {//直至步长为length
        int s = len;//合并的中间位置
        len = 2 * s;//步长*2，每次
        int i = 0;//序列头
        while (i + len < length) {//对等长的两个子表合并
            Merge(q, rf, i, i + s - 1, i + len - 1);
            i = i + len;
        }
        if (i + s < length) {//对不等长的两个子表合并
            Merge(q, rf, i, i + s - 1, length - 1);
        }
        temp = q;//交换q,rf,以保证下一趟归并仍能从q归并到rf
        q = rf;
        rf = temp;
    }
}
void Msort(int *r,int *rf,int s,int t){
    int *rf2;
    if(s==t)
        r[s]=rf[s];
    else{
        int m=(s+t)/2;//平分P表
        Msort(r,rf2,s,m);//将左边归并有序
        Msort(r,rf2,m+1,t);//右边
        Merge(rf2,ef,s,m+1,t);//一起归并
    }
}
void MergeSort2(int *r,int *rf,int n)
{
    Msort(r,rf,0,n-1);
}