#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student {
	int id;
	char* nume;
	int nrNote;
	int* note;
	float medie; //calculata ca medie aritmetica a notelor 
	char bursa; //D = da; N = nu (in functie de medie)
};
typedef struct Student Student;

//Functie care sa citeasca studentii dintr un fisier 
void adaugaNota(Student* student, int nota)
{
	if (nota > 1 && nota <= 10)
	{
		student->nrNote++;
		int* aux = malloc((student->nrNote ) * sizeof(int));
		for (int i = 0; i < student->nrNote - 1 ;  i++)
		{
			aux[i] = student->note[i]; 
		}
		aux[student->nrNote - 1] = nota;
		free(student->note);
		student->note = malloc(student->nrNote * sizeof(int));
		for (int i = 0; i < student->nrNote; i++)
		{
			student->note[i] = aux[i];
		}

		free(aux);

	}
}

void adaugareStudentInVector(Student student, int* nrStudenti, Student** vector)
{
	Student* aux = malloc(((*nrStudenti) +1) * sizeof(Student));
	for (int i = 0; i < (*nrStudenti); i++)
	{
		aux[i] = (*vector)[i];
	}
	(*nrStudenti)++;
	aux[(*nrStudenti) - 1] = student;
	free(*vector);
	(*vector) = aux;


}

Student citireStudentDinFisier(FILE* file)
{
	Student student;
	char buffer[50];
	char delimitator[3] = ",\n";
	fgets(buffer, 50, file);
	student.id = atoi(strtok(buffer, delimitator));
	char* nume = strtok(NULL, delimitator);
	student.nume = malloc((strlen(nume) + 1) * sizeof(char));
	strcpy(student.nume, nume);
	student.nrNote = 0;
	student.note = NULL;
	char* token = strtok(NULL, delimitator);
	
	while (token != NULL)
	{
		int nota = atoi(token);
		adaugaNota(&student, nota);
		token = strtok(NULL, delimitator);
	
	}
	if (student.note != NULL)
	{
		float suma = 0;
		for (int i = 0; i < student.nrNote; i++)
		{
			suma += student.note[i];
		}
		student.medie = suma / student.nrNote;
	}
	if (student.medie >= 8.50)
	{
		student.bursa = 'D';
	}
	else
	{
		student.bursa = 'N';
	}


	return student;
}

Student* citireVectorStudentiDinFisier(const char* numeFisier, int *nrStudenti)
{
	FILE* file = fopen(numeFisier, "r");
	Student* vector = NULL;
	while (!feof(file))
	{
		adaugareStudentInVector(citireStudentDinFisier(file), nrStudenti, &vector);
	}
	fclose(file);
	return vector;
	
}

void afisareStudent(Student s)
{
	printf("\nId: %d\n", s.id);
	printf("\nNume: %s\n", s.nume);
	printf("\nNr note : %d\n", s.nrNote);
	for (int i = 0; i < s.nrNote; i++)
	{
		printf("\nnota %d: %d\n",i, s.note[i]);
	}
	printf("\nMedie: %5.2f\n", s.medie);
	printf("\nBursa: %c\n", s.bursa);
}

void afisareVectorStudenti(Student* s, int nrStudenti)
{
	for (int i = 0; i < nrStudenti; i++)
	{
		afisareStudent(s[i]);
		printf("\n");
	}
}


int main()
{
	int nrStudenti = 0;
	Student* studenti = citireVectorStudentiDinFisier("studenti.txt", &nrStudenti);
	afisareVectorStudenti(studenti, nrStudenti);
	return 0;
}