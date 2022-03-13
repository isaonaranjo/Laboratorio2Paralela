//Maria Isabel Ortiz Naranjo
// 18176
// Corto 5 y Lab 2 

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
//comparar
int compare (const int * a, const int * b) //what is it returning?
{
   return ( *(int*)a - *(int*)b ); //What is a and b?
}
void par_qsort(int *data, int lo, int hi) //}, int (*compare)(const int *, const int*))
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
  //recursive call
  par_qsort(data, lo, h);
  par_qsort(data, l, hi);
}

int main (int argc, char *argv[]){
  if (argc == 1)
    {
      printf("Usage: quickSort arrayLen #tasks\n");
      exit (1);
    }
  int N = atoi(argv[1]);
  int T = atoi(argv[2]);
  
  int random[N];
  for(int i=0;i<N;i++)
     random[i]=rand()%100;  

  ofstream file ("file.txt");
    if (file.is_open())
    {
        for(int count = 0; count < N; count ++){
            file << random[count] << "," ;
        }
        file.close();
    }
    else cout << "Unable to open file";

    // Inspirado por : https://stackoverflow.com/questions/5199557/reading-a-string-and-integers

    std::ifstream inFile("file.txt");
    std::vector<int> num;
    std::string number_as_string;
    while (std::getline(inFile, number_as_string, ','))
    {
        num.push_back(std::stoi(number_as_string));
    }
    std::cout << "n : " << num.size() << "\n";
    int n = num.size();
    int* D = &num[0];
  par_qsort(D, 0, N-1);

  printf("Primeros Elementos: %d, %d, %d\n", D[0], D[1], D[2]);
  printf("Medios Elementos: %d, %d, %d\n", D[N/4], D[N/4 +1], D[N/4 +2]);
  printf("Ultimos Elementos: %d, %d, %d\n", D[N-3], D[N-2], D[N-1]);

  ofstream Outputfile ("dataS.txt");
  if (Outputfile.is_open())
    {
        for(int cont = 0; cont < N; cont ++){
            Outputfile << D[cont] << "," ;
        }
        Outputfile.close();
    }
  return 0;
}
