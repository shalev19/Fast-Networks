#include <stdio.h>
#include <iostream>
#include <ostream>

using namespace std;
#include <time.h>  
float simRout(float ts, int N);
int main(){
    for(int z = 2; z<51; z++){
    cout<< simRout(1000000,z)<<endl;
    }

return 0;
}


float simRout(float ts, int N){
    srand (time(NULL));
    int input[N];
    int output[N];
    int counter = 0;


    for(int i = 0; i<N; i++){
        input[i] = -1;
        output[i] = -1;
    }

    for (int i = 0; i < ts; i++)
    {
        for(int j = 0; j<N; j++){
            if(input[j] == -1){
                input[j] = rand()%N;
            }      
        }

        for(int k = 0; k<N; k++){
            if(output[input[k]] == 0){
                output[input[k]] += 1;
                input[k] = -1;
            }  
        }
        
        for(int w = 0; w<N ; w++){
            if(output[w]){
                counter++;
                output[w] = 0;
            }
        }  
    }
    
    return counter/(ts*N);
}

