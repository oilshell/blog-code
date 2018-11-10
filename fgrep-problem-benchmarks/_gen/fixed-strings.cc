/* Generated by re2c 1.0.3 on Sat Nov 10 12:00:55 2018 */
#line 1 "fixed-strings.re2c.cc"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/mman.h>  // mmap()
#include <unistd.h>  // write()
#include <string.h>  // strlen()

const int MAX_LINE = 1024;

void CountLines(char* buf, size_t num_bytes) {
    int num_lines = 0;
    char* cur = buf;
    char* end = buf + num_bytes;

    while (cur < end){
      if (*cur == '\n') {
        num_lines++;
      }
      cur++;
    }
    fprintf(stderr, "num_lines = %d\n", num_lines);
}

#line 28 "fixed-strings.re2c.cc"


void GrepFixedStrings(char* buf, size_t num_bytes) {
  char* p = buf;
  char* end = buf + num_bytes;
  char* end1 = end-1;

  char* YYMARKER;

  int num_lines = 0;
  int num_keywords = 0;
  int nothing = 0;

  bool print_line = false;

  // NOTE: I tried the "goto loop/goto done" instead of "continue/break", but
  // it didn't speed it up.
  for (;;) {
    
#line 47 "_gen/fixed-strings.cc"
{
	char yych;
	unsigned int yyaccept = 0;
	yych = *p;
	switch (yych) {
	case '\n':	goto yy4;
	case 'b':	goto yy6;
	case 'c':	goto yy7;
	case 'd':	goto yy8;
	case 'e':	goto yy9;
	case 'f':	goto yy10;
	case 'i':	goto yy11;
	case 't':	goto yy12;
	case 'w':	goto yy13;
	default:	goto yy2;
	}
yy2:
	++p;
yy3:
#line 59 "fixed-strings.re2c.cc"
	{
        // NOTE: states are reordered so we need continue everywhere.
        continue;
      }
#line 72 "_gen/fixed-strings.cc"
yy4:
	++p;
#line 53 "fixed-strings.re2c.cc"
	{
         print_line = false;
         num_lines++;
         if (p >= end1) break;
         continue;
      }
#line 82 "_gen/fixed-strings.cc"
yy6:
	yyaccept = 0;
	yych = *(YYMARKER = ++p);
	switch (yych) {
	case 'r':	goto yy14;
	default:	goto yy3;
	}
yy7:
	yyaccept = 0;
	yych = *(YYMARKER = ++p);
	switch (yych) {
	case 'a':	goto yy16;
	case 'o':	goto yy17;
	default:	goto yy3;
	}
yy8:
	yych = *++p;
	switch (yych) {
	case 'o':	goto yy18;
	default:	goto yy3;
	}
yy9:
	yyaccept = 0;
	yych = *(YYMARKER = ++p);
	switch (yych) {
	case 'l':	goto yy20;
	case 's':	goto yy21;
	default:	goto yy3;
	}
yy10:
	yyaccept = 0;
	yych = *(YYMARKER = ++p);
	switch (yych) {
	case 'i':	goto yy22;
	case 'o':	goto yy23;
	default:	goto yy3;
	}
yy11:
	yych = *++p;
	switch (yych) {
	case 'f':	goto yy22;
	default:	goto yy3;
	}
yy12:
	yyaccept = 0;
	yych = *(YYMARKER = ++p);
	switch (yych) {
	case 'h':	goto yy24;
	default:	goto yy3;
	}
yy13:
	yyaccept = 0;
	yych = *(YYMARKER = ++p);
	switch (yych) {
	case 'h':	goto yy25;
	default:	goto yy3;
	}
yy14:
	yych = *++p;
	switch (yych) {
	case 'e':	goto yy26;
	default:	goto yy15;
	}
yy15:
	p = YYMARKER;
	if (yyaccept == 0) {
		goto yy3;
	} else {
		goto yy19;
	}
yy16:
	yych = *++p;
	switch (yych) {
	case 's':	goto yy27;
	default:	goto yy15;
	}
yy17:
	yych = *++p;
	switch (yych) {
	case 'n':	goto yy28;
	default:	goto yy15;
	}
yy18:
	yyaccept = 1;
	yych = *(YYMARKER = ++p);
	switch (yych) {
	case 'n':	goto yy27;
	default:	goto yy19;
	}
yy19:
#line 49 "fixed-strings.re2c.cc"
	{
        num_keywords++;
        continue;
      }
#line 178 "_gen/fixed-strings.cc"
yy20:
	yych = *++p;
	switch (yych) {
	case 'i':	goto yy29;
	case 's':	goto yy27;
	default:	goto yy15;
	}
yy21:
	yych = *++p;
	switch (yych) {
	case 'a':	goto yy30;
	default:	goto yy15;
	}
yy22:
	++p;
	goto yy19;
yy23:
	yych = *++p;
	switch (yych) {
	case 'r':	goto yy22;
	default:	goto yy15;
	}
yy24:
	yych = *++p;
	switch (yych) {
	case 'e':	goto yy31;
	default:	goto yy15;
	}
yy25:
	yych = *++p;
	switch (yych) {
	case 'i':	goto yy32;
	default:	goto yy15;
	}
yy26:
	yych = *++p;
	switch (yych) {
	case 'a':	goto yy33;
	default:	goto yy15;
	}
yy27:
	yych = *++p;
	switch (yych) {
	case 'e':	goto yy22;
	default:	goto yy15;
	}
yy28:
	yych = *++p;
	switch (yych) {
	case 't':	goto yy34;
	default:	goto yy15;
	}
yy29:
	yych = *++p;
	switch (yych) {
	case 'f':	goto yy22;
	default:	goto yy15;
	}
yy30:
	yych = *++p;
	switch (yych) {
	case 'c':	goto yy22;
	default:	goto yy15;
	}
yy31:
	yych = *++p;
	switch (yych) {
	case 'n':	goto yy22;
	default:	goto yy15;
	}
yy32:
	yych = *++p;
	switch (yych) {
	case 'l':	goto yy27;
	default:	goto yy15;
	}
yy33:
	yych = *++p;
	switch (yych) {
	case 'k':	goto yy22;
	default:	goto yy15;
	}
yy34:
	yych = *++p;
	switch (yych) {
	case 'i':	goto yy35;
	default:	goto yy15;
	}
yy35:
	yych = *++p;
	switch (yych) {
	case 'n':	goto yy36;
	default:	goto yy15;
	}
yy36:
	yych = *++p;
	switch (yych) {
	case 'u':	goto yy27;
	default:	goto yy15;
	}
}
#line 63 "fixed-strings.re2c.cc"

  }
  fprintf(stderr, "num_lines = %d\n", num_lines);
  fprintf(stderr, "num_keywords = %d\n", num_keywords);
  fprintf(stderr, "nothing = %d\n", nothing);
}


