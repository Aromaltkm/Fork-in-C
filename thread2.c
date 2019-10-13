#include <stdio.h>
#include <pthread.h>
int pizza = 200000;
void* eat(void *a)
{
  int i;
  for (i = 0; i < 20000; i++) {
    pizza = pizza - 1;
  }
  return NULL;
}

int main()
{
  pthread_t threads[10];
  int t;
  printf("%i pizza on the table\n", pizza);
  for (t = 0; t < 10; t++) {
  	pthread_create(&threads[t],NULL,eat,NULL);
  }
  void* result;
  for (t = 0; t < 10; t++) {
  	pthread_join(threads[t], &result);
  }
  printf("There are now %i pizza on the table\n", pizza);
  return 0;
}