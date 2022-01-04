#include <iostream>
#include <time.h>       
using namespace std;
#define P 0.9


int main(){
    int counter = 0;
    double rand_Num;
    int empty = 0;
    int droped = 0;

    srand(time(NULL));
    for(int i=0; i<1000000;i++){
        for(int j = 0; j < 4; j++){
            rand_Num = (double) rand()/(RAND_MAX+1);
            if(rand_Num < P/4){
                if(counter < 4)
                counter++;
                else {
                    droped++;
                }
            }
        }
        if(!counter){
            empty++;
        }
        else{
            counter--;
        }
    }
    cout<<1 - empty/1000000.0<<endl;
    cout<< 0.9 - droped/1000000.0<<endl;

    return 0;
}