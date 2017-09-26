//
//  handleClient.c
//  WebServer
//
//  Created by Leo Smith on 31/10/2016.
//  Copyright © 2016 Leo Smith. All rights reserved.
//

#include "main.h"

int acceptClient(struct _server_vars * s_var)
{
	int c;

	printf("%s",
			(s_var->a_var.verbose)? "[ Status ]Accepting connection ...\n" : "");
	c = sizeof(struct sockaddr_in);
	*(s_var->s_client + s_var->cliNum) = accept(s_var->s,
				(struct sockaddr *)&s_var->client, (socklen_t *)&c);
	if(*(s_var->s_client + s_var->cliNum) < 0)
		error("accept Error");
	else
		printf("%s", (s_var->a_var.verbose)? "[ Ok ]Client accepted\n": "");

	read(*(s_var->s_client+s_var->cliNum), s_var->request, BUFSIZ);
	printf("%s", s_var->request);
	if(s_var->a_var.file)
		sendFile(s_var);
	else
		error404(s_var, 1);
	s_var->cliNum++;

	return 0;
}

int closeConnected_cli(struct _server_vars * s_var)
{
	int err;

	err = close( *(s_var->s_client + s_var->cliNum) );
	if(err < 0) {
		printf("[ Err ]Can't close the clients socket\n");
		if(s_var->a_var.verbose)
			printf("[ Err ]Error code is %d\n", errno);
	} else {
		s_var->cliNum--;
		printf("%s", (s_var->a_var.verbose)? "[ Ok ]Client disconected\n" : "");
	}

	return 0;
}
