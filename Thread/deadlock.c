#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
void *fun1();
void *fun2();
pthread_mutex_t m1,m2;
int main()
{
pthread_t t1,t2;
pthread_create(&t1,NULL,fun1,NULL);
pthread_create(&t2,NULL,fun2,NULL);
pthread_mutex_init(&m1,NULL);
pthread_mutex_init(&m2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("thread joined\n");

}
void *fun1()
{
printf("t1 is acuired m1\n");
pthread_mutex_lock(&m1);
printf("t1 is acquired\n");
pthread_mutex_lock(&m2);

}
void *fun2()
{
printf("t2 is acuired m1\n");
pthread_mutex_lock(&m2);
printf("t2 is acquired\n");
pthread_mutex_lock(&m2);
printf("acquired");

pthread_mutex_unlock(&m2);



}
