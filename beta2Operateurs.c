#include "beta2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int saisir(char *chaine, int longueur)
{
	char *positionEntree = NULL;
	if(fgets(chaine, longueur, stdin) != NULL)
	{
		positionEntree = strchr(chaine, '\n');
		if(positionEntree != NULL)
		{
			*positionEntree = '\0';
		}
		else
		{
			viderBuffer();
		}
		return 1;
	}
	else
	{
		viderBuffer();
		return 0;
	}
}
void viderBuffer()
{
	int c = 0;
	while (c != '\n' && c != EOF)
	{
		c = getchar();
	}
}
int verifchiffre(char *string)
{
	for(int i=0;i<strlen(string);i++)
	{
		if((string[i]<48 && string[i]!=46)||string[i]>57)
		{
			return 1;
		}
	}
	return 0;
}
int verifLettre(char *string)
{
	for(int i=0;i<strlen(string);i++)
	{
		if(string[i]<'A'||string[i]>'z'||(string[i]<'a'&& string[i]>'Z'))
		{
			return 1;
		}
	}
	return 0;
}
int verifchiffreEtLettre(char *string)
{
	for(int i=0;i<strlen(string);i++)
	{
		if(string[i]<'0'||string[i]>'z'||(string[i]>'9' && string[i]<'A')||(string[i]>'Z' && string[i]<'a'))
		{
			return 1;
		}
	}
	return 0;
}
int verifId(eleve **tabEleves, int choixId, int compteurTab)
{
	for (int i=0;i<compteurTab;i++)
	{
		if(choixId==tabEleves[i]->id)
		{
			return 0;
		}
	}
	return 1;
}
int verifPromo(eleve **tabEleves,char *buffPromo, int compteurTab)
{
	for(int i=0;i<compteurTab;i++)
	{
		if(strcmp(tabEleves[i]->promotion, buffPromo)==0)
		{
			return 0;
		}
	}
	return 1;
}
void pause(void)
{
	char *buff;
	buff=(char*)malloc(2*sizeof(char));
	printf("Appuyez sur une touche pour continuer\n");
	saisir(buff, 2);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	free(buff);
	buff=NULL;
}
double moyenne(eleve *tabEleves)
{
	int c=0;
	double tmpProg=0;
	double tmpLinux=0;
	double tmpSecu=0;
	double tmpReseau=0;
	double moyennF=0;
	if(tabEleves->matieres.nbNoteProg!=0)
	{
			for(int i=0; i < tabEleves->matieres.nbNoteProg;i++)
			{
				tmpProg=tmpProg+tabEleves->matieres.programmation[i];
			}
		tmpProg=tmpProg/tabEleves->matieres.nbNoteProg;
		c++;
	}
	if(tabEleves->matieres.nbNoteLinux!=0)
	{
			for(int i=0;i<tabEleves->matieres.nbNoteLinux;i++)
			{
				tmpLinux=tmpLinux+tabEleves->matieres.Linux[i];
			}
		tmpLinux=tmpLinux/tabEleves->matieres.nbNoteLinux;
		c++;
	}
	if(tabEleves->matieres.nbNoteSecu!=0)
	{
		for(int i=0;i<tabEleves->matieres.nbNoteSecu;i++)
		{
			tmpSecu=tmpSecu+tabEleves->matieres.secu[i];
		}
		tmpSecu=tmpSecu/tabEleves->matieres.nbNoteSecu;
		c++;
	}
	if(tabEleves->matieres.nbNoteReseau!=0)
	{
		for(int i=0;i<tabEleves->matieres.nbNoteReseau;i++)
		{
			tmpReseau=tmpReseau+tabEleves->matieres.reseau[i];
		}
		tmpReseau=tmpReseau/tabEleves->matieres.nbNoteReseau;
		c++;
	}
	moyennF=(tmpProg+tmpLinux+tmpSecu+tmpReseau)/c;
	return moyennF;
}
eleve* createEleve(int compteurId)
{
	int taille = 50;
	char *bufferNom=malloc(taille*sizeof(char));
	char *bufferPrenom=malloc(taille*sizeof(char));
	char *bufferPromotion=malloc(taille*sizeof(char));
	eleve *newEleve;
	newEleve=malloc(sizeof(eleve));
	newEleve->id=compteurId;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("+--------------------------------------------------+\n");
	printf("Entrer le nom de l'élève :           ");
	saisir(bufferNom, taille);
	while(verifLettre(bufferNom))
	{
		printf("Eurreur de saisie, veuillez saisir un nom valide :  ");
		saisir(bufferNom, taille);
	}
	newEleve->nom=(char*)malloc((strlen(bufferNom)+1)*sizeof(char));
	strcpy(newEleve->nom, bufferNom);
	
	printf("Entrer le prenom de l'élève :        ");
	saisir(bufferPrenom, taille);
	while(verifLettre(bufferPrenom))
	{
		printf("Eurreur de saisie, veuillez saisir un prenom valide : ");
		saisir(bufferPrenom, taille);
	}
	newEleve->prenom=(char*)malloc((strlen(bufferPrenom)+1) *sizeof(char));
	strcpy(newEleve->prenom, bufferPrenom);

	printf("Entrer la promotion de l'élève :     ");
	saisir(bufferPromotion, taille);
	while(verifchiffreEtLettre(bufferPromotion))
	{
		printf("Erreur de saisie, veuillez saisir un nom de promotion valide : ");
		saisir(bufferPromotion, taille);
	}
	newEleve->promotion=(char*)malloc((strlen(bufferPromotion)+1)*sizeof(char));
	strcpy(newEleve->promotion, bufferPromotion);
	printf("+--------------------------------------------------+\n");
	pause();
	newEleve->matieres.programmation=malloc(sizeof(double));
	newEleve->matieres.programmation=NULL;
	newEleve->matieres.Linux=malloc(sizeof(double));
	newEleve->matieres.Linux=NULL;
	newEleve->matieres.secu=malloc(sizeof(double));
	newEleve->matieres.programmation=NULL;
	newEleve->matieres.reseau=malloc(sizeof(double));
	newEleve->matieres.reseau=NULL;
	newEleve->matieres.nbNoteProg=0;
	newEleve->matieres.nbNoteLinux=0;
	newEleve->matieres.nbNoteSecu=0;
	newEleve->matieres.nbNoteReseau=0;
	free(bufferNom);
	bufferNom=NULL;
	free(bufferPrenom);
	bufferPrenom=NULL;
	free(bufferPromotion);
	bufferPromotion=NULL;
	return newEleve;
}
int delEleve(eleve **tabEleves, int compteurTab)
{
	int i=0;
	int idDel=0;
	char *buff=malloc(3*sizeof(char));
	if(compteurTab==0)
	{
		printf("Aucun élèves enregistré\n");
		pause();
		return 1;
	}
	printf("Veuillez saisir l'identifiant de l'élève à supprimer : \n");
	saisir(buff, 3);
	while(verifchiffre(buff))
	{
		printf("Erreur de saisie, veuillez saisir un identifiant valide : \n");
		saisir(buff, 3);
	}
	idDel=atoi(buff);
	if(verifId(tabEleves, idDel, compteurTab)!=0)
	{
		printf("Aucun identifiant corespondant trouvé!!\n");
		pause();
		return 1;
	}
	while(tabEleves[i]->id!=idDel)
	{
		i++;
	}
		free(tabEleves[i]->nom);
		tabEleves[i]->nom=NULL;
		free(tabEleves[i]->prenom);
		tabEleves[i]->prenom=NULL;
		free(tabEleves[i]->promotion);
		tabEleves[i]->promotion=NULL;
		free(tabEleves[i]->matieres.programmation);
		tabEleves[i]->matieres.programmation=NULL;
		free(tabEleves[i]->matieres.Linux);
		tabEleves[i]->matieres.Linux=NULL;
		free(tabEleves[i]->matieres.secu);
		tabEleves[i]->matieres.secu=NULL;
		free(tabEleves[i]->matieres.reseau);
		tabEleves[i]->matieres.reseau=NULL;
	for(int j=i;j<compteurTab-1;j++)
	{		
		tabEleves[j]=tabEleves[j+1];
	}
	tabEleves=realloc(tabEleves,(compteurTab-1)*sizeof(eleve*));
	free(buff);
	buff=NULL;
	return 0;
} 
int modif(eleve **tabEleves, int compteurTab)
{
	int i=0;
	int c=0;
	int idModif=0;
	int taille = 50;
	char *bufferNotes=malloc(7*sizeof(char));
	char *bufferNom=malloc(taille*sizeof(char));
	char *bufferPrenom=malloc(taille*sizeof(char));
	char *bufferPromotion=malloc(taille*sizeof(char));
	char *buff=malloc(3*sizeof(char));
	if(compteurTab==0)
	{
		printf("Aucun élèves enregistré\n");
		pause();
		return 1;
	}
	printf("Veuillez saisir l'identifiant de l'élève : ");
	saisir(buff, 3);
	while(verifchiffre(buff))
	{
		printf("Erreur de saisie, veuillez saisir un identifiant valide : \n");
		saisir(buff, 3);
	}
	idModif=atoi(buff);
	for(i=0;i<compteurTab;i++)
	{
		if(tabEleves[i]->id==idModif)
		{
		c=1;
		break;	
		}
	}
	if(c==0)
	{
		printf("Aucun élèves ne corespond à cet identifiant \n");
		pause();
		return 1;
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("+-----------------------------------------+\n");
	printf("nom actuel : %s\n",tabEleves[i]->nom);
	printf("Entrer le nouveau nom de l'élève (entrée = defaut) : ");
	saisir(bufferNom, taille);
	while(verifLettre(bufferNom))
	{
		printf("Eurreur de saisie, veuillez saisir un nom valide : \n");
		saisir(bufferNom, taille);
	}
	if(bufferNom[0]!='\0')
	{ 
	tabEleves[i]->nom=(char*)malloc((strlen(bufferNom)+1)*sizeof(char));
	strcpy(tabEleves[i]->nom, bufferNom);
	}
	printf("+-----------------------------------------+\n");
	printf("Prenom actuel : %s\n",tabEleves[i]->prenom);
	printf("Entrer le nouveau prenom de l'élève (entrée = defaut) : ");
	saisir(bufferPrenom, taille);
	while(verifLettre(bufferPrenom))
	{
		printf("Eurreur de saisie, veuillez saisir un prenom valide : \n");
		saisir(bufferPrenom, taille);
	}
	if(bufferPrenom[0]!='\0')
	{ 
	tabEleves[i]->prenom=(char*)malloc((strlen(bufferPrenom)+1) *sizeof(char));
	strcpy(tabEleves[i]->prenom, bufferPrenom);
	}
	printf("+-----------------------------------------+\n");
	printf("Promotion actuelle : %s\n",tabEleves[i]->promotion);
	printf("Entrer la nouvelle promotion de l'élève (entrée = defaut) : ");
	saisir(bufferPromotion, taille);
	printf("+-----------------------------------------+\n");
	while(verifchiffreEtLettre(bufferPromotion))
	{
		printf("Erreur de saisie, veuillez saisir une promotion valide : \n");
		saisir(bufferPromotion, taille);
	}
	if(bufferPromotion[0]!='\0')
	{ 
	tabEleves[i]->promotion=(char*)malloc((strlen(bufferPromotion)+1)*sizeof(char));
	strcpy(tabEleves[i]->promotion, bufferPromotion);
	}
	if(tabEleves[i]->matieres.nbNoteProg!=0)
	{
		printf("Programmation\n");
		for(int j=0;j<tabEleves[i]->matieres.nbNoteProg;j++)
		{
			printf("note %d : %.2lf\n",j+1,tabEleves[i]->matieres.programmation[j]);
			printf("Entrer la nouvelle note de l'élève (entrée = defaut) : ");
			saisir(bufferNotes,7);
			while(verifchiffre(bufferNotes))
			{
			printf("Erreur de saisie, veuillez saisir une note entre 1 et 20 : \n" );
			saisir(bufferNotes, 7);
			}
			tabEleves[i]->matieres.programmation[j]=atof(bufferNotes);
		}
		printf("+-----------------------------------------+\n");
	}
	if(tabEleves[i]->matieres.nbNoteLinux!=0)
	{
		printf("Linux\n");
		for(int j=0;j<tabEleves[i]->matieres.nbNoteLinux;j++)
		{
			printf("note %d : %.2lf\n",j+1,tabEleves[i]->matieres.Linux[j]);
			printf("Entrer la nouvelle note de l'élève (entrée = defaut) : ");
			saisir(bufferNotes,7);
			while(verifchiffre(bufferNotes))
			{
			printf("Erreur de saisie, veuillez saisir une note entre 1 et 20 : \n" );
			saisir(bufferNotes, 7);
			}
			tabEleves[i]->matieres.Linux[j]=atof(bufferNotes);
		}
		printf("+-----------------------------------------+\n");
	}
	if(tabEleves[i]->matieres.nbNoteSecu!=0)
	{
		printf("Sécurité informatique\n");
		for(int j=0;j<tabEleves[i]->matieres.nbNoteSecu;j++)
		{
			printf("note %d : %.2lf\n",j+1,tabEleves[i]->matieres.secu[j]);
			printf("Entrer la nouvelle note de l'élève (entrée = defaut) : ");
			saisir(bufferNotes,7);
			while(verifchiffre(bufferNotes))
			{
			printf("Erreur de saisie, veuillez saisir une note entre 1 et 20 : \n" );
			saisir(bufferNotes, 7);
			}
			tabEleves[i]->matieres.secu[j]=atof(bufferNotes);
		}
		printf("+-----------------------------------------+\n");
	}
	if(tabEleves[i]->matieres.nbNoteProg!=0)
	{
		printf("Réseau\n");
		for(int j=0;j<tabEleves[i]->matieres.nbNoteReseau;j++)
		{
			printf("note %d : %.2lf\n",j+1,tabEleves[i]->matieres.reseau[j]);
			printf("Entrer la nouvelle note de l'élève (entrée = defaut) : ");
			saisir(bufferNotes,7);
			while(verifchiffre(bufferNotes))
			{
			printf("Erreur de saisie, veuillez saisir une note entre 1 et 20 : \n" );
			saisir(bufferNotes, 7);
			}
			tabEleves[i]->matieres.reseau[j]=atof(bufferNotes);
		}
		printf("+-----------------------------------------+\n");
	}
	free(bufferNotes);
	bufferNotes=NULL;
	free(buff);
	buff=NULL;
	free(bufferNom);
	bufferNom=NULL;
	free(bufferPrenom);
	bufferPrenom=NULL;
	free(bufferPromotion);
	bufferPromotion=NULL;
	return 0;
}      
int ajouterNote(eleve **tabEleves, int compteurTab)
{
	int i=0;
	int taille=10;
	int choix=0;
	char *buffPromo=malloc(taille*sizeof(char));
	char *bufferNotes=malloc(4*sizeof(char));
	if(compteurTab==0)
	{
		printf("Aucun élèves enregistré\n");
		pause();
		return 1;
	}
	printf("Veuillez entrer une promotion : \n");
	saisir(buffPromo, taille);
	while(verifchiffreEtLettre(buffPromo))
	{
		printf("Erreur de saisie, veuillez saisir un nom de promotion valide : ");
		saisir(buffPromo, taille);
	}
	if(verifPromo(tabEleves, buffPromo, compteurTab)!=0)
	{
		printf("Aucune promotion de ce nom trouvé \n");
		pause();
		return 1;
	}
	choix=menuMatiere();
	switch (choix)
	{
		case 1:
		{	//Programmatioin
			for(i=0;i<compteurTab;i++)
			{
				if(strcmp(tabEleves[i]->promotion, buffPromo)==0)
				{ 	
					tabEleves[i]->matieres.nbNoteProg++;
					tabEleves[i]->matieres.programmation=realloc(tabEleves[i]->matieres.programmation,tabEleves[i]->matieres.nbNoteProg*sizeof(float));
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("+-----------------------------------------+\n");
					printf("Nom de l'eleve : %s\n",tabEleves[i]->nom);
					printf("Matière :        Programmation\n");
					printf("Veuillez saisir la nouvelle note : ");
					saisir(bufferNotes,7);
					printf("+-----------------------------------------+\n");
					pause();
					while(verifchiffre(bufferNotes))
					{
						printf("Erreur de saisie, veuillez saisir une note entre 1 et 20 : \n" );
						saisir(bufferNotes, 7);
					}
					tabEleves[i]->matieres.programmation[tabEleves[i]->matieres.nbNoteProg-1]=atof(bufferNotes);
				}
			}
			free(bufferNotes);
			bufferNotes=NULL;
			free(buffPromo);
			buffPromo=NULL;
			break;
		}
		case 2:
		{	//Linux
			for(i=0;i<compteurTab;i++)
			{
				if(strcmp(tabEleves[i]->promotion, buffPromo)==0)
				{ 	
					tabEleves[i]->matieres.nbNoteLinux++;
					tabEleves[i]->matieres.Linux=realloc(tabEleves[i]->matieres.Linux,tabEleves[i]->matieres.nbNoteLinux*sizeof(float));
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("+-----------------------------------------+\n");
					printf("Nom de l'eleve : %s\n",tabEleves[i]->nom);
					printf("Matière :        Linux\n");
					printf("Veuillez saisir la nouvelle note : ");
					saisir(bufferNotes,7);
					printf("+-----------------------------------------+\n");
					pause();
					while(verifchiffre(bufferNotes))
					{
						printf("Erreur de saisie, veuillez saisir une note entre 1 et 20 : \n" );
						saisir(bufferNotes,7);
					}
					tabEleves[i]->matieres.Linux[tabEleves[i]->matieres.nbNoteLinux-1]=atof(bufferNotes);
				}
			}
			free(bufferNotes);
			bufferNotes=NULL;
			free(buffPromo);
			buffPromo=NULL;
			break;
		}
		case 3:
		{	//Secu
			for(i=0;i<compteurTab;i++)
			{
				if(strcmp(tabEleves[i]->promotion, buffPromo)==0)
				{ 	
					tabEleves[i]->matieres.nbNoteSecu++;
					tabEleves[i]->matieres.secu=realloc(tabEleves[i]->matieres.secu,tabEleves[i]->matieres.nbNoteSecu*sizeof(float));
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("+-----------------------------------------+\n");
					printf("Nom de l'eleve : %s\n",tabEleves[i]->nom);
					printf("Matière :        Sécurité informatique\n");
					printf("Veuillez saisir la nouvelle note : ");
					saisir(bufferNotes,7);
					printf("+-----------------------------------------+\n");
					pause();
					while(verifchiffre(bufferNotes))
					{
						printf("Erreur de saisie, veuillez saisir une note entre 1 et 20 : \n" );
						saisir(bufferNotes,7);
					}
					tabEleves[i]->matieres.secu[tabEleves[i]->matieres.nbNoteSecu-1]=atof(bufferNotes);
				}
			}
			free(bufferNotes);
			bufferNotes=NULL;
			free(buffPromo);
			buffPromo=NULL;
			break;
		}
		case 4:
		{	//Reseau
			for(i=0;i<compteurTab;i++)
			{
				if(strcmp(tabEleves[i]->promotion, buffPromo)==0)
				{ 	
					tabEleves[i]->matieres.nbNoteReseau++;
					tabEleves[i]->matieres.reseau=realloc(tabEleves[i]->matieres.reseau,tabEleves[i]->matieres.nbNoteReseau*sizeof(float));
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
					printf("+-----------------------------------------+\n");
					printf("Nom de l'eleve : %s\n",tabEleves[i]->nom);
					printf("Matière :        Réseau\n");
					printf("Veuillez saisir la nouvelle note : ");
					saisir(bufferNotes,7);
					printf("+-----------------------------------------+\n");
					pause();
					while(verifchiffre(bufferNotes))
					{
						printf("Erreur de saisie, veuillez saisir une note entre 1 et 20 : \n" );
						saisir(bufferNotes,7);
					}
					tabEleves[i]->matieres.reseau[tabEleves[i]->matieres.nbNoteReseau-1]=atof(bufferNotes);
				}
			}
			free(bufferNotes);
			bufferNotes=NULL;
			free(buffPromo);
			buffPromo=NULL;
			break;
		}
	}
	return 0;
}     
int ajouterNoteTlm(eleve **tabEleves, int compteurTab)
{
	int i=0;
	int choix=0;
	char *bufferNotes=malloc(4*sizeof(char));
	choix=menuMatiere();
	switch (choix)
	{
		case 1:
		{	//Programmatioin
			for(i=0;i<compteurTab;i++)
			{	
				tabEleves[i]->matieres.nbNoteProg++;
				tabEleves[i]->matieres.programmation=realloc(tabEleves[i]->matieres.programmation,tabEleves[i]->matieres.nbNoteProg*sizeof(float));
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				printf("+-----------------------------------------+\n");
				printf("Nom de l'eleve : %s\n",tabEleves[i]->nom);
				printf("Matière :        Programmation\n");
				printf("Veuillez saisir la nouvelle note : ");
				saisir(bufferNotes,7);
				printf("+-----------------------------------------+\n");
				pause();
				while(verifchiffre(bufferNotes))
				{
					printf("Erreur de saisie, veuillez saisir une note entre 1 et 20 : \n" );
					saisir(bufferNotes,7);
				}
				tabEleves[i]->matieres.programmation[tabEleves[i]->matieres.nbNoteProg-1]=atof(bufferNotes);
			}
			free(bufferNotes);
			bufferNotes=NULL;
			break;
		}
		case 2:
		{	//Linux
			for(i=0;i<compteurTab;i++)
			{	
				tabEleves[i]->matieres.nbNoteLinux++;
				tabEleves[i]->matieres.Linux=realloc(tabEleves[i]->matieres.Linux,tabEleves[i]->matieres.nbNoteLinux*sizeof(float));
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				printf("+-----------------------------------------+\n");
				printf("Nom de l'eleve : %s\n",tabEleves[i]->nom);
				printf("Matière :        Linux\n");
				printf("Veuillez saisir la nouvelle note : ");
				saisir(bufferNotes,7);
				printf("+-----------------------------------------+\n");
				pause();
				while(verifchiffre(bufferNotes))
				{
					printf("Erreur de saisie, veuillez saisir une note entre 1 et 20 : \n" );
					saisir(bufferNotes,7);
				}
				tabEleves[i]->matieres.Linux[tabEleves[i]->matieres.nbNoteLinux-1]=atof(bufferNotes);
			}
			free(bufferNotes);
			bufferNotes=NULL;
			break;
		}
		case 3:
		{	//Secu
			for(i=0;i<compteurTab;i++)
			{	
				tabEleves[i]->matieres.nbNoteSecu++;
				tabEleves[i]->matieres.secu=realloc(tabEleves[i]->matieres.secu,tabEleves[i]->matieres.nbNoteSecu*sizeof(float));
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				printf("+-----------------------------------------+\n");
				printf("Nom de l'eleve : %s\n",tabEleves[i]->nom);
				printf("Matière :        Sécurité informatique\n");
				printf("Veuillez saisir la nouvelle note : ");
				saisir(bufferNotes,7);
				printf("+-----------------------------------------+\n");
				pause();
				while(verifchiffre(bufferNotes))
				{
					printf("Erreur de saisie, veuillez saisir une note entre 1 et 20 : \n" );
					saisir(bufferNotes,7);
				}
				tabEleves[i]->matieres.secu[tabEleves[i]->matieres.nbNoteSecu-1]=atoi(bufferNotes);
			}
			free(bufferNotes);
			bufferNotes=NULL;
			break;
		}
		case 4:
		{	//Reseau
			for(i=0;i<compteurTab;i++)
			{	
				tabEleves[i]->matieres.nbNoteReseau++;
				tabEleves[i]->matieres.reseau=realloc(tabEleves[i]->matieres.reseau,tabEleves[i]->matieres.nbNoteReseau*sizeof(float));
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				printf("+-----------------------------------------+\n");
				printf("Nom de l'eleve : %s\n",tabEleves[i]->nom);
				printf("Matière :        Réseau\n");
				printf("Veuillez saisir la nouvelle note : ");
				saisir(bufferNotes,7);
				printf("+-----------------------------------------+\n");
				pause();
				while(verifchiffre(bufferNotes))
				{
					printf("Erreur de saisie, veuillez saisir une note entre 1 et 20 : \n" );
					saisir(bufferNotes,7);
				}
				tabEleves[i]->matieres.reseau[tabEleves[i]->matieres.nbNoteReseau-1]=atof(bufferNotes);
			}
			free(bufferNotes);
			bufferNotes=NULL;
			break;
		}
	}
	return 0;
}
void freeTabEleves(eleve** tabEleves, int compteurTab)
{
	for(int i=0;i<compteurTab;i++)
		{
			if(tabEleves[i]->matieres.nbNoteProg!=0)
			{
				free(tabEleves[i]->matieres.programmation);
				tabEleves[i]->matieres.programmation=NULL;
			}
			if(tabEleves[i]->matieres.nbNoteLinux!=0)
			{
				free(tabEleves[i]->matieres.Linux);
				tabEleves[i]->matieres.Linux=NULL;
			}
				if(tabEleves[i]->matieres.nbNoteSecu!=0)
			{
				free(tabEleves[i]->matieres.secu);
				tabEleves[i]->matieres.secu=NULL;
			}
				if(tabEleves[i]->matieres.nbNoteReseau!=0)
			{
				free(tabEleves[i]->matieres.reseau);
				tabEleves[i]->matieres.reseau=NULL;
			}
			free(tabEleves[i]->nom);
			tabEleves[i]->nom=NULL;
			free(tabEleves[i]->prenom);
			tabEleves[i]->prenom=NULL;
			free(tabEleves[i]->promotion);
			tabEleves[i]->promotion=NULL;
			free(tabEleves[i]);
			tabEleves[i]=NULL;
		}
		free(tabEleves);
		tabEleves=NULL;
}