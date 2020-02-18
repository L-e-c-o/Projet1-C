#include "beta2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void afficherMenu(void)
{
	printf("\n\n\n\n");
	printf("                                                    ********  ********  ******** ********** **   *******   ****     ** ****     **     **     ** *******   ********  \n");
	printf("                                                   **//////**/**/////  **////// /////**/// /**  **/////** /**/**   /**/**/**   /**    ****   /**/**////** /**/////   \n");
	printf("                                                  **      // /**      /**           /**    /** **     //**/**//**  /**/**//**  /**   **//**  /**/**   /** /**        \n");
	printf("                                                 /**         /******* /*********    /**    /**/**      /**/** //** /**/** //** /**  **  //** /**/*******  /*******   \n");
	printf("                                                 /**    *****/**////  ////////**    /**    /**/**      /**/**  //**/**/**  //**/** **********/**/**///**  /**////    \n");
	printf("                                                 //**  ////**/**             /**    /**    /**//**     ** /**   //****/**   //****/**//////**/**/**  //** /**        \n");
	printf("                                                  //******** /******** ********     /**    /** //*******  /**    //***/**    //***/**     /**/**/**   //**/********  \n");
	printf("                                                   ////////  //////// ////////      //     //   ///////   //      /// //      /// //      // // //     // ////////   \n");
	printf("\n\n");
	printf("                                                                       *******   ** ******** **       ******** **      ** ********  ******** \n");
	printf("                                                                      /**////** //*/**///// /**      /**///// /**     /**/**/////  **//////  \n");
	printf("                                                                      /**    /** / /**      /**      /**      /**     /**/**      /**        \n");
	printf("                                                                      /**    /**   /******* /**      /******* //**    ** /******* /********* \n");
	printf("                                                                      /**    /**   /**////  /**      /**////   //**  **  /**////  ////////** \n");
	printf("                                                                      /**    **    /**      /**      /**        //****   /**             /** \n");
	printf("                                                                      /*******     /********/********/********   //**    /******** ********  \n");
	printf("                                                                      ///////      //////// //////// ////////     //     //////// ////////   \n");
	printf("\n\n");
	printf("                                                                                         ********  ********   ********  **  \n");
	printf("                                                                                        /**/////  **//////   **//////**/**  \n");
	printf("                                                                                        /**      /**        **      // /**  \n");
	printf("                                                                                        /******* /*********/**         /**  \n");
	printf("                                                                                        /**////  ////////**/**    *****/**  \n");
	printf("                                                                                        /**             /**//**  ////**/**  \n");
	printf("                                                                                        /******** ********  //******** /**  \n");
	printf("                                                                                        //////// ////////    ////////  //   \n\n\n\n");
	printf("                                                                      +--------------------------------------------------------------------+\n");
	printf("                                                                      |                        GESTIONNAIRE D'ELEVES                       |\n");
	printf("                                                                      +--------------------------------------------------------------------+\n");
	printf("                                                                      |  1-------------------- Lister les promotions   ------------------- |\n");
	printf("                                                                      |  2-------------------- Lister les élèves       ------------------- |\n");
	printf("                                                                      |  3-------------------- Ajouter un élève        ------------------- |\n");
	printf("                                                                      |  4-------------------- Supprimer un élève      ------------------- |\n");
	printf("                                                                      |  5-------------------- Modifier un élève       ------------------- |\n");
	printf("                                                                      |  6-------------------- Ajouter une note        ------------------- |\n");
	printf("                                                                      |  7-------------------- Détail d'un élève       ------------------- |\n");
	printf("                                                                      |  8-------------------- Charger ou Sauvegarder  ------------------- |\n");
	printf("                                                                      |  9-------------------- Quitter                 ------------------- |\n");
	printf("                                                                      +--------------------------------------------------------------------+\n\n\n\n\n");
	printf("\n\n");
	printf("Entrez votre choix : \n");
}
int menu(void)
{
	char *choix;
	int taille = 2;
	int choixFinal=0;
	choix =(char*)malloc(taille*sizeof(char));
	afficherMenu();	
	saisir(choix, taille);
	choixFinal = atoi(choix);
	while(choixFinal < 1 || choixFinal > 10)
	{ 	
		//afficherMenu();
		printf("Erreur  Veuillez saisir un chiffre entre 1 et 9...\n");
		saisir(choix, taille);
		choixFinal = atoi(choix);
	}
	free(choix);
	choix=NULL;
	return choixFinal;
}
int menuLister(void)
{
	char *choix;
	int taille = 2;
	int choixFinal=0;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("+-----------------------------------------------------------+\n");
	printf("| 1----------- Lister tous les élèves            -----------|\n");
	printf("| 2----------- Lister les élèves d'une promotion -----------|\n");
	printf("+-----------------------------------------------------------+\n\n\n\n\n\n\n\n\n");
	printf("Entrez votre choix : ");
	choix =(char*)malloc(taille*sizeof(char));	
	saisir(choix, taille);
	choixFinal = atoi(choix);
	while(choixFinal < 1 || choixFinal > 2)
	{ 	
		printf("Erreur  Veuillez saisir un chiffre entre 1 et 2...\n");
		saisir(choix, taille);
		choixFinal = atoi(choix);
	}
	free(choix);
	choix=NULL;
	return choixFinal;
}
int menuTrie(void)
{
	char *choix;
	int taille = 2;
	int choixFinal=0;
	choix =(char*)malloc(taille*sizeof(char));
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("+-----------------------------------------------------------+\n");
	printf("| 1------------------ Trier par nom       ------------------|\n");
	printf("| 2------------------ Trier par prenom    ------------------|\n");
	printf("| 3------------------ Trier par promotion ------------------|\n");
 	printf("| 4------------------ Trier par moyenne   ------------------|\n");
	printf("+-----------------------------------------------------------+\n\n\n\n\n\n\n\n\n\n");
	printf("Entrez votre choix : ");	
	saisir(choix, taille);
	choixFinal = atoi(choix);
	while(choixFinal < 1 || choixFinal > 4)
	{ 	
		printf("Erreur  Veuillez saisir un chiffre entre 1 et 4...\n");
		saisir(choix, taille);
		choixFinal = atoi(choix);
	}
	free(choix);
	choix=NULL;
	return choixFinal;
}
int menuTriePromo(void)
{
	char *choix;
	int taille = 2;
	int choixFinal=0;
	choix =(char*)malloc(taille*sizeof(char));
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("+-----------------------------------------------------------+\n");
	printf("| 1------------------ Trier par nom       ------------------|\n");
	printf("| 2------------------ Trier par prenom    ------------------|\n");
 	printf("| 3------------------ Trier par moyenne   ------------------|\n");
	printf("+-----------------------------------------------------------+\n\n\n\n\n\n\n\n\n\n");
	printf("Entrez votre choix : ");	
	saisir(choix, taille);
	choixFinal = atoi(choix);
	while(choixFinal < 1 || choixFinal > 3)
	{ 	
		printf("Erreur  Veuillez saisir un chiffre entre 1 et 4...\n");
		saisir(choix, taille);
		choixFinal = atoi(choix);
	}
	free(choix);
	choix=NULL;
	return choixFinal;
}
int menuAjouter(void)
{
	char *choix;
	int taille = 2;
	int choixFinal=0;
	choix =(char*)malloc(taille*sizeof(char));
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("+---------------------------------------------------------------+\n");
	printf("| 1----------- Ajouter une note à une promotion   --------------|\n");
	printf("| 2----------- Ajouter une note à tous les élèves --------------|\n");
	printf("+---------------------------------------------------------------+\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("Entrez votre choix : ");	
	saisir(choix, taille);
	choixFinal = atoi(choix);
	while(choixFinal < 1 || choixFinal > 3)
	{ 	
		printf("Erreur  Veuillez saisir un chiffre entre 1 et 2...\n");
		saisir(choix, taille);
		choixFinal = atoi(choix);
	}
	free(choix);
	choix=NULL;
	return choixFinal;
}
int menuMatiere(void)
{
	char *choix;
	int taille = 2;
	int choixFinal=0;
	choix =(char*)malloc(taille*sizeof(char));
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("+-----------------------------------------------------------+\n");
	printf("|              			    MATIERE                         |\n");
	printf("+-----------------------------------------------------------+\n");
	printf("| 1--------------------- Programmation ---------------------|\n");
	printf("| 2--------------------- Linux         ---------------------|\n");
	printf("| 3--------------------- Sécurité      ---------------------|\n");
 	printf("| 4--------------------- Réseau        ---------------------|\n");
	printf("+-----------------------------------------------------------+\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("Entrez votre choix : ");	
	saisir(choix, taille);
	choixFinal = atoi(choix);
	while(choixFinal < 1 || choixFinal > 4)
	{ 	
		printf("Erreur  Veuillez saisir un chiffre entre 1 et 2...\n");
		saisir(choix, taille);
		choixFinal = atoi(choix);
	}
	free(choix);
	choix=NULL;
	return choixFinal;
}
int menuChargerSauvegarder(void)
{
	char *choix;
	int taille = 2;
	int choixFinal=0;
	choix =(char*)malloc(taille*sizeof(char));
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("+-----------------------------------------------------------+\n");
	printf("| 1---------------------- Charger     ----------------------|\n");
	printf("| 2---------------------- Sauvegarder ----------------------|\n");
	printf("+-----------------------------------------------------------+\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("Entrez votre choix : ");	
	saisir(choix, taille);
	choixFinal = atoi(choix);
	while(choixFinal < 1 || choixFinal > 3)
	{ 	
		printf("Erreur  Veuillez saisir un chiffre entre 1 et 2...\n");
		saisir(choix, taille);
		choixFinal = atoi(choix);
	}
	free(choix);
	choix=NULL;
	return choixFinal;
}
void quitter(eleve** tabEleves, int compteurTab)
{
	freeTabEleves(tabEleves,compteurTab);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                                                           **     **     **   *******   ******** **      **   *******   ** *******  \n"); 
  	printf("                                                          ****   /**    /**  /**////** /**///// /**     /**  **/////** /**/**////** \n");
   	printf("                                                         **//**  /**    /**  /**   /** /**      /**     /** **     //**/**/**   /** \n");
 	printf("                                                        **  //** /**    /**  /*******  /******* //**    ** /**      /**/**/*******  \n");
	printf("                                                       **********/**    /**  /**///**  /**////   //**  **  /**      /**/**/**///**  \n");
	printf("                                                      /**//////**/**    /**  /**  //** /**        //****   //**     ** /**/**  //** \n");
	printf("                                                     /**      /**//*******   /**   //**/********   //**     //*******  /**/**   //**\n");
	printf("                                                     //       //  ///////    //     // ////////     //       ///////   // //     // \n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
void save(char* filename, eleve **tabEleves, int compteurTab)
{
	int i=0;
	int j=0;
	FILE *f;
	f=fopen(filename,"wb");
	if(f==NULL)
	{
		printf("Erreur d'ouverture du fichier.\n");
		return;
	}
	fprintf(f,"%d",compteurTab);
	fputs("\n",f);
	for(i=0;i<compteurTab;i++)
	{ 	
	fprintf(f,"%d",tabEleves[i]->id);
	fputs(":",f);
	fwrite(tabEleves[i]->nom,sizeof(char),strlen(tabEleves[i]->nom),f);
	fputs(":",f);
	fwrite(tabEleves[i]->prenom,sizeof(char),strlen(tabEleves[i]->prenom),f);
	fputs(":",f);
	fwrite(tabEleves[i]->promotion,sizeof(char),strlen(tabEleves[i]->promotion),f);
	fputs(":",f);
	fprintf(f,"%d",tabEleves[i]->matieres.nbNoteProg);
	fputs(":",f);
	if(tabEleves[i]->matieres.nbNoteProg!=0)
	{
		for(j=0;j<tabEleves[i]->matieres.nbNoteProg;j++)
		{
			fprintf(f,"%.2lf",tabEleves[i]->matieres.programmation[j]);
			fputs(":",f);
		}
	}
	else
	{
		fprintf(f,"NULL");
		fputs(":",f);
	}
	fprintf(f,"%d",tabEleves[i]->matieres.nbNoteLinux);
	fputs(":",f);
	if(tabEleves[i]->matieres.nbNoteLinux!=0)
	{
		for(j=0;j<tabEleves[i]->matieres.nbNoteLinux;j++)
		{
			fprintf(f,"%.2lf",tabEleves[i]->matieres.Linux[j]);
			fputs(":",f);
		}
	}
	else
	{
		fprintf(f,"NULL");
		fputs(":",f);
	}
	fprintf(f,"%d",tabEleves[i]->matieres.nbNoteSecu);
	fputs(":",f);
	if(tabEleves[i]->matieres.nbNoteSecu!=0)
	{
		for(j=0;j<tabEleves[i]->matieres.nbNoteSecu;j++)
		{
			fprintf(f,"%.2lf",tabEleves[i]->matieres.secu[j]);
			fputs(":",f);
		}
	}
	else
	{
		fprintf(f,"NULL");
		fputs(":",f);
	}
	fprintf(f,"%d",tabEleves[i]->matieres.nbNoteReseau);
	fputs(";",f);
	if(tabEleves[i]->matieres.nbNoteReseau!=0)
	{
		for(j=0;j<tabEleves[i]->matieres.nbNoteReseau;j++)
		{
			fprintf(f,"%.2lf",tabEleves[i]->matieres.reseau[j]);
			fputs(":",f);
		}
	}
	else
	{
		fprintf(f,"NULL");
		fputs(":",f);
	}
	fputs("\n",f);
	}
	fclose(f);	
}
eleve** load(char* filename, eleve **tabEleves, int* ptrCompteurTab)
{
	int i=0;
	int compteurTab=*ptrCompteurTab;
	char* buffer=NULL;
	char* token;
	FILE *f;
	if(*ptrCompteurTab!=0)
	{
		freeTabEleves(tabEleves, compteurTab);
	}
	f=fopen(filename,"rb");
	if(f==NULL)
	{
		printf("Erreur d'ouverture du fichier.\n");
		return NULL;
	}
	buffer=malloc(500*sizeof(char));
	fgets(buffer,500,f);
	*ptrCompteurTab=atoi(buffer);
	compteurTab=*ptrCompteurTab;
	tabEleves=(eleve**)malloc(compteurTab*sizeof(eleve*));
	for(i=0;i<compteurTab;i++)
	{
		fgets(buffer,500,f);
		token=strtok(buffer,":");
		tabEleves[i]=malloc(sizeof(eleve));
		tabEleves[i]->id=atoi(token);
		token=strtok(NULL,":");
		tabEleves[i]->nom=malloc((strlen(token)+1)*sizeof(char));
		strcpy(tabEleves[i]->nom, token);
		token=strtok(NULL,":");
		tabEleves[i]->prenom=malloc((strlen(token)+1)*sizeof(char));
		strcpy(tabEleves[i]->prenom, token);
		token=strtok(NULL,":");
		tabEleves[i]->promotion=malloc((strlen(token)+1)*sizeof(char));
		strcpy(tabEleves[i]->promotion, token);
		token=strtok(NULL,":");
		tabEleves[i]->matieres.nbNoteProg=atoi(token);
		if(tabEleves[i]->matieres.nbNoteProg==0)
		{
			token=strtok(NULL,":");
			tabEleves[i]->matieres.programmation=malloc(sizeof(double));
			tabEleves[i]->matieres.programmation=NULL;
		}
		else
		{
			tabEleves[i]->matieres.programmation=malloc((tabEleves[i]->matieres.nbNoteProg)*sizeof(double));
			for(int j=0;j<tabEleves[i]->matieres.nbNoteProg;j++)
			{
				token=strtok(NULL,":");
				tabEleves[i]->matieres.programmation[j]=atof(token);
			}
		}
		token=strtok(NULL,":");
		tabEleves[i]->matieres.nbNoteLinux=atoi(token);
		if(tabEleves[i]->matieres.nbNoteLinux==0)
		{
			token=strtok(NULL,":");
			tabEleves[i]->matieres.Linux=malloc(sizeof(double));
			tabEleves[i]->matieres.Linux=NULL;
		}
		else
		{
			tabEleves[i]->matieres.Linux=malloc((tabEleves[i]->matieres.nbNoteLinux)*sizeof(double));
			for(int j=0;j<tabEleves[i]->matieres.nbNoteLinux;j++)
			{
				token=strtok(NULL,":");
				tabEleves[i]->matieres.Linux[j]=atof(token);
			}
		}
		token=strtok(NULL,":");
		tabEleves[i]->matieres.nbNoteSecu=atoi(token);
		if(tabEleves[i]->matieres.nbNoteSecu==0)
		{
			token=strtok(NULL,":");
			tabEleves[i]->matieres.secu=malloc(sizeof(double));
			tabEleves[i]->matieres.secu=NULL;
		}
		else
		{
			tabEleves[i]->matieres.secu=malloc((tabEleves[i]->matieres.nbNoteSecu)*sizeof(double));
			for(int j=0;j<tabEleves[i]->matieres.nbNoteSecu;j++)
			{
				token=strtok(NULL,":");
				tabEleves[i]->matieres.secu[j]=atof(token);
			}
		}
		token=strtok(NULL,":");
		tabEleves[i]->matieres.nbNoteReseau=atoi(token);
		if(tabEleves[i]->matieres.nbNoteReseau==0)
		{
			token=strtok(NULL,":");
			tabEleves[i]->matieres.reseau=malloc(sizeof(double));
			tabEleves[i]->matieres.reseau=NULL;
		}
		else
		{
			tabEleves[i]->matieres.reseau=malloc((tabEleves[i]->matieres.nbNoteReseau)*sizeof(double));
			for(int j=0;j<tabEleves[i]->matieres.nbNoteReseau;j++)
			{
				token=strtok(NULL,":");
				tabEleves[i]->matieres.reseau[j]=atof(token);
			}
		}
	}
free(buffer);
buffer=NULL;
return tabEleves;
}
