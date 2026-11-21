void cond(short a, short *p) {
	if (a && *p < a)
		goto assign;
	return;
assign:
	*p = a;
}
