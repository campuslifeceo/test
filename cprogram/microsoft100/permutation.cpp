#include <stdio.h>
#include <string.h>
void swap(char &a,char &b){
	char temp;
	temp=a;
	a=b;
	b=temp;
}
void permutation(char *str, int start){
	if(start==strlen(str)){
	 printf("%s\n",str);
	 return;
	}
	
	for(int i=start;i<strlen(str);i++){
		swap(str[start],str[i]);
		permutation(str,start+1);
		swap(str[i],str[start]);
	}
}

int main(){
	char str[]="abcd";
	permutation(str,0);
}
