#include "SortingHelper.h"
template <class T>
void merge(T *, T*, T*, int, int);

template <class T>
void selectionsort(T * data, int size){
	for(int m = 0; m < size-1; ++m){
		int min = m;
		for(int i = m+1; i < size; ++i){
			if(data[i] < data[min]){
				min = i;
			}
		}
		if(min != m){
			Swap(data[min],data[m]);
		}
	}
}

template <class T>
void insertionsort(T * data, int size){
    int i, j;
	for(i = 1; i < size; ++i){
        j = i;
		while(j > 0 && data[j-1] > data[j]){
            Swap(data[j-1], data[j]);
            --j;
		}
	}
}

template <class T>
void mergesort(T * data, int size, T * temp){
	if(size > 1){
        int mid = (size+1)/2;
        T * left = new T[mid]();
        for(int i = 0; i < mid; ++i){
            left[i] = data[i];
        }
        T * right = new T[size-mid]();
        for(int i = 0; i < size-mid; ++i){
            right[i] = *(data+mid+i);
        }
        mergesort(left, mid, temp);
        mergesort(right, size-mid, temp);
        merge(left,right,temp,size, mid);
        for(int i = 0; i < size; ++i){
            data[i] = temp[i];
        }
        delete[] left;
        delete[] right;
	}
}
template <class T>
void merge(T * left, T * right, T * temp, int size, int mid){
    int l = 0, r = 0, s = 0;
    while (l < mid && r < size - mid) {
        if (left[l] < right[r]) {
            temp[s] = left[l];
            ++l;
        }
        else{
            temp[s] = right[r];
            ++r;
        }
        ++s;
    }
    while(l < mid){
        temp[s] = left[l];
        ++l;
        ++s;
    }
    while (r < size-mid) {
        temp[s] = right[r];
        ++r;
        ++s;
    }
}

template <class T>
void quicksort(T * data, int size){
    if(size <= 1){}
    else{
        int mid = (size+1)/2;
        int pivot;
        switch (medianof3(data[0], data[mid], data[size-1])) {
            case 1:
                pivot = 0;
                break;
            case 2:
                pivot = mid;
                break;
            case 3:
                pivot = size-1;
                break;
        }
        Swap(data[pivot], data[0]);
        int left = 0;
        int right = size - 1;
        while (left < right) {
            while (left < right && data[left] <= data[0]) {
                ++left;
            }
            while(left < right && data[right] > data[0]){
                --right;
            }
            Swap(data[left], data[right]);
        }
        if (data[left] > data[0]) {
            --left;
        }
        Swap(data[left], data[0]);
        quicksort(data, left);
        quicksort(data+left, size-left);
    }
}
