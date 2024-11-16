#include <stdio.h>
#include <time.h>
clock_t clock(void);

void quick(int[], int, int);

#define N 8000000 //ここにデータサイズを入力する

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
  データサイズが小さいときはソート後を数列を出力してチェックするのも良いが、データサイズが大きくなると流石にできない
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