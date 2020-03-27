/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: HP PC
 *
 * Created on 26 de marzo de 2020, 07:47 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int max(int a, int b) { return (a > b)? a : b; } 

/*
 * 
 */
int main(int argc, char** argv) {
    int valores[] = {7,8,4}; 
    int pesos[] = {3,8,6}; 
    int  weight = 10; 
    int n = sizeof(valores)/sizeof(valores[0]); 
    
    int matriz_principal[n+1][weight+1],maximo; 
    for (int i = 0; i <= n; i++) 
   { 
        
       for (int w = 0; w <= weight; w++) 
       { 
           if (i==0 || w==0) 
                matriz_principal[i][w] = 0; 
           else {
               if (pesos[i-1] > w) 
                matriz_principal[i][w] = matriz_principal[i-1][w];   
                else{
                   maximo= max(valores[i-1] + matriz_principal[i-1][w-pesos[i-1]],  matriz_principal[i-1][w]);
                   if(maximo==matriz_principal[i-1][w]){
                      matriz_principal[i][w] = matriz_principal[i-1][w];
                   }
                   else{
                       matriz_principal[i][w] =valores[i-1] + matriz_principal[i-1][w-pesos[i-1]];
                   }
                       
                }
                
           }
       }
       for(int j=0; j<=weight; j++){
           cout<<matriz_principal[i][j]<<" ";
       }
       cout<<""<<endl;
   } 
    
    cout<<"El valor máximo es "<<matriz_principal[n][weight];
    return 0;
}

