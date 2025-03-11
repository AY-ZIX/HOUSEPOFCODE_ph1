#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int word_cont(const char *str, int delimiter)
{
	int i=0;
	int word;
	
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

	answer=malloc(sizeof (char* ) * word_cont(str,delimiter));
	
	while(str[i] != '\0')
	{
		if(str[i] == delimiter)
			i++;
		else
		{
			answer[j]=malloc(sizeof(char) * word_len);
			strcpy(answer[j],return_the_word(str,i,delimiter));
			j++;
			i=word_len+i;
		}
		
		word_len=return_word_length(str,i,delimiter);
	}

	answer[j]=NULL;
	return answer;
}
/*
int main(void)
{
    char *str = " /IAE/ /CLUB/CHALLANGE";
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

