#include<stdio.h>
#include<malloc.h>

struct Film  {
	int id;
	int durata;
	char* nume ;
	float buget;
	char varstaMin;
};
struct Film initializare( int _id, int _durata, const char* _nume, float _buget, char _varstaMin) {
	struct Film s;
	s.id = _id;
	//initializare structura 
	s.durata = _durata;
	s.nume = malloc((strlen(_nume) + 1) * sizeof(char));
	strcpy(s.nume, _nume);
	s.buget = _buget;
	s.varstaMin = _varstaMin;
	return s;
}

struct Film copyFilm(struct Film s)
{
	return initializare(s.id, s.durata, s.nume, s.buget, s.varstaMin);
}

void afisare(struct Film s) {
	//afisarea tuturor atributelor.
	printf("id: %d\n", s.id);
	printf("nume: %s\n", s.nume);
	printf("durata: %d\n", s.durata);
	printf("buget: %5.2f\n", s.buget);
	printf("varsta minima: %d\n", s.varstaMin);
	printf("\n");
}

void afisareVector(struct Film* vector, int nrElemente) {
	//afisarea elementelor din vector apeland functia afisare
	for (int i = 0; i < nrElemente; i++)
	{
		afisare(vector[i]);
	}
}

struct Film* copiazaPrimeleNElemente(struct Film* vector, int nrElemente, int nrElementeCopiate) {
	//copiem intr-un vector nou pe care il vom returna primele nrElementeCopiate
	struct Film *vectorNou=malloc(nrElementeCopiate * sizeof(struct Film));
	for (int i = 0; i < nrElementeCopiate; i++)
	{
		vectorNou[i] = copyFilm(vector[i]);
	}

	return vectorNou;
}

void dezalocare(struct Film** vector, int* nrElemente) {
	//dezalocam elementele din vector si vectorul
	for (int i = 0; i < *nrElemente; i++)
	{
		free(((*vector)[i]).nume);
	}
	free(*vector);
	*vector = NULL;
	*nrElemente = 0;
}

void copiazaAnumiteElemente(struct Film* vector, char nrElemente, float bugetMax, struct Film** vectorNou, int* dimensiune) {
	//parametrul prag poate fi modificat in functie de 
	// tipul atributului ales pentru a indeplini o conditie
	//este creat un nou vector cu elementele care indeplinesc acea conditie
	*dimensiune = 0;
	for (int i = 0; i < nrElemente; i++ )
	{
		if (vector[i].buget < bugetMax)
		{
			(*dimensiune)++;
		}
	}
	(*vectorNou) = malloc((*dimensiune) * sizeof(struct Film));
	int k = 0;
	for (int i = 0; i < nrElemente; i++)
	{
		if (vector[i].buget < bugetMax)
		{
			(*vectorNou)[k] = copyFilm(vector[i]);
			k++;
		}
	}

}

//struct Sablon getPrimulElementConditionat(struct Sablon* vector, int nrElemente, const char* conditie) {
//	//trebuie cautat elementul care indeplineste o conditie
//	//dupa atributul de tip char*. Acesta este returnat.
//	struct Sablon s;
//	s.id = 1;
//
//	return s;
//}
	


int main() {

	struct Film f1 = initializare(1, 120, "Dune", 286.5, 14);
	//afisare(f1);
	int nrFilme = 3;
	struct Film* filme = malloc(nrFilme * sizeof(struct Film));
	filme[0] = f1;
	*(filme + 1) = initializare(2, 170, "James Bond", 263.78, 13);
	filme[2] = initializare(3, 240, "Star Wars", 536.7, 16);
	//sageata face dereferentiere si accesare 
	//index face deplasare si dereferentiere 
	//afisareVector(filme, nrFilme);
	struct Film* vectorNou;
	int nrFilmeCopiate = 1;
	vectorNou = copiazaPrimeleNElemente(filme, nrFilme, nrFilmeCopiate);
	//afisareVector(vectorNou, nrFilmeCopiate);
	dezalocare(&vectorNou, &nrFilmeCopiate);
	//afisareVector(vectorNou, nrFilmeCopiate);
	struct Film* vectorIeftin;
	float prag = 300;
	int dimensiune = 0;
	copiazaAnumiteElemente(filme, nrFilme, prag, &vectorIeftin, &dimensiune);
	afisareVector(vectorIeftin , dimensiune);
	return 0;

	//??
	//dereferentiere + deplasare + dereferentiere + accesare -> la dezalocare 
	//fiecre functie are o stiva 
	//pointerul ocupa 4 sau 8 octeti 
	//in char putem stoca si valori intregi, putem avea pana la 255(daca avem unsigned)
	//8 biti pentru semn, primul e pentru semn -> putem stoca pana la 127
}