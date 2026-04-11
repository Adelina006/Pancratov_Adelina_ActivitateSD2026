#include<stdio.h>
#include<malloc.h>

struct Film {
	int id;
	int durata;
	char* nume ;
	float buget ;
	char varstaMin;
};
struct Film initializare(int _id, int _durata, const char* _nume, float _buget, char _varstaMin) {
	struct Film s;
	s.id = _id;
	s.durata = _durata;
	s.nume = malloc((strlen(_nume) + 1) * sizeof(char));
	strcpy(s.nume, _nume);
	s.buget = _buget;
	s.varstaMin = _varstaMin;
	return s;
}

void afisare(struct Film s) {
	printf("Id: %d\n", s.id);
	printf("Durata: %d\n", s.durata);
	printf("Nume: %s\n", s.nume);
	printf("Buget: %5.2f\n", s.buget);
	printf("Varsta minima: %d\n", s.varstaMin);
}

void afisareVector(struct Film* vector, int nrElemente) {
	for (int i = 0; i < nrElemente; i++)
	{
		afisare(vector[i]);
	}
}

struct Film copyFilm(struct Film s)
{
	return initializare(s.id, s.durata, s.nume, s.buget, s.varstaMin);
}

struct Film* copiazaPrimeleNElemente(struct Film* vector, int nrElemente, int nrElementeCopiate) {
	struct Film *vectorNou=malloc(nrElementeCopiate * sizeof(struct Film));
	for (int i = 0; i < nrElementeCopiate; i++)
	{
		vectorNou[i] = copyFilm(vector[i]);
	}

	return vectorNou;
}

void dezalocare(struct Film** vector, int* nrElemente) {
	for (int i = 0; i < *nrElemente; i++)
	{
		free((*vector)[i].nume);
	}
	free(*vector);
	(*vector) = NULL;
	*nrElemente = 0;
}

void copiazaAnumiteElemente(struct Film* vector, char nrElemente, float bugetMax, struct Film** vectorNou, int* dimensiune)
{
	(*dimensiune) = 0;
	for (int i = 0; i < nrElemente; i++)
	{
		if (vector[i].buget < bugetMax)
		{
			(*dimensiune)++;
		}
	}
	int k = 0;
	(*vectorNou) = malloc((*dimensiune) * sizeof(struct Film));
	for (int i = 0; i < nrElemente; i++)
	{
		if (vector[i].buget < bugetMax)
		{
			(*vectorNou)[k]=copyFilm(vector[i]);
			k++;
		}
	}
}

struct Film getPrimulElementConditionat(struct Film* vector, int nrElemente, const char* numeCautat) {
	struct Film s;
	s.id = -1;
	for (int i = 0; i < nrElemente; i++)
	{
		if (strcmp(vector[i].nume, numeCautat) == 0)
		{
			return vector[i];
		}
	}

	return s;
}
	


int main() {

	struct Film film = initializare(1, 135, "Dune", 500, 12);
	//afisare(film);
	int nrElemente = 3;
	struct Film* filme = malloc(nrElemente * sizeof(struct Film));
	filme[0] = copyFilm(film);
	filme[1] = initializare(2, 120, "Film 2",262.3, 16);
	filme[2] = initializare(3, 234, "Film 3",435.19, 18);
	//afisareVector(filme, nrElemente);
	struct Film* vectorNou;
	int elemCopiate = 2;
	vectorNou = copiazaPrimeleNElemente(filme, nrElemente, elemCopiate);
	//afisareVector(vectorNou, elemCopiate);
	dezalocare(&vectorNou, &elemCopiate);
	copiazaAnumiteElemente(filme, nrElemente, 300, &vectorNou, &elemCopiate);
	//afisareVector(vectorNou, elemCopiate);
	afisare(getPrimulElementConditionat(filme, nrElemente, "Film 2"));
	return 0;
}