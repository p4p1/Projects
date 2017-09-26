//
//  serverSetup.c
//  WebServer
//
//  Created by Leo Smith on 31/10/2016.
//  Copyright © 2016 Leo Smith. All rights reserved.
//

#include "main.h"

int setupSock_Bind(struct _server_vars * s_var)
{
	int binderr;
	int lerr;
	int enable;
	
	binderr = 0;
	lerr = 0;
	enable = 1;

	s_var->s_client = malloc(MAXCLI * sizeof(int));
	printf("%s",
		(s_var->a_var.verbose)? "[ Ok ]Allocated memory for the clients\n" : "");
	if(s_var->a_var.file){
		s_var->fp = fopen(s_var->file_name, "r");
		if(s_var->fp == NULL)
			error("[ Err ]File does not exist");
	}
	printf("%s", (s_var->a_var.verbose)? "[ Ok ]File opened succesfully\n": "");
	s_var->s = socket(AF_INET, SOCK_STREAM, 0);
	if(((s_var->s)) < 0)
		error("[ Err ]Couldnt create socket");
	printf("%s", (s_var->a_var.verbose)? "[ Ok ]Socket created\n" : "");

	s_var->server.sin_family = AF_INET;
	s_var->server.sin_addr.s_addr = INADDR_ANY;
	s_var->server.sin_port = htons( PORT );
	printf("%s",
		(s_var->a_var.verbose)? "[ Ok ]Socket parameters updated\n" : "");

	if (setsockopt(s_var->s, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int))<0)
		error("setsockopt(SO_REUSEADDR) failed");

	binderr = bind(s_var->s, (struct sockaddr *)&s_var->server, sizeof(s_var->server));
	if(binderr < 0) {
		error("Bind Failed");
	}
	printf("%s", (s_var->a_var.verbose)? "[ Ok ]Bind successful\n": "");

	lerr = listen(s_var->s, 3);
	if(lerr < 0) {
		error("listen failed");
	}	
	printf("%s", (s_var->a_var.verbose)? "[ Ok ]Listen successful\n" : "");

	return 0;
}

int setupProgram_arg(struct _server_vars * s_var, int argc, char * argv[])
{
	int argn;

	argn=1;
	if(argc > 1) {
		if(!strcmp(argv[argn], "-v")) {
			s_var->a_var.verbose++;
			argn++;
		}
		if (!strcmp(argv[argn], "-c")) {
			if(argc > 2)
				s_var->a_var.counter = atoi(argv[argn+1]);
			else
				usage(argv[0]);
		} else if(!strcmp(argv[argn], "-f")) {
			if(argc > 2) {
				s_var->a_var.file++;
				snprintf(s_var->file_name, BUFSIZ, "%s", argv[argn+1]);
			} else
				usage(argv[0]);
		} else {
			usage(argv[0]);
		}
	}
	return 0;
}

int init(struct _server_vars * s_var)
{
	for(int i = 0; i < BUFSIZ; i++) {
		s_var->buf[i] = 0;
		s_var->request[i] = 0;
		s_var->file_name[i] = 0;
	}

	s_var->fp = NULL;
	s_var->cliNum = 0;
	s_var->a_var.verbose = 0;
	s_var->s = 0;
	s_var->a_var.rm_error = 0;
	s_var->a_var.counter = 100000;
	s_var->a_var.file = 0;

	return 0;
}
