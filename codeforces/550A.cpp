#include<stdio.h>
#include <string.h>
 
char s[100001];
int main()
{
	char *c;
    scanf("%s",s);
    if((c=strstr(s,"AB"))!=NULL && strstr(c+2,"BA")!=NULL)
    {
         printf("YES\n");
         return 0;
    }
    if((c=strstr(s,"BA"))!=NULL && strstr(c+2,"AB")!=NULL)
    {
         printf("YES\n");
         return 0;
    }
    printf("NO\n");
    return 0;
}






//strstr用法
//多罗列考虑特殊情况 如ABAB 和 ABABAB 
