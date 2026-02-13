#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>


void file_check(const char *file){
  //detect the last work in filename ".png" or "jpg" or "jpeg"
  const char* dot = strchr(file,'.');

  //xem nếu đó có phần dấu chấm không 
  if(!dot || dot == file){
    printf("this is not a picture file\n");
    return;
  }
  //if is not that name so is not the file return This is not a picture file 
  if(strcmp(dot,".png") == 0 || strcmp(dot,".jpg") == 0 || strcmp(dot,".jpeg") == 0){
    printf("this is the picture file: %s\n",file);
  }else{
    perror("this is not a picture file\n");
    return;
  }
}

int main(int argc , char *argv[]) {
  const char *destination = "/home/elliot/.config/omarchy/backgrounds/tokyo-night/";
  if (argc < 2){
    printf("Usage: ./set_background imagefile1 imagefile2 ... (or picture directory) \n");
    exit(1); 
  }
  for(int i = 1 ; i < argc; i++){ 
    pid_t pid = fork(); // tạo ra tiến trình con cho cá phần 
    
    if (pid == 0){  // tiến trình con
      file_check(argv[i]); 
      execlp("mv","mv", argv[i],destination,(char *)NULL);
      //if process fail 
      perror("this command can not work\n");
    }else if (pid > 0){ 
      wait(NULL); 
      printf("process file %s\n", argv[i]);  
    }else { // tiến trình không hoạt động được 
      perror("fork failed ");
    }  
  } 
  return 0;
}

