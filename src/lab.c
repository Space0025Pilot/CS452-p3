#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h> /* for gettimeofday system call */
#include "../src/lab.h"

/**
 * @brief Standard insertion sort that is faster than merge sort for small array's
 *
 * @param A The array to sort
 * @param p The starting index
 * @param r The ending index
 */
static void insertion_sort(int A[], int p, int r)
{
  int j;

  for (j = p + 1; j <= r; j++)
    {
      int key = A[j];
      int i = j - 1;
      while ((i > p - 1) && (A[i] > key))
        {
	  A[i + 1] = A[i];
	  i--;
        }
      A[i + 1] = key;
    }
}


void mergesort_s(int A[], int p, int r)
{
  if (r - p + 1 <=  INSERTION_SORT_THRESHOLD)
    {
      insertion_sort(A, p, r);
    }
  else
    {
      int q = (p + r) / 2;
      mergesort_s(A, p, q);
      mergesort_s(A, q + 1, r);
      merge_s(A, p, q, r);
    }

}

void merge_s(int A[], int p, int q, int r)
{
  int *B = (int *)malloc(sizeof(int) * (r - p + 1));

  int i = p;
  int j = q + 1;
  int k = 0;
  int l;

  /* as long as both lists have unexamined elements */
  /*  this loop keeps executing. */
  while ((i <= q) && (j <= r))
    {
      if (A[i] < A[j])
        {
	  B[k] = A[i];
	  i++;
        }
      else
        {
	  B[k] = A[j];
	  j++;
        }
      k++;
    }

  /* now only at most one list has unprocessed elements. */
  if (i <= q)
    {
      /* copy remaining elements from the first list */
      for (l = i; l <= q; l++)
        {
	  B[k] = A[l];
	  k++;
        }
    }
  else
    {
      /* copy remaining elements from the second list */
      for (l = j; l <= r; l++)
        {
	  B[k] = A[l];
	  k++;
        }
    }

  /* copy merged output from array B back to array A */
  k = 0;
  for (l = p; l <= r; l++)
    {
      A[l] = B[k];
      k++;
    }

  free(B);
}

double getMilliSeconds()
{
  struct timeval now;
  gettimeofday(&now, (struct timezone *)0);
  return (double)now.tv_sec * 1000.0 + now.tv_usec / 1000.0;
}

void mergesort_mt(int *A, int n, int num_thread){
  pthread_t threads[num_thread];
  struct parallel_args args[num_thread];

  int chunk_size = n / num_thread;
  int remainder = n % num_thread;
  int start_index = 0;

  for(int i = 0; i < num_thread; i++){
    args[i].start = start_index;
    args[i].end = start_index + chunk_size - 1 + (i < remainder);
    args[i].A = A;

    pthread_create(&threads[i], NULL, parallel_mergesort, &args[i]);
    // pthread_t tid = pthread_self();
    // args[i].tid = tid;

    start_index = args[i].end + 1;
  }

  for(int i = 0; i < num_thread; i++){
    pthread_join(threads[i], NULL);
  }

  for(int i = 0; i < num_thread - 1; i++){
    merge_s(args[i].A, 0, args[i].end, args[i + 1].end);
  }
  
}

void *parallel_mergesort(void *args){
  struct parallel_args * pa = (struct parallel_args *)args;

  mergesort_s(pa->A,pa->start,pa->end);
  pthread_exit(NULL);
}
