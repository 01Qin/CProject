/* Diskrete Fourier Reihe einer Wertefolge mit einer Periodendauer von 4 Werten, 
Discrete Fourier Series of a periodically repeating 4 samples signal */

#include<stdio.h>
#include<conio.h>
#include<math.h>
main()
{    double X[4], CR[4], CI[4], PI;
     int N, K;

     PI = 3.141593;

/*--Nullsetzen der Feldelemente-- Put all array elements to zero  ---*/
        for (N=0;N<=3;N++)
		{
            	X[N]= 0.0;
            	CR[N]=0.0;
            	CI[N]=0.0;
      		}


/*--- Generieren des Saegezahn-Eingangssignals X[N]
      Generate a saw-tooth-looking input signal X[N]  ---*/

X[0] =  0.0;
X[1] =  1.0;
X[2] =  2.0;
X[3] =  3.0;

for (N=0;N<=3;N++) printf("%10.5f\n",X[N]);

/*--- Komplexe Fourier Coefficienten berechnen ---*/
/*--- Calculate the complex Fourier Coefficients ---*/

           for (K=0;K<=3;K++) {
              for (N=0;N<=11;N++) {
                 CR[K]= CR[K]+(1.0/4.0)*X[N]*cos(2.0*PI*K*N/4.0);
                 CI[K]= CI[K]-(1.0/4.0)*X[N]*sin(2.0*PI*K*N/4.0);
               }
	   }

         for (N=0;N<=3;N++) printf("%10.5f\t%10.5f\n",CR[N],CI[N]);

 }
