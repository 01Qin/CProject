/* 	DIGITALE SIGNALVERARBEITUNG
	BEISPIEL 8b: DISKRETE FOURIER-REIHE EINES PERIODISCHEN
	VERSCHOBENEN ISOLIERTEN DELTA-PULSES (32-WERTE-ARRAY)
	DARST. BETRAG UND PHASE
		( DSP_08EJ.C )  */

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <snap.h>

void main()
{
	int GraphMode, GraphDriver;
	double X[32]; double CR[32]; double CI[32];
	double BETRAG[32]; double PHASE[32];
	int N, K, I_VZ_IM, I_VZ_RE;
	double PI, B, M1, M2, M3, H1;
	PI=3.141593;    /*-- Festlegung von PI  --*/
/*-- Nullsetzen der Felder und eintragen
			eines verschobenen Delta-Pulses--*/
	for (N=0;N<=31;N++) {
	    CR[N] = 0.0;
	    CI[N] = 0.0;
	    X[N] = 0.0;
	}
	X[1]= 1.0;
	for (K=0;K<=31;K++) {
	     for (N=0;N<=31;N++) {
		  CR[K] = CR[K]+(1.0/32.0)*X[N]*cos(2.0*PI*K*N/32.0);
		  CI[K] = CI[K]-(1.0/32.0)*X[N]*sin(2.0*PI*K*N/32.0);
	     }
	}
/*-- Manipulation von Im. und Re. zur Vermeid. einer Div. durch Null
     und Speichern der Lage von Re. und Im. der Koeffizienten
     durch Flags I_VZ_IM und I_VZ_RE      --*/
	for (K=0;K<=31;K++) {
	    I_VZ_IM = 0;
	    I_VZ_RE = 0;
	    if ((CI[K]) < 0.0) I_VZ_IM = 1; /* VZ-Flag auf 1 wenn CI neg.*/
	    if ((CR[K]) < 0.0) I_VZ_RE = 1; /* VZ-Flag auf 1 wenn CR neg.*/


	    if (fabs (CI[K]) < 0.001) CI[K] = 0.0;
	    if ((CR[K] < 0.00001)&&((CR[K] >= 0.0))) CR[K] = 0.00001;
	    if ((CR[K] > -0.00001)&&((CR[K]<= 0.0))) CR[K] = -0.00001;

		// betrag: magnitude
	    BETRAG[K] = sqrt(CR[K]*CR[K] + CI[K]*CI[K]);
	    PHASE[K] = atan(CI[K]/CR[K]);
	    if ((I_VZ_RE == 1)&&((I_VZ_IM == 1))) PHASE[K] = PHASE[K] - PI;
	    if ((I_VZ_RE == 1)&&((I_VZ_IM == 0))) PHASE[K] = PHASE[K] + PI;
	}
/*-- Normierung von X, BETRAG und PHASE auf +- 1 --*/
	M1 = 0.001;
	M2 = 0.001;
	M3 = 0.001;
	for (N=0;N<=31;N++) {
	    if (fabs (X[N]) > M1) M1 = fabs(X[N]);
	    if (fabs (BETRAG[N]) > M2) M2 = fabs(BETRAG[N]);
	    if (fabs (PHASE[N]) > M3) M3 = fabs(PHASE[N]);
	} 
	for (N=0;N<=31;N++) {
	    X[N] = X[N]/M1;
	    BETRAG[N] = BETRAG[N]/M2;
	    PHASE[N] = PHASE[N]/M3;
	}
/*-- Vorbereitung der graphischen  Ausgabe --*/
	GraphDriver=DETECT;
	initgraph(&GraphDriver,&GraphMode, "C:\\TC\\BGI");
	cleardevice();
/*-- Darstellung von X, BETRAG und PHASE auf dem Schirm  --*/
	for (N=0;N<=31;N++) {
	    line (5*N,50,5*N,(50-(int)floor(X[N]*25.0 + 0.5)));
	    line (5*N,120,5*N,(120-(int)floor(BETRAG[N]*30.0 + 0.5)));
	    line (5*N,160,5*N,(160-(int)floor(PHASE[N]*25.0 + 0.5)));
	}
	capture("C:\\TC\\Capture\\DSP_08J.jpg");
	getch(); /*-- mit <RETURN> geht es weiter --*/
	closegraph();
}