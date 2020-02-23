#include "beta2.h"

void listerEleves(eleve **tabEleves, int compteurTab)
{
	for(int i=0;i<compteurTab;i++)
	{
		if(i==0)
		{
			clear();
		}	
		printf("+----------------------------+\n");
		printf("  identifiant : %d           \n", tabEleves[i]->id);
		printf("  nom :         %s           \n", tabEleves[i]->nom);
		printf("  prenom :      %s           \n", tabEleves[i]->prenom);
		printf("  promotion :   %s           \n", tabEleves[i]->promotion);
		printf("+----------------------------+\n\n");
	}
	if(compteurTab==0)
		{
			printf("Aucun élèves enregistré\n");
			pause();
		}
}
int details(eleve **tabEleves, int compteurTab)
{
	int i=0;
	int b=0;
	int nb =0;
	double moyenne=0;
	double moyenneFinal=0;
	double moyenneGeneral=0;
	int idDetails=0;
	char *buff=malloc(3*sizeof(char));
	if(compteurTab==0)
	{
		printf("Aucun élève enregistré.\n");
		pause();
		return 1;
	}
	listerEleves(tabEleves, compteurTab);
	printf("Veuillez saisir l'identifiant de l'élève : \n");
	saisir(buff, 3);
	while(verifchiffre(buff))
	{
		printf("Erreur de saisie, veuillez saisir un identifiant valide : \n");
		saisir(buff, 3);
	}
	idDetails=atoi(buff);
	for(i=0;i<compteurTab;i++)
	{
		if(tabEleves[i]->id==idDetails)
		{
		b=1;	
		break;	
		}
	}
		if(b==0)
		{
			printf("Aucun élèves ne corespond à cet identifiant \n");
			pause();
			return 1;
		}
		clear();
		printf("+------------------------------------+\n");
		printf("  identifiant : %d           \n", tabEleves[i]->id);
		printf("  nom :         %s           \n", tabEleves[i]->nom);
		printf("  prenom :      %s           \n", tabEleves[i]->prenom);
		printf("  promotion :   %s           \n", tabEleves[i]->promotion);		
		if(tabEleves[i]->matieres.nbNoteProg==0)
		{
			printf("+------------------------------------+\n");
			printf("  matière :     Programmation\n");
			printf("  note    :     Aucune \n");
			printf("  moyenne :     Aucune \n");
		}
		else
		{ 	
			printf("+------------------------------------+\n");
			printf("  matière :     Programmation\n");
			for(int j=0;j<tabEleves[i]->matieres.nbNoteProg;j++)
			{
			printf("  note %d :      %.2lf\n",j+1,tabEleves[i]->matieres.programmation[j]);
			moyenne=moyenne+tabEleves[i]->matieres.programmation[j];
			}
		moyenneFinal=moyenne/tabEleves[i]->matieres.nbNoteProg;
		printf("  moyenne :     %.2lf\n",moyenneFinal);
		moyenneGeneral=moyenneGeneral+moyenneFinal;
		nb++;
		}
		if(tabEleves[i]->matieres.nbNoteLinux==0)
		{
			printf("+------------------------------------+\n");
			printf("  matière :     Linux  \n");
			printf("  note    :     Aucune \n");
			printf("  moyenne :     Aucune \n");
		}
		else
		{ 	
			printf("+------------------------------------+\n");
			printf("  matière :     Linux\n");
			moyenne=0;
			moyenneFinal=0;
			for(int j=0;j<tabEleves[i]->matieres.nbNoteLinux;j++)
			{
			printf("  note %d :      %.2lf\n",j+1,tabEleves[i]->matieres.Linux[j]);
			moyenne=moyenne+tabEleves[i]->matieres.Linux[j];
			}
		moyenneFinal=moyenne/tabEleves[i]->matieres.nbNoteLinux;
		printf("  moyenne :     %.2lf\n",moyenneFinal);	
		moyenneGeneral=moyenneGeneral+moyenneFinal;
		nb++;
		}
		if(tabEleves[i]->matieres.nbNoteSecu==0)
		{
			printf("+------------------------------------+\n");
			printf("  matière :     Sécurité  \n");
			printf("  note    :     Aucune \n");
			printf("  moyenne :     Aucune \n");
		}
		else
		{ 	
			printf("+------------------------------------+\n");
			printf("  matière :     Sécurité \n");
			moyenne=0;
			moyenneFinal=0;
			for(int j=0;j<tabEleves[i]->matieres.nbNoteSecu;j++)
			{
			printf("  note %d :      %.2lf\n",j+1,tabEleves[i]->matieres.secu[j]);
			moyenne=moyenne+tabEleves[i]->matieres.secu[j];
			}
		moyenneFinal=moyenne/tabEleves[i]->matieres.nbNoteSecu;
		printf("  moyenne :     %.2lf\n",moyenneFinal);
		moyenneGeneral=moyenneGeneral+moyenneFinal;
		nb++;
		}
		if(tabEleves[i]->matieres.nbNoteReseau==0)
		{
			printf("+------------------------------------+\n");
			printf("  matière :     Réseau  \n");
			printf("  note    :     Aucune \n");
			printf("  moyenne :     Aucune \n");
		}
		else
		{ 	
			printf("+------------------------------------+\n");
			printf("  matière :     Réseau \n");
			moyenne=0;
			moyenneFinal=0;
			for(int j=0;j<tabEleves[i]->matieres.nbNoteReseau;j++)
			{
			printf("  note %d :      %.2lf\n",j+1,tabEleves[i]->matieres.reseau[j]);
			moyenne=moyenne+tabEleves[i]->matieres.reseau[j];
			}
		moyenneFinal=moyenne/tabEleves[i]->matieres.nbNoteReseau;
		printf("  moyenne :     %.2lf\n",moyenneFinal);
		moyenneGeneral=moyenneGeneral+moyenneFinal;
		nb++;
		}
		printf("+------------------------------------+\n");
		if(moyenneGeneral!=0)
		{
		moyenneGeneral=moyenneGeneral/nb; 	
			printf("  moyenne générale :     %.2lf\n",moyenneGeneral);
			printf("+------------------------------------+\n\n");
		}
		else
		{
			printf("  moyenne générale :     Aucune note\n");
			printf("+------------------------------------+\n\n");
		}
		pause();
		free(buff);
		buff=NULL;
	return 0;	
}
int listerPromo(eleve **tabEleves, int compteurTab)
{
	int c;
	int nb;
	double moyenneF;
	int nbPromo;
	if(compteurTab==0)
	{
		printf("Aucune promotion \n");
		pause();
		return 1;
	}
	else
	{ 
		eleve **tabPromo=malloc(sizeof(eleve*));
		tabPromo[0]=tabEleves[0];
		nbPromo=1;
		for(int i=1;i<compteurTab;i++)
		{
			c=0;
			for (int j=0;j<nbPromo;j++)
			{
				if(strcmp(tabEleves[i]->promotion, tabPromo[j]->promotion)==0)
				{
					c++;
				}
			}
			if(c==0)
			{
				nbPromo++;
				tabPromo=realloc(tabPromo,nbPromo*sizeof(eleve*));
				tabPromo[nbPromo-1]=tabEleves[i];
			}
		}
		for(int i=0;i<nbPromo;i++)
		{
			nb=0;
			moyenneF=0;
			for(int j=0;j<compteurTab;j++)
			{
				if(strcmp(tabPromo[i]->promotion, tabEleves[j]->promotion)==0)
				{
					nb++;
					if(tabEleves[i]->matieres.nbNoteProg!=0||tabEleves[i]->matieres.nbNoteLinux!=0||tabEleves[i]->matieres.nbNoteSecu!=0||tabEleves[i]->matieres.nbNoteReseau!=0)
					{
						moyenneF=moyenneF+moyenne(tabEleves[j]);
					}
				}
			}
				if(i==0)
				{ 
					clear();
				}
				printf("+----------------------------+\n");
				printf("  promotion :       %s        \n", tabPromo[i]->promotion);
				printf("  nombre d'élèves : %d        \n",nb);
				if(moyenneF!=0)
				{ 	
					moyenneF=moyenneF/nb;
					printf("  moyenne :         %.2lf      \n", moyenneF);
				}
				else
				{
					printf("  moyenne :         Aucune note\n");
				}
				printf("+----------------------------+\n\n");		
		}
		if(bolean!=1)
		{ 	
			pause();
		}	
		for(int i=0;i<nbPromo;i++)
		{
			tabPromo[i]=NULL;
			free(tabPromo[i]);
		}
		*tabPromo=NULL;
		free(*tabPromo);
	}
	return 0;
}
int trie(eleve **tabEleves, int nb, int compteurTab)
{
	int i=0;
	eleve *tmp=NULL;
	if(compteurTab==0)
	{
		printf("Aucun élève enregistré\n");
		pause();
		return 1;
	}
	else if(nb==1)
	{ 
		for(int c=0;c<compteurTab;c++)
		{
			if(compteurTab==1)
			{ 
				break;
			}		
			for(int j=0;j<compteurTab-1;j++)
			{
				if(strcmp(tabEleves[j]->nom, tabEleves[j+1]->nom)>0)
				{
					tmp=tabEleves[j];
					tabEleves[j]=tabEleves[j+1];
					tabEleves[j+1]=tmp;
				}
				if(strcmp(tabEleves[j]->nom, tabEleves[j+1]->nom)==0)
				{
					if(strcmp(tabEleves[j]->prenom, tabEleves[j+1]->prenom)>0)
					{
					tmp=tabEleves[j];
					tabEleves[j]=tabEleves[j+1];
					tabEleves[j+1]=tmp;
					}
				}
			}
		}
	}
	else if(nb==2)
	{ 
		for(int c=0;c<compteurTab;c++)
		{
			if(compteurTab==1)
			{ 
				break;
			}		
			for(int j=0;j<compteurTab-1;j++)
			{
				if(strcmp(tabEleves[j]->prenom, tabEleves[j+1]->prenom)>0)
				{
					tmp=tabEleves[j];
					tabEleves[j]=tabEleves[j+1];
					tabEleves[j+1]=tmp;
				}
				if(strcmp(tabEleves[j]->prenom, tabEleves[j+1]->prenom)==0)
				{
					if(strcmp(tabEleves[j]->nom, tabEleves[j+1]->nom)>0)
					{
					tmp=tabEleves[j];
					tabEleves[j]=tabEleves[j+1];
					tabEleves[j+1]=tmp;
					}
				}
			}
		}
	}
	else if(nb==3)
	{ 
		for(int c=0;c<compteurTab;c++)
		{
			if(compteurTab==1)
			{ 
				break;
			}		
			for(int j=0;j<compteurTab-1;j++)
			{
				if(strcmp(tabEleves[j]->promotion, tabEleves[j+1]->promotion)>0)
				{
					tmp=tabEleves[j];
					tabEleves[j]=tabEleves[j+1];
					tabEleves[j+1]=tmp;
				}
				if(strcmp(tabEleves[j]->promotion, tabEleves[j+1]->promotion)==0)
				{
					if(strcmp(tabEleves[j]->nom, tabEleves[j+1]->nom)>0)
					{
						tmp=tabEleves[j];
						tabEleves[j]=tabEleves[j+1];
						tabEleves[j+1]=tmp;
					}
					if(strcmp(tabEleves[j]->nom, tabEleves[j+1]->nom)==0)
					{
						if(strcmp(tabEleves[j]->prenom, tabEleves[j+1]->prenom)>0)
						{
							tmp=tabEleves[j];
							tabEleves[j]=tabEleves[j+1];
							tabEleves[j+1]=tmp;
						}
					}
				}
			}
		}
	}
	else if(nb==4)
	{ 
		for(int c=0;c<compteurTab;c++)
		{
			if(compteurTab==1)
			{ 
				break;
			}		
			for(int j=0;j<compteurTab-1;j++)
			{
				if(moyenne(tabEleves[j])>moyenne(tabEleves[j+1]))
				{
					tmp=tabEleves[j];
					tabEleves[j]=tabEleves[j+1];
					tabEleves[j+1]=tmp;
				}
				if(moyenne(tabEleves[j])==moyenne(tabEleves[j+1]))
				{
					if(strcmp(tabEleves[j]->nom, tabEleves[j+1]->nom)>0)
					{
					tmp=tabEleves[j];
					tabEleves[j]=tabEleves[j+1];
					tabEleves[j+1]=tmp;
					}
					if(strcmp(tabEleves[j]->nom, tabEleves[j+1]->nom)==0)
					{
						if(strcmp(tabEleves[j]->prenom, tabEleves[j+1]->prenom)>0)
						{
							tmp=tabEleves[j];
							tabEleves[j]=tabEleves[j+1];
							tabEleves[j+1]=tmp;
						}
					}
				}
			}
		}
	}
	for(i=0;i<compteurTab;i++)
	{
		if(i==0)
		{
			clear();
		}
		printf("+---------------------------------+\n");
		printf("  identifiant : %d           \n", tabEleves[i]->id);
		printf("  nom :         %s           \n", tabEleves[i]->nom);
		printf("  prenom :      %s           \n", tabEleves[i]->prenom);
		printf("  promotion :   %s           \n", tabEleves[i]->promotion);
		if(tabEleves[i]->matieres.nbNoteProg==0 && tabEleves[i]->matieres.nbNoteLinux==0 && tabEleves[i]->matieres.nbNoteSecu==0 && tabEleves[i]->matieres.nbNoteReseau==0)
		{ 
		printf("  moyenne générale :  Aucune note   \n");
		}
		else
		{ 
		printf("  moyenne générale :     %.2lf\n",moyenne(tabEleves[i]));
		}
		printf("+---------------------------------+\n\n");
	}
	pause();
	return 0;
}
int extract(eleve **tabEleves, int nb ,int compteurTab)
{
	int i=0;
	int j=0;
	int taille =10;
	char *bufferPromo=malloc(taille*sizeof(char));
	eleve **tab=malloc(sizeof(eleve*));

	if(compteurTab==0)
	{
		printf("Aucun élèves enregistré\n");
		pause();
		return 1;
	}
	listerEleves(tabEleves, compteurTab);
	printf("Veuillez entrer une promotion : \n");
	saisir(bufferPromo, taille);
	while(verifchiffreEtLettre(bufferPromo))
	{
		printf("Erreur de saisie, veuillez saisir un nom de promotion valide : ");
		saisir(bufferPromo, taille);
	}
	if(verifPromo(tabEleves, bufferPromo, compteurTab)!=0)
	{
		printf("Aucune promotion de ce nom trouvé \n");
		pause();
		return 1;
	}
	for(i=0;i<compteurTab;i++)
	{
		if(strcmp(tabEleves[i]->promotion, bufferPromo)==0)
		{
			tab[j]=tabEleves[i];
			j++;
		}
	}
	trie(tab, nb, j);
	return 0;
}