#ifndef _BETA2_H_
#define _BETA2_H_

typedef struct matieres matieres;
struct matieres
{
	int nbNoteProg;
	double *programmation;
	int nbNoteLinux;
	double *Linux;
	int nbNoteSecu;
	double *secu;
	int nbNoteReseau;
	double *reseau;	
};

typedef struct eleve eleve;
struct  eleve
{
	int id;
	char *nom;
	char *prenom;
	char *promotion;
	matieres matieres;
};
//----------------Menu---------------------------------
void afficherMenu(void);
int menu(void);
int menuLister(void);
int menuTrie(void);
int menuTriePromo(void);
int menuAjouter(void);
int menuMatiere(void);
int menuChargerSauvegarder(void);
void quitter(eleve** tabEleves, int compteurTab);
void save(char* filename, eleve **tabEleves, int compteurTab);
eleve** load(char* filename, eleve **tabEleves, int* ptrCompteurTab);
//----------------Operateurs---------------------------
int saisir(char *chaine, int longueur);
void viderBuffer();
int verifchiffre(char *string);
int verifLettre(char *string);
int verifchiffreEtLettre(char *string);
int verifId(eleve **tabEleves, int choixId, int compteurTab);
int verifPromo(eleve **tabEleves,char *buffPromo, int compteurTab);
void pause(void);
double moyenne(eleve *tabEleves);
void freeTabEleves(eleve** tabEleves, int compteurTab);
//----------------Eleves-------------------------------
eleve* createEleve(int compteurId);
int delEleve(eleve **tabEleves, int compteurTab);
int modif(eleve **tabEleves, int compteurTab);
int ajouterNote(eleve **tabEleves, int compteurTab);
int ajouterNoteTlm(eleve **tabEleves, int compteurTab);
//----------------Trie---------------------------------
void listerEleves(eleve **tabEleves, int compteurTab);
int details(eleve **tabEleves, int compteurTab);
int listerPromo(eleve **tabEleves, int compteurTab);
int trie(eleve **tabEleves, int nb, int compteurTab);
int extract(eleve **tabEleves, int nb ,int compteurTab);
#endif
