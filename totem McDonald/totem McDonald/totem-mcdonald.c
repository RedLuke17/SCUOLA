#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>


int main()
{
	char alimenti[8][100] =
	{
		{"BigMac"},
		{"MySelection"},
		{"Gran Crispy McBacon"},
		{"McChicken"},
		{"Hamburger"},
		{"Patatine"},
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

	float coupon[6] =
	{
		0.2f,
		0.1f,
		0.3f,
		0.5f,
		0.9f,
		0.7f,
	};

	char codiceCoupon[6][100] = {
		{"AHGIUDH"},
		{"USDFWAA"},
		{"QUYRFSH"},
		{"PODSAHF"},
		{"CVYUISY"},
		{"RFEGBNI"},
	};

	char cpinserito[100];

	int i = 0;

	int scelta;

	int carrello[8];

	float prezzoTotale[100];

	float resocontoFinale = 0;

	int cliente = 0;

	for (i = 0; i < 100; i++)
	{
		prezzoTotale[i] = 0;
	}

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
	do {

		for (i = 0; i < 8; i++)
		{
			carrello[i] = 0;
		}

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

			if (i == 1)
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

			if (i == 1)
			{
				scanf("%d", &scelta);

				if (scortealimenti[scelta] > 0)
				{
					carrello[scelta] += 1;
					scortealimenti[scelta] = scortealimenti[scelta] - 1;
				}
				else if (scortealimenti[scelta] == 0)
				{
					printf("vuoi chiamare un addetto che ti fornisca l'alimento selezionato? [1]=si [0]=no\t");
					scanf("%d", &i);

					if (i == 1)
					{
						printf("rifornisci questo alimento\n");
						scanf("%d", &scortealimenti[scelta]);

						carrello[scelta] += 1;
						scortealimenti[scelta] = scortealimenti[scelta] - 1;
					}
				}
			}


			
		} while (i >= 1);

		for (i = 0; i < 8; i++)
		{
			if (carrello[i] > 0)
			{
				prezzoTotale[cliente] += prezzialimenti[i] * carrello[i];
			}
		}

		printf("hai un coupon? [1]=si [0]=no\t");
		scanf("%d", &i);

		if (i == 1)
		{
			printf("applica il codice del coupon\t");
			scanf("%s", &cpinserito);

			for (i = 0; i <= 6; i++)
			{
				if (strcmp(cpinserito, codiceCoupon[i]) == 0)
				{
					prezzoTotale[cliente] -= prezzoTotale[cliente] * coupon[i];
				}
			}
		}


		for (i = 0; i < 8; i++)
		{
			if (carrello[i] > 0)
			{
				printf("\n(%d)%s = %.2f $\n", carrello[i], alimenti[i], prezzialimenti[i]);
			}
		}

		printf("%.2f\n", prezzoTotale[cliente]);

		cliente++;
		

	} while (cliente < 24);

	
	for (i = 0; i < 100; i++)
	{
		resocontoFinale += prezzoTotale[i];
	}

	printf("Ecco il resoconto della giornata\n");
	printf("%.2f", resocontoFinale);
}