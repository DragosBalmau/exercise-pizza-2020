#include <stdio.h>
#include <stdlib.h>

int main() {


    int numarTipuriPizza, numarFeliPizza;

    FILE *fIntrare = fopen("C:\\Users\\Dragos\\Desktop\\a_example.in", "r");
    FILE *fIesire = fopen("C:\\Users\\Dragos\\Desktop\\Aexample.txt", "w");

    fscanf(fIntrare, "%d %d ", &numarFeliPizza, &numarTipuriPizza);
    //printf("%d %d\n", numarFeliPizza, numarTipuriPizza);

    int feliPizza[numarTipuriPizza];

    for (int i = 0; i < numarTipuriPizza; i++) {
	fscanf(fIntrare, "%d ", &feliPizza[i]);
    }

    int numarElementeFinal = numarFeliPizza / feliPizza[numarTipuriPizza - 1];
    //printf("%d ",numarElementeFinal);
    int sumFeli = 0;

    for (int i = numarTipuriPizza - 1; i > numarTipuriPizza - numarElementeFinal - 1; i--)
	sumFeli += feliPizza[i];
     //fprintf(stdout,"%d\n",sumFeli);

    int index = -1;
    if (sumFeli < numarFeliPizza) {
	for (int i = 0; i < numarTipuriPizza - numarElementeFinal; i++) {
	    if (sumFeli + feliPizza[i] < numarFeliPizza)
		sumFeli += feliPizza[i];
	    else {
		index = i;
		break;
	    }
	}


    }
   // fprintf(stdout,"%d\n",sumFeli);

    //fprintf(stdout,"%d\n",index);
    if (index > -1){
	fprintf(fIesire,"%d\n",numarElementeFinal+index);
	for (int i = 0; i < index; i++)
	    fprintf(fIesire, "%d ", i);

    }
    else
        fprintf(fIesire,"%d\n",numarElementeFinal);


    for(int i=numarTipuriPizza - numarElementeFinal;i<numarTipuriPizza;i++)
	fprintf(fIesire,"%d ", i);

}