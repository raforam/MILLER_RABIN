#include <iostream>
#include <bitset>
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <vector>
using namespace std;
typedef unsigned __int64 NUM64B;
typedef bitset<64> BIN64;

NUM64B potencia(NUM64B x, NUM64B y){
    NUM64B rpta = 1; 
    while (y > 0) {
        if (y & 1){rpta = rpta * x;}
        y = y >> 1;
        x = x * x;
    }
    return rpta;
}

NUM64B moduloFunc(NUM64B a, NUM64B b) {
    NUM64B q = a / b;
    NUM64B r = a - (q * b);

    if (r < 0) {
        q--;
        r = a - (q * b);
    }
    return r;
}

NUM64B expoMod(NUM64B base, NUM64B expo, NUM64B mod)
{
    NUM64B result = 1;
    base = moduloFunc(base, mod);

    while (expo > 0) {
        if (expo & 1) {
            result = moduloFunc(result * base, mod);
        }
        expo = expo >> 1;
        base = moduloFunc(base * base, mod);
    }
    return result;
}

bool millerFunc(NUM64B d, NUM64B n) {
    NUM64B a = 2 + rand() % (n - 4);
    NUM64B x = expoMod(a, d, n);

    if (x == 1 || x == n - 1) {
        return true;
    }

    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;

        if (x == 1) { return false; }
        if (x == n - 1) { return true; }
    }
    return false;
}

bool primeCheck(NUM64B n, NUM64B k) {
    if (n <= 1 || n == 4) { return false; }
    if (n <= 3) { return true; }

    NUM64B d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }

    for (NUM64B i = 0; i < k; i++) {
        if (!millerFunc(d, n)) {
            return false;
        }
    }
    return true;
}


NUM64B randomize(bitset<64> numba, int size) {
    NUM64B number = 0;
    for (int i = 0; i < size; i++) {
        numba[i] = (rand() % 2);
    }
    //cout<<"Binary Number: "<<numba<<endl;
    if(numba[0] == false){numba[0] = true;}
    for (int i = 0; i < size; i++) {
        if (numba[i] == 1) {
            number += (potencia(2, i));
        }
    }
    //cout<<"Binary Number: "<<numba<<endl;
    //cout<<"Dcimal Number: "<<number<<endl;
    return number;
}


void turnToPrime(bitset<64> base, NUM64B* number, int size){
    *number = randomize(base,size);
    //cout<<*number<<endl;
    while( primeCheck(*number,14) == false ){
        //cout<<*number<<endl;
        //*number += 2;
        *number = randomize(base,size);
        if(primeCheck(*number,14) == true){/*cout<<"PRIME"*/;break;}
    }
    return;
}


int main() {
    srand((unsigned)time(NULL));
    NUM64B s = 4;

    bitset<64> binary16, binary32, binary64;

    NUM64B num16_1, num16_2, num16_3, num16_4, num16_5, num16_6, num16_7, num16_8, num16_9, num16_10;
    vector<NUM64B> Array16{num16_1, num16_2, num16_3, num16_4, num16_5, num16_6, num16_7, num16_8, num16_9, num16_10};

    NUM64B num32_1, num32_2, num32_3, num32_4, num32_5, num32_6, num32_7, num32_8, num32_9, num32_10;
    vector<NUM64B> Array32{num32_1, num32_2, num32_3, num32_4, num32_5, num32_6, num32_7, num32_8, num32_9, num32_10};

    NUM64B num64_1, num64_2, num64_3, num64_4, num64_5, num64_6, num64_7, num64_8, num64_9, num64_10;
    vector<NUM64B> Array64{num64_1, num64_2, num64_3, num64_4, num64_5, num64_6, num64_7, num64_8, num64_9, num64_10};

    cout<<"10 prime numbers (16bits):"<<endl;
    for(int i=0; i<10; i++){
        turnToPrime(binary16, &(Array16[i]), 16);
        cout<<"- "<<Array16[i]<<endl;
    }cout<<endl;
    
    cout<<"10 prime numbers (32bits):"<<endl;
    for(int i=0; i<10; i++){
        turnToPrime(binary32, &(Array32[i]), 32);
        cout<<"- "<<Array32[i]<<endl;
    }cout<<endl;

    cout<<"10 prime numbers (64bits):"<<endl;
    for(int i=0; i<10; i++){
        turnToPrime(binary64, &(Array64[i]), 64);
        cout<<"- "<<Array64[i]<<endl;
    }cout<<"\n"<<endl;
    
    return 0;
}