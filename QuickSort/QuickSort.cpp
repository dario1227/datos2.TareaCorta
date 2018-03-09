//
// Created by dario1227 on 08/03/18.
//
#include "QuickSort.h"
void QuickSort::Start(int *array, int start, int end) {
    int pivot;

    if (start < end) {
        pivot = divide(array, start, end);

        QuickSort::Start(array, start, pivot - 1);
        QuickSort::Start(array, pivot + 1, end);
    }

}
int QuickSort::divide(int *array, int start, int end) {
    int left;
    int right;
    int pivot;
    int temp;

    pivot = array[start];
    left = start;
    right = end;
    while (left < right) {
        while (array[right] > pivot) {
            right--;
        }

        while ((left < right) && (array[left] <= pivot)) {
            left++;
        }

        if (left < right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }

    temp = array[right];
    array[right] = array[start];
    array[start] = temp;

    return right;
}