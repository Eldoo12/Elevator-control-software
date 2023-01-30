#ifndef ADMINPANEL_H_INCLUDED
#define ADMINPANEL_H_INCLUDED
#include <time.h>
#include <Windows.h>

struct Nosilo {
    char naziv[256];
    int brojSpratova;
    int maxKoristenja;
    int brojKoristenja;
    int aktivirano; /* 0 deaktivirano  1 aktivirano*/
};
void novi_korisnik ()
{
    char email[256];
    char sifra[256];

    // unos podataka
    printf("Unesite email: ");
    scanf("%s", email);
    printf("Unesite sifru: ");
    scanf("%s", sifra);

    // otvori fajl za pisanje (append mode)
    FILE *fajl = fopen("korisnik.dat", "a");
    if (fajl == NULL) {
        printf("Greska prilikom otvaranja fajla!");
        return 1;
    }

    // upis podataka u fajl
    fprintf(fajl, "\n%s\n%s\n", email, sifra);

    // zatvori fajl
    fclose(fajl);

    printf("Podaci su  upisani u fajl.");

    return 0;
}
/*------------------------------------------ */


void kreiraj_novo_nosila()
{
       struct Nosilo nosilo;
    printf("Unesite naziv nosila: ");
    scanf("%s", nosilo.naziv);
    printf("Unesite broj spratova: ");
    scanf("%d", &nosilo.brojSpratova);
    printf("Unesite maksimalni broj koristenja: ");
    scanf("%d", &nosilo.maxKoristenja);
    printf("Unesite broj koristenja nakon servisa: ");
    scanf("%d", &nosilo.brojKoristenja);

    FILE *datoteka = fopen("nosilo.dat", "ab");
    if (datoteka == NULL) {
        printf("Greska pri otvaranju datoteke!\n");
        return;
    }
    fwrite(&nosilo, sizeof(struct Nosilo), 1, datoteka);
    fclose(datoteka);
}
/*----------------------------------------------*/

void pretrazi_datoteku(char *naziv) {
    FILE *datoteka = fopen("nosilo.dat", "rb");
    if (datoteka == NULL) {
        printf("Greska pri otvaranju datoteke!\n");
        return;
    }
    struct Nosilo nosilo;
    while (fread(&nosilo, sizeof(struct Nosilo), 1, datoteka) == 1) {
        if (strcmp(nosilo.naziv, naziv) == 0) {
            printf("Naziv nosila: %s\n", nosilo.naziv);
            printf("Broj spratova: %d\n", nosilo.brojSpratova);
            printf("Maksimalni broj koristenja: %d\n", nosilo.maxKoristenja);
            printf("Broj koristenja nakon servisa: %d\n", nosilo.brojKoristenja);
            printf("Aktivirano: %d\n", nosilo.aktivirano);

             break;
        }
    }

    fclose(datoteka);

}


void nosila_za_servis() {
int broj;
FILE *file = fopen("nosilo.dat", "r+b");
if (file == NULL) {
printf("Greska pri otvaranju datoteke!\n");
return;
}

struct Nosilo nosilo;
pocetak:
fseek(file, 0, SEEK_SET); // postavi pokazivac na pocetak datoteke
while (fread(&nosilo, sizeof(struct Nosilo), 1, file) == 1) {
    if (nosilo.brojKoristenja > nosilo.maxKoristenja) {
        printf("\nNaziv nosila: %s\n", nosilo.naziv);
        printf("Broj koristenja: %d\n", nosilo.brojKoristenja);
        printf("Maksimalni broj koristenja: %d\n", nosilo.maxKoristenja);

        printf("Ako zelite resetovati ovaj lift unesite broj jedan: ");
        scanf("%d", &broj);
        if (broj == 1) {
            nosilo.brojKoristenja = 0;
            fseek(file, -sizeof(struct Nosilo), SEEK_CUR); // vrati pokazivac na prethodnu poziciju
            fwrite(&nosilo, sizeof(struct Nosilo), 1, file);
            printf("Lift je resetovan\n");
            goto pocetak;
        }
    }
}

fclose(file);
}







void ispis_nosila() {
    FILE *datoteka = fopen("nosilo.dat", "rb");
    if (datoteka == NULL) {
        printf("Greska pri otvaranju datoteke!\n");
        return;
    }

    struct Nosilo nosilo;
    while (fread(&nosilo, sizeof(struct Nosilo), 1, datoteka) == 1) {
        printf("Naziv nosila: %s\n", nosilo.naziv);
        printf("Broj spratova: %d\n", nosilo.brojSpratova);
        printf("Maksimalni broj koristenja: %d\n", nosilo.maxKoristenja);
        printf("Broj koristenja nakon servisa: %d\n", nosilo.brojKoristenja);
        printf("---------------------------------\n");
    }

    fclose(datoteka);
}

