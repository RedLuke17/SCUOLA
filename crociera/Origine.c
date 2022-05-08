#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i;
int j;

char nome[4][10][100];

char cognome[4][10][100];

int giorno[4][10];

int mese[4][10];

int anno[4][10];

int cabine[4];	//il numero di cabine occupate
				//[0] cabine da 1;
				//[1] cabine da 2;
				//[2] cabine da 3;
				//[3] cabine da 4;

int famiglia; //è il numero che definisce da quanto è formata la famiglia

int famiglie[4]; //è il numero che acquisisce da quanto è formata la famiglia per ogni rispettiva posizione

int totfamiglie[4]; //è il numero che somma alla variabile famiglia per non far sovrascrivere i valori precedenti a quelli successivi per ogni posizione

float soldispesi[4][40];

float totsoldispesi;

void registrazione1();

void registrazione2();

void registrazione3();

void registrazione4();

//1 luca rossi 10 10 2010
//2 pollo lollo 1 1 2001 billone supremo 2 2 2002
//3 vito ferro 3 3 2003 dicco rosso 4 4 2004 sosso vivvo 5 5 2005
//4 giglo rossi 6 6 2006 giggo rosa 7 7 2007 lucia strana 8 8 2008 bibbo kokko 9 9 2009

int main()
{
	srand(time(NULL));

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 4; j++)
		{
			nome[j][i][100] = "";
			cognome[j][i][100] = "";
			giorno[j][i] = 0;
			mese[j][i] = 0;
			anno[j][i] = 0;
			soldispesi[j][i] = 0.0;
		}
	}

	for (j = 0; j < 10; j++)
	{
		printf("\nin quanti siete a partecipare alla crociera?");
		scanf("%d", &famiglia);
		
		switch (famiglia)
		{
			default:
				printf("\nil numero inserito e' troppo grande, la nostra crociera ospita un massimo di 4 persone, riprova a inserire il numero corretto:\n");
				j--;
			break;
					
				case 4:
					if (cabine[3] < 3)
					{
						cabine[3]++;
						famiglie[3] = famiglia;
						registrazione4();
						break;
					}
					else
					{
						j--;
						printf("ci spiace ma le cabine da 4 sono tutte occupate");
						break;
					}
			
					case 3:
						if (cabine[2] < 3)
						{
							cabine[2]++;
							famiglie[2] = famiglia;
							registrazione3();
							break;
						}
						else
						{
							j--;
							printf("ci spiace ma le cabine da 3 sono tutte occupate");
							break;
						}
				
						case 2:
							if (cabine[1] < 2)
							{
								cabine[1]++;
								famiglie[1] = famiglia;
								registrazione2();
								break;
							}
							else
							{
								j--;
								printf("ci spiace ma le cabine da 2 sono tutte occupate");
								break;
							}

							case 1:
								if (cabine[0] < 2) {
									cabine[0]++;
									famiglie[0] = famiglia;
									registrazione1();
									break;
								}
								else
								{
									j--;
									printf("ci spiace ma le cabine da 1 sono tutte occupate");
									break;
								}
		}
	}

//stampa persone nelle cabine da 1
	for (i = 0; i < cabine[0]; i++)
	{
		if (i == 0)
		{
			printf("\nnelle cabine da 1 ci sono:\n");
		}
			soldispesi[0][i] = ((double)rand() / RAND_MAX) * 700;
			printf("persona numero %d ha speso %.2f:\t", i + 1, soldispesi[0][i]);
			printf("%s %s\t%d %d %d\n", nome[0][i], cognome[0][i], giorno[0][i], mese[0][i], anno[0][i]);
	}

//stampa persone nelle cabine da 2
//moltiplico il numero delle cabine occupate per la grandezza delle cabine stesse, quindi se la cabina è da due ed è occupata solo una cabina,per stampare due persone moltiplica 1*2
		for (i = 0; i < cabine[1] * 2; i++)
		{
			soldispesi[1][i] = ((double)rand() / RAND_MAX) * 700;
				
				if (i == 0)
				{
					printf("nelle cabine da 2 ci sono:\n");
				}
					
					printf("persona numero %d ha speso %.2f:\t", i + 1, soldispesi[1][i]);
					printf("%s %s\t%d %d %d\n", nome[1][i], cognome[1][i], giorno[1][i], mese[1][i], anno[1][i]);

						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9 || i == 11)
						{
							totsoldispesi = soldispesi[1][i - 1] + soldispesi[1][i];
							printf("cabina numero %d della famiglia %s ha speso un totale di %.2f\n\n", i - 1, cognome[1][i - 1], totsoldispesi);
						}
		}

//stampa persone nelle cabine da 3
			for (i = 0; i < cabine[2] * 3; i++)
			{
				soldispesi[2][i] = ((double)rand() / RAND_MAX) * 900;
		
					if (i == 0)
					{
						printf("nelle cabine da 3 ci sono:\n");
					}
				
						printf("persona numero %d ha speso %.2f:\t", i + 1, soldispesi[2][i]);
						printf("%s %s\t%d %d %d\n", nome[2][i], cognome[2][i], giorno[2][i], mese[2][i], anno[2][i]);
		
							if (i == 2 || i == 5 || i == 8 || i == 11 || i == 14)
							{
								totsoldispesi = soldispesi[2][i - 2] + soldispesi[2][i - 1] + soldispesi[2][i];
								printf("cabina numero %d della famiglia %s ha speso un totale di %.2f\n\n", i - 2, cognome[2][i - 2], totsoldispesi);
							}
			}

