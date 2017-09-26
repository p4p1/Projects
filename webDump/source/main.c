/*
 *  main.c
 *  WebServer
 *
 *  Created by Leo Smith on 31/10/2016.
 *  Copyright © 2016 Leo Smith. All rights reserved.
*/

#include "main.h"

int main(int ac, char * av[])
{
	int i;
	struct _server_vars s_var;
	init(&s_var);
	i = 0;

	setupProgram_arg(&s_var, ac, av);
	setupSock_Bind(&s_var);	
	while(i < s_var.a_var.counter){
		acceptClient(&s_var);
		closeConnected_cli(&s_var);
		i++;
	}

	free(s_var.s_client);
	return (0);
}

void error(char * msg)
{
	perror(msg);
	exit(errno);
}

void usage(char * exec)
{
	printf("%s is a non profit software used to have a small web server\n"
		"That dumps its output on the go  for various manipulation."
		"usage:\n"
		"\t%s\t-h\tShow this message\n"
		"\t%s\t-v\tVerbose mode\n"
		"\t%s\t-c\tOnly accept a number n of connections\n"
		"\t%s\t-f\tFile mode\n"
		"Exemples:\n"
		"\t%s\n"
		"\t%s -c 1 > output.txt\n"
		"\t%s -f file.html\n"
		"\t%s -v\n", exec, exec, exec, exec, exec, exec, exec, exec, exec);
}

void print_var(struct _server_vars * inf)
{
	inf->a_var.rm_error = 0;
	#ifdef _DEBUG
	printf("buf : %s\n"
				"cliNum : %d\n"
				"s : %d\n"
				"request : %s\n"
				"file_name : %s\n"
				"------------------------\n",
				inf->buf, inf->cliNum, inf->s, inf->request, inf->file_name);

	printf("_arg_vars a_var\n"
				"a_var.verbose : %d\n"
				"a_var.counter : %d\n"
				"a_var.file : %d\n"
				"------------------------\n",
				inf->a_var.verbose, inf->a_var.counter, inf->a_var.file);

	printf("s_client:\n");
	for(int i = 0; i < MAXCLI; i++)
		printf("%d : %d\n", i, s_client[i]);
	#endif
}
