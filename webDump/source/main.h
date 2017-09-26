//
//  main.h
//  WebServer
//
//  Created by Leo Smith on 31/10/2016.
//  Copyright © 2016 Leo Smith. All rights reserved.
//

#ifndef main_h
#define main_h

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#ifndef GLOBAL
	#define PORT 80
	#define MAXCLI 5
#endif

struct _arg_vars {

	int verbose;
	int counter;
	int file;
	int rm_error;						// a var to remove warnings

};

struct _server_vars {

	FILE *fp;

	int s;
	int *s_client;
	unsigned int cliNum;
	
	char buf[BUFSIZ];
	char request[BUFSIZ];
	char file_name[BUFSIZ];
	
	struct sockaddr_in server, client;
	struct _arg_vars a_var;	

};

enum METHOD { POST, GET };

extern int errno;

//nt closeConnected_cli(struct _server_vars * s_var); misc
void usage(char * exec);
void print_var(struct _server_vars * s_var);
int init(struct _server_vars * s_var);

// errors
void error(char * msg);

// server Files
int error404(struct _server_vars * s_var, int flag);
int sendFile(struct _server_vars * s_var);

// setup
int setupSock_Bind(struct _server_vars * s_var);
int setupProgram_arg(struct _server_vars * s_var, int argc, char * argv[]);

// server
int acceptClient(struct _server_vars * s_var);
int handleRequest(struct _server_vars * s_var);
int closeConnected_cli(struct _server_vars * s_var);

#endif /* main_h */