int main(int argc, char **argv) {
  if (argc == 0) {
    printf("Expected filename\n");
    return 1;
  }
  char* action = argv[1];

  FILE *f = fopen(argv[2], "rb");
  if (!f) {
    printf("Error opening %s\n", argv[1]);
    return 1;
  }

  fseek(f, 0, SEEK_END);
  size_t num_bytes = ftell(f);
  fseek(f, 0, SEEK_SET);  //same as rewind(f);

  int fd = fileno(f);

  if (strcmp(action, "read:fixed-strings") == 0) {  // read
    char* buf = (char*)malloc(num_bytes);
    size_t num_read = read(fd, buf, num_bytes);

    GrepFixedStrings(buf, num_bytes);

    fprintf(stderr, "num_bytes = %zu\n", num_bytes);
    //free(buf);

    return 0;
  } 

  if (strcmp(action, "read:count-lines") == 0) {  // read
    char* buf = (char*)malloc(num_bytes);
    size_t num_read = read(fd, buf, num_bytes);

    CountLines(buf, num_bytes);

    fprintf(stderr, "num_bytes = %zu\n", num_bytes);
    //free(buf);

    return 0;
  } 

  if (strcmp(action, "fgets") == 0) {
    char line[MAX_LINE]; 
    while (fgets(line, MAX_LINE, f)) {
      //printf("string is: %s\n", buf); 
      //puts(line);
      fputs(line, stdout);
      //write(1, line, strlen(line));
    }

    return 0;
  }
  
  if (strcmp(action, "mmap") == 0) {  // mmap

    //int fd = open(argv[1], O_RDONLY, 0);
    //assert(fd != -1);
    //Execute mmap
    char* buf = (char*)mmap(NULL, num_bytes, PROT_READ, MAP_PRIVATE | MAP_POPULATE, fd, 0);
    assert(buf != MAP_FAILED);

    // 963 ms on all-10.txt.  Hm OK.
    //CountLines(buf, num_bytes);

    // 969 ms with a couple keywords.  Not slower.
    // But if I add like 10 keywords, then it's 2.3 seconds!  Slower than
    // fgrep!

    // fgrep is over a second too though.
    GrepFixedStrings(buf, num_bytes);

    //Write the mmapped data to stdout (= FD #1)
    //size_t out = write(1, buf, num_bytes);

    //Cleanup
    int rc = munmap(buf, num_bytes);
    if (rc != 0) {
      perror("Error munmap:");
    }
    //close(fd);

    return 0;
  }

  fclose(f);

  fprintf(stderr, "Invalid action");
  return 1;
}