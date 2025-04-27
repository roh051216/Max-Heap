#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int heap[MAX + 1];  // 인덱스를 1부터 사용하기 위해 배열 크기를 MAX+1로 설정
int heap_size = 0;

// 힙에 데이터 삽입
void insert(int data) {
    int i = ++heap_size;  // 힙에 삽입할 위치

    // 부모 노드와 비교하며 큰 값을 위로 올림
    while (i != 1 && data > heap[i / 2]) { 
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = data;  // 삽입된 데이터
}

// 힙의 루트(최댓값) 삭제
int delete() {
    if (heap_size == 0) {
        printf("Heap is empty.\n");
        return -1;
    }

    int data = heap[1];  // 루트값 저장
    int temp = heap[heap_size--];  // 마지막 요소 저장 후 heap_size 감소
    int parent = 1;
    int child = 2;

    // 자식 노드와 비교하며 힙을 재정렬
    while (child <= heap_size) {
        if (child < heap_size && heap[child] < heap[child + 1]) {
            child++;  // 더 큰 자식 선택
        }

        if (temp >= heap[child]) break;  // 힙 속성 유지

        heap[parent] = heap[child];  // 자식 노드를 부모에 저장
        parent = child;  // 부모를 자식으로 이동
        child *= 2;  // 자식 노드로 이동
    }

    heap[parent] = temp;  // 재배치된 값을 적절한 위치에 삽입
    return data;  // 삭제된 루트값 반환
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
    int temp_heap[MAX + 1];  // 힙 복사본 저장
    int temp_size = heap_size;

    // 기존 힙 백업
    for (int i = 1; i <= heap_size; i++) {
        temp_heap[i] = heap[i];
    }

    printf("Heap Sort Result: ");
    while (heap_size > 0) {
        printf("%d ", delete());  // 루트(최댓값)를 삭제하며 출력
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
                if (heap_size < MAX) {
                    insert(data);
                } else {
                    printf("Heap is full.\n");
                }
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
