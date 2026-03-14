#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int x){

    heap[size] = x;

    int i = size;

    size++;

    while(i>0 && heap[(i-1)/2] > heap[i]){

        swap(&heap[i], &heap[(i-1)/2]);

        i = (i-1)/2;
    }
}

int deleteMin(){

    if(size == 0)
        return -1;

    int root = heap[0];

    heap[0] = heap[size-1];

    size--;

    int i = 0;

    while(2*i+1 < size){

        int left = 2*i+1;
        int right = 2*i+2;

        int smallest = left;

        if(right < size && heap[right] < heap[left])
            smallest = right;

        if(heap[i] <= heap[smallest])
            break;

        swap(&heap[i], &heap[smallest]);

        i = smallest;
    }

    return root;
}

int main(){

    insert(30);
    insert(10);
    insert(20);

    printf("%d\n", deleteMin());
    printf("%d\n", deleteMin());

}