void blokirana_nosila (){
    FILE *datoteka = fopen("nosilo.dat", "rb");
    if (datoteka == NULL) {
        printf("Greska pri otvaranju datoteke!\n");
        return;
    }
    struct Nosilo nosilo;
    while (fread(&nosilo, sizeof(struct Nosilo), 1, datoteka) == 1) {
    if(nosilo.brojKoristenja >= nosilo.maxKoristenja + 10) {
        printf("Naziv nosila: %s\n", nosilo.naziv);
        printf("Broj spratova: %d\n", nosilo.brojSpratova);
        printf("Maksimalni broj koristenja: %d\n", nosilo.maxKoristenja);
        printf("Broj koristenja nakon servisa: %d\n", nosilo.brojKoristenja);
        printf("---------------------------------\n");
    }
}

fclose(datoteka);

}




/*----------------------------------------------------- KORISNIK --------------------------------------------------------------------------*/




void aktivacija_nosila (char *naziv)
{
        FILE *datoteka = fopen("nosilo.dat", "rb+");
    if (datoteka == NULL) {
        printf("Greska pri otvaranju datoteke!\n");
        return;
    }
    struct Nosilo nosilo;
    while (fread(&nosilo, sizeof(struct Nosilo), 1, datoteka) == 1) {
        if (strcmp(nosilo.naziv, naziv) == 0) {
            if (nosilo.aktivirano == 1) {
                printf("Nosilo je veæ aktivirano!\n");
            } else {
                nosilo.aktivirano = 1;
                printf("Nosilo je aktivirano!\n");
                fseek(datoteka, -sizeof(struct Nosilo), SEEK_CUR); /* Postavljanje pozicije*/
                fwrite(&nosilo, sizeof(struct Nosilo), 1, datoteka);
            }
            break;
        }
    }
    fclose(datoteka);
}


void pozovi_nosilo(char *naziv) {
    FILE *datoteka = fopen("nosilo.dat", "rb+");
    if (datoteka == NULL) {
        printf("Greska pri otvaranju datoteke!\n");
        return;
    }
    struct Nosilo nosilo;
    while (fread(&nosilo, sizeof(struct Nosilo), 1, datoteka) == 1) {
        if (strcmp(nosilo.naziv, naziv) == 0) {
            if (nosilo.aktivirano == 0) {
                printf("Nosilo nije aktivirano!\n");
                break;
            }
            if (nosilo.brojKoristenja >= nosilo.maxKoristenja+10) {
                printf("Nosilo nije u funkciji\n");
                break;
            }
            nosilo.brojKoristenja++;
            printf("Lift pozvan. Broj koristenja: %d\n", nosilo.brojKoristenja);
            fseek(datoteka, -sizeof(struct Nosilo), SEEK_CUR);
            fwrite(&nosilo, sizeof(struct Nosilo), 1, datoteka);

                int trenunti;
                int zeljeni;
                opet:
                printf("Vas trenutni sprat je: ");
                scanf("%d", &trenunti);
                printf("Na koji sprat želite: ");
                scanf("%d", &zeljeni);

                 if(zeljeni>nosilo.brojSpratova)
                 {
                     printf("Ovaj lift na tom spratu ne možete koristiti!\n");
                     goto opet;
                 }
if(trenunti<zeljeni)
{
for(trenunti; trenunti<=zeljeni; trenunti++){

     printf("------------\n");
     printf("|          |\n");
     printf("|          |\n");
     printf("|          |\n");
     printf("|          |\n");
     printf("|          |\n");
     printf("|          |\n");
     printf("| [%d]      |\n", trenunti);
     printf("------------\n");

     sleep(2);
     system("cls");

}
}
for(trenunti; trenunti>=zeljeni; trenunti--){

     printf("------------\n");
     printf("|          |\n");
     printf("|          |\n");
     printf("|          |\n");
     printf("|          |\n");
     printf("|          |\n");
     printf("|          |\n");
     printf("| [%d]      |\n", trenunti);
     printf("------------\n");

     sleep(2);
     system("cls");

} break;
}
}
    fclose(datoteka);
}
#endif // ADMINPANEL_H_INCLUDED
