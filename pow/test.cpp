#include <iostream>
#include "KISA_SHA256.h"

struct blockheader {
	BYTE previousBlockHash[257];    // 전 블록의 거래내역을 해쉬 한 값
};

struct block {
	int blockSize;    // 거래내역 크기
	blockheader header;    // 위에 있는 블록헤더 (이전 블록의 해쉬 값 저장)
	int transactionCount ;    // 몇 번째 거래인지
	BYTE transaction[100];    // 거래내역
	BYTE BlockHash[257];
	long long nonce;
	int flag;
};

void ulong2byte(BYTE* nonce, ULONG a) {
	int i = 0;

	for (i = 0; i < 8; ++i)
	{
		nonce[i] = (unsigned char)((((unsigned long long) a) >> (56 - (8 * i))) & 0xFFu);
	}
}

int main()
{
	block Block[100];
	int select = 0;
	int total = 0;
	printf("=============================================================================================================");
	printf("\n					Proof Of Work(Pow) Simulator  \n");
	printf("=============================================================================================================");

	
	int num = 0;
	while (1) {
		printf("\n\n***1.[Mining]Input Transaction(Data)   2.Block Data Check   3.Block Data Tampering   4.Print All Blocks   0. Quit***\n");
		printf("Enter a number : ");
		scanf("%d", &select);
		if (select == 0) {
			return 0;
		}
		else if (select == 1) {
			if (total == 0) {
				printf("1st Block_Input Transaction(Data) : ");
				scanf("%s", Block[0].transaction);
				Block[0].transactionCount++;
				Block[0].blockSize = strlen((char*)Block[0].transaction);
				Block[0].nonce = 0;
				Block[0].flag = 0;
				BYTE tmp[257] = { 0, };

				BYTE nonce[8] = { 0, };
				while (Block[0].BlockHash[0] != 0) {
					Block[0].nonce++;
					ulong2byte(nonce, Block[0].nonce);					
					memcpy(tmp, Block[total].transaction, sizeof(BYTE) * Block[total].blockSize);
					memcpy(tmp, nonce, sizeof(BYTE) * 8);
					SHA256_Encrpyt(tmp, sizeof(BYTE) * 257, Block[0].BlockHash);
					printf("\nfinding nonce..: %llu\n", Block[0l].nonce);
					printf("\nHash Value :");
					for (int j = 0; j < 32; j++) {
						printf("%02X", Block[total].BlockHash[j]);
					};
				}
				total++;
			}
			else {
				printf("%dth Block_Input Transaction(Data) : ", total + 1);
				scanf("%s", Block[total].transaction);
				Block[total].transactionCount = Block[total - 1].transactionCount + 1;
				Block[total].blockSize = strlen((char*)Block[total].transaction);
				memcpy(Block[total].header.previousBlockHash, Block[total - 1].BlockHash, sizeof(BYTE) * 257);
				Block[total].nonce = 0;
				Block[total].flag = 0;
				//1. 이전 해쉬 값 + 데이터 + nonce
				BYTE tmp[257] = { 0, };
				memcpy(tmp, Block[total].header.previousBlockHash, sizeof(BYTE) * 257);
				//2. HASH(이전 해쉬 값 + 데이터+nonce)
				BYTE nonce[8] = { 0, };
				while (Block[total].BlockHash[0] != 0 ) {
					Block[total].nonce++;
					ulong2byte(nonce, Block[total].nonce);
					memcpy(tmp, Block[total].transaction, sizeof(BYTE) * Block[total].blockSize);
					memcpy(tmp, nonce, sizeof(BYTE) * 8);
					SHA256_Encrpyt(tmp, sizeof(BYTE) * 257, Block[total].BlockHash);
					printf("\nfinding nonce..: %llu", Block[total].nonce);
					printf("\nHash Value :");
					for (int j = 0; j < 32; j++) {
						printf("%02X", Block[total].BlockHash[j]);
					};
				}
				total++;
			}
			printf("\n\nCurrent Block Hash Value :");
			for (int j = 0; j < 32; j++) {
				printf("%02X", Block[total - 1].BlockHash[j]);
			};
			printf("\nCurrent Block nonce : %llu", Block[total - 1].nonce);

		}
		else if (select == 2) {
			int i;
			
			printf("Block number(1~%d): ",total-1);  // 반드시 갯수가 2개 이상일때부터 가능함.
			scanf("%d", &num);
			if ( num > total-1 )  continue;
			BYTE EncryptCheck[257];
			BYTE tmp[257] = { 0, };
			if (num == 1) {
				BYTE nonce[8] = { 0, };
				ulong2byte(nonce, Block[num - 1].nonce);
				memcpy(tmp, Block[num - 1].transaction, sizeof(BYTE) * Block[num - 1].blockSize);
				memcpy(tmp, nonce, sizeof(BYTE) * 8);
				SHA256_Encrpyt(tmp, sizeof(BYTE) * 257, EncryptCheck);
			}
			else {
				BYTE nonce[8] = { 0, };
				ulong2byte(nonce, Block[num - 1].nonce);
				memcpy(tmp, Block[num - 1].header.previousBlockHash, sizeof(BYTE) * 257);
				memcpy(tmp, Block[num - 1].transaction, sizeof(BYTE) * Block[num - 1].blockSize);
				memcpy(tmp, nonce, sizeof(BYTE) * 8);
				SHA256_Encrpyt(tmp, sizeof(BYTE) * 257, EncryptCheck);
			}
			for (i = 0; i <= 256; i++) {
				if (Block[num].header.previousBlockHash[i] != EncryptCheck[i]) {
					break;
				}
			}
			if (i != 257) {
				printf("\nERROR :Tampered Data; ");
				printf("The transaction record has been tampered with.\n");
			}
			else {
				printf("\n=============================================================================================================");
				printf("\nBlock number: %d ", num);
				printf("\nBlock Transaction(Data) : %s ", Block[num-1].transaction);
				printf("\nBlock Transaction Size : %d ", Block[num-1].blockSize);
				printf("\nPrevious Block Hash Value : ");
				if (num == 1) printf(" ");
				else {
					for (int j = 0; j < 32; j++) {
						printf("%02X", Block[num - 1].header.previousBlockHash[j]);
					};
				}
				printf("\nCurrent Block Hash Value : ");
				for (int j = 0; j < 32; j++) {
					printf("%02X", Block[num-1].BlockHash[j]);
				};
				printf("\nCurrent Block nonce : % llu", Block[num - 1].nonce);
				printf("\n=============================================================================================================\n");
			}
		}
		else if (select == 3) {
			printf("Block number(1~%d) : ",total);
			scanf("%d", &num);
			if (num > total) continue;
			printf("Tamper Data : ");
			scanf("%s", Block[num - 1].transaction);
			Block[num - 1].blockSize = strlen((char*)Block[num - 1].transaction);
			printf("\nTampering is completed.\n");
			Block[num - 1].flag = 1;
		}
		else if (select == 4) {
			int i;
			for (i = 0; i < total-1 && Block[i].flag == 0; i++){
				printf("\n=============================================================================================================");
				printf("\nBlock number: %d ", i + 1);
				printf("\nBlock Transaction(Data) : %s ",Block[i].transaction);
				printf("\nBlock Transaction Size : %d ", Block[i].blockSize);
				printf("\nPrevious Block Hash Value : "); 
				if (i == 0) printf(" ");
				else{
					for (int j = 0; j < 32; j++){
						printf("%02X", Block[i].header.previousBlockHash[j]);
					};
				}
				printf("\nCurrent Block Hash Value :");
				for (int j = 0; j < 32; j++){
					printf("%02X", Block[i].BlockHash[j]);
				};
				printf("\nCurrent Block nonce : % llu", Block[i].nonce);
				printf("\n=============================================================================================================");
			}
			while(i < total - 1) {
				printf("\n=============================================================================================================");
				printf("\nBlock number: %d ", i + 1);
				printf("\n거래 내용: %s ", Block[i].transaction);
				printf("\n거래 내용 크키 : %d ", Block[i].blockSize);
				printf("\nERROR :Tampered Data; ");
				printf("거래기록이 변조되었습니다\n");
				printf("\n=============================================================================================================");
				i++;
			}
		}
	}
	return 0;
}