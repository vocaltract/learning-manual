#include <stdio.h>
#include <string.h>
#define a2imap(x) ((x)-48)

int atoi(const char* nptr){
    int start=0, sign=1, res=0;
    /*If you want to send -1 when num is overflowed, cancel the comment.*/

/*    if((strcmp(nptr,"2147483647")>0 && strlen(nptr) >=10)|| 
    (nptr[0]=='-' && strlen(nptr) >=11 && strcmp(nptr, "-2147483648")>0))           return -1;*/
    if(a2imap(nptr[0]) == a2imap('-'))
    {
      start++;
      sign =-1;
    }
    for(;nptr[start]!='\0';start++)
    {
      res *= 10;
      res += (int)a2imap(nptr[start]);
    }
    return res*sign;

}
int main()
{
    printf("%d\n",atoi("-2147483648"));
}