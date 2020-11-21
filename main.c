#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define D 1000
#define R 50
//DEFINIZIONE DELLE LISTE

//ORIZZONTALI
//1.Lista delle domande 
struct domande_orizzontali{
    int num_domanda;
    char domanda[D];
    struct domande_orizzontali *next;
};

//2.Lista delle risposte 
struct risposte_orizzontali{
  int num_risposta;
  char risposta[R];
  struct risposte_orizzontali *next;
};

//3.Lista delle risposte inserite dall'utente
struct risposte_utente_o{
  int num_risposta;
  char risposta[R];
  struct risposte_utente_o *next;
};

//VERTICALI
//1.Lista delle domande 
struct domande_verticali{
    int num_domanda;
    char domanda[D];
    struct domande_verticali *next;
};

//2.Lista delle risposte 
struct risposte_verticali{
  int num_risposta;
  char risposta[R];
  struct risposte_verticali *next;
};

//3.Lista delle risposte inserite dall'utente
struct risposte_utente_v{
  int num_risposta;
  char risposta[R];
  struct risposte_utente_v *next;
};
   
    //FUNZIONI UTILI AL FUNZIONAMENTO DEL PROGRAMMA 
    
    //1.Caricamento domande orizzontali da file txt domande_orizzontali.txt
    struct domande_orizzontali *carica_o(struct domande_orizzontali *testa){
	FILE *f=NULL;
	struct domande_orizzontali *d_o;
	int num;
	char dom[D];
	
	f=fopen("domande_orizzontali.txt", "r");
	if( f==NULL ) {
		printf("Errore in apertura del file");
		exit(1);
	}
    //Effettuo un ciclo fino ad EOF ed alloco il puntatore d_o
    //Effettuo il caricamento dei dati in lista, uso strcpy poichè il file è composto oltre che da numeri da stringhe
	//scanf("%[^\n]", s); leggerà tutti i caratteri finché non raggiungerà \n o EOF e li inserisce in dom
	while(fscanf(f, "%d %[^\n]s\n", &num, dom) != EOF){
		d_o = (struct domande_orizzontali*) malloc(sizeof(struct domande_orizzontali));	
		d_o->num_domanda=num;
		strcpy(d_o->domanda,dom);    //La strcpy effettua una copia nel nodo domanda
        d_o->next=testa;
        testa=d_o;  
	}
	fclose(f);
	return testa;
}
    //2.Caricamento domande verticali da file txt domande_verticali.txt
    struct domande_verticali *carica_v(struct domande_verticali *testa){
	FILE *f=NULL;
	struct domande_verticali *d_v;
	int num;
	char dom[D];
	
	f=fopen("domande_verticali.txt", "r");
	if( f==NULL ) {
		printf("Errore in apertura del file");
		exit(1);
	}
    //Effettuo un ciclo fino ad EOF ed alloco il puntatore d_v
    //Effettuo il caricamento dei dati in lista, uso strcpy poichè il file è composto oltre che da numeri da stringhe
	//scanf("%[^\n]", s); leggerà tutti i caratteri finché non raggiungerà \n o EOF e li inserisce in dom
	while(fscanf(f, "%d %[^\n]s\n", &num, dom) != EOF){
		d_v = (struct domande_verticali*) malloc(sizeof(struct domande_verticali));	
		d_v->num_domanda=num;
		strcpy(d_v->domanda,dom);       //La strcpy effettua una copia nel nodo domanda
        d_v->next=testa;
        testa=d_v;  
	}
	fclose(f);
	return testa;
    }
    
    //3.Caricamento risposte orizzontali da file txt risposte_orizzontali.txt
    struct risposte_orizzontali *carica_r_o(struct risposte_orizzontali *testa){
    	FILE *f=NULL;
	    struct risposte_orizzontali *r_o;
	    int num;
	    char ris[R];
	    
	    f=fopen("risposte_orizzontali.txt", "r");
	    if( f==NULL ) {
	    	printf("Errore in apertura del file");
	    	exit(1);
	    }
	    
    	while(fscanf(f, "%d %s\n", &num, ris) != EOF){
		r_o = (struct risposte_orizzontali*) malloc(sizeof(struct risposte_orizzontali));	
		r_o->num_risposta=num;
		strcpy(r_o->risposta,ris);      //La strcpy effettua una copia nel nodo risposta
        r_o->next=testa;
        testa=r_o;
	    }
	fclose(f);
	return testa;
    }
    
    //4.Caricamento risposte verticali da file txt risposte_verticali.txt
    struct risposte_verticali *carica_r_v(struct risposte_verticali *testa){
    	FILE *f=NULL;
	    struct risposte_verticali *r_v;
	    int num;
	    char ris[R];
	    
	    f=fopen("risposte_verticali.txt", "r");
	    if( f==NULL ) {
	    	printf("Errore in apertura del file");
	    	exit(1);
	    }
	    
    	while(fscanf(f, "%d %s\n", &num, ris) != EOF){
		r_v = (struct risposte_verticali*) malloc(sizeof(struct risposte_verticali));	
		r_v->num_risposta=num;
		strcpy(r_v->risposta,ris);      //La strcpy effettua una copia nel nodo risposta
        r_v->next=testa;
        testa=r_v;
	    }
	fclose(f);
	return testa;
    }
    
    //5.Inizializzazione lista risposte_utente_v con risposte utente 
    struct risposte_utente_v *r_utente_v(struct risposte_utente_v *testa){
    struct risposte_utente_v *r_u_v;
    struct risposte_verticali *r_v;
    int n, confronto, i;
    char c[R];
   
    r_u_v=(struct risposte_utente_v*)malloc(sizeof(struct risposte_utente_v));
    printf("Inserisci il numero della risposta seguito dalla risposta:\nEsempio-> 1 Risposta\n>>");
    scanf("%d %s", &n, c);
    strcpy(r_u_v->risposta,c);      
    r_u_v->num_risposta=n; 
    r_u_v->next=testa;
    testa=r_u_v;  
    return r_u_v;
    }
    
    //6.Inizializzazione lista risposte_utente_o con risposte utente
    struct risposte_utente_o *r_utente_o(struct risposte_utente_o *testa){
    struct risposte_utente_o *r_u_o;
    struct risposte_orizzontali *r_o;
    int n, confronto, i;
    char c[R];
   
    r_u_o=(struct risposte_utente_o*)malloc(sizeof(struct risposte_utente_o));
    printf("Inserisci il numero della risposta seguito dalla risposta:\nEsempio-> 1 Risposta\n>>");
    scanf("%d %s", &n, c);
    strcpy(r_u_o->risposta,c);
    r_u_o->num_risposta=n; 
    r_u_o->next=testa;
    testa=r_u_o;  
    return r_u_o;
    }
    
    //7.Funzione di stampa delle domande orizzontali (richiamata nello switch case 1)
    void stampa_d_o(struct domande_orizzontali *testa){
	    struct domande_orizzontali* temp;
	    temp = testa;
	    
	    if(temp == NULL){       //Se il puntatore non punterà a nulla allora stamperà la frase
		    printf("Nessun valore letto dal file");
		    return;
	    }else
	    
		while (temp!=NULL){     //Mentre il puntatore scorre l'intera lista effettua la stampa
			printf("\nDomanda orizzontale n° %d : %s", temp->num_domanda, temp->domanda);
		    temp=temp->next;
		}
    }
    
    //8.Funzione di stampa delle domande verticali (richiamata nello switch case 1)
     void stampa_d_v(struct domande_verticali *testa){
	    struct domande_verticali *temp;
	    temp = testa;
	    
	    if(temp == NULL){
		    printf("Nessun valore letto dal file");
		    return;
	    }else
	    
		while (temp!=NULL){
			printf("\nDomanda verticale n° %d : %s", temp->num_domanda, temp->domanda);
		    temp=temp->next;
		}
    }
    
    //9.Funzione di confronto orizzontali.
    //Il confronto delle risposte avviene tra quelle inserite dall'utente e quelle presenti nella 
    //rispettiva lista delle orizzontali. Se risposta coincidente (quindi se strcmp=0 per stringhe identiche)
    //sostituirà il numero della domanda con uno 0 nella lista delle risposte orizzontali
    void confronto_r_o(struct risposte_orizzontali *testa){
        struct risposte_utente_o *r_u_o;
        struct risposte_orizzontali *r_o;
        r_o=testa;
        int n, confronto, i;
        char c[R];

        while(r_o!=NULL){
        confronto=strcmp(r_u_o->risposta, r_o->risposta); 
           
            if (confronto==0){
              r_o->num_risposta=0;
              r_o=r_o->next;
              break; 
            }else(r_o=NULL);
        }
    }
    //10.Funzione di confronto verticali.
    //Il confronto delle risposte avviene tra quelle inserite dall'utente e quelle presenti nella 
    //rispettiva lista delle verticali. Se risposta coincidente (quindi se strcmp=0 per stringhe identiche)
    //sostituirà il numero della domanda con uno 0 nella lista delle risposte verticali
    void confronto_r_v(struct risposte_verticali *testa){
        struct risposte_utente_v *r_u_v;
        struct risposte_verticali *r_v;
        r_v=testa;
        int n, confronto, i;
        char c[R];

        while(r_v!=NULL){
        confronto=strcmp(r_u_v->risposta, r_v->risposta); 
           
            if (confronto==0){
            r_v->num_risposta=0;
              r_v=r_v->next;
              break; 
            }else(r_v=NULL);
            
        }
    }
    
    //11.Funzione di verifica finale dell'intero cruciverba. 
    //Facendo scorrere i due puntatori alla testa delle liste r_o(risposte orizzontali) e r_v(risposte verticali)
    //se nel numero della risposta è presente 0 allora effettua la stampa del cruciverba completato
    //altrimenti stampa le domande sbagliate.
    void verifica(struct risposte_orizzontali *v_o, struct risposte_verticali *v_v){
        struct risposte_orizzontali *r_o;
        struct risposte_verticali *r_v;
        r_o=v_o;
        r_v=v_v;
        int i;
            if((r_o->num_risposta==0) && (r_v->num_risposta==0)){
            printf("Hai completato il cruciverba!\n\n");
  printf ("  _____ _____ _____ _____ _____ _____ _____ _____ _____ \n");
  printf (" |1    |2    |3    |4    |     |5    |6    |7    |     |\n");
  printf (" |  F  |  R  |  A  |  N  |  C  |  E  |  S  |  E  |  *  |\n");
  printf (" |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
  printf (" |8    |     |     |     |     |9    |     |     |10   |\n");
  printf (" |  R  |  E  |  N  |  O  |  *  |  R  |  A  |  N  |  A  |\n");
  printf (" |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
  printf (" |11   |     |     |12   |13   |     |     |     |     |\n");
  printf (" |  A  |  S  |  *  |  I  |  P  |  E  |  R  |  *  |  S  |\n");
  printf (" |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
  printf (" |14   |     |15   |     |     |     |     |     |     |\n");
  printf (" |  N  |  I  |  T  |  R  |  A  |  T  |  O  |  *  |  S  |\n");
  printf (" |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
  printf (" |16   |     |     |     |17   |     |     |18   |     |\n");
  printf (" |  C  |  S  |  I  |  *  |  R  |  T  |  *  |  F  |  I  |\n");
  printf (" |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
  printf (" |19   |     |     |     |     |     |20   |     |     |\n");
  printf (" |  E  |  T  |  N  |  O  |  L  |  O  |  G  |  I  |  A  |\n");
  printf (" |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
  printf (" |21   |     |     |     |     |     |22   |     |     |\n");
  printf (" |  S  |  E  |  T  |  *  |  A  |  *  |  A  |  S  |  L  |\n");
  printf (" |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
  printf (" |23   |     |     |24   |     |25   |     |26   |     |\n");
  printf (" |  C  |  R  |  A  |  U  |  T  |  I  |  *  |  S  |  E  |\n");
  printf (" |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
  printf (" |27   |     |     |28   |     |     |     |     |     |\n");
  printf (" |  O  |  E  |  *  |  V  |  O  |  L  |  T  |  O  |  *  |\n");
  printf (" |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
            
       }else{
           for(i=0;i<15;i++){
             if(r_o->num_risposta!=0){
                printf("Hai sbagliato la %d° definizione orizzontale\n",r_o->num_risposta);
               }
               r_o=r_o->next; 
              
           } 
          
            for(i=0;i<14;i++){
             if(r_v->num_risposta!=0){
                printf("Hai sbagliato la %d° definizione verticale\n",r_v->num_risposta);
               }
               r_v=r_v->next; 
           } 
       }
    }
     
     //12.Suggerimenti orizzontali all'utente
     //L'utente ha a disposizione 3 suggerimenti terminati i quali non avrà più possibilità di richiedere aiuto.
     //Al termine dei tentativi verrà avvisato l'utente.
     int tips_orizz(int a, int tentativi_o){
          if(tentativi_o<=3 && tentativi_o>0){
              switch(a){
            case 1: 
            printf("\nE' una lingua appartenente al gruppo delle lingue romanze della famiglia delle lingue indoeuropee.");
            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_o);
            break;
            case 8: 
            printf("\nLa lettera iniziale è 'R'");
         
            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_o);
            break;
            case 9: 
            printf("Hai davvero bisogno di aiuto? è un anfibio.");
            
             printf("\nHai ancora a disposizione %d tentativi/o",tentativi_o);
            break;
            case 11: 
            printf("\nNome identico al primo uomo frutto della creazione del cristianesimo");
        
            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_o);
            break;
            case 12: 
            printf("\nSuperlativo assoluto");
 
            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_o);
            break;
            case 14: 
            printf("NO3-");

              printf("\nHai ancora a disposizione %d tentativi/o",tentativi_o);
            break;
            case 16: 

            printf("Crime Scene Investigation");
            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_o);
            break;
            case 17: 

            printf("Tip Non disponibile");
             printf("\nHai ancora a disposizione %d tentativi/o",tentativi_o);
            break;
            case 18: 
            printf("\nSigla provincia");

            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_o);
            break;
            case 19: 
            printf("\nDal greco ********: popolo");

            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_o);
            break;
            case 21: 
            printf("\nSerie, gruppo");

            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_o);
            break;
            case 22: 
            printf("\nAcronimo");

            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_o);
            break;
            case 23: 
            printf("\nOttenuto dal cavolo cappuccio, tagliato finemente e sottoposto a fermentazione lattica.");

            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_o);
            break;
            case 26: 
            printf("Tip Non disponibile");

            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_o);
            break;
            case 27: 
            printf("Tip Non disponibile");

            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_o);
            break;
            case 28: 
            printf("\nSinonimo di viso.");

             printf("\nHai ancora a disposizione %d tentativi/o",tentativi_o);
            break;
            default: 
            printf("Scelta non disponibile!");
             printf("\nHai ancora a disposizione %d tentativi/o",tentativi_o);
            break;   
                }
            tentativi_o=tentativi_o-1; 
             return tentativi_o;
          }else{
             printf("Hai terminato i tentativi a disposizione!!");   
            }
           
    }
    
     //13.Suggerimenti verticali all'utente
     //L'utente ha a disposizione 3 suggerimenti terminati i quali non avrà più possibilità di richiedere aiuto.
     //Al termine dei tentativi verrà avvisato l'utente.
     int tips_vert(int b,int tentativi_v){
          if(tentativi_v<=3 && tentativi_v>0){
         switch(b){
            case 1: 
            printf("\nInizia 'F'.");
            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_v);
            break;
            case 2: 
            printf("\nSinonimo di reggere.");
            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_v);
            break;
            case 3: 
            printf("\nTip Non Disponibile.");
            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_v);
            break;
            case 4: 
            printf("\nNero in francese.");
            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_v);
            break;
            case 5: 
            printf("\nIn botanica, di organo che presenti una evidente disposizione verticale.");
            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_v);
            break;
            case 6: 
            printf("\nSarò senza accento.");
            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_v);
            break;
            case 7: 
            printf("\nTip Non Disponibile.");
            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_v);
            break;
            case 10: 
            printf("\nForza applicata secondo l'asse.");
            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_v);
            break;
            case 13: 
            printf("\nFornito di colonna sonora.");
            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_v);
            break;
            case 15: 
            printf("\nTip Non Disponibile.");
            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_v);
            break;
            case 18: 
            printf("\nIninterrottamente e ossessivamente presente.");
            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_v);
            break;
            case 20: 
            printf("\nTip Non Disponibile.");
            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_v);
            break;
            case 24: 
            printf("\nE' un intervallo della radiazione elettromagnetica.");
            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_v);
            break;
            case 25: 
            printf("\nTip Non Disponibile.");
            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_v);
            break;
            default: 
            printf("Scelta non disponibile!");
            printf("\nHai ancora a disposizione %d tentativi/o",tentativi_v);
            break;
         }
            tentativi_v=tentativi_v-1; 
             return tentativi_v;
          }else{
             printf("\nHai terminato i tentativi a disposizione!");   
            }
           
    }


