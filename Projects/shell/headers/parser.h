#ifndef PARSER_H
#define PARSER_H

struct parsed_command {
	char **args;
	char *filename;
};

struct parsed_command *parser(char *input);

#endif
