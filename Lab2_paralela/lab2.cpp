#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void sort(int *data, int lo, int hi) 
{
  if(lo > hi) return;
  int l = lo;
  int h = hi;
  int p = data[(hi + lo)/2];

  while(l <= h){
    while((data[l] - p) < 0) l++;
    while((data[h] - p) > 0) h--;
    if(l<=h){
      int tmp = data[l];
      data[l] = data[h];
      data[h] = tmp;
      l++; h--;
    }
  }
  sort(data, lo, h);
  sort(data, l, hi);
}


int cp (const int * a, const int * b) 
{
   return ( *(int*)a - *(int*)b );
}

int main (int argc, char *argv[]){
  if (argc == 1)
    {
      printf("Usage: quickSort arrayLen #tasks\n");
      exit (1);
    }
  int N = atoi(argv[1]);
  int T = atoi(argv[2]);
  
   int randArray[N];
   for(int i=0;i<N;i++)
      randArray[i]=rand()%100;  

  sort(a, 0, N-1);


  ofstream myOutputfile ("dataS.txt");
  if (myOutputfile.is_open())
    {
        for(int count = 0; count < N; count ++){
            myOutputfile << a[count] << "," ;
        }
        myOutputfile.close();
    }
  return 0;
}
