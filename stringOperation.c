#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ISLETTER(x) (((x >= 'a') && (x <= 'z')) || ((x >= 'A') && (x <= 'Z')))

void str_reverse(char *s1, char *s2)
{
	int i = strlen(s1);
	while (i) {
		*s2++ = s1[--i];
	}
	*s2 = '\0';
}

int str_word_num(char *s)
{
	int cnt = 0;
	
	while (*s != '\0') {
		if (!ISLETTER(*s)) {
			s++;
			continue;
		}

		do{
			s++;
		}while(ISLETTER(*s));

		cnt++;
	}
	return cnt;
}

int main(int argc, char *argv[])
{
	char s1[100];
	char *s2;
	int len;
	printf("Input the string:\n");
	gets(s1);
	
	len = strlen(s1);

	s2 = malloc(len + 1);
	if (s2 == NULL) {
		printf(" Malloc error\n");
		return -1;
	}

	str_reverse(s1, s2);

	printf("Length: %d\n", len);
	printf("Words: %d\n", str_word_num(s1));
	printf("Reverse: %s\n", s2);
	return 0;
}
