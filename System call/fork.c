#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include <stdlib.h>
int main()
{
pid_t q;
q=fork();
if(q<0)
{
printf("fork error/n");
exit(1);
}
else if(q==0)
{
printf("child process create\n");

printf("I am child having id:%d\n",getpid());
printf("My parent id:%d\n",getppid());
printf("child process is exitting\n");
exit(0);

}
else {printf("parent process is processing\n");
printf("I am parent having id:%d\n",getpid());
printf("My child id:%d\n",q);
sleep(2);
printf("parent process is exiting\n");
exit(0);



}








}

