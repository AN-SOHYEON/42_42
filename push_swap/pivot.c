
#include "push_swap.h"

void    swap(int *a, int *b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr, int begin, int end)
{
    int pivot;
    int left;
    int right;

    pivot = (begin + end) / 2 + 1;
    left = begin;
    right = end;
    while (left < right)
    {
        while ((arr[left] < arr[pivot]) && (left < right))
            left++;
        while ((arr[pivot] <= arr [right]) && (left < right))
            right--;
        if (left < right)
            swap(arr[left], arr[right]);
            if (left = pivot)
                pivot = right;
    }
    swap(arr[pivot], arr[right]);
    return (right);
}

void    quick_sort(int *arr, int begin, int end)
{
    int pivot;

    if (begin < end)
    {
        pivot = partition(arr, begin, end);
        quick_sort(arr, begin, pivot - 1);
        quick_sort(arr, pivot + 1, end);
    }
}

int find_middle(int size, t_Dnode *stack_a, int begin, int end)
{
    int *arr;

    arr = (int *)malloc(sizeof(int) * size);
    if (!arr)
        exit(1);
    while (begin <= end)
    {
        arr[]

    }
    

}//   이거 큌소트 사용하는 걸로 바꾸기

int find_best_pivot(t_stack *stack)
{
    int middle;
    int size;
 

    size = ft_dlstsize(stack->stack_a);

    middle = find_middle(size, stack->stack_a, 0, size - 1);
    return (middle);
}