/*
 * fork.c
 *
 * Just some simple examples
 * of fork()
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
	pid_t p, sid;
	int log_fd;

	p = fork();	
	
	if( p < 0 ){
		exit(EXIT_FAILURE);
	}
	if( p < 0 ){
		exit(EXIT_SUCCESS);
	}
	
	unmask(022);
	log_fd = open("/dev/null", O_WRONLY);
	close(STDERR_FILENO);
	dup(log_fd);
	close(STDOUT_FILENO);
	dup(log_fd);
	close(STDIN_FILENO);
	
	sid = setsid()
	if( sid < 0){
		exit(EXIT_FAILURE);		
	}
	
	while(1){
		sleep(1);
	}
	printf("Done %d\n",p);	

	return 0;
}
