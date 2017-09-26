//
//	Made by p4p1
//	httpError.c
//	WebServer
//
//	Created by Leo Smith
//	Copyright 2016 Leo Smith. All rights reserved
//

#include "main.h"

int error404(struct _server_vars * s_var, int flag)
{
	sprintf(s_var->buf, "<script>"
                                "alert(\"ERROR 404: index.html\");"
                        "</script>"
                        "<h1>ERROR 404</h1>"
                        "<p>We are sorry to tell you that this page is now "
                        "unavailable</p><br />"
						"<img src=\"http://2slick.com/web/wp-content/"
						"uploads/2012/09/sad_website_620x350.jpg\" />"
			);

	if(flag)
		write(*(s_var->s_client+s_var->cliNum), s_var->buf, strlen(s_var->buf));

	return 404;
}
