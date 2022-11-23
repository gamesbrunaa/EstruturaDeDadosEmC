#include <stdio.h>
#include <stdlib.h>

int subtrai(char s1, char s2){
	return s1;
}

int main(){
	char string1;
	char string2;
	char result;
	printf("Digite a primeira string: \n");
	scanf("%s", &string1);
	printf("Digite a segunda string: \n");
	scanf("%s", &string2);
	result = subtrai(string1, string2);
	printf(result);
}
