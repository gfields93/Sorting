#include "SortingHelper.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

/**
  Creates an array of integers 1 to n

  @param n the size of the array
  @return the array
 */
int* increasingArray(int n)
{
  int* arr = new int[n];
  for (int i = 0; i < n; i++)
    arr[i] = i+1;
  return arr;
}

/**
  Creates an array of integers n down to 1

  @param n the size of the array
  @return the array
 */
int* decreasingArray(int n)
{
  int* arr = new int[n];
  for (int i = 0; i < n; i++)
    arr[i] = n-i;
  return arr;
}

/**
  Creates an array of n zeros

  @param n the size of the array
  @return the array
 */
int* zeroArray(int n)
{
  int* arr = new int[n];
  memset(arr, 0, n*sizeof(int));
  return arr;
}

/**
  Creates a random permutation of the integers 1 to n

  @param n the size of the array
  @return the array
 */
int* randomArray(int n)
{
  srand(time(NULL));
  int* arr = increasingArray(n);
  for (int i = n; i > 1; i--)
  {
    int swap = rand() % i;
    Swap(arr[swap], arr[i-1]);
  }

  return arr;
}