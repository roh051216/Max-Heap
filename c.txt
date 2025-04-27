#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int heap[MAX];
int heap_size = 0;

// 힙에 데이터 삽입
void insert(int data) {
    int i = ++heap_size;

    while (i != 1 && data > heap[i / 2]) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = data;
}

// 힙의 루트(최댓값) 삭제
int delete() {
    int parent, child;
    int data, temp;

    if (heap_size == 0) {
        printf("Heap is empty.\n");
        return -1;
    }

    data = heap[1];
    temp = heap[heap_size--];
    parent = 1;
    child = 2;

    while (child <= heap_size) {
        if (child < heap_size && heap[child] < heap[child + 1]) {
            child++;
        }

        if (temp >= heap[child]) break;

        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }

    heap[parent] = temp;
    return data;
}

// 힙 출력
void print_heap() {
    printf("Heap: ");
    for (int i = 1; i <= heap_size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// 힙 정렬
void heap_sort() {
    int temp_heap[MAX];
    int temp_size = heap_size;

    // 기존 힙 백업
    for (int i = 1; i <= heap_size; i++) {
        temp_heap[i] = heap[i];
    }

    printf("Heap Sort Result: ");
    while (heap_size > 0) {
        printf("%d ", delete());
    }
    printf("\n");

    // 원래 힙 복원
    for (int i = 1; i <= temp_size; i++) {
        heap[i] = temp_heap[i];
    }
    heap_size = temp_size;
}

int main() {
    int choice, data;

    while (1) {
        printf("\n1. Insert  2. Delete  3. Print Heap  4. Heap Sort  5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Deleted data: %d\n", delete());
                break;
            case 3:
                print_heap();
                break;
            case 4:
                heap_sort();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
