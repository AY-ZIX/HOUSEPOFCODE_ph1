#include<stdio.h>

/* the logic: WE WILL USE THE STRLEN FONCTION WE CREATE IN PROB1 TO GET THE LENGTH OF THE
	      STRING SO WE CAN REVERSE THE ORDER OF THE STRING
*/


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
	char tmp;// we will use this variable to reverse the char in the str position
		 
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
//SO MY IDEA IS TO USE THe SWAP method TO CHANGE THE STR[i] WITH STR[len] TILL WE HAVE
//LEN < i AND THAT WILL MEAN THAT THE BOTH RIGHT AND LEFT HALF OF THE STRINGS WERE SWAPED!

/*
int main ( void )
 {
 char test1 [] = "edoc fo esuoH oT emocleW" ;
 char test2 [] = "uoy pleh lliw ti ;3 melborp ni noitcnuf siht esU" ;
 char test3 [] = "Hello World" ;
 char test4 [] = "G" ;

 printf ( " Before : % s \n " , test1 ) ;
 reverse_string ( test1 ) ;
 printf ( " After : % s \n \n " , test1 ) ;

 printf ( " Before : % s \n " , test2 ) ;
 reverse_string ( test2 ) ;
 printf ( " After : % s \n \n " , test2 ) ;

 printf ( " Before : % s \n " , test3 ) ;
 reverse_string ( test3 ) ;
 printf ( " After : % s \n \n " , test3 ) ;

 printf ( " Before : % s \n " , test4 ) ;
 reverse_string ( test4 ) ;
 printf ( " After : % s \n \n " , test4 ) ;

 return 0;
 }
