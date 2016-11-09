#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <ctype.h>


void cls_help();
void error(char * err);	//Wrapper for perror

int main(int argc, char *argv[])
{
	char cwd[1024];
	int i, z;
	DIR *dp = opendir("./");
	struct dirent *ep;
	i = z = 0;

	if(dp == NULL || getcwd(cwd, sizeof(cwd)) == NULL)
		error("Can't open dir");
	system("clear");
	
	printf("pwd: %s\n", cwd); //print's out current dir
	while(ep = readdir(dp) != EOF){ //printf out current dir files
		
		if(strcmp(ep->d_name, ".") || strcmp(ep->d_name, " ..")){
			printf("%s ", ep->d_name);
			i++;
		}
		
		if (i == z + 5) {
			printf("\n"); 
			z = i;
		}
	}
	printf("\n");
	
	closedir(dp);
	return 0;
}

void error(char * err)
{
	perror(err);
	exit(0);
}

void cls_help()
{
	printf("cls made by k0oo _ 2015-10©\n");
	printf("cls is a command line app that recreates this command:\n");
	printf("\t\tclear && pwd && ls\n");
	printf("-------------\n");
	printf("Usage:\n");
	printf("\t cls [-h]\n\n");
	printf("\t\'-h\'\t\'--help\'\tGives help and aditional info.\n");
	printf("cls-ko© All right's reserved.\n");
}
