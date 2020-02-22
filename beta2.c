#include "beta2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{	
	eleve **tabEleves;
	int choixMenu=0;
	int choixSousMenu=0;
	int choixSousMenu1=0;
	int choixSousMenu2=0;
	int compteurTab=0;
	int compteurId=0;
	int* ptrCompteurTab;
	ptrCompteurTab=&compteurTab;
	tabEleves=(eleve**)malloc(sizeof(eleve*));

	while(choixMenu!=9)
	{ 	
		choixMenu=menu();
			if(choixMenu==1)
			{ 
				//####Lister les promotions####
				listerPromo(tabEleves, compteurTab);
			}
			if(choixMenu==2)
			{ 	//####Lister les élèves####
				choixSousMenu=menuLister();
				if(choixSousMenu==1)
				{ 	//----Lister tous les élèves----
					choixSousMenu1=menuTrie();
					if(choixSousMenu1==1)
					{ 	//====Trier par nom===
						trie(tabEleves, 1, compteurTab);
					}					
					if(choixSousMenu1==2)
					{	//====Trier par prenom====
						trie(tabEleves, 2, compteurTab);
					} 
					if(choixSousMenu1==3)
					{	//====Trier par promotion====
						trie(tabEleves, 3, compteurTab);
					}	
					if(choixSousMenu1==4)
					{ 	//====Trier par nom moyenne====
						trie(tabEleves, 4, compteurTab);
					}					
				}
				if(choixSousMenu==2)
				{ 	//----Lister les élèves d'une promotion-----
					choixSousMenu=menuTriePromo();
					if(choixSousMenu==1)
					{ 	//====Trier par nom==== 
						//listerEleves(tabEleves, compteurTab);
						extract(tabEleves, 1, compteurTab);
					
					}	
					if(choixSousMenu==2)
					{ 	//====Trier par prenom====
						extract(tabEleves, 2, compteurTab);
					}	
					if(choixSousMenu==3)
					{ 	//====Trier par moyenne====
						extract(tabEleves, 4, compteurTab);
					}			
			    }
			}    
			if(choixMenu==3)
			{ 	//####Ajouter un élève####	
				compteurId++;
				tabEleves=realloc(tabEleves,(compteurTab+1)*sizeof(eleve*));
				tabEleves[compteurTab]=createEleve(compteurId);
				compteurTab++;
			}
			if(choixMenu==4)
			{ 	//####Supprimer un élève####
				if(delEleve(tabEleves, compteurTab)!=1)
				{ 	
					compteurTab--;
				}
			}
			if(choixMenu==5)
			{ 	//####Modifier un élève####
				modif(tabEleves, compteurTab);
			}
			if(choixMenu==6)
			{ 	//####Ajouter une note##### 
				choixSousMenu=menuAjouter();
				if(choixSousMenu==1)
				{	//----Par Promotion----
					ajouterNote(tabEleves, compteurTab);
				}
				if(choixSousMenu==2)
				{	//----A tous les eleves----
					ajouterNoteTlm(tabEleves, compteurTab);
				}
			}
			if(choixMenu==7)
			{ 	//####Détail d'un élève (à ajouter les matieres et moyenne des matieres)
				details(tabEleves, compteurTab);
			}
			if(choixMenu==8)
			{ 	//####Charger Sauvegarder (à ajouter chiffrer et dechiffrer)
				choixSousMenu2=menuChargerSauvegarder();
				if(choixSousMenu2==1)
				{
					// Charger
					tabEleves=load("saved.txt", tabEleves, ptrCompteurTab);
				}
				if(choixSousMenu2==2)
				{
					// Sauvegarder
					save("saved.txt", tabEleves, compteurTab);
				}
			}	
			if(choixMenu==9)
			{ 	//####Quitter (à ajouter un GIF ou ascii art)
				quitter(tabEleves,compteurTab);
			}
	}
	return 0;
}
