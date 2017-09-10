#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[100010];
char strR[100010];
int pre[100010];

void prefix(char str[],int pre[]){
    int i,j; 

    for(i=1,j=pre[0]=-1; str[i]!='\0'; ++i){
        
	while(j>=0 && str[i] != str[j+1]) j = pre[j];
        
	if(str[i] == str[j+1]) ++j;
        pre[i] = j;

	}
}

int main(){
    int i,j;
    int len;
    
    while(gets(str)){
        
	len = strlen(str);
        
	for(i=0; i<len; ++i){
            strR[i] = str[len-1-i];
        }

        strR[len] = '\0';
        prefix(strR,pre);
        
	for(i=0,j=-1;str[i]!='\0';++i){
            while(j>=0 && str[i]!=strR[j+1])j=pre[j];
            if(str[i]==strR[j+1])++j;
        }
	
        printf("%s%s\n",str,&strR[j+1]);
    }
    return 0;
}
