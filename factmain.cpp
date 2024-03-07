#include <iostream>
#include "date_Paques.h"
#include "demander_annee.h"
#include "affiche_date.h"

int main () { 
	int annee(demander_annee());
	int jour (date_Paques(annee));
	affiche_date(annee,jour);
	
	
}
