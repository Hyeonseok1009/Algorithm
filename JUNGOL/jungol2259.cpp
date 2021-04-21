#include<stdio.h>
// 6���� ��ǥ�� ��´�.
// ����������...
#define abs(a) ((a>0) ? a : -a)
struct coord{
	int x;
	int y;
};


int main() {
	freopen("Text.txt", "rt", stdin);
	int K;
	scanf("%d", &K);

	coord * joapyo = new coord[6];
	int dir, distance;
	joapyo[0].x = 0; joapyo[0].y = 0;

	int max_x= 0, max_y = 0, min_y= 0, min_x = 0;
	//x��ǥ , y��ǥ�� ��� �߰��� ���� ã��,
	// �� ���� �Ŀ� �鸰 ��ǥ�� x��ǥ�� �ٸ��� �� ���̸�, y��ǥ�� �ٸ��� �����̸� ���ϸ� �װ� ���ٻ簢���̴�.

	for (int i = 1; i <= 5; i++)
	{
		scanf("%d %d", &dir, &distance);
		switch (dir) {
		case 1: /*����*/
			joapyo[i].x = joapyo[i - 1].x + distance;
			joapyo[i].y = joapyo[i - 1].y;
			if (max_x < joapyo[i].x) max_x = joapyo[i].x;
			break;
		case 2: /*����*/
			joapyo[i].x = joapyo[i - 1].x - distance;
			joapyo[i].y = joapyo[i - 1].y;
			if (min_x > joapyo[i].x) min_x = joapyo[i].x;
			break;
		case 3: /*����*/
			joapyo[i].x = joapyo[i - 1].x;
			joapyo[i].y = joapyo[i - 1].y - distance;
			if (min_y > joapyo[i].y) min_y = joapyo[i].y;
			break;
		case 4: /*����*/
			joapyo[i].x = joapyo[i - 1].x;
			joapyo[i].y = joapyo[i - 1].y + distance;
			if (max_y < joapyo[i].y) max_y = joapyo[i].y;
			break;
		}
	}
	int middleindex = -1;

	/*for (int i = 0; i < 6; i++) {
	    printf("x : %d, y: %d \n", min_y, max_y);
	}*/

	for (int i = 0; i < 6; i++) {
		if ( (joapyo[i].x > min_x && joapyo[i].x < max_x) && (joapyo[i].y > min_y && joapyo[i].y < max_y) ) {
			middleindex = i;
			//printf("%d \n", i);
			break;
		}
	}
	int preidx, postidx;
	preidx = (middleindex + 5)%6;
	postidx = (middleindex + 1)%6;

	int totalsum = (max_x - min_x)*(max_y - min_y);
	//printf("x : %d, y: %d \n", min_y, max_y);
	int tmp_x, tmp_y,a,b;
	if (joapyo[preidx].x == joapyo[middleindex].x) {
		a = joapyo[postidx].x - joapyo[middleindex].x;
		tmp_x = abs(a);
		b= joapyo[preidx].y - joapyo[middleindex].y;
		tmp_y = abs(b);
	}
	else {
		a = joapyo[preidx].x - joapyo[middleindex].x;
		tmp_x = abs(a);
		b = joapyo[postidx].y - joapyo[middleindex].y;
		tmp_y = abs(b);
	}
	int minsum = tmp_x * tmp_y;

	printf("%d\n", (totalsum-minsum)*K);
	return 0;
}