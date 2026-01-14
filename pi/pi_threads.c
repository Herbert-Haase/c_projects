#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define BOUNDS 100

struct pi
{
  long double pi_v;
  pthread_mutex_t pi_lock;
};

struct thread_args
{
  unsigned long long start;
  unsigned long long end;
};

struct pi pi;

static void *get_pi(void *);
static void init_pi(struct pi *);

static void init_pi(struct pi *pi)
{
  pi->pi_v = 0;
  pthread_mutex_init(&pi->pi_lock, NULL);
}

static void *get_pi(void *arg)
{
  double sum = 0;
  double sign = 1;
  struct thread_args *range = (struct thread_args *)arg;

  for (unsigned long long k = range->start; k < range->end; k++)
  {
    sum += (1.0 / pow(16.0, k)) *
           (4.0 / (8.0 * (k) + 1.0) - 2.0 / (8.0 * (k) + 4.0) -
            1.0 / (8.0 * (k) + 5.0) - 1.0 / (8.0 * (k) + 6.0));
  }
  pthread_mutex_lock(&pi.pi_lock);
  pi.pi_v += sum;
  pthread_mutex_unlock(&pi.pi_lock);
  return NULL;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    fprintf(stderr, "usage: %s <number>\n", argv[0]);
    exit(1);
  }
  init_pi(&pi);
  unsigned n_threads = atoi(argv[1]);
  pthread_t tid[n_threads];
  struct thread_args targs[n_threads];
  for (unsigned i = 0; i < n_threads; i++)
  {
    unsigned long long loop_end = (BOUNDS / n_threads) * (i + 1);
    unsigned long long loop_start = loop_end - (BOUNDS / n_threads);
    targs[i].start = loop_start;
    targs[i].end = loop_end;
    pthread_create(&tid[i], NULL, get_pi, (void *)&targs[i]);
  }
  for (unsigned i = 0; i < n_threads; i++)
  {
    pthread_join(tid[i], NULL);
  }
  printf("pi is: %.30f\n", (double)pi.pi_v);
}
