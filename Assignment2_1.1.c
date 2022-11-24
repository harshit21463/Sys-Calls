#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sched.h>
#include <unistd.h>
#include <pthread.h>

void *cntp()
{
  clock_t shuru;
  clock_t khatam;
  double nettime;
  shuru = clock();
  int k = 1;
  long int j = 1;
  while(j<pow(2,32))
    {
      k++;
      j++;
    }
      khatam = clock();
      nettime = (double)(khatam-shuru)/CLOCKS_PER_SEC;
      printf("For RR Policy: %f\n",nettime);
  return NULL;  
}

void *cntd()
{
  clock_t shuru;
  clock_t khatam;
  double nettime;
  shuru = clock();
  int k = 1;
  long int j = 1;
  while(j<pow(2,32))
    {
      k++;
      j++;
    }
      khatam = clock();
      nettime = (double)(khatam-shuru)/CLOCKS_PER_SEC;
      printf("For FIFO Policy: %f\n",nettime);
  return NULL;
}

void *cntt()
{
  clock_t shuru;
  clock_t khatam;
  double nettime;
  shuru = clock();
  int k = 1;
  long int j = 1;
  while(j<pow(2,32))
    {
      k++;
      j++;
    }
      khatam = clock();
      nettime = (double)(khatam-shuru)/CLOCKS_PER_SEC;
      printf("For OTHER Policy: %f\n",nettime);
  return NULL;
}


int main()
{
  pthread_t pehli;
  pthread_t dusri;
  pthread_t teesri;
  pthread_attr_t attp;
  pthread_attr_t attd;
  pthread_attr_t attt;
  struct sched_param paramp; 
  struct sched_param paramd;
  struct sched_param paramt;

  paramp.sched_priority = 30;
  pthread_attr_init(&attp);
  pthread_attr_setinheritsched(&attp,PTHREAD_EXPLICIT_SCHED);
  pthread_attr_getschedparam(&attp, &paramp);
  pthread_attr_setschedpolicy(&attp,SCHED_RR);
  pthread_create(&pehli,&attp,cntp,NULL);
  
  paramd.sched_priority = 30;
  pthread_attr_init(&attd);
  pthread_attr_setinheritsched(&attd,PTHREAD_EXPLICIT_SCHED);
  pthread_attr_getschedparam(&attd, &paramd);
  pthread_attr_setschedpolicy(&attp,SCHED_FIFO);
  pthread_create(&dusri,&attd,cntd,NULL);
  
  paramt.sched_priority = 0;
  pthread_attr_init(&attt);
  pthread_attr_setinheritsched(&attt,PTHREAD_EXPLICIT_SCHED);
  pthread_attr_getschedparam(&attt, &paramt);
  pthread_attr_setschedpolicy(&attp,SCHED_OTHER);
  pthread_create(&teesri,&attt,cntt,NULL);

  pthread_join(pehli,NULL);
  pthread_join(dusri,NULL);
  pthread_join(teesri,NULL);
  pthread_attr_destroy(&attp);
  pthread_attr_destroy(&attd);
  pthread_attr_destroy(&attt);
}
 