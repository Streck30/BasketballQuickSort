#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
struct basketballData{
	char * playerName;
	float pointsPerGame;
	float reboundsPerGame;
	float assistsPerGame;
	float fieldGoalPer;
	float stealsPerGame;
	float blocksPerGame;
	float TOPerGame;
};
int partitionPoints(void * structPointer, int p, int r) {
	struct basketballData  * bballdata = structPointer;
	float x = bballdata[p].pointsPerGame;
	int i = p-1;
	int j = r + 1;
	while(1){
		j = j - 1;
		while(bballdata[j].pointsPerGame < x) {
			j = j - 1;
		}
		i = i + 1;
		while(bballdata[i].pointsPerGame > x) {
			i = i + 1;
		}
		if(i < j) {
			struct basketballData temp = bballdata[i];
			bballdata[i] = bballdata[j];
			bballdata[j] = temp;
		}
		else return j;
	}
}
int partitionRebounds(void * structPointer, int p, int r) {
	struct basketballData  * bballdata = structPointer;
	float x = bballdata[p].reboundsPerGame;
	int i = p-1;
	int j = r + 1;
	while(1){
		j = j - 1;
		while(bballdata[j].reboundsPerGame < x) {
			j = j - 1;
		}
		i = i + 1;
		while(bballdata[i].reboundsPerGame > x) {
			i = i + 1;
		}
		if(i < j) {
			struct basketballData temp = bballdata[i];
			bballdata[i] = bballdata[j];
			bballdata[j] = temp;
		}
		else return j;
	}
}
int partitionAssists(void * structPointer, int p, int r) {
	struct basketballData  * bballdata = structPointer;
	float x = bballdata[p].assistsPerGame;
	int i = p-1;
	int j = r + 1;
	while(1){
		j = j - 1;
		while(bballdata[j].assistsPerGame < x) {
			j = j - 1;
		}
		i = i + 1;
		while(bballdata[i].assistsPerGame > x) {
			i = i + 1;
		}
		if(i < j) {
			struct basketballData temp = bballdata[i];
			bballdata[i] = bballdata[j];
			bballdata[j] = temp;
		}
		else return j;
	}
}
int partitionFG(void * structPointer, int p, int r) {
	struct basketballData  * bballdata = structPointer;
	float x = bballdata[p].fieldGoalPer;
	int i = p-1;
	int j = r + 1;
	while(1){
		j = j - 1;
		while(bballdata[j].fieldGoalPer < x) {
			j = j - 1;
		}
		i = i + 1;
		while(bballdata[i].fieldGoalPer > x) {
			i = i + 1;
		}
		if(i < j) {
			struct basketballData temp = bballdata[i];
			bballdata[i] = bballdata[j];
			bballdata[j] = temp;
		}
		else return j;
	}
}
int partitionSteals(void * structPointer, int p, int r) {
	struct basketballData  * bballdata = structPointer;
	float x = bballdata[p].stealsPerGame;
	int i = p-1;
	int j = r + 1;
	while(1){
		j = j - 1;
		while(bballdata[j].stealsPerGame < x) {
			j = j - 1;
		}
		i = i + 1;
		while(bballdata[i].stealsPerGame> x) {
			i = i + 1;
		}
		if(i < j) {
			struct basketballData temp = bballdata[i];
			bballdata[i] = bballdata[j];
			bballdata[j] = temp;
		}
		else return j;
	}
}
int partitionBlocks(void * structPointer, int p, int r) {
	struct basketballData  * bballdata = structPointer;
	float x = bballdata[p].blocksPerGame;
	int i = p-1;
	int j = r + 1;
	while(1){
		j = j - 1;
		while(bballdata[j].blocksPerGame < x) {
			j = j - 1;
		}
		i = i + 1;
		while(bballdata[i].blocksPerGame > x) {
			i = i + 1;
		}
		if(i < j) {
			struct basketballData temp = bballdata[i];
			bballdata[i] = bballdata[j];
			bballdata[j] = temp;
		}
		else return j;
	}
}
int partitionTO(void * structPointer, int p, int r) {
	struct basketballData  * bballdata = structPointer;
	float x = bballdata[p].TOPerGame;
	int i = p-1;
	int j = r + 1;
	while(1){
		j = j - 1;
		while(bballdata[j].TOPerGame < x) {
			j = j - 1;
		}
		i = i + 1;
		while(bballdata[i].TOPerGame > x) {
			i = i + 1;
		}
		if(i < j) {
			struct basketballData temp = bballdata[i];
			bballdata[i] = bballdata[j];
			bballdata[j] = temp;
		}
		else return j;
	}
}


