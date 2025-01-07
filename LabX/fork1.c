#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
pid_t mainp=getpid();

	for (int i =0; i<3; i++){ 
	pid_t pid=fork();

	if (pid <0){
	perror("fork failed");
	exit(EXIT_FAILURE);
}

	if (pid ==0 && getppid()==mainp){
	printf("Fork : %d \t PID : %d \n", i , getpid()); 
}

}
}

