//N.2948

#include <stdio.h>
#include <iostream>


char set1[100000][51] = { 0, };
char set2[100000][51] = { 0, };
int Bigprime(int n);
int my_strlen(const char *str);
int hashtablesize;
unsigned int hashfunction(char *str, unsigned int len);
int strcmp(const char*str1, const char*str2);
int main() {
	freopen("Text.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	int numOfset1, numOfset2;

	for (int tc = 1; tc <= TC; tc++) {
		scanf("%d %d", &numOfset1, &numOfset2);
		getchar();
		for (int i = 0; i < numOfset1; i++) {
			scanf("%s", set1[i]);
		}
		for (int i = 0; i < numOfset2; i++) {
			scanf("%s", set2[i]);
		}


		hashtablesize = Bigprime(numOfset1 + numOfset2 + 181);
		char** hashtable = new char*[hashtablesize];
		for (int i = 0; i < hashtablesize; i++) {
			hashtable[i] = 0;
		}

		// set1을 hashtable에 배치
		int len, hash_value;
		for (int i = 0; i < numOfset1; i++) {
			len =my_strlen(set1[i]);
			hash_value = hashfunction(set1[i], len);
			int flag = 1;
			while (flag) {
				if (hashtable[hash_value] != 0) {     // 충돌 발생
					hash_value = (hash_value + 1) % hashtablesize;
				}
				else {
					hashtable[hash_value] = set1[i];   // 충돌 안 발생.
					flag = 0;
				}
			}
		}
		// 이제 중복을 카운트 해보자.
		int count = 0;
		for (int i = 0; i < numOfset2; i++) {
			len = my_strlen(set2[i]);
			hash_value = hashfunction(set2[i], len);
			int flag = 1;
			int tmp = 0;

			while (flag) {
				if (hashtable[hash_value] != 0) {  // 충돌 발생
					if (strcmp(set2[i], hashtable[hash_value]) == 0) {
						count++;
						break;
					}
					hash_value = (hash_value + 1) % hashtablesize;

				}
				else {
					flag = 0;
				}
			}
		}


		printf("#%d %d\n",tc, count);

		//전역변수 초기화
		for (int i = 0; i < numOfset1; i++) {
			for (int j = 0; j < 51; j++) {
				set1[i][j] = 0;
			}
		}
		for (int i = 0; i < numOfset2; i++) {
			for (int j = 0; j < 51; j++) {
				set2[i][j] = 0;
			}
		}
	}
	return 0;
}


unsigned int hashfunction(char *str, unsigned int len) {
	unsigned int hash_value = 0;
	for (int i = 0; i < len; i++) {
		hash_value = hash_value + *(str + i);
	}
	return hash_value % hashtablesize;
}
int strcmp(const char* str1, const char* str2)
{
	int i = 0;
	// 한쪽 문자열이 끝날 때까지 비교 수행
	while (str1[i] != '\0' && str2[i] != '\0') {

		if (str1[i] != str2[i]) {
			return str1[i] - str2[i];
		}
		i++;
	}
	return str1[i] - str2[i];
}

int my_strlen(const char *str) {
	int leng = 0;
	while (*(str + leng) != '\0') {
		leng++;
	}
	return leng;
}

int Bigprime(int n) {
	int max = 0;

	for (int i = 2; i < n; i++) {
		int flag = 1;
		for (int j = 2; j < i; j++) {
			if (i%j == 0) {
				flag = 0;
			}
		}
		if (flag == 1) {
			max = i;
		}
	}
	return max;
}