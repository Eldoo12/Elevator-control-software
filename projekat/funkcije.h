#ifndef FUNKCIJE_H_INCLUDED
#define FUNKCIJE_H_INCLUDED

int login(char email[], char password[])
{
  int vrijednost=0;

  /*ADMIN POETAK*/
  FILE *f = fopen("admin.dat", "r");
  if (f == NULL) {
    printf("Greska pri otvaranju datoteke!\n");
    return 1;
  }
  char admin_email[100];
  char admin_password[100];
  fscanf(f, "%s\n", admin_email);
  fscanf(f, "%s\n", admin_password);

  fclose(f);


   /*ADMIN KRAJ*/

   /*KORISNIK POCETAK*/


   FILE *fi = fopen("korisnik.dat", "r");
  if (fi == NULL) {
    printf("Greska pri otvaranju datoteke!\n");
    return 1;
  }
  char user_email[100];
  char user_password[100];
  fscanf(fi, "%s\n", user_email);
  fscanf(fi, "%s\n", user_password);

  fclose(fi);

  /*KORISNIK KRAJ*/

  if (strcmp(email, admin_email) == 0 && strcmp(password, admin_password) == 0) {

    vrijednost = 1;
    return 1;
}

  else if (strcmp(email, user_email) == 0 && strcmp(password, user_password) == 0){
    vrijednost = 2;
    return 2;
  }
  else
  {
      printf("POGREŠAN UNOS!");
      vrijednost = 3;
    return 3;
  }
}



#endif // FUNKCIJE_H_INCLUDED
