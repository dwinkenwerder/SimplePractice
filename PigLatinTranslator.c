#include <stdio.h>
#include <string.h>

//NOTE PLEASE READ: After writing this, I realised it was riddled with opportunities
//for an attacker to perform a buffer overflow attack. While I don't
//anticipate anyone to try, as they would have nothing to gain from this,
//I am rewriting this program as an excercise in practicing safer coding
//conventions.
//Other things that could be improved : check the input to make sure its
//a single word. At the moment, any input would be accepted, but there's
//no use trying to make a sentence like "the sun is bright" pig latin, as
//for now it would just output "he sun is brighttay"
//also, if the starting letter is part of a two letter syllable such as
//th or sh, i should ensure that both go. its not proper pig latin to say
//heretay, it should be erethay.


int isVowel(char c){
	if (c == 'a' || c == 'e' ||  c== 'i' || c== 'o' || c =='u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c== 'U')
		return 1;
	else
		return 0;
}

main()
{
	//get user input string
	printf("Please enter a word to be turned to pig latin\n");
	char str[100];
	gets(str);
	char first = str[0];
	//perform the string manipulation to make pig latin
	if (isVowel(first)==0)
	{
		char tmp[4];
		tmp[0] = first; tmp[1] = 'a'; tmp[2] = 'y'; tmp[3] = '\0';
		strcat(str, tmp);
		memmove(str, str + 1, strlen(str));
		printf("%s\n", str);
	}
	else
	{
		strcat(str, "yay");
		printf("%s\n", str);
	}
	//stall indefinitely to show the result
	while (1 == 1)
	{

	}

}