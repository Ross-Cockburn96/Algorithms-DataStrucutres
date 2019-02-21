#include <time.h>
#include <stdio.h>

void code(){
	for(int i=0; i<10000; i++){
		printf(".");
	}
	printf("\n");
}

int main(int argc, char* argv[]){
	printf("Running program %s", argv[0]);
	int *times;
	if (argc == 1){
		int *times = (int*)malloc(sizeof(int)*5);
		printf("\n No extra command line argument passed other than program name");
	}
	if (argc >=2){
		printf("Looping %s number of times", argv[1]);
		int *times = (int*)malloc(sizeof(int)*(int)argv[1]);
	}
	clock_t t;
	size_t s = sizeof(times);
	printf("%zu bytes\n", s);
	double sum = 0;
	for (int i=0; i<sizeof(times)/4; i++){
		printf("running");
		printf("start: %d \n", (int) (t=clock()));
		code();
		printf("stop: %d \n", (int) (t=clock()-t));
		times[i] = (double) t/CLOCKS_PER_SEC;
		sum += (double) t/CLOCKS_PER_SEC;
		printf("Elapsed: %f seconds \n", (double) t / CLOCKS_PER_SEC);
	}
	printf("average runtime is %f", sum/(sizeof(times)/4));
	
	return 0;
}