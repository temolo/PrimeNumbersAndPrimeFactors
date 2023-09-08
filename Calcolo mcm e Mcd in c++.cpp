// Calcolo mcm e Mcd in c++

// include goes on top
#include <chrono>
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main() {
  // variables
  int i;
  int n;
  int nn1;
  int n1;
  int nn2;
  int n2;
  int index;
  int mcm;
  int mcd;

  cout << "[?] . . . Inserire il primo numero: ";
  cin >> nn1;
  sleep(1);
  cout << "[?] . . . Inserire il secondo numero: ";
  cin >> nn2;

  cout << "test";
  printf(" \n ");

  n1 = nn1;
  n2 = nn2;

  if (n1 >= n2) {
    n = n1;
  } else {
    n = n2;
  }

  index = 2; // 4 perchè ci sono già 2 e 3
  int ok = 0;
  int prime_numbers[n];
  prime_numbers[0] = 2;
  int lenght = 1;

  // printf("checkpoint 0.5");
  printf("\n ");
  // trova i numeri primi fino al massimo numero dato
  while (index <= n) {
    ok = 1;
    for (i = 0; i < lenght; i++) {
      if (index % prime_numbers[i] == 0) {
        ok = 0;
        //break;
      }
    }
    if (ok == 1) {
      prime_numbers[lenght] = index;
      lenght = lenght + 1;
    }
    index = index + 1;
  }
  printf("Checkpoint1: numeri primi");
  printf("\n");
  for (i = 0; i < (lenght); i++) {
    cout << prime_numbers[i];
    cout << ",  ";
  }
  int bre;
  int potenze1[lenght];
  for (i=0;i<lenght;i++)
    {
      potenze1[i]=0;
    }
  // scompone in fattori primi il PRIMO numero
  bre = 0;
  int div1[n1]; // tantissimissimi numeri "sprecati", length è una buona
                // soluzione
  int len1 = 0;

  for (i = 0; i < lenght; i++) // controlla se è un numero primo
  {
    if (prime_numbers[i] == n1) {
      bre = 1;
    }
  }
  if (bre == 1) {
    div1[len1] = n1; // se lo è, è il suo unico divisore
    len1 = len1 + 1;
  }

  if (bre == 0) // se non lo è cerca divisori
  {
    for (i = 0; i < lenght; i++) {
      if (n1 % prime_numbers[i] == 0) {
        n1 = n1 / prime_numbers[i];
        div1[len1] = prime_numbers[i];
        potenze1[i]=potenze1[i]+1;
        len1 = len1 + 1;
        i = i - 1; // setolone per le potenze
      }
    }
  }
  // div1[len1] = prime_numbers[i]; non ho capito
  printf("\n");
  printf("Checkpoint 2: Divisori primi");
  printf("\n");
  for (i = 0; i < len1; i++) {
    cout << div1[i];
    cout << ",  ";
  }
  // scompone in fattori primi il SECONDO numero
  bre = 0;
  int div2[n2];
  int len2 = 0;
  int potenze2[lenght];
  for (i=0;i<lenght;i++)
    {
      potenze2[i]=0;
    }
  for (i = 0; i < lenght; i++) // controlla se è un numero primo
  {
    if (prime_numbers[i] == n2) {
      bre = 1;
    }
  }
  if (bre == 1) {
    div2[len2] = n2; // se lo è, è il suo univo divisore (len2=0)
    len2 = len2 + 1;
  }

  if (bre == 0) // se non lo è cerca divisori
  {
    for (i = 0; i < lenght; i++) {
      if (n2 % prime_numbers[i] == 0) {
        n2 = n2 / prime_numbers[i];
        div2[len2] = prime_numbers[i];
        potenze2[i]=potenze2[i]+1;
        len2 = len2 + 1;
        i = i - 1; // setolone per le potenze
      
      }
    }
  }
  // div1[len1] = prime_numbers[i]; non ho capito
  printf("\n");
  printf("Checkpoint 3: secondo Divisori primi");
  printf("\n");
  for (i = 0; i < len2; i++) {
    cout << div2[i];
    cout << ",  ";
  }
  printf("\n");
  printf("Checkpoint 4: primo potenze");
  printf("\n");
  for (i = 0; i < lenght; i++) {
    cout << potenze1[i];
    cout << ",  ";
  }
  printf("\n");
  printf("Checkpoint 5: secondo potenze");
  printf("\n");
  for (i = 0; i < lenght; i++) {
    cout << potenze2[i];
    cout << ",  ";
  }
int esponenti[lenght]; 
int j;
// confronto esponenti 
  for (i = 0; i < lenght; i++) {
    if (potenze1[i]>=potenze2[i])
    {
      esponenti[i]=potenze1[i];
    }
    else {
      esponenti[i]=potenze2[i];
    }
  }
int risultati_intermedi[lenght];
  for (i=0;i<lenght;i++)
    {
      risultati_intermedi[i]=1;
    }
for (i = 0; i < lenght; i++) {
  for (j=0;j<esponenti[i];j++){
    risultati_intermedi[i]=risultati_intermedi[i]*prime_numbers[i];
  }
}
printf("\n");
  printf("Checkpoint 6: risultati intermedi");
  printf("\n");
  for (i = 0; i < lenght; i++) {
    cout << risultati_intermedi[i];
    cout << ",  ";
  }
int risultato_finale=1;
for (i = 0; i < lenght; i++) {
  risultato_finale=risultato_finale*risultati_intermedi[i];
}
  printf("\n");
  printf("Checkpoint 7: risultato finale");
  printf("\n");
  cout << risultato_finale;
  
}
