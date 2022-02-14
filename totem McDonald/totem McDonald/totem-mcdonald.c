#include <stdio.h>
#include <stdlib.h>

int main()
{
	char alimenti[8][100] =
	{
	{"BigMac"},
	{"MySelection"},
	{"Gran Crispy McBacon"},
	{"McChicken"},
	{"Hamburger"},
	{"patatine"},
	{"Acqua"},
	{"Coca Cola"},
	};

	float prezzialimenti[8] =
	{
	4.50f,
	7.80f,
	5.40f,
	3.10f,
	1.0f,
	2.50f,
	1.0f,
	2.0f,
	};

	int scortealimenti[8];

	int coupon[6] =
	{
		2,
		10,
		3,
		5,
		1,
		7,
	};

	int i = 0;

	int scelta;

	int sceltaSN;

	int carrello[8];

	float prezzoTotale[100];

	for (i = 0; i < 100; i++)
	{
		prezzoTotale[i] = 0;
	}

	int cliente = 0;

	for (i = 0; i < 8; i++)
	{
		carrello[i] = 0;
	}

	printf("INSERISCI LE SCORTE DEI SEGUENTI ALIMENTI\n");

	for (i = 0; i < 8; i++)
	{
		if (i == 5)
		{
			printf("------------------------\n");
			printf("     ---PATATINE---\n");
			printf("------------------------\n");
		}


		if (i == 6)
		{
			printf("------------------------\n");
			printf("     ---BEVANDE---\n");
			printf("------------------------\n");
		}
		printf("[%d]%s\n", i, alimenti[i]);
	}

	for (i = 0; i < 8; i++)
	{
		scanf("%d", &scortealimenti[i]);
	}

	//inizio programma

	printf("Scegli uno dei seguenti alimenti:\n");

	for (i = 0; i < 8; i++)
	{
		printf("[%d]%s\n", i, alimenti[i]);
	}

	scanf("%d", &scelta);

	if (scortealimenti[scelta] > 0)
	{
		carrello[scelta] += 1;
		scortealimenti[scelta] = scortealimenti[scelta] - 1;
	}
	else if (scortealimenti[scelta] == 0)
	{
		printf("vuoi chiamare un addetto che ti fornisca l'alimnento selezionato? [1]=si [0]=no\t");
		scanf("%d", &i);

		if (i > 0)
		{
			printf("rifornisci questo alimento\n");
			scanf("%d", &scortealimenti[scelta]);

			carrello[scelta] += 1;
			scortealimenti[scelta] = scortealimenti[scelta] - 1;
		}
	}
	do
	{
		printf("vuoi aggiungere qualcos altro? [1]=si [0]=no\t");
		scanf("%d", &i);

		if (i > 0)
		{
			scanf("%d", &scelta);
		}


		if (scortealimenti[scelta] > 0)
		{
			carrello[scelta] += 1;
			scortealimenti[scelta] = scortealimenti[scelta] - 1;
		}
		else if (scortealimenti[scelta] == 0)
		{
			printf("vuoi chiamare un addetto che ti fornisca l'alimento selezionato? [1]=si [0]=no\t");
			scanf("%d", &i);

			if (i > 0)
			{
				printf("rifornisci questo alimento\n");
				scanf("%d", &scortealimenti[scelta]);

				carrello[scelta] += 1;
				scortealimenti[scelta] = scortealimenti[scelta] - 1;
			}
		}
	} while (i >= 1);

	printf("hai un coupon? [1]=si [0]=no\t");
	if (i > 0)
	{
		printf("applica il prezzo dello sconto:\t");
		scanf("")
	}

	for (i = 0; i < 8; i++)
	{
		if (carrello[i] > 0)
		{
			prezzoTotale[cliente] += prezzialimenti[i] * carrello[i];
		}
	}
	for (i = 0; i < 8; i++)
	{
		if (carrello[i] > 0)
		{
			printf("\n(%d)%s = %.2f $\n", carrello[i], alimenti[i], prezzialimenti[i]);
		}
	}

	printf("%.2f", prezzoTotale[cliente]);
}