int main (){
    struct domande_orizzontali *d_o = NULL;     //puntatore alla testa della lista delle domande orizzontali
    struct domande_verticali *d_v = NULL;       //puntatore alla testa della lista delle domande verticali
    struct risposte_orizzontali *r_o = NULL;    //puntatore alla testa della lista delle risposte orizzontali
    struct risposte_verticali *r_v = NULL;      //puntatore alla testa della lista delle risposte verticali
    struct risposte_utente_o *r_u_o=NULL;       //puntatore alla testa della lista delle risposte utente orizzontali
    struct risposte_utente_v *r_u_v=NULL;       //puntatore alla testa della lista delle risposte utente verticali
    int inserimento, a, b, scelta;
    int tentativi_o=3;
    int tentativi_v=3;
    char risposta_o[R], c, nome[R];
    
    printf("                                                                                                    \n");
    printf("                                           ****       ***\n");
    printf("                                           ****       ***\n");
    printf("                                           ****       ***\n");
    printf("                                           ****       ***\n");
    printf("                                           ****       ***\n");        
    printf("                                           ****       ***\n");       
    printf("                                           ****       *******\n");      
    printf("                                           ****       *******\n\n\n");
    printf("\n");
    printf("  *********  *******   ***   ***   *********  ****  ****     ****  *********  *******   ********   *********\n");
    printf("  *********  ********  ***   ***   *********  ****  ****     ****  *********  ********  *********  *********\n");
    printf("  ****       **    **  ***   ***   ****       ****  ****     ****  ***        **    **  ***     ** ***   ***\n");
    printf("  ****       ********  ***   ***   ****       ****  ****     ****  *********  ********  ***    **  ***   ***\n");
    printf("  ****       ********  ***   ***   ****       ****  ****     ****  *********  ********  ********   *********\n");
    printf("  ****       **   ***  ***   ***   ****       ****   ****   ****   ***        **   ***  ***     ** ***   ***\n");
    printf("  *********  **    **  *********   *********  ****    **** ****    *********  **    **  ********** ***   ***\n");
    printf("  *********  **    **  *********   *********  ****      ****       *********  **    **  *********  ***   ***\n");
    printf("                                                                                                  \n");
            printf ("\n\nVuoi continuare? S/N\n");
		    printf (">>  ");
		    scanf ("%c", &c);  
		        if (c == 'S' || c== 's'){   

                    printf ("*************************\n");
                    printf ("           Menù          \n");
                    printf ("                         \n");
                    printf (" 1. Inizia gioco         \n");
                    printf (" 2. Esci                 \n");
                    printf ("                         \n");
                    printf ("*************************\n");
                    printf (">>");
                    scanf ("%d", &scelta);
                }else if (c == 'N' || c == 'n'){
                    exit(1);
                    }else if (c !='S' || c !='s' || c != 'N' || c != 'n'){
		                printf("Scelta non disponibile!");
		                return 0;
                    }
    

switch(scelta){
    case 1:
        d_o = carica_o(d_o);    //Funzione 1
	    d_v = carica_v(d_v);    //Funzione 2
	    r_o = carica_r_o(r_o);  //Funzione 3
	    r_v = carica_r_v(r_v);  //Funzione 4
    
    while(1){
    printf("\n\n************************************");
    printf ("\n               Menù                \n");
    printf("\n1. Visualizza domande");
    printf("\n2. Inserisci definizione orizzontale");
    printf("\n3. Inserisci definizione verticale");
    printf("\n4. Suggerimenti orizzontali");
    printf("\n5. Suggerimenti verticali");
    printf("\n6. Verifica cruciverba");
    printf("\n7. Esci            ");
    printf("\n");
    printf("\n************************************");
    printf("\n>> ");
    scanf("%d", &inserimento);

        switch (inserimento){
    
            case 1:
                printf ("  _____ _____ _____ _____ _____ _____ _____ _____ _____ \n");
                printf (" |1    |2    |3    |4    |     |5    |6    |7    |     |\n");
                printf (" |     |     |     |     |     |     |     |     |  *  |\n");
                printf (" |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
                printf (" |8    |     |     |     |     |9    |     |     |10   |\n");
                printf (" |     |     |     |     |  *  |     |     |     |     |\n");
                printf (" |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
                printf (" |11   |     |     |12   |13   |     |     |     |     |\n");
                printf (" |     |     |  *  |     |     |     |     |  *  |     |\n");
                printf (" |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
                printf (" |14   |     |15   |     |     |     |     |     |     |\n");
                printf (" |     |     |     |     |     |     |     |  *  |     |\n");
                printf (" |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
                printf (" |16   |     |     |     |17   |     |     |     |     |\n");
                printf (" |     |     |     |  *  |     |     |  *  |     |     |\n");
                printf (" |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
                printf (" |19   |     |     |     |     |     |20   |     |     |\n");
                printf (" |     |     |     |     |     |     |     |     |     |\n");
                printf (" |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
                printf (" |21   |     |     |     |     |     |22   |     |     |\n");
                printf (" |     |     |     |  *  |     |  *  |     |     |     |\n");
                printf (" |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
                printf (" |23   |     |     |24   |     |25   |     |26   |     |\n");
                printf (" |     |     |     |     |     |     |  *  |     |     |\n");
                printf (" |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
                printf (" |27   |     |     |28   |     |     |     |     |     |\n");
                printf (" |     |     |  *  |     |     |     |     |     |  *  |\n");
                printf (" |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n"); 
        
                printf("\n************************************************\n");
                printf("                  ORIZZONTALI                   \n");
                printf("************************************************\n");
	            stampa_d_o(d_o);            //Funzione 7
	    
	            printf("\n\n\n************************************************\n");
                printf("                    VERTICALI                    \n");
                printf("************************************************\n");
	            stampa_d_v(d_v);            //Funzione 8
                break;
                
            case 2:
                r_u_o = r_utente_o(r_u_o);   //Funzione 6
                confronto_r_o(r_o);          //Funzione 9
                break;
                
            case 3:
                r_u_v=r_utente_v(r_u_v);    //Funzione 5
                confronto_r_v(r_v);         //Funzione 10
                break;
    
            case 4:
                printf("Inserisci il numero della domanda cui hai bisogno di aiuto\nRicorda: Hai a disposizione 3 suggerimenti\n>>");
                scanf("%d", &a);
                tentativi_o = tips_orizz(a, tentativi_o);        //Funzione 12
            break;
    
            case 5:
                printf("Inserisci il numero della domanda cui hai bisogno di aiuto\nRicorda: Hai a disposizione 3 suggerimenti\n>>");
                scanf("%d", &b);
                tentativi_v = tips_vert(b, tentativi_v);         //Funzione 13
                break;
   
            case 6: 
                verifica(r_o, r_v);                              //Funzione 11
            break;
    
            case 7: 
                exit(1);
            break;
    
            default: 
                printf("Scelta non disponibile!");
            break;
        }
}
    case 2:
        exit(1);
        break;
    
    default: 
        printf("Scelta non disponibile!");
        break;
}
}
