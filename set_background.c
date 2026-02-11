#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(int argc , char *argv[]) {
  const char *destination = "/home/your_username/.config/omarchy/backgrounds/tokyo-night/";
  if (argc < 2){
    printf("Usage: ./set_background imagefile1 imagefile2 ... \n");
    exit(1); 
  }
  for(int i = 1 ; i < argc; i++){ 
    pid_t pid = fork();
    
    if (pid == 0){ 
      execlp("mv","mv", argv[i],destination,(char *)NULL);
      //if process fail 
      perror("this command can not work\n");
    }else if (pid > 0){
      wait(NULL); 
      printf("process file %s\n", argv[i]);  
    }else {
      perror("fork failed ");
    }  
  } 
  return 0;
}
