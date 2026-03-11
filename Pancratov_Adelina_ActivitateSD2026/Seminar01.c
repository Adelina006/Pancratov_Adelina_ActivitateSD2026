//#include<stdio.h>
//#include<stdlib.h>
//
//struct Joc
//{
//	int id;
//	int nrJucatori;
//	char* Denumire;
//	float pret;
//	char rating;
//};
//
//struct Joc initializare(int _id, int _nrJucatori, char* _denumire, float _pret, char _rating)
//{
//	struct Joc s;
//	s.id = _id;
//	s.nrJucatori = _nrJucatori;
//	s.pret = _pret;
//	s.rating = _rating;
//	s.Denumire = malloc(sizeof(char) * (strlen(_denumire) + 1));
//	strcpy(s.Denumire, _denumire);
//	return s;
//}
//
//void afisare(struct Joc s)
//{
//	printf("\nId: %d\n", s.id);
//	printf("Denumire: %s\n", s.Denumire);
//	printf("Numar Minim de Jucatori: %d\n", s.nrJucatori);
//	printf("Rating : %c\n", s.rating);
//	printf("Pret: %f\n", s.pret);
//}
//
//void modificaDenumire(struct Joc *s, char* _den)
//{
//	free((*s).Denumire);
//	(*s).Denumire = malloc(sizeof(char) * (strlen(_den) + 1));
//	strcpy((*s).Denumire, _den);
//}
//
//void dezalocare(struct Joc *s)
//{
//	free(s->Denumire);
//}
//
//float calculPretIndividual(struct Joc s)
//{
//	float pret;
//	pret = s.pret / s.nrJucatori;
//	return pret;
//}
//
//int main()
//{
//	struct Joc s;
//	s = initializare(1, 2, "Monopoly", 120, 'A');
//	afisare(s);
//
//	modificaDenumire(&s, "Pocker");
//	afisare(s);
//
//	float pret = calculPretIndividual(s);
//	printf("\nPretul per jucator este %5.2f\n", pret);
//
//	int nrJocuri = 3;
//	struct Joc* jocuri = malloc(sizeof(struct Joc) * nrJocuri);
//	jocuri[0] = s;
//	jocuri[1] = initializare(2, 3, "Catan", 300, 'A');
//	jocuri[2] = initializare(3, 4, "Alias", 230, 'B');
//
//	afisare(*(jocuri));
//	afisare(*(jocuri + 1));
//
//	dezalocare(&s);
//
//	return 0;
//}