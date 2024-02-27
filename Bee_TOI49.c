/*
TASK: BEE
LANG: C
AUTHOR: Tapat Toungsakul
CENTER: Home

#include <stdio.h>
int main()
{
    int i,j,k;
    scanf("%d %d %d",&i,&j,&k);

}*/
#include <stdio.h>

int main(void){
	short int years[24] = {0};
	int n = 0, answer = 0;
	do{
		scanf("%d", &answer);
		years[n++] = answer;
		
	} while (answer != -1);
	for(int i = 0; i < n - 1; i++){
		int year = years[i];
		int bees[3] = {1, 1, 0};
		while(year--){
			int worker_dead = bees[1];
			int soldier_dead = bees[2];
			bees[1]++;
			for(int j = 0; j < worker_dead; j++){
				bees[1]++;
				bees[2]++;
			}
			for(int j = 0; j < soldier_dead; j++){
				bees[1]++;
			}
			bees[1] -= worker_dead;
			bees[2] -= soldier_dead;
		}
		printf("%d %d\n", bees[1], bees[0] + bees[1] + bees[2]);
	}
	return 0;
}