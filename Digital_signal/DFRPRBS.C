/* 	DIGITALE SIGNALVERARBEITUNG
	DISKRETE FOURIER-REIHE  (15-WERTE-ARRAY)
	DARST. BETRAG UND PHASE ( DFRPRBS.C )  */

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <snap.h>

void main()
{
	int GraphMode, GraphDriver;
	double X[15], CR[15], CI[15], BETRAG[15], PHASE[15];
	int N, K, I_VZ_IM, I_VZ_RE;
	double PI, SKAL1, SKAL2, SKAL3;
	PI=3.141593;    /*-- Festlegen auf PI  --*/
/*-- Nullsetzen der Felder und Eintragen des x(n)-Verlaufs  --*/
	for (N=0;N<=14;N++) {
	    CR[N] = 0.0;
	    CI[N] = 0.0;
	}

X[0]=1.0; X[1]=1.0; X[2]=1.0; X[3]=1.0; X[4]=-1.0;X[5]=1.0;X[6]=-1.0; 
X[7]=1.0; X[8]=1.0; X[9]=-1.0; X[10]=-1.0; X[11]=1.0;
X[12]=-1.0; X[13]=-1.0; X[14]=-1.0;


	for (K=0;K<=14;K++) {
	     for (N=0;N<=14;N++) {
		  CR[K] = CR[K]+(1.0/15.0)*X[N]*cos(2.0*PI*K*N/15.0);
		  CI[K] = CI[K]-(1.0/15.0)*X[N]*sin(2.0*PI*K*N/15.0);
	     }
	}
/*-- Manipulation von Im. und Re. zur Vermeid. einer Div. durch Null
     und Speichern der Lage von Re. und Im. der Koeffizienten
     durch Flags I_VZ_IM und I_VZ_RE      --*/
	for (K=0;K<=14;K++) {
	    if (fabs (CI[K]) < 0.001) CI[K] = 0.0;
	    if ((CR[K] < 0.00001)&&((CR[K] >= 0.0))) CR[K] = 0.00001;
	    if ((CR[K] > -0.00001)&&((CR[K]<= 0.0))) CR[K] = 0.00001;
	    I_VZ_IM = 0;
	    I_VZ_RE = 0;
	    if ((CI[K]) < 0.0) I_VZ_IM = 1; /* VZ-Flag auf 1 wenn CI neg.*/
	    if ((CR[K]) < 0.0) I_VZ_RE = 1; /* VZ-Flag auf 1 wenn CR neg.*/

	    BETRAG[K] = sqrt(CR[K]*CR[K] + CI[K]*CI[K]);
	    PHASE[K] = atan(CI[K]/CR[K]);
	    if ((I_VZ_RE == 1)&&((I_VZ_IM == 1))) PHASE[K] = PHASE[K] - PI;
	    if ((I_VZ_RE == 1)&&((I_VZ_IM == 0))) PHASE[K] = PHASE[K] + PI;
	}
/*-- Normierung von X, BETRAG und PHASE auf +- 1 --*/
	SKAL1 = 0.0;
	SKAL2 = 0.0;
	SKAL3 = 0.0;
	for (N=0;N<=14;N++) {
	    if (fabs (X[N]) > SKAL1) SKAL1 = fabs(X[N]);
	    if (fabs (BETRAG[N]) > SKAL2) SKAL2 = fabs(BETRAG[N]);
	    if (fabs (PHASE[N]) > SKAL3) SKAL3 = fabs(PHASE[N]);
	} 
	for (N=0;N<=14;N++) {
	    X[N] = X[N]/SKAL1;
	    BETRAG[N] = BETRAG[N]/SKAL2;
	    PHASE[N] = PHASE[N]/SKAL3;
	}
/*-- Vorbereitung der graphischen  Ausgabe --*/
	GraphDriver=DETECT;
	initgraph(&GraphDriver,&GraphMode, "C:\\TC\\BGI");
	cleardevice();
/*-- Darstellung von X, BETRAG und PHASE auf dem Schirm  --*/
	for (N=0;N<=14;N++) {
	    line (5*N,50,5*N,(50-(int)floor(X[N]*25.0 + 0.5)));
	    line (5*N,150,5*N,(150-(int)floor(BETRAG[N]*30.0 + 0.5)));
	    line (5*N,200,5*N,(200-(int)floor(PHASE[N]*25.0 + 0.5)));
	}
	capture("C:\\TC\\Capture\\DFRPRBS.jpg");
	getch(); /*-- mit <RETURN> geht es weiter --*/
	closegraph();
}