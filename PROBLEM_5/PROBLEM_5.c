#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//this function will return the length of a the chars btw the delimiters
//(words,etc..)
int return_word_length(const char *string,int pos,char delimiter)
{
	int start=pos;
	while(string[pos] !='\0')
	{
		if(string[pos]== delimiter)
			break;
		pos++;
	}
	return pos -start;
}

//this function will return the chars btw the delimiters
char *return_the_word(const char *string,int pos,char delimiter)
{
	char *s=malloc(sizeof(char)*return_word_length(string,pos,delimiter)+1);
	int i=0;
	while( string[pos] !='\0')
	{
		if(string[pos] == delimiter)
			break;
		s[i]=string[pos];
		i++;
		pos++;
	}
	s[i]='\0';
	return s;
}

//this function is using delimiters and '\0' to count the number of word 
//to help us after,to allocat the exact numb of lines
int word_cont(const char *str, int delimiter)
{
	int i=0;
	int word=0;
	
	while (str[i] != '\0')
	{
		if (str[i+1]== delimiter ||str[i+1] == '\0' )
		{
			word++;
			i++;
		}
		else
			i++;
	}
	return word;
}

char** split_str(const char* str, char delimiter)
{
	int i=0;
	int j=0;
	char **answer=NULL;
	int word_len;

	word_len=return_word_length(str,i,delimiter);

	answer=malloc(sizeof (char* ) * word_cont(str,delimiter)+1);
	//add 1 for NULL
	
	while(str[i] != '\0')
	{
		if(str[i] == delimiter)
			i++; //skip delimiters
		else 
		{
			answer[j]=malloc(sizeof(char) * word_len);
			//allocat for the word
			strcpy(answer[j],return_the_word(str,i,delimiter));
			//copy the word in the line[j]
			j++;
			i=word_len+i;//skip to the end of the word+1
		}
		
		word_len=return_word_length(str,i,delimiter);
		//every time it will change the wordlen to allocat the
		//exact length of the string(line)
	}

	answer[j]=NULL;
	return answer;
}
// my idea is to cont every word and allocat the exact space using wordlen
// and allocat the exact lines by usin word_cont function
// and then cpy with a function only chars != delimiter


/*
int main(void)
{
    char *str = " / IAE / / CLUB /", delimiter = ' ';
    char **vector = split_str(str, '/');
    int i;

    i = 0;
    while (vector[i] != NULL)
    {
        printf("Substring %d: %s\n", i + 1, vector[i]);
        i++;
    }
    i=0;
    while (vector[i] != NULL)
    {
        free(vector[i]);
        i++;
    }

    free(vector);
    return 0;
}

