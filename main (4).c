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

//4.Lista dei suggerimenti orizzontali
struct suggerimenti_o{
  int num_s;
  char suggerimento_o[D];
  struct suggerimenti_o *next;
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

//4.Lista dei suggerimenti verticali
struct suggerimenti_v{
  int num_s;
  char suggerimento_v[D];
  struct suggerimenti_v *next;
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
	//scanf("%[^\n]s", s); leggerà tutti i caratteri finché non raggiungerà \n o EOF e li inserisce in dom
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

    //1.1 Caricamento suggerimenti orizzontali da file txt suggerimenti_orizzontali.txt
    struct suggerimenti_o *carica_s_o(struct suggerimenti_o *testa){
	FILE *f=NULL;
	struct suggerimenti_o *s_o;
	int num_s;
	char suggerimento[D];
	
	f=fopen("suggerimenti_orizzontali.txt", "r");
	if( f==NULL ) {
		printf("Errore in apertura del file");
		exit(1);
	}
    //Effettuo un ciclo fino ad EOF ed alloco il puntatore s_o
    //Effettuo il caricamento dei dati in lista, uso strcpy poichè il file è composto oltre che da numeri da stringhe
	//scanf("%[^\n]s", s); leggerà tutti i caratteri finché non raggiungerà \n o EOF e li inserisce in suggerimento
	while(fscanf(f, "%d %[^\n]s\n", &num_s, suggerimento) != EOF){
		s_o = (struct suggerimenti_o*) malloc(sizeof(struct suggerimenti_o));	
		s_o->num_s=num_s;
		strcpy(s_o->suggerimento_o,suggerimento);    //La strcpy effettua una copia nel nodo suggerimenti_orizzontali
        s_o->next=testa;
        testa=s_o;  
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
    
    //2.1 Caricamento suggerimenti verticali da file txt suggerimenti_verticali.txt
    struct suggerimenti_v *carica_s_v(struct suggerimenti_v *testa){
	FILE *f=NULL;
	struct suggerimenti_v *s_v;
	int num_s;
	char suggerimento[D];
	
	f=fopen("suggerimenti_verticali.txt", "r");
	if( f==NULL ) {
		printf("Errore in apertura del file");
		exit(1);
	}
    //Effettuo un ciclo fino ad EOF ed alloco il puntatore s_v
    //Effettuo il caricamento dei dati in lista, uso strcpy poichè il file è composto oltre che da numeri da stringhe
	//scanf("%[^\n]s", s); leggerà tutti i caratteri finché non raggiungerà \n o EOF e li inserisce in suggerimento
	while(fscanf(f, "%d %[^\n]s\n", &num_s, suggerimento) != EOF){
		s_v = (struct suggerimenti_v*) malloc(sizeof(struct suggerimenti_v));	
		s_v->num_s=num_s;
		strcpy(s_v->suggerimento_v,suggerimento);    //La strcpy effettua una copia nel nodo suggerimenti_v
        s_v->next=testa;
        testa=s_v;  
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
    struct risposte_utente_v *r_utente_v(struct risposte_utente_v *testa,  struct risposte_verticali *head){
    struct risposte_utente_v *r_u_v;
    struct risposte_verticali *r_v;
    r_v=head;
    int n, r_u, r_s, n_r;
    char c[R];
   
    r_u_v=(struct risposte_utente_v*)malloc(sizeof(struct risposte_utente_v));
    printf("Inserisci il numero della risposta seguito dalla risposta:\nEsempio-> 1 Risposta\n>>");
    scanf("%d %s", &n, c);
    r_u=strlen(c);
    
    //Controllo la lunghezza della risposta inserita e se coincidente con la risposta corretta
    //la inserisco in lista
   
    while(r_v!=NULL){
        n_r=r_v->num_risposta;
        r_s=strlen(r_v->risposta);
        r_v=r_v->next;
        
            if(n==n_r && r_u==r_s){
            strcpy(r_u_v->risposta,c);
            r_u_v->num_risposta=n;
        //    printf("%d %d %d %s\n",r_u, r_s, n, c);
            break;
            }
    } 
            if(n!=n_r && r_u!=r_s) printf("Il numero di caratteri inserito non è valido, perfavore ricontrolla.");
    
    strcpy(r_u_v->risposta,c);      
    r_u_v->num_risposta=n; 
    r_u_v->next=testa;
    testa=r_u_v;  
    return r_u_v;
    }
    
    //6.Inizializzazione lista risposte_utente_o con risposte utente
    struct risposte_utente_o *r_utente_o(struct risposte_utente_o *testa, struct risposte_orizzontali *head){
    struct risposte_utente_o *r_u_o;
    struct risposte_orizzontali *r_o;
    r_o=head;
    int n, r_u, r_s, n_r;
    char c[R];
    
    r_u_o=(struct risposte_utente_o*)malloc(sizeof(struct risposte_utente_o));
    printf("Inserisci il numero della risposta seguito dalla risposta:\nEsempio-> 1 Risposta\n>>");
    scanf("%d %s", &n, c);
    r_u=strlen(c);
    
    //Controllo la lunghezza della risposta inserita e se coincidente con la risposta corretta
    //la inserisco in lista
   
    while(r_o!=NULL){
        n_r=r_o->num_risposta;
        r_s=strlen(r_o->risposta);
        r_o=r_o->next;
        
            if(n==n_r && r_u==r_s){
            strcpy(r_u_o->risposta,c);
            r_u_o->num_risposta=n;
         //   printf("%d %d %d %s\n",r_u, r_s, n, c);
            break;
            }
    } 
            if(n!=n_r && r_u!=r_s) printf("Il numero di caratteri inserito non è valido, perfavore ricontrolla.");
            
    r_u_o->next=testa;
    testa=r_u_o;  
    return r_u_o;
    }
    
    void stampa_griglia_o(struct risposte_utente_o *testa){
    struct risposte_utente_o *r_u_o;
    r_u_o=testa;
    int i;
    char c[R];
    
    while(r_u_o!=NULL){
        strcpy(c, r_u_o->risposta);
        
        for(i=0;i<8;i++){
        printf("|");
        printf("%s", c);
        printf("|");
        break;
        }   
    }

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
    void confronto_r_o(struct risposte_orizzontali *testa, struct risposte_utente_o *head){
        struct risposte_utente_o *r_u_o;
        r_u_o=head;
        struct risposte_orizzontali *r_o;
        r_o=testa;
        int confronto, i;
        
        for(i=0;i<15;i++){
            confronto=strcmp(r_u_o->risposta, r_o->risposta); 
            // printf("%s %s\n",r_u_o->risposta, r_o->risposta);
            
            while(confronto==0){
              r_o->num_risposta=0;
              return;
              break; 
            }
            r_o=r_o->next;
        }
        
        
    }

    //10.Funzione di confronto verticali.
    //Il confronto delle risposte avviene tra quelle inserite dall'utente e quelle presenti nella 
    //rispettiva lista delle verticali. Se risposta coincidente (quindi se strcmp=0 per stringhe identiche)
    //sostituirà il numero della domanda con uno 0 nella lista delle risposte verticali
    void confronto_r_v(struct risposte_verticali *testa, struct risposte_utente_v *head){
        struct risposte_utente_v *r_u_v;
        r_u_v=head;
        struct risposte_verticali *r_v;
        r_v=testa;
        int confronto, i;
        

        for(i=0;i<15;i++){
            confronto=strcmp(r_u_v->risposta, r_v->risposta); 
            // printf("%s %s\n",r_u_v->risposta, r_v->risposta);
            
            while(confronto==0){
              r_v->num_risposta=0;
              return;
              break; 
            }
            r_v=r_v->next;
             
        }
    }
    
    //11.Funzione di verifica finale dell'intero cruciverba. 
    //Facendo scorrere i due puntatori alla testa delle liste r_o(risposte orizzontali) e r_v(risposte verticali)
    //se nel numero della risposta è presente 0 allora effettua la stampa del cruciverba completato
    //altrimenti stampa le domande sbagliate.
    void verifica(struct risposte_orizzontali *testa, struct risposte_verticali *head){
        struct risposte_orizzontali *r_o;
        struct risposte_verticali *r_v;
        r_o=testa;
        r_v=head;
        int i;
        
         for(i=0;i<15;i++){
            if(r_o->num_risposta!=0){
            printf("Hai sbagliato la %d° definizione orizzontale\n",r_o->num_risposta);  
            }
            r_o=r_o->next; 
         }
         
         for(i=0;i<13;i++){
            if(r_v->num_risposta!=0){
            printf("Hai sbagliato la %d° definizione verticale\n",r_v->num_risposta);  
            }
            r_v=r_v->next; 
         }
    }
     
     //12.Suggerimenti orizzontali all'utente
     //L'utente ha a disposizione 3 suggerimenti terminati i quali non avrà più possibilità di richiedere aiuto.
     //Al termine dei tentativi verrà avvisato l'utente.
     int tips_orizz(int a, int tentativi_o, struct suggerimenti_o *testa){
	     struct suggerimenti_o *s_o;
	     s_o=testa;
	     int b, i;
	     char suggerimento_o[D];
	
        while(s_o!=NULL){
            b=s_o->num_s;
            strcpy(suggerimento_o, s_o->suggerimento_o);
            s_o=s_o->next;
                
            if(a==b && tentativi_o>0 && tentativi_o<=3){
                tentativi_o=tentativi_o-1; 
                printf("%d %d %s\n",a, b, suggerimento_o);
                printf("\nHai ancora a disposizione %d tentativi/o", tentativi_o);
                return tentativi_o;
            }
        }printf("\nHai terminato i tentativi a disposizione!");
        
     }
    
     //13.Suggerimenti verticali all'utente
     //L'utente ha a disposizione 3 suggerimenti terminati i quali non avrà più possibilità di richiedere aiuto.
     //Al termine dei tentativi verrà avvisato l'utente.
     int tips_vert(int b, int tentativi_v, struct suggerimenti_v *testa){
	     struct suggerimenti_v *s_v;
	     s_v=testa;
	     int c, i;
	     char suggerimento_v[D];
	
        while(s_v!=NULL){
            c=s_v->num_s;
            strcpy(suggerimento_v, s_v->suggerimento_v);
            s_v=s_v->next;
                
            if(b==c && tentativi_v>0 && tentativi_v<=3){
                tentativi_v=tentativi_v-1; 
                printf("%d %d %s\n",b, c, suggerimento_v);
                printf("\nHai ancora a disposizione %d tentativi/o", tentativi_v);
                return tentativi_v;
            }
        }printf("\nHai terminato i tentativi a disposizione!");
     } 
     
     void salva_o(struct risposte_utente_o *testa){
        struct risposte_utente_o *r_u;
        r_u=testa;
        FILE *f=NULL;
        int i;
        
        f=fopen("salva_o.txt", "w");
        if(f==NULL){
        printf("Errore in apertura del file");
        }
        
        while(r_u!=NULL){
            fprintf(f, "%d %s\n", r_u->num_risposta, r_u->risposta);
            r_u=r_u->next;
        }
        fclose(f);
        
     }
     
     void salva_v(struct risposte_utente_v *testa){
        struct risposte_utente_v *r_v;
        r_v=testa;
        FILE *f=NULL;
        int i;
        
        f=fopen("salva_v.txt", "w");
        if(f==NULL){
        printf("Errore in apertura del file");
        }
        
        while(r_v!=NULL){
            fprintf(f, "%d %s\n", r_v->num_risposta, r_v->risposta);
            r_v=r_v->next;
        }
        fclose(f);
       
     }
     
    struct risposte_utente_o *caricamento_f_o(struct risposte_utente_o *testa){
	FILE *f=NULL;
	struct risposte_utente_o *r_u_o;
	int num;
	char ris[R];
	
	f=fopen("salva_o.txt", "r");
	if( f==NULL ) {
		printf("Errore in apertura del file");
		exit(1);
	}
    
	while(fscanf(f, "%d %[^\n]s\n", &num, ris) != EOF){
		r_u_o = (struct risposte_utente_o*) malloc(sizeof(struct risposte_utente_o));	
		r_u_o->num_risposta=num;
		strcpy(r_u_o->risposta,ris);      
        r_u_o->next=testa;
        testa=r_u_o;  
	}
	fclose(f);
	return testa;
    }
    
    struct risposte_utente_v *caricamento_f_v(struct risposte_utente_v *testa){
	FILE *f=NULL;
	struct risposte_utente_v *r_u_v;
	int num;
	char ris[R];
	
	f=fopen("salva_v.txt", "r");
	if( f==NULL ) {
		printf("Errore in apertura del file");
		exit(1);
	}
    
	while(fscanf(f, "%d %[^\n]s\n", &num, ris) != EOF){
		r_u_v = (struct risposte_utente_v*) malloc(sizeof(struct risposte_utente_v));	
		r_u_v->num_risposta=num;
		strcpy(r_u_v->risposta,ris);      
        r_u_v->next=testa;
        testa=r_u_v;  
	}
	fclose(f);
	return testa;
    }

    void menu(int scelta){
        struct domande_orizzontali *d_o = NULL;     //puntatore alla testa della lista delle domande orizzontali
        struct suggerimenti_o *s_o = NULL;          //puntatore alla testa della lista dei suggerimenti orizzontali
        struct domande_verticali *d_v = NULL;       //puntatore alla testa della lista delle domande verticali
        struct suggerimenti_v *s_v = NULL;          //puntatore alla testa della lista dei suggerimenti verticali
        struct risposte_orizzontali *r_o = NULL;    //puntatore alla testa della lista delle risposte orizzontali
        struct risposte_verticali *r_v = NULL;      //puntatore alla testa della lista delle risposte verticali
        struct risposte_utente_o *r_u_o=NULL;       //puntatore alla testa della lista delle risposte utente orizzontali
        struct risposte_utente_v *r_u_v=NULL;       //puntatore alla testa della lista delle risposte utente verticali
        int a, b, inserimento;
        int tentativi_o=3;
        int tentativi_v=3;
        
        d_o = carica_o(d_o);    //Funzione 1
	   // s_o = carica_s_o(s_o);  //Funzione 1.1
	    d_v = carica_v(d_v);    //Funzione 2
	   // s_v = carica_s_v(s_v);  //Funzione 2.2
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
            printf("\n7. Salva i tuoi progressi");
            printf("\n8. Esci            ");
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
                r_u_o = r_utente_o(r_u_o, r_o);          //Funzione 6
                stampa_griglia_o(r_u_o);
                confronto_r_o(r_o, r_u_o);
                break;
                
            case 3:
                r_u_v=r_utente_v(r_u_v, r_v);            //Funzione 5
                confronto_r_v(r_v, r_u_v);
                break;
    
            case 4:
              printf("Inserisci il numero della domanda cui hai bisogno di aiuto\nRicorda: Hai a disposizione 3 suggerimenti\n>>");
              scanf("%d", &a);
                tentativi_o = tips_orizz(a ,tentativi_o, s_o);        //Funzione 12
            break;
    
            case 5:
                printf("Inserisci il numero della domanda cui hai bisogno di aiuto\nRicorda: Hai a disposizione 3 suggerimenti\n>>");
                scanf("%d", &b);
                tentativi_v = tips_vert(b, tentativi_v, s_v);         //Funzione 13
                break;
   
            case 6:
              verifica(r_o, r_v);                              //Funzione 11
            break;
    
            case 7:
                salva_o(r_u_o);
                salva_v(r_u_v);
                printf("I tuoi progressi sono stati salvati con successo!");
               
            break;
            
            case 8:
                exit(1);
            break;
            
            default: 
                printf("Scelta non disponibile!");
            break;
        }    
	    }
        
    }
    
int main (){
    struct risposte_utente_o *r_f_o=NULL;  
    struct risposte_utente_v *r_f_v=NULL;
    int scelta;
    
    
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
                    printf ("*************************\n");
                    printf ("     Menù Principale     \n");
                    printf ("                         \n");
                    printf (" 1. Inizia nuova partita \n");
                    printf (" 2. Carica partita       \n");
                    printf (" 3. Esci                 \n");
                    printf ("                         \n");
                    printf ("*************************\n");
                    printf (">>");
                    scanf ("%d", &scelta);

switch(scelta){
        
    case 1:
        menu(scelta);
    break;
    
    case 2:
        r_f_o=caricamento_f_o(r_f_o);
        r_f_v=caricamento_f_v(r_f_v);
        menu(scelta);
        break;
    
    case 3:
        exit(1);
        break;
        
    default: 
        printf("Scelta non disponibile!");
        break;
}
}



