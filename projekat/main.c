#include <stdio.h>
#include <stdlib.h>
#include "funkcije.h"
#include "adminpanel.h"
#define RED "\033[0;31m"
#define RESET "\033[0m"

int main()
{
  char email[100];
  char password[100];
  int vrijednost = 0;
  int odabir=0;
  char nosilo[256];

  printf("Unesite vas mail: ");
  scanf("%s", email);
  printf("Unesite vasu sifru: ");
  scanf("%s", password);

  vrijednost = login(email, password);

  switch(vrijednost)
  {

  case 1:
        system("cls");
    pocetak:
    printf("\nAdmin panel:\n");
    start:
     printf("\n[1] Kreiranje novog korisnika\n");
     printf("[2] Kreiranje novog nosila\n");
     printf("[3] Trenutni broj koristenja nosila\n");
     printf("[4] Nosila spremna za servisiranje\n");
     printf("[5] Blokirana nosila\n");
     printf("[6] Ispis svih nosila\n" );
     printf(RED "[7] Izlaz\n" RESET);
     printf("Unesite zeljenu opciju: ");
     scanf("%d", &odabir);
      system("cls");
    switch(odabir)
    {
    case 1:
        novi_korisnik();
        system("cls");
        printf(RED "Korisnik je kreiran!\n" RESET);
        goto pocetak;

        break;
    case 2:
        kreiraj_novo_nosila();
          system("cls");
          printf(RED "Nosilo je kreirano!\n" RESET);

         goto pocetak;
        break;
    case 3:
        printf("Unesite naziv nosila: ");
        scanf("%s", nosilo);
        pretrazi_datoteku(nosilo);
         goto pocetak;

        break;
    case 4:
        system("cls");
        nosila_za_servis();
        goto pocetak;
        break;
    case 5:
       blokirana_nosila ();
        goto pocetak;
        break;
    case 6:
        ispis_nosila();
        goto pocetak;
        break;
    case 7:
        exit(1);
        break;


    default:
        printf("Izabrali ste nepostojecu opciju, probajte ponovo\n");
        goto start;
        break;

    }

    break;

  case 2:

    printf("Korisnik");
    korisnik:
     printf("\n[1] Aktivacija nosila \n");
     printf("[2] Pozivanje i koristenje nosila \n");
     printf("[3] Exit\n");
     printf("Unesite zeljenu opciju: ");
     scanf("%d", &odabir);


     switch(odabir)
     {
     case 1:
        system("cls");
        printf("Unesite naziv nosila: ");
        scanf("%s", nosilo);
        aktivacija_nosila(nosilo);

        goto korisnik;
        break;



    case 2:
        system("cls");
        printf("Unesite naziv nosila: ");
        scanf("%s", nosilo);
        pozovi_nosilo(nosilo);
        goto korisnik;
        break;



    case 3:
        exit(1);
        break;
     }


    break;
   default:
    printf("Nista");
    break;
  }

}

