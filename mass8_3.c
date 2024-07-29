#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int srav(int *ost, int i);

// float y = (float)n/ (float)m;
int main()
{
  int n;   // числитель
  int m;   // знаменатель
  int i;   // номер ячейки массива
  int res; // сюда складываем то что получим при выходе из функции нахождения одинаковых чисел(начало периода)

  scanf("%d %d", &n, &m);
  // int t = n; // переменная для нахождения массива остатков

  int *arr = malloc(m * sizeof(int)); // выделяем динамическую память для размещения массива
  int *ost = malloc(m * sizeof(int)); // выделяем динамическую память для размещения массива


  for (i = 0; i < m; i++) //число элементов в массиве не больше знаменателя - есть такое правило
  {
    ost[i] = n;
    arr[i] = ((n * 10) / m);
    n = ((n * 10) % m);
   // printf("i = %d; arr[i] = %d; ost[i] = %d\n", i, arr[i], ost[i]);
    if ((res = (srav(ost, i))) != -1)
      break;
  }

  printf("0,");
  for (int j = 0; j < i; j++)
  {
   if(j == res)
   {
     printf("(");
   }
    printf("%d", arr[j]);
    
    if(j == i-1)
  {
    printf(")");
  }
    
  }
  
  printf("\n");

  free(arr);
  free(ost);
  return 0;
}

int srav(int *ost, int i)
{
  for (int k = 0; k < i; k++)
  {
    if (ost[i] != ost[k])
    {
      continue;
    }
    return k;
  }
  return -1;
}