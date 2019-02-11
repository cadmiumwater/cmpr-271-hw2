/* Leo Mahdessian lnm6735 CMPR-271
Alex Dacey xxx0000 CMPR-271 */

#include<stdio.h>
#include <string.h>
#include <stdlib.h>

int matSize = 100;

float mean(float dataSet[matSize][matSize], int set, int size);
float median(float dataSet[matSize][matSize], int set, int size);
float mode(float dataSet[matSize][matSize], int set, int size);
float range(float dataSet[matSize][matSize], int set, int size);
float stdDev(float dataSet[matSize][matSize], int set, int size);
float variance(float dataSet[matSize][matSize], int set, int size);

int main(int argc, char *argv[]) {
  char buffer[1024];
  char *record,*line;
  char *header[100];
  int i=0,j=0,k=0;
  float mat[matSize][matSize];

  printf("Welcome to the Statistics Calculator!\nCreated by Leo Mahdessian and Alex Dacey (c)2019\n\n");

  //tests for input args and returns error if not present
  if(argc < 2) {
    printf("Invalid Usage! Use: statcalc <inputFile.csv>\n");
    return -1;
  }

  //store the values of the input.csv into fstream
  FILE *fstream = fopen(argv[1],"r");

  //tests for file exsistance
  if(fstream == NULL) {
    //print error if file is not found
    printf("Error: file opening failed -- cannot access or find %s\n", argv[1]);
    return -1 ;
  }

  //loop that parses the CSV file, line by line, seperating ints by commas, and storing them to the 2d array mat
  while((line=fgets(buffer,sizeof(buffer),fstream))!=NULL) {
    record = strtok(line,",");
    //this loop parses each line by commas, and incrementally stores the values in line number i, row j
		while(record != NULL) {
       //tests to see if its reading the header line (line i=0)
	     if(i == 0) {
         header[j] = record;
       } else {
         //convert the char stored at the pointer record into an int, and store it into the correct position in the mat
         mat[i][j] = atoi(record);
       }
       j++;
			 record = strtok(NULL,",");
		}
    j = 0;
    i++;
  }

  int row = sizeof(mat) / sizeof(mat[0]);
  int column = sizeof(mat[0]) / row;

  int set = 0;

  printf("There are %d valid data sets. Enter a number 0 to %d to select which data set to calculate.\n",column,column);
  scanf("Set: %d\n", set);

  float meanComp = mean(mat, set, row);

  printf("Your average is: %f\n", meanComp);

}

float mean(float dataSet[matSize][matSize], int set, int size) {
  //calculate the mean of the dataSet
  float total = 0;

  for(int i = 0; i < size; i++) {
    total+=dataSet[1][i];
  }

  printf("%d\n", size);

  return total;
}

float median(float dataSet[matSize][matSize], int set, int size) {
  //calculate the median value of the dataSet
  return 0;
}

float mode(float dataSet[matSize][matSize], int set, int size) {
  //calculate the mode of the dataSet
  return 0;
}

float range(float dataSet[matSize][matSize], int set, int size) {
  //calculate the min/max of the dataSet
  return 0;
}

float stdDev(float dataSet[matSize][matSize], int set, int size) {
  //calculate the standard deviation of the dataSet
  return 0;
}

float variance(float dataSet[matSize][matSize], int set, int size) {
  //calculate the variance of the dataSet
  return 0;
}
