#include <stdio.h>
#include <time.h>

void printArray(int len, int *a)
{
  for (int i = 0; i < len; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void Merge(int a[], int low, int mid, int high)
{
  int i, j, k;
  // int size = high + 1;
  int b[100];

  i = low;
  j = mid + 1;
  k = low;

  while (i <= mid && j <= high)
  {
    if (a[i] > a[j])
    {
      b[k] = a[j];
      j++;
      k++;
    }
    else
    {
      b[k] = a[i];
      i++;
      k++;
    }
  }

  while (i <= mid)
  {
    b[k] = a[i];
    i++;
    k++;
  }

  while (j <= high)
  {
    b[k] = a[j];
    j++;
    k++;
  }

  for (int p = 0; p <= high; p++)
  {
    a[p] = b[p];
  }
}

void Merge_Sort(int a[], int low, int high)
{
  int mid;
  if (low < high)
  {
    mid = (low + high) / 2;
    Merge_Sort(a, low, mid);
    Merge_Sort(a, mid + 1, high);
    Merge(a, low, mid, high);
  }
}

int main()
{
  clock_t start, end;

  double cpu_time_used;
  int key, n, arr[n];

  printf("Total number of elements : \n");
  scanf("%d", &n);

  printf("Enter The elements : \n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  printf("Before Sorting Array : \t");
  printArray(n, arr);

  start = clock();
  Merge_Sort(arr, 0, n - 1);
  end = clock();

  printf("After Sorting Array : \n");
  printArray(n, arr);

  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("\n Running time =%lf", cpu_time_used);
}
