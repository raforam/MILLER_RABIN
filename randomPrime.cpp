#include <iostream>
#include <bitset>
using namespace std;

template <typename ITGR>
ITGR moduloFunc(ITGR a, ITGR b) {
    ITGR q = a / b;
    ITGR r = a - (q * b);

    if (r < 0) {
        q--;
        r = a - (q * b);}
    return r;
}

template <typename ITGR>
ITGR expoMod(ITGR base, ITGR expo, ITGR mod)
{
    ITGR result = 1;      
    base = moduloFunc(base,mod);

    while (expo > 0){
        if (expo & 1){
            result = moduloFunc(result*base,mod);
        } 
        expo = expo>>1;
        base = moduloFunc(base*base,mod);
    }
    return result;
}

template <typename ITGR>
bool millerFunc(ITGR d, ITGR n){
    ITGR a = 2 + rand() % (n - 4);
    ITGR x = expoMod(a, d, n);
 
    if (x == 1  || x == n-1){
       return true;}

    while (d != n-1){
        x = (x * x) % n;
        d *= 2;
 
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
    return false;
}
 

template <typename ITGR>
bool primeCheck(ITGR n, ITGR k){
    if (n <= 1 || n == 4)  {return false;}
    if (n <= 3) {return true;}
 
    ITGR d = n - 1;
    while (d % 2 == 0){
        d /= 2;
    }
 
    for(ITGR i = 0; i < k; i++){
        if (!millerFunc(d, n)){
            return false;
        }
    }
    return true;
}

int main()
{
    unsigned __int64 s = 4;
    unsigned __int64 count = 100;


    cout<<"Primos de 3 cifras:"<<endl;
    while(count<=1000){
        if(primeCheck(count,s)){
            cout<<count<<" ";
        }
        count++;
    }
    cout<<"\n\n------------------------------------------\n"<<endl;

    cout<<"Primos de 4 cifras:"<<endl;
    while(count<=10000){
        if(primeCheck(count,s)){
            cout<<count<<" ";
        }
        count++;
    }
    cout<<"\n\n------------------------------------------\n"<<endl;

    cout<<"Primos de 5 cifras:"<<endl;
    while(count<=100000){
        if(primeCheck(count,s)){
            cout<<count<<" ";
        }
        count++;
    }
    cout<<endl;


    return 0;
}