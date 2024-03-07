#include <iostream> 
using namespace std;

int demander_annee()
{ int annee(0);
	do {
	cout <<"Entrez une annee (1583-4000) : ";
	cin >> annee;
}while (annee<1583 or annee>4000);
return annee;

}
