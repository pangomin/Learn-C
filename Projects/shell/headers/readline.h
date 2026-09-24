#ifndef READLINE_H
#define READLINE_H

enum readline_status {
	READLINE_OK,
	READLINE_EOF,
	READLINE_ERROR
};

char *readline(enum readline_status *rlstatus);

#endif
