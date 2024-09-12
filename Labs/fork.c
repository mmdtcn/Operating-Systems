#include     <sys/types.h>
#include     <stdio.h>
#include     <unistd.h>

int main()
{
	pid_t pid;	

	/*fork a child process*/
	pid = fork();
	if (pid<0){ /*error occured*/
	sprintf(stderr,"Fork Failed");
	return 1;	
	}	
	else if (pid==0){ /*child process*/
		execlp("/bin/ls","ls",NULL);

	}
	 else {/*parent processs*/
	/*parent will wait for the child to complete*/
	wait(NULL);
	printf("child Complete \n");   
	}		
	return 0;
}
