#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printTitlu()
{
	printf(" * SPANZURATOAREA*\n");
 	printf("   _________     \n");
    printf("  |         |    \n");
    printf("  |         0    \n");
    printf("  |        /|\\  \n");          //text cool
    printf("  |        / \\  \n");
    printf("  |              \n\n\n");
}


int main()
{
    char prop[1024], prop2[1024], litera;
    int litere[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int i, gasit, stop, greseli = 0;
    char img[8][18]={"   _________     ",
    			  	 "  |         |    ",
    				 "  |         0    ",
    				 "  |        /|\\  ",       //grafica care apare dc gresesti
    				 "  |        / \\  ",
    				 "  |             ",
    				 "  |             ",
    				 "  |             "};
    char img2[8][18]={"  _________ ",
    			  	 "  |         |",
    				 "  |",
    				 "  |",
    				 "  |",
    				 "  |",
    				 "  |",
    				 "  |"};

	printTitlu();
    printf("* Apasa enter pentru a continua *\n");
    getchar();

    printf("   * PLAYER 1 *\n");
    printf("Da propozitia\n");
    fgets(prop, 1024, stdin);
    for (int i = 0; i < strlen(prop); i++)
    {
    	if(prop[i] == ' ')
    		prop2[i] = ' ';
    	else prop2[i] = '_';
    	if(prop[i] > 96)
    		prop[i] -= 32; 
    }
    prop2[strlen(prop2)] = '\0';

    while(greseli < 7)
    {
    	gasit = stop = 0;
    	for (int i = 0; i < strlen(prop2); i++)
    	{
    		if(prop2[i] == '_')
    			stop++;
    	}

    	if(stop == 0)
    		break;
    	system("cls");
    	printf(" * Baga litera si mult noroc *\n\n");
    	printf("* Mai ai %d incercari\n", 7 - greseli);
    	if(greseli != 0)
    		for (int i = 0; i < 8; i++)
    		{
    			if(i <= greseli)
    				printf("%s\n", img[i]);
    			else printf("%s\n", img2[i]);
    		}

    	printf("%s\n", prop2);
    	printf("* Da litera *\n");
    	scanf("%c", &litera);

    	if(litera > 96)
    		litera -= 32;
    	if(litere[litera - 65] == 0)
    	{
    		for (int i = 0; i < strlen(prop); i++)
    			if(prop[i] == litera)
    			{
    				gasit++;
    				prop2[i] = litera;
    			}

    		if(gasit == 0)
    			greseli++;
    	}
    	litere[litera - 65]++;
    }
    system("cls");
    printf("Propozitia era %s\n", prop);
    if(greseli == 7)
    	printf("AI PIERDUT\n");
    else printf("AI CASTIGAT\n");
  	return 0;
}