//stampa persone nelle cabine da 4
				for (i = 0; i < cabine[3] * 4 ; i++)
				{
					soldispesi[3][i] = ((double)rand() / RAND_MAX) * 900;
		
						if (i == 0)
						{
							printf("nelle cabine da 4 ci sono:\n");
						}
		
							printf("persona numero %d ha speso %.2f:\t", i + 1, soldispesi[3][i]);
							printf("%s %s\t%d %d %d\n", nome[3][i], cognome[3][i], giorno[3][i], mese[3][i], anno[3][i]);
					
								if (i == 3 || i == 7 || i == 11 || i == 15 || i == 19)
								{
									totsoldispesi = soldispesi[3][i - 3] + soldispesi[3][i - 2] + soldispesi[3][i - 1] + soldispesi[3][i];
									printf("cabina numero %d della famiglia %s ha speso un totale di %.2f\n\n", i - 3, cognome[3][i - 3], totsoldispesi);
								}
				}
}

void registrazione1() {
	for (i = totfamiglie[0]; i < famiglie[0] + totfamiglie[0]; i++)
	{
		printf("\ninserisci nome:\t");
		scanf("%s", nome[0][i]);

			printf("\ninserisci cognome:\t");
			scanf("%s", cognome[0][i]);

				printf("\ninserisci giorno di nascita:\t");
				scanf("%d", &giorno[0][i]);
				while (giorno[0][i] < 0 || giorno[0][i] > 32)
				{
					printf("inserisci un giorno di nascita reale:\t");
					scanf("%d", &giorno[0][i]);
				}

					printf("\ninserisci mese di nascita:\t");
					scanf("%d", &mese[0][i]);
					while (mese[0][i] < 0 || mese[0][i] > 12)
					{
						printf("inserisci un  mese di nascita reale:\t");
						scanf("%d", &mese[0][i]);
					}

						printf("\ninserisci anno di nascita:\t");
						scanf("%d", &anno[0][i]);
						while (anno[0][i] < 1960 || anno[0][i] > 2023)
						{
							printf("inserisci un anno di nascita reale:\t");
							scanf("%d", &anno[0][i]);
						}
	}
	totfamiglie[0] += famiglie[0];
}

void registrazione2() {
	for (i = totfamiglie[1]; i < famiglie[1] + totfamiglie[1]; i++)
	{
		printf("\ninserisci nome:\t");
		scanf("%s", nome[1][i]);

		printf("\ninserisci cognome:\t");
		scanf("%s", cognome[1][i]);

		printf("\ninserisci giorno di nascita:\t");
		scanf("%d", &giorno[1][i]);

		while (giorno[1][i] < 0 || giorno[1][i] > 32) {
			printf("inserisci un giorno di nascita reale:\t");
			scanf("%d", &giorno[1][i]);
		}

		printf("\ninserisci mese di nascita:\t");
		scanf("%d", &mese[1][i]);

		while (mese[1][i] < 0 || mese[1][i] > 12) {
			printf("inserisci un  mese di nascita reale:\t");
			scanf("%d", &mese[1][i]);
		}

		printf("\ninserisci anno di nascita:\t");
		scanf("%d", &anno[1][i]);

		while (anno[1][i] < 1960 || anno[1][i] > 2023) {
			printf("inserisci un anno di nascita reale:\t");
			scanf("%d", &anno[1][i]);
		}
	}
	totfamiglie[1] += famiglie[1];
}

void registrazione3() {
	for (i = totfamiglie[2]; i < famiglie[2] + totfamiglie[2]; i++)
	{
		printf("\ninserisci nome:\t");
		scanf("%s", nome[2][i]);

		printf("\ninserisci cognome:\t");
		scanf("%s", cognome[2][i]);

		printf("\ninserisci giorno di nascita:\t");
		scanf("%d", &giorno[2][i]);

		while (giorno[2][i] < 0 || giorno[2][i] > 32) {
			printf("inserisci un giorno di nascita reale:\t");
			scanf("%d", &giorno[2][i]);
		}

		printf("\ninserisci mese di nascita:\t");
		scanf("%d", &mese[2][i]);

		while (mese[2][i] < 0 || mese[2][i] > 12) {
			printf("inserisci un  mese di nascita reale:\t");
			scanf("%d", &mese[2][i]);
		}

		printf("\ninserisci anno di nascita:\t");
		scanf("%d", &anno[2][i]);

		while (anno[2][i] < 1960 || anno[2][i] > 2023) {
			printf("inserisci un anno di nascita reale:\t");
			scanf("%d", &anno[2][i]);
		}
	}
	totfamiglie[2] += famiglie[2];
}

void registrazione4() {
	for (i = totfamiglie[3]; i < famiglie[3] + totfamiglie[3]; i++)
	{
		printf("\ninserisci nome:\t");
		scanf("%s", nome[3][i]);

		printf("\ninserisci cognome:\t");
		scanf("%s", cognome[3][i]);

		printf("\ninserisci giorno di nascita:\t");
		scanf("%d", &giorno[3][i]);

		while (giorno[3][i] < 0 || giorno[3][i] > 32) {
			printf("inserisci un giorno di nascita reale:\t");
			scanf("%d", &giorno[3][i]);
		}

		printf("\ninserisci mese di nascita:\t");
		scanf("%d", &mese[3][i]);

		while (mese[3][i] < 0 || mese[3][i] > 12) {
			printf("inserisci un  mese di nascita reale:\t");
			scanf("%d", &mese[3][i]);
		}

		printf("\ninserisci anno di nascita:\t");
		scanf("%d", &anno[3][i]);

		while (anno[3][i] < 1960 || anno[3][i] > 2023) {
			printf("inserisci un anno di nascita reale:\t");
			scanf("%d", &anno[3][i]);
		}
	}
	totfamiglie[3] += famiglie[3];
}