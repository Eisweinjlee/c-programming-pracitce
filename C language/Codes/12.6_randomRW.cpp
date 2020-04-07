#include<stdio.h>
#include<stdlib.h>

#define N 4

struct Stu
{
	char name[50];
	int num;
	float score;
} stu[N], sb;

int main(void)
{
	FILE *fp;
	int i;
	
	//write
	if( (fp = fopen("score.txt","wb")) == NULL)
	{
		printf("failed to open file 1.\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Input the score (name, number, score):");
	for(i=0;i<N;i++)
	{
		scanf("%s %d %f", stu[i].name, &stu[i].num, &stu[i].score);
	}
	fwrite(stu, sizeof(struct Stu), N, fp);
	fclose(fp);
	
	//read
	if( (fp = fopen("score.txt","rb")) == NULL)
	{
		printf("failed to open file 2.\n");
		exit(EXIT_FAILURE);
	}
	fseek(fp,sizeof(struct Stu), SEEK_SET); // move to 2nd student
	fread(&sb, sizeof(struct Stu), 1, fp);
	
	printf("%s(%d)'s score is: %.2f\n", sb.name, sb.num, sb.score);
	
	fclose(fp);
	return 0;
}
