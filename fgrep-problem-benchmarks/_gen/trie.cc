/* Generated by re2c 3.0 on Wed Dec  6 16:35:55 2023 */
#line 1 "trie.re2c.cc"

#line 5 "_gen/trie.cc"
{
	YYCTYPE yych;
	unsigned int yyaccept = 0;
	if ((YYLIMIT - YYCURSOR) < 5) YYFILL(5);
	yych = *YYCURSOR;
	switch (yych) {
		case 'b': goto yy3;
		case 'd': goto yy4;
		default: goto yy1;
	}
yy1:
	++YYCURSOR;
yy2:
#line 6 "trie.re2c.cc"
	{
    printf("other\n");
  }
#line 23 "_gen/trie.cc"
yy3:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
		case 'r': goto yy5;
		default: goto yy2;
	}
yy4:
	yych = *++YYCURSOR;
	switch (yych) {
		case 'o': goto yy7;
		default: goto yy2;
	}
yy5:
	yych = *++YYCURSOR;
	switch (yych) {
		case 'e': goto yy9;
		default: goto yy6;
	}
yy6:
	YYCURSOR = YYMARKER;
	if (yyaccept == 0) {
		goto yy2;
	} else {
		goto yy8;
	}
yy7:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
		case 'n': goto yy10;
		default: goto yy8;
	}
yy8:
#line 3 "trie.re2c.cc"
	{
    printf("keyword\n");
  }
#line 62 "_gen/trie.cc"
yy9:
	yych = *++YYCURSOR;
	switch (yych) {
		case 'a': goto yy11;
		default: goto yy6;
	}
yy10:
	yych = *++YYCURSOR;
	switch (yych) {
		case 'e': goto yy12;
		default: goto yy6;
	}
yy11:
	yych = *++YYCURSOR;
	switch (yych) {
		case 'k': goto yy12;
		default: goto yy6;
	}
yy12:
	++YYCURSOR;
	goto yy8;
}
#line 10 "trie.re2c.cc"

