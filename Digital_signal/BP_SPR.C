/* Sprungantwort Bandpass, Step response of a bandpass filter  */

#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<snap.h>

void main()
{
int N, GraphDriver, GraphMode;
double X[300], Y[300];

/* Feldelemente Null setzen, danach ab N=2 mit Einsen auffuellen, 
püt array elements to zero then fill up with ones starting at N=2 */

for (N=0;N<=299;N++) X[N]= 0.0; 
for (N=2;N<=299;N++) X[N]= 1.0;

Y[0]=0;
Y[1]=0;

for (N=2;N<=299;N++) Y[N] = 1.7119*Y[N-1] -0.81*Y[N-2] + X[N] -X[N-1];


/* Laenge Nullst.Vekt=0.9, groeste Verst. bei Signalperiodenlänge 20 ,bei Omega= 2*Pi/20 */
/* lenght of pole_vector =0.9, best gain ,at signal period length 20, at Omega= 2*Pi/20  */

GraphDriver= DETECT;
initgraph(&GraphDriver,&GraphMode, "C:\\TC\\BGI");
cleardevice();

/*   Skalierung und Rundung, scaling and rounding */
for(N=2;N<=299;N++) 
	{
	if(X[N] > 0.0) X[N]= X[N]*25.0 +0.5;
	if(X[N] < 0.0) X[N]= X[N]*25.0 -0.5;
	if(Y[N] > 0.0) Y[N]= Y[N]*25.0 +0.5;
	if(Y[N] < 0.0) Y[N]= Y[N]*25.0 -0.5;

	line(2*N,50,2*N,(50-(int)X[N]));
	line(2*N,150,2*N,(150-(int)Y[N]));
	}

getch();

capture("C:\\TC\\Capture\\BP_SPR.jpg");
closegraph();
}