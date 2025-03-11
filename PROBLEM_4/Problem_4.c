#include<stdio.h>
#include<stdbool.h>
//every braket need to be matched
//order too!!!


bool check_match(const char *s ,char braket,int pos)
{

	bool test;
	char the_match;

	if(braket == '(')
		the_match = ')';
	else if(braket == '[')
		the_match =']';
	else if(braket= '{')
		the_match= '}';	//we chose the match braket we search for

       	while(s[pos] != '\0')
		 {
			 if(s[pos] == '[' ||s[pos] == '{'||s[pos] == '(')
			{
			//if there is another braket opened we need to 
			//verfie its match first cuz order is importent
				test = check_match(s,s[pos],pos+1);
				if(test ==false)
					return false;
			//if test=false no need to continue return false
			}
		       	else if(s[pos] == the_match)
			//if the match exict ret true
				return true;
			pos++;
		 }
	//we can know that test = false if this while is ended and nothing
	//is returned
	
}
bool isValid ( const char *s )
{
	int i=0;
	
	while(s[i] != '\0')
	{

	//so this bocle that will go through the string will test if 
	//a braket exist
	//and it will lanch a test if it exist
		if(s[i] == '[' ||s[i] == '{'|| s[i]== '(')
		{
			return check_match(s,s[i],i+1);
		}
		i++;
	}
}
/*
int main(void)
{
    const char *test1 = " () ";
    const char *test2 = " [{() } ";
    const char *test3 = " {({{_}[ a] + b} ) * x } ";
    const char *test4 = " {[ a + b ]*( x / y ][) } ";

    printf("Test 1: %s\n", test1);
    printf("Is valid: %d\n", isValid(test1));

    printf("Test 2: %s\n", test2);
    printf("Is valid: %d\n", isValid(test2));

    printf("Test 3: %s\n", test3);
    printf("Is valid: %d\n", isValid(test3));

    printf("Test 4: %s\n", test4);
    printf("Is valid: %d\n", isValid(test4));

    return 0;
}
