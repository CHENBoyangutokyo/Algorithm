#include <stdio.h>
//Time measurement
#include <time.h>
clock_t clock(void);

void quick(int[], int, int);

#define N 8000000  //Enter the data size (number of elements) here

void main(void){

  clock_t start_clock, end_clock;

    start_clock = clock();

      static int a[N];
      for(int i = 0; i < N; i++){
          a[i] = N - i;
      }
      int k;

  quick(a,0,N-1);

  /*
  If the data size is small, you can output the sorted array to check it manually.
  for (k = 0; k < N; k++){
    printf("%4d",a[k]);
    printf("\n");
    }
  */

    end_clock = clock();

    printf(
        "clock:%f\n", 
        (double)(end_clock - start_clock) / CLOCKS_PER_SEC
    );


}

void quick(int a[], int left, int right){
  int s,t,i,j;
  if (left < right){
    s = a[(left + right)/2];
    i = left - 1;
    j = right + 1;
    while(1){
      while(a[++i]<s);
      while(a[--j]>s);
      if(i>=j) break;
      t = a[i]; a[i] = a[j]; a[j] = t;
    }
    quick(a, left, i-1);
    quick(a, j+1, right);
  }
}
