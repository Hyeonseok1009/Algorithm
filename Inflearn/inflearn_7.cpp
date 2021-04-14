//Inflearn #7 version C-language
#include <stdio.h>

int main() {
	char v_str[101] = { 0, };
	scanf("%[^\n]s", v_str);

	char str[101] = { 0, };
	int count = 0;
	
	for (int i = 0; v_str[i] != '\0'; i++) {
		if (v_str[i] >= 'A' && v_str[i] <= 'Z') {
			str[count] = v_str[i]+32;
			count++;
		}
		else if (v_str[i] >= 'a' && v_str[i] <= 'z') {
			str[count] = v_str[i];
			count++;
		}
	}

	str[count] = '\0';
	printf("%s",str);
}

//모범답안: gets 함수에 관한 이해가 필요하다.
#include<stdio.h>
using namespace std;
int main(){
	//freopen("input.txt", "rt", stdin);
	char a[101], b[101];
	int i, p=0;
	gets(a);
	for(i=0; a[i]!='\0'; i++){
		if(a[i]!=' '){
			if(a[i]>=65 && a[i]<=90){
				b[p++]=a[i]+32;
			}
			else b[p++]=a[i];
		}
	}
	b[p]='\0';
	printf("%s\n", b);	
	return 0;
}
