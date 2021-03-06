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
   
    //FUNZIONI UTILI AL PROGRAMMA

    //Caricamento domande orizzontali da file txt domande_orizzontali.txt
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

    //Caricamento suggerimenti orizzontali da file txt suggerimenti_orizzontali.txt
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

    //Caricamento domande verticali da file txt domande_verticali.txt
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
    
    //Caricamento suggerimenti verticali da file txt suggerimenti_verticali.txt
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
    
    //Caricamento risposte orizzontali da file txt risposte_orizzontali.txt
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
    
    //Caricamento risposte verticali da file txt risposte_verticali.txt
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
    
    //Funzione di stampa della griglia
    //se orientamento==0 stampo risposte orizzontali
    //se orientamento==1 stampo risposte verticali
    //incroci è un vettore che contiene tutti i punti da cui parto per inserire la risposta
    char stampa_griglia(char griglia[60][60],int n, char c[R], int r_s, int orientamento){
        int i, j=0;
        int incroci[28][2] = {{2,4},{2,10},{2,16},{2,22},{2,34},{2,40},{2,46},{5,4},{5,34},{5,52},{8,4},{8,22},{8,28},{11,4},{11,16},{14,4},{14,28},{14,46},{17,4},{17,40},{20,4},{20,40},{23,4},{23,22},{23,34},{23,46},{26,4},{26,22}};
    
        if(orientamento==0){
            for(int i=0; i<r_s; i++){
	        griglia[incroci[n-1][0]][incroci[n-1][1]+j] = c[i];
	        j=j+6;
            } 
        }else if(orientamento==1){
            for(int i=0; i<r_s; i++){
	        griglia[incroci[n-1][0]+j][incroci[n-1][1]] = c[i];
	        j=j+3;
            } 
        }
        
        for(int i=0; i<60; i++){
                for(int j=0; j<60; j++){
                printf("%c",griglia[i][j]);
                }
        } 
    }
    
     //Funzione di confronto orizzontali.
    //Il confronto delle risposte avviene tra quelle inserite dall'utente e quelle presenti nella 
    //rispettiva lista delle orizzontali. Se risposta coincidente (quindi se strcmp=0 per stringhe identiche)
    //sostituirà il numero della domanda con uno 0 nella lista delle risposte orizzontali
    void confronto_r_o(char griglia[60][60],struct risposte_orizzontali *testa, struct risposte_utente_o *head, int n, char c[R], int orientamento){
        struct risposte_utente_o *r_u_o;
        r_u_o=head;
        struct risposte_orizzontali *r_o;
        r_o=testa;
        int confronto, i,a, b;
        
        for(i=0;i<16;i++){
            confronto=strcmp(r_u_o->risposta, r_o->risposta); 
            a=strlen(r_u_o->risposta);
            b=strlen(r_o->risposta);
            //printf("%d %s %d %s\n",a, r_u_o->risposta, b ,r_o->risposta);
           
            
            while(r_o->num_risposta==n && a==b){
                while(confronto==0){
                r_o->num_risposta=0;   
                break;
                }
            stampa_griglia(griglia, n, c, b, orientamento);
            return;
            }
            r_o=r_o->next;
        }
        if(a!=b){
            printf("ATTENZIONE, il numero dei caratteri inseriti non è valido");
            return;
        }
        
       
    }


    //Funzione di confronto verticali.
    //Il confronto delle risposte avviene tra quelle inserite dall'utente e quelle presenti nella 
    //rispettiva lista delle verticali. Se risposta coincidente (quindi se strcmp=0 per stringhe identiche)
    //sostituirà il numero della domanda con uno 0 nella lista delle risposte verticali
    void confronto_r_v(char griglia[60][60],struct risposte_verticali *testa, struct risposte_utente_v *head, int n, char c[R], int orientamento){
        struct risposte_utente_v *r_u_v;
        r_u_v=head;
        struct risposte_verticali *r_v;
        r_v=testa;
        int confronto, i, a, b;
        
        for(i=0;i<14;i++){
            confronto=strcmp(r_u_v->risposta, r_v->risposta); 
            a=strlen(r_u_v->risposta);
            b=strlen(r_v->risposta);
            // printf("%s %s\n",r_u_v->risposta, r_v->risposta);
            
             while(r_v->num_risposta==n && a==b){
                while(confronto==0){
                r_v->num_risposta=0;   
                break;
                }
            stampa_griglia(griglia, n, c, b, orientamento);
            return;
            }
            r_v=r_v->next;
        }
        if(a!=b){
            printf("ATTENZIONE, il numero dei caratteri inseriti non è valido");
            return;
        }
    }
    
    //Inizializzazione lista risposte_utente_o con risposte utente
    struct risposte_utente_o* r_utente_o(char griglia[60][60],struct risposte_utente_o *testa, struct risposte_orizzontali *head){
    struct risposte_utente_o *r_u_o;
    struct risposte_orizzontali *r_o;
    r_o=head;
    int n;
    char c[R];
    int orientamento=0;     //orientamento risposte 0=orizzontali
    
    r_u_o=(struct risposte_utente_o*)malloc(sizeof(struct risposte_utente_o));
    if(!r_u_o) printf("Errore di allocazione di memoria");
    printf("Inserisci il numero della risposta seguito dalla risposta:\nEsempio-> 1 Risposta\n>>");
    scanf("%d %s", &n, c);
    while(getchar() != '\n');
    strcpy(r_u_o->risposta,c);
    r_u_o->num_risposta=n;
    confronto_r_o(griglia, r_o, r_u_o, n, c, orientamento);
    r_u_o->next=testa;
    testa=r_u_o;  
    return r_u_o;
    }
    
    //Inizializzazione lista risposte_utente_v con risposte utente 
    struct risposte_utente_v* r_utente_v(char griglia[60][60],struct risposte_utente_v *testa, struct risposte_verticali *head){
    struct risposte_utente_v *r_u_v;
    struct risposte_verticali *r_v;
    r_v=head;
    int n=0, r_u=0, r_s=0, n_r=0;
    char c[R];
    int orientamento=1;     //orientamento risposte 1=verticali
    
    r_u_v=(struct risposte_utente_v*)malloc(sizeof(struct risposte_utente_v));
     if(!r_u_v) printf("Errore di allocazione di memoria");
    printf("Inserisci il numero della risposta seguito dalla risposta:\nEsempio-> 1 Risposta\n>>");
    scanf("%d %s", &n, c);
    while(getchar() != '\n');
    strcpy(r_u_v->risposta,c);
    r_u_v->num_risposta=n;
    confronto_r_v(griglia, r_v, r_u_v, n, c, orientamento);
    r_u_v->next=testa;
    testa=r_u_v;  
    return r_u_v;
    }
    
    //Funzione di stampa delle domande orizzontali
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

    //Funzione di stampa delle domande verticali
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
    
    //Suggerimenti orizzontali all'utente
    //L'utente ha a disposizione 3 suggerimenti terminati i quali non avrà più possibilità di richiedere aiuto.
    //Al termine dei tentativi verrà avvisato l'utente.
    int tips_orizz(int a, int tentativi_o, struct suggerimenti_o *testa){
	     struct suggerimenti_o *s_o;
	     s_o=testa;
	     int b=0, i=0;
	     char suggerimento_o[D];
	
        while(s_o!=NULL){
            b=s_o->num_s;
            strcpy(suggerimento_o, s_o->suggerimento_o);
            s_o=s_o->next;
                
            if(a==b && tentativi_o>0 && tentativi_o<=3){
                tentativi_o=tentativi_o-1; 
                printf("%d %s\n", b, suggerimento_o);
                printf("\nHai ancora a disposizione %d tentativi/o", tentativi_o);
                return tentativi_o;
            }
        }printf("\nHai terminato i tentativi a disposizione!");
        
     }
    
     //Suggerimenti verticali all'utente
     //L'utente ha a disposizione 3 suggerimenti terminati i quali non avrà più possibilità di richiedere aiuto.
     //Al termine dei tentativi verrà avvisato l'utente.
     int tips_vert(int b, int tentativi_v, struct suggerimenti_v *testa){
	     struct suggerimenti_v *s_v;
	     s_v=testa;
	     int c=0, i=0;
	     char suggerimento_v[D];
	
        while(s_v!=NULL){
            c=s_v->num_s;
            strcpy(suggerimento_v, s_v->suggerimento_v);
            s_v=s_v->next;
                
            if(b==c && tentativi_v>0 && tentativi_v<=3){
                tentativi_v=tentativi_v-1; 
                printf("%d %s\n",c, suggerimento_v);
                printf("\nHai ancora a disposizione %d tentativi/o", tentativi_v);
                return tentativi_v;
            }
        }printf("\nHai terminato i tentativi a disposizione!");
     } 
     
    //Funzione di verifica finale dell'intero cruciverba. 
    //Facendo scorrere i due puntatori alla testa delle liste r_o(risposte orizzontali) e r_v(risposte verticali)
    //se nel numero della risposta è presente 0 allora effettua la stampa del cruciverba completato
    //altrimenti stampa le domande sbagliate.
    void verifica(char griglia[60][60],struct risposte_orizzontali *testa, struct risposte_verticali *head){
        struct risposte_orizzontali *r_o;
        struct risposte_verticali *r_v;
        r_o=testa;
        r_v=head;
        int i=0;
        
         for(i=0;i<16;i++){
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
        
        while(r_o!=NULL && r_v!=NULL){
            if(r_o->num_risposta==0 && r_v->num_risposta==0){
                printf("HAI COMPLETATO IL CRUCIVERBA!");
                for(int i=0; i<60; i++){
                    for(int j=0; j<60; j++){
                    printf("%c",griglia[i][j]);
                    }
                } 
                return;
            }
        }
    }
    
    
    //FUNZIONI DI SALVATAGGIO
    
    //Funzione di salvataggio delle risposte utente orizzontali 
    //in file di txt salva_r_u_o
    void salva_r_u_o(struct risposte_utente_o *testa){
        struct risposte_utente_o *r_u_o;
        r_u_o=testa;
        FILE *f=NULL;
        
        f=fopen("salva_r_u_o.txt", "w");
        if(f==NULL){
        printf("Errore in apertura del file");
        }
        
        while(r_u_o!=NULL){
            fprintf(f, "%d %s\n", r_u_o->num_risposta, r_u_o->risposta);
            r_u_o=r_u_o->next;
        }
        fclose(f);
        
     }
     
    //Funzione di salvataggio delle risposte orizzontali
    //in file di txt salva_r_o    
     void salva_r_o(struct risposte_orizzontali *testa){
        struct risposte_orizzontali *r_o;
        r_o=testa;
        FILE *f=NULL;

        
        f=fopen("salva_r_o.txt", "w");
        if(f==NULL){
        printf("Errore in apertura del file");
        }
        
        while(r_o!=NULL){
            fprintf(f, "%d %s\n", r_o->num_risposta, r_o->risposta);
            r_o=r_o->next;
        }
        fclose(f);
        
     }
    
    //Funzione di salvataggio delle risposte utente verticali 
    //in file di txt salva_r_u_v
    void salva_r_u_v(struct risposte_utente_v *testa){
        struct risposte_utente_v *r_u_v;
        r_u_v=testa;
        FILE *f=NULL;
        
        f=fopen("salva_r_u_v.txt", "w");
        if(f==NULL){
        printf("Errore in apertura del file");
        }
        
        while(r_u_v!=NULL){
            fprintf(f, "%d %s\n", r_u_v->num_risposta, r_u_v->risposta);
            r_u_v=r_u_v->next;
        }
        fclose(f);
       
     }
     
    //Funzione di salvataggio delle risposte verticali
    //in file di txt salva_r_v 
    void salva_r_v(struct risposte_verticali *testa){
        struct risposte_verticali *r_v;
        r_v=testa;
        FILE *f=NULL;
        
        f=fopen("salva_r_v.txt", "w");
        if(f==NULL){
        printf("Errore in apertura del file");
        }
        
        while(r_v!=NULL){
            fprintf(f, "%d %s\n", r_v->num_risposta, r_v->risposta);
            r_v=r_v->next;
        }
        fclose(f);
       
    }
    
    //Funzione di salvataggio stato della griglia 
    //su file di txt salva_griglia
    void salva_griglia(char griglia[60][60]){
        FILE *f=NULL;
        int i=0,j=0;
        
        f=fopen("salva_griglia.txt", "w");
        if(f==NULL){
        printf("Errore in apertura del file");
        }
        
        for(int i=0; i<60; i++){
                for(int j=0; j<60; j++){
                fprintf(f, "%c",griglia[i][j]);
                }
        } 
        fclose(f);    
    }
    
    //FUNZIONI DI CARICAMENTO
     
    //Caricamento risposte utente orizzontali da file txt salva_r_u_o
    struct risposte_utente_o* caricamento_r_u_o(struct risposte_utente_o *testa){
	FILE *f=NULL;
	struct risposte_utente_o *r_u_o;
	int num;
	char ris[R];
	
	f=fopen("salva_r_u_o.txt", "r");
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
    
    //Caricamento risposte orizzontali da file txt salva_r_o
    struct risposte_orizzontali* caricamento_r_o(struct risposte_orizzontali *testa){
	FILE *f=NULL;
	struct risposte_orizzontali *r_o;
	int num;
	char ris[R];
	
	f=fopen("salva_r_o.txt", "r");
	if( f==NULL ) {
		printf("Errore in apertura del file");
		exit(1);
	}
    
	while(fscanf(f, "%d %[^\n]s\n", &num, ris) != EOF){
		r_o = (struct risposte_orizzontali*) malloc(sizeof(struct risposte_orizzontali));	
		r_o->num_risposta=num;
		strcpy(r_o->risposta,ris);      
        r_o->next=testa;
        testa=r_o;  
	}
	fclose(f);
	return testa;
    }
    
    //Caricamento risposte utente verticali da file txt salva_r_u_v
    struct risposte_utente_v* caricamento_r_u_v(struct risposte_utente_v *testa){
	FILE *f=NULL;
	struct risposte_utente_v *r_u_v;
	int num;
	char ris[R];
	
	f=fopen("salva_r_u_v.txt", "r");
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
    
    //Caricamento risposte verticali da file txt salva_r_v
    struct risposte_verticali* caricamento_r_v(struct risposte_verticali *testa){
	FILE *f=NULL;
	struct risposte_verticali *r_v;
	int num;
	char ris[R];
	
	f=fopen("salva_r_v.txt", "r");
	if( f==NULL ) {
		printf("Errore in apertura del file");
		exit(1);
	}
    
	while(fscanf(f, "%d %[^\n]s\n", &num, ris) != EOF){
		r_v = (struct risposte_verticali*) malloc(sizeof(struct risposte_verticali));	
		r_v->num_risposta=num;
		strcpy(r_v->risposta,ris);      
        r_v->next=testa;
        testa=r_v;  
	}
	fclose(f);
	return testa;
    }
    
    //Caricamento stato griglia da file txt salva_griglia
    char carica_griglia(char griglia[60][60]){
        FILE *f=NULL;
        char aggiornamento[60][60];
        int i=0,j=0;;
        
        f=fopen("salva_griglia.txt", "r");
        if(f==NULL){
        printf("Errore in apertura del file");
        }
            for(int i=0; i<60; i++){
                for(int j=0; j<60; j++){
                    fscanf(f, "%c",&aggiornamento[i][j]) != EOF;
                    printf("%c",aggiornamento[i][j]);
                    griglia[i][j]=aggiornamento[i][j];
                }
            }   
            return griglia[60][60];
        fclose(f);    
    }
    
    //FUNZIONE MENU'
    void menu(int flag, char griglia[60][60]){
        struct domande_orizzontali *d_o = NULL;     //puntatore alla testa della lista delle domande orizzontali
        struct suggerimenti_o *s_o = NULL;          //puntatore alla testa della lista dei suggerimenti orizzontali
        struct domande_verticali *d_v = NULL;       //puntatore alla testa della lista delle domande verticali
        struct suggerimenti_v *s_v = NULL;          //puntatore alla testa della lista dei suggerimenti verticali
        struct risposte_orizzontali *r_o = NULL;    //puntatore alla testa della lista delle risposte orizzontali
        struct risposte_verticali *r_v = NULL;      //puntatore alla testa della lista delle risposte verticali
        struct risposte_utente_o *r_u_o=NULL;       //puntatore alla testa della lista delle risposte utente orizzontali
        struct risposte_utente_v *r_u_v=NULL;       //puntatore alla testa della lista delle risposte utente verticali
        struct risposte_utente_o *r_f_u_o=NULL;     //puntatore alla testa della lista delle risposte utente orizzontali
        struct risposte_utente_v *r_f_u_v=NULL;     //puntatore alla testa della lista delle risposte utente verticali
        int a, b, inserimento;
        int tentativi_o=3;
        int tentativi_v=3;

        //Caricamento domande,risposte e suggerimenti
        d_o = carica_o(d_o);    
	    s_o = carica_s_o(s_o);  
	    d_v = carica_v(d_v);   
	    s_v = carica_s_v(s_v);  
	    
	    if(flag==0){
	        r_o = carica_r_o(r_o); 
	        r_v = carica_r_v(r_v);      
	    }else{
	        r_f_u_o=caricamento_r_u_o(r_f_u_o);
            r_f_u_v=caricamento_r_u_v(r_f_u_v);
	        r_o=caricamento_r_o(r_o);
	        r_v=caricamento_r_v(r_v);
	        carica_griglia(griglia);
	    }
	    
    
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
            while(getchar() != '\n');
    
	        switch (inserimento){
    
            case 1:
                printf("\n************************************************\n");
                printf("                  ORIZZONTALI                   \n");
                printf("************************************************\n");
	            stampa_d_o(d_o);            
	    
	            printf("\n\n\n************************************************\n");
                printf("                    VERTICALI                    \n");
                printf("************************************************\n");
	            stampa_d_v(d_v);       
                break;
                
            case 2:
                r_u_o = r_utente_o(griglia,r_u_o, r_o);         
                break;
                
            case 3:
                r_u_v = r_utente_v(griglia, r_u_v, r_v);           
                break;
    
            case 4:
                printf("Inserisci il numero della domanda cui hai bisogno di aiuto\nRicorda: Hai a disposizione 3 suggerimenti\n>>");
                scanf("%d", &a);
                while(getchar() != '\n');
                tentativi_o = tips_orizz(a ,tentativi_o, s_o);     
            break;
    
            case 5:
                printf("Inserisci il numero della domanda cui hai bisogno di aiuto\nRicorda: Hai a disposizione 3 suggerimenti\n>>");
                scanf("%d", &b);
                while(getchar() != '\n');
                tentativi_v = tips_vert(b, tentativi_v, s_v);     
                break;
   
            case 6:
              verifica(griglia,r_o, r_v);                      
            break;
    
            case 7:
                salva_r_u_o(r_u_o);
                salva_r_o(r_o);
                salva_r_u_v(r_u_v);
                salva_r_v(r_v);
                salva_griglia(griglia);
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
    int scelta;
    int flag;
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
                    while(getchar() != '\n');
    char griglia[60][60] = {
    "  _____ _____ _____ _____ _____ _____ _____ _____ _____ \n",
    " |1    |2    |3    |4    |     |5    |6    |7    |     |\n",
    " |     |     |     |     |     |     |     |     |  *  |\n",
    " |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n",
    " |8    |     |     |     |     |9    |     |     |10   |\n",
    " |     |     |     |     |  *  |     |     |     |     |\n",
    " |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n",
    " |11   |     |     |12   |13   |     |     |     |     |\n",
    " |     |     |  *  |     |     |     |     |  *  |     |\n",
    " |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n",
    " |14   |     |15   |     |     |     |     |     |     |\n",
    " |     |     |     |     |     |     |     |  *  |     |\n",
    " |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n",
    " |16   |     |     |     |17   |     |     |18   |     |\n",
    " |     |     |     |  *  |     |     |  *  |     |     |\n",
    " |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n",
    " |19   |     |     |     |     |     |20   |     |     |\n",
    " |     |     |     |     |     |     |     |     |     |\n",
    " |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n",
    " |21   |     |     |     |     |     |22   |     |     |\n",
    " |     |     |     |  *  |     |  *  |     |     |     |\n",
    " |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n",
    " |23   |     |     |24   |     |25   |     |26   |     |\n",
    " |     |     |     |     |     |     |  *  |     |     |\n",
    " |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n",
    " |27   |     |     |28   |     |     |     |     |     |\n",
    " |     |     |  *  |     |     |     |     |     |  *  |\n",
    " |_____|_____|_____|_____|_____|_____|_____|_____|_____|\n"
    };

switch(scelta){
        
    case 1:
        flag=0;
        menu(flag, griglia);
    break;
    
    case 2:
        flag=1;
        menu(flag, griglia);
        break;
    
    case 3:
        exit(1);
        break;
        
    default: 
        printf("Scelta non disponibile!\n");
        break;
}
}