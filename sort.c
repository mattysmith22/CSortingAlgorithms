#include <string.h>
#include <stdlib.h>

int *merge(int aarr[], int alen, int barr[], int blen)
{
    int *tmp = malloc((alen + blen)*sizeof(int));
    int *ptr = tmp; /*points at next empty spot in tmp*/
    int *aptr = aarr, *bptr = barr;
    do
    {
        if(*aptr > *bptr)
        {
            *(ptr++) = *bptr;
            bptr++; blen--;
        }
        else
        {
            *(ptr++) = *aptr;
            aptr++; alen--;
        }
    }
    while(alen != 0 && blen != 0);

    if(alen != 0)
        memcpy(ptr, aptr, alen * sizeof(int));
    else
        memcpy(ptr, bptr, blen * sizeof(int));
    return tmp;
}

void merge_sort(int arr[], int len)
{
    int *res;
    if(len == 1)
        return;
    
    merge_sort(arr, len/2);
    merge_sort(arr + (len/2), len - len/2);

    res = merge(arr, len/2, arr+len/2, len - len/2);
    memcpy(arr, res, len * sizeof(int));
    free(res);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertion_sort(int arr[], int len)
{
    int i, j;
    for(i = 1; i < len; i++)
        for(j = i; j > 0 && arr[j-1] > arr[j]; j--)
            swap(arr + j - 1, arr + j);
}

void bubble_sort(int arr[], int len)
{
    int j, sorted;
    do
        for(sorted = 1, j = 1; j < len; j++)
            if(arr[j-1] > arr[j])
            {
                swap(arr + j - 1, arr + j);
                sorted = 0;
            }
    while (!sorted);
}

void better_bubble_sort(int arr[], int len)
{
    int i, j, sorted = 0;
    for(i = len - 1; i > 0 && !sorted; i--)
        for(j = 1, sorted = 1; j <= i; j++)
            if(arr[j-1] > arr[j])
            {
                sorted = 0;
                swap(arr + j - 1, arr + j);
            }
}

int partition(int arr[], int len)
{
    int pivot, i, j;
    pivot = arr[len-1];
    for(i=-1, j = 0; j < len - 1; j++)
        if(arr[j] <= pivot)
            swap(arr + ++i, arr + j);
    swap(arr + i + 1, arr + len - 1);
    return i + 1;
}

void quick_sort(int arr[], int len)
{
    int q;
    /*p = 0, r = len - 1*/
    if(len <= 1)
        return;
    q = partition(arr, len);
    quick_sort(arr, q);
    quick_sort(arr + q + 1, len - q - 1);
}

void cocktail_sort(int arr[], int len)
{
    int swapped, i;
    do
    {
        swapped = 0;
        for(i = 0; i < len - 1; i++)
            if(arr[i] > arr[i + 1])
            {
                swap(arr + i, arr + i + 1);
                swapped = 1;
            }
        if(!swapped)
            break;
        swapped = 0;
        for(i = len - 2; i >= 0; i--)
            if(arr[i] > arr[i+1])
            {
                swap(arr + i, arr + i + 1);
                swapped = 1;
            }
    }
    while(swapped);
}

void cocktail_sort_gapped(int arr[], int offset, int len, int gap)
{
    int swapped, i;
    do
    {
        swapped = 0;
        for(i = offset; i + gap < len; i+=gap)
            if(arr[i] > arr[i + gap])
            {
                swap(arr + i, arr + i + gap);
                swapped = 1;
            }
        if(!swapped)
            break;
        swapped = 0;
        for(i = len - 1 - gap - offset; i >= 0; i-=gap)
            if(arr[i] > arr[i + gap])
            {
                swap(arr + i, arr + i + gap);
                swapped = 1;
            }
    }
    while(swapped);
}

void shell_sort(int arr[], int len)
{
    int gap, i;
    for(gap = 2; gap < len; gap *= 2)
        for(i = 0;i < len / gap + (len % gap != 0 ? 1 : 0); i++)
            cocktail_sort_gapped(arr, i, len, gap);
    cocktail_sort(arr, len);
}

void selection_sort(int arr[], int len) {
    int i, j, max_index;
    for(i = len; i > 0; i--) {
        max_index = 0;
        for(j = 0; j < i; j++) {
            if(arr[max_index] <= arr[j])
                max_index = j;
        }
        swap(arr + max_index, arr + i - 1);
    }
}