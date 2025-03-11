#include<stdio.h>


int My_strlen(const char *str)
{
        int i=0;//declare the index to move through the string

        while(str[i] != '\0')
        {
                i++;
        }
        return i;
}

void reverse_string(char *str)
{
        int i=0;
        int len;//the length of the string
        char tmp;// we will use this variable to reverse the chars in the str
                 
        len=My_strlen(str)-1;

        while (len > i)
        {
                tmp = str[i];
                str[i] = str[len];
                str[len] = tmp; 
                i++;
                len--;
        }

}


//so the idea behind the function reverse_by_ur_wills is to reserve only the caracters 
//btw start and end(we will need it in the next function)
void reverse_by_ur_will(char *str,int start,int end)
{
	char swap;//to help store a value while swaping
	while (start < end)
	{
		swap=str[end];
		str[end]=str[start];
		str[start]= swap;
		start++;
		end--;
	}
}


void reverse_words(char *str)
{

	int start=0;//index to move through the string
	int end=0;//so the start and end var will help us know the index of the start andthe end of a'word'

	reverse_string(str);

	while(str[start] !='\0')
	{
		end++;
		if(str[start] == ' ')
			start++;

		else if (str[end]== '\0' || str[end] ==' ')
		{
			reverse_by_ur_will(str,start,end-1);
			start = end;
		}
	}
}
/*
int main ( void )
 {
 char test1 [] = " The dragons are coming " ;
 char test2 [] = " code love I " ;
 char test3 [] = " G " ;

 printf ( " Before : % s \n " , test1 ) ;
 reverse_words ( test1 ) ;
 printf ( " After : % s \n \n " , test1 ) ;

 printf ( " Before : % s \n " , test2 ) ;
 reverse_words ( test2 ) ;
 printf ( " After : % s \n \n " , test2 ) ;

 printf ( " Before : % s \n " , test3 ) ;
 reverse_words ( test3 ) ;
 printf ( " After : % s \n \n " , test3 ) ;

 return 0;
 }*/
