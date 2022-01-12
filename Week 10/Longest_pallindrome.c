/*Finding longest pallindrome*/ 

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int Str_check(char *s, int len)           
{
	char *s1,*s2;
	s1=s;
	s2=s+len;	
	int outcome=1;

	while((s1+1)<s2)
	{
		if(*s1++!=*s2--)
		{
			return 0;
		}
	}
	if((s1+1)==s2 && *s1!=*s2)
		return 0;

	return outcome;	
}

void L_Pallindrome(char * str){           /*LP function*/
	int i,j,len,max=0;
	char *ptr1,*ptr2,*ptr;
	char *lpd;

	len=strlen(str);
	lpd=(char*)malloc((len+1)*sizeof(char));

	for(i=0;i<len;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(Str_check(str+i,j-i)&&(max<j-i+1))
			{				
				ptr=str+i;
				max=j-i+1;
			}				
		}
	}

	if(max==0)
	{
		lpd[0]=str[0];
	}
	else
	{        
		memcpy(lpd,ptr,max);				
		lpd[max]='\0';          
	}
    printf("\nLongest Pallindrome  = ");
	printf(lpd);
}

int main(){
    char str[100];
    printf("Enter the string : ");
    scanf("%s",&str);
    printf("\n");
    printf("Entered string       = %s",str);
    
    L_Pallindrome(str);      //Longest Pallindrome

}