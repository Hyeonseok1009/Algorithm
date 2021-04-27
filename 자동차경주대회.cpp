#include <stdio.h>
#define MAX 100

int max_distance;
int repair_num;
int distances[MAX + 2]; // 1 ~ 100 + 도착지점(1)
int repair_price[MAX + 1];  //1 ~100 


int total; // 답1
int visit_num; //답 2
int vists_idx[MAX+1]; // 답 3
void repair() {
	int remain = max_distance;
	int last_vistidx = 0;

	for (int i = 1; i <= repair_num + 1; i++) {
		if (remain - distances[i] <= 0) {
			int cheap_idx = last_vistidx + 1;
			for (int j = cheap_idx + 1; j < i; j++) {
				if (repair_price[j] < repair_price[cheap_idx]) cheap_idx = j;
			}
			total += repair_price[cheap_idx];
			vists_idx[visit_num++] = cheap_idx;
			last_vistidx = cheap_idx;
			remain = max_distance;
			for (int j = cheap_idx + 1; j <= i; j++) {
				remain -= distances[j];
			}
			//printf("i:%d remain: %d ", i, remain);
		}
		else {
			remain -= distances[i];
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &max_distance);
	scanf("%d", &repair_num);

	for (int i = 1; i <= repair_num + 1;i++) {
		scanf("%d", &distances[i]);
	}
	for (int i = 1; i <= repair_num; i++) {
		scanf("%d", &repair_price[i]);
	}
	repair();
	printf("%d\n", total);
	if (visit_num != 0) {
		for (int i = 0; i < visit_num; i++) {
			printf("%d ", vists_idx[i]);
		}
	}
}