void Quicksort(void * Array, int p, int r, int toSortBy) {
	int q;
	if(p < r) {
		switch(toSortBy) {
			case 1:
				q = partitionPoints(Array, p, r);
				break;
			case 2:
				q = partitionRebounds(Array, p, r);
				break;
			case 3:
				q = partitionAssists(Array, p, r);
				break;
			case 4:
				q = partitionFG(Array, p, r);
				break;
			case 5:
				q = partitionSteals(Array, p, r);
				break;
			case 6:
				q = partitionBlocks(Array, p, r);
				break;
			case 7:
				q = partitionTO(Array, p, r);
				break;
		}
		Quicksort(Array, p, q, toSortBy);
		Quicksort(Array, q+1, r, toSortBy);
					
	}
}

int main(int argc, char ** argv) {
	if(argc != 4 && argc != 3 ) {
		printf("please enter the correct number of arguments, being file first, stat to be sorted by, and optional leader\n");
		return 1; 
	}
	struct basketballData basketballArray[30];
	char bufferHolder[1024*128];
	int leader = 0;
	if(argc == 4) {
		if(strcmp(argv[3], "leader") == 0)
			leader = 1;
	}
	int openError = open(argv[1], O_RDONLY);
	if( openError == -1 ) {
		printf("file open error\n");
		return 1;
	}
	int readError = read(openError, bufferHolder, sizeof(bufferHolder));
	if( readError == -1 ) {
		printf("file read error\n");
		return 1;
	}
	strtok( bufferHolder,"\t\n" );
	for( int i = 0; i < 30; i++ ) {
		basketballArray[i].playerName = strtok( NULL, "\t\n" );
		basketballArray[i].pointsPerGame = atof( strtok( NULL, "\t\n"));
		basketballArray[i].reboundsPerGame = atof( strtok( NULL, "\t\n"));
		basketballArray[i].assistsPerGame = atof( strtok( NULL, "\t\n"));
		basketballArray[i].fieldGoalPer = atof( strtok( NULL, "\t\n"));
		basketballArray[i].stealsPerGame = atof( strtok( NULL, "\t\n"));
		basketballArray[i].blocksPerGame = atof( strtok( NULL, "\t\n"));
		basketballArray[i].TOPerGame = atof( strtok( NULL, "\t\n"));
	}
	if(strcmp(argv[2], "points") == 0)
		Quicksort(basketballArray, 0, 29, 1);
	if(strcmp(argv[2], "rebounds") == 0)
		Quicksort(basketballArray, 0, 29, 2);
	if(strcmp(argv[2], "assists") == 0)
		Quicksort(basketballArray, 0, 29, 3);
	if(strcmp(argv[2], "fieldgoal") == 0)
		Quicksort(basketballArray, 0, 29, 4);
	if(strcmp(argv[2], "steals") == 0)
		Quicksort(basketballArray, 0, 29, 5);
	if(strcmp(argv[2], "blocks") == 0)
		Quicksort(basketballArray, 0, 29, 6);
	if(strcmp(argv[2], "TO") == 0)
		Quicksort(basketballArray, 0, 29, 7);
	if(leader == 1) {
		printf("%s leader: %s: ", argv[2], basketballArray[0].playerName);
			if(strcmp(argv[2], "points") == 0)
				printf("%.1f\n", basketballArray[0].pointsPerGame);
			if(strcmp(argv[2], "rebounds") == 0)
				printf("%.1f\n", basketballArray[0].reboundsPerGame);
			if(strcmp(argv[2], "assists") == 0)
				printf("%.1f\n", basketballArray[0].assistsPerGame);
			if(strcmp(argv[2], "fieldgoal") == 0)	
				printf("%.3f\n", basketballArray[0].fieldGoalPer);
			if(strcmp(argv[2], "steals") == 0)
				printf("%.1f\n", basketballArray[0].stealsPerGame);
			if(strcmp(argv[2], "blocks") == 0)
				printf("%.1f\n", basketballArray[0].blocksPerGame);
			if(strcmp(argv[2], "TO") == 0)
				printf("%.1f\n", basketballArray[0].TOPerGame);
	}else {
		printf("Player Name\t\tPoints\tRebound\tAssists\tFG per \tSteals\tBlocks\tTOs\n");
		for(int i = 0; i <30; i++) {
			printf("%s\t", basketballArray[i].playerName);
			if( strlen(basketballArray[i].playerName) < 16) 
				printf("\t");
			printf("%.1f\t", basketballArray[i].pointsPerGame);
			printf("%.1f\t", basketballArray[i].reboundsPerGame);
			printf("%.1f\t", basketballArray[i].assistsPerGame);
			printf("%.3f\t", basketballArray[i].fieldGoalPer);
			printf("%.1f\t", basketballArray[i].stealsPerGame);
			printf("%.1f\t", basketballArray[i].blocksPerGame);
			printf("%.1f\n", basketballArray[i].TOPerGame);
		}
	}

	return 0;
}
