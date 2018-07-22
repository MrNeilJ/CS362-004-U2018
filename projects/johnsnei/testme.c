#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	// Get all the potential letters and select one of them (we included both upper and lowercase)
	char allLetters = rand() % 94 + 32;
	return allLetters;
}

char *inputString()
{
    // TODO: rewrite this function
	// Set a size for the "string" to fit into
	static char strArr[6];

	// Slowly build a string for the test, since it only looks for lower case letters we will limit it to that
	int i;
	// Since both vowels are 1 apart, and are the only odd values in the set we can use that to shorten our random
	char vowelRound = "aeiou"[rand() % 5];
	// Change of plans, shrink the amount of potential letters that it can be otherwise this will take forever
	for(i = 0; i < 5; i++) {
		//strArr[i] = rand() % 26 + 97;
		if (i % 2  == 1) {
			strArr[i] = vowelRound;
		}
		else {
			strArr[i] = rand() % 17 + 101;
		}
	}
	// Make sure the final character is in fact a null terminator
	strArr[5] = '\0';
	return strArr;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
	inputChar();
	testme();
    return 0;
}


