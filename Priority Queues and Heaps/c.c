#include<stdio.h>
#include<unistd.h>
int main()
{
    FILE * fp;
    char buf[50];
    fp = popen("ps", "r");
    fread(buf,1,50,fp);
    printf("%s \n", buf);
    pclose(fp);
}