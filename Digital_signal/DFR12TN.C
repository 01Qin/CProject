/* DFR einer Wertefolge mit einer Periodendauer von 12 Werten */
#include<stdio.h>
#include<conio.h>
#include<math.h>
main()
{    double X[12]; double CR[12];double CI[12];double PI;
     int N, K;

     PI = 3.141593;

/*--Nullsetzen der Feldelemente--*/
        for (N=0;N<=11;N++)
		{
            	X[N]= 0.0;
            	CR[N]=0.0;
            	CI[N]=0.0;
      		}


/*Generieren des periodischen Eingangssignals X[N]----*/
for (N=0;N<=11;N++){
    X[N]= 4.0 + cos(2.0*PI*N/12.0) + sin(2.0*PI*N/6.0);
    printf("%10.5f\n",X[N]);
    }

           for (K=0;K<=11;K++) {
              for (N=0;N<=11;N++) {
                 CR[K]= CR[K]+(1.0/12.0)*X[N]*cos(2.0*PI*K*N/12.0);
                 CI[K]= CI[K]-(1.0/12.0)*X[N]*sin(2.0*PI*K*N/12.0);
               }
	   }

         for (N=0;N<=11;N++) printf("%10.5f\t%10.5f\n",CR[N],CI[N]);

 }
