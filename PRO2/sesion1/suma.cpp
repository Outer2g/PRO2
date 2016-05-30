#include "utils.PRO2"

int  main ()
{
    int n= readint();
    int suma=0;
    while (n != 0){
      suma += n;
      n = readint();
    }
    cout << suma << endl;

}

