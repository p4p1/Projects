//
//	Made by p4p1
//	httpError.c
//	WebServer
//
//	Created by Leo Smith
//	Copyright 2016 Leo Smith. All rights reserved
//

#include "main.h"

int sendFile(struct _server_vars * s_var)
{
	char c;
	char * fbuf;
	int size;
	int i;

	c = size = i = 0;
	while((c = getc(s_var->fp)) != EOF) {
		printf("%c", (s_var->a_var.verbose)? c : '\0');
		size++;
	}
	rewind(s_var->fp);
	fbuf = malloc((size+1) * sizeof(char));
	while(((c = getc(s_var->fp)) != EOF) && i < size) {
		fbuf[i++] = c;
	}
	write(*(s_var->s_client+s_var->cliNum), fbuf, size);
	free(fbuf);
	return (0);
}
