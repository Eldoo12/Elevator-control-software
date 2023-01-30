# Projekat
 Admin strana:
Pokretanjem softvera korisniku se prezentuje login forma putem koje korisnik unosi svoje lične identifikatore, u ovom slučaju to će biti email i password, a nakon što korisnik unese lične podatke potrebno je odraditi provjeru kako bi utvrdili da li je korisnik admin sistema ili obični korisnik. Admin podatke treba da predefinišete i da sačuvate u "admin.dat" fajlu. Nakon što prođemo verifikaciju korisnika i utvrdimo da je admin aktivan, korisnik treba da vidi sljedeće opcije:
Admin opcije su:
•	kreiranje novog korisnika
•	kreiranje novog nosila
•	trenutni broj korištenja nosila 
•	nosila spremna za servisiranje
•	blokirana nosila
•	exit

Opcija za kreiranje korisnika treba biti jednostavna, te adminu ponuditi opciju za kreiranje nove email adrese kao i passworda koji će imati pristup sistemu za korištenje nosila.

Opcija za kreiranje novog nosila adminu daje mogućnost da unese naziv nosila, nakon toga da unese broj spratova gdje se nosila koristi i koliko puta nosilo može biti aktivirano prije nego što postavimo zastavicu za servis, a kao zadnji podatak je broj koji dodajemo na broj korištenja nakon sto označimo za servis kada postavljamo nosilo kao blokirano. Nakon što korisnik unese sve podatke, potrebno je ponuditi opciju da snimi sve navedeno u fajl nazvan "nosila.dat".

Opcija za prikaz broja korištenja opcija prvobitno treba adminu da prikaze unos za naziv nosila, a nakon što unese naziv da mu se prikazu potrebi podaci tog nosila, kao broj trenutnih korištenja i kolika je razlika između trenutnog stanja do servisiranja ili blokiranja.

Opcija prikaza nosila spremnih za servisiranje treba da prikaze nazive svih nosila obilježenih sa zastavicom za servisiranje, odnosno nosila koja su ispunila zadati broj s kojim ćemo obilježiti servis. Admin treba da ima reset opciju gdje će sva navedena nosila postaviti na 0.
 
Opcija prikaza blokiranih nosila treba da prikaze nazive svih nosila obilježenih sa zastavicom za blokiranje, odnosno nosila koja su ispunila zadati broj s kojim ćemo obilježiti blok korištenja. Admin treba da ima reset opciju gdje će sva navedena nosila postaviti na 0.

Exit opciju koristimo za napuštanje programa.
Korisnička strana:
Pokretanjem softvera korisniku se prezentuje login forma putem koje korisnik unosi svoje lične identifikatore, u ovom slučaju to će biti email i password, a nakon što korisnik unese lične podatke potrebno je odraditi provjeru kako bi utvrdili da li je korisnik admin sistema ili obični korisnik. U ovom slučaju radimo na korisničkoj strani, a korisnike kreirate logovanjem s adminom, te nakon što korisnik unese email i password radimo provjeru liste koja je kreirana od strane admina, i gledamo da li korisnik postoji i da li može pristupiti sistemu. Nakon što verifikujemo korisnika, trebamo prikazati sljedeće opcije:opcije:
Korisničke opcije su:
•	aktivacija nosila ili lifta
•	pozivanje i korištenje nosila ili lifta
•	exit

Opcija za aktivaciju nosila ili lifta treba korisniku prikazati unos gdje će ukucati naziv lifta te aktivirati isti za svoj profil.
Opcija za pozivanje i korištenje lifta predstavlja korištenje nosila kreiranog od admin strane, i svako pozivanje računa +1 na broj korištenja. Potrebno je grafički prikaz korištenje nosila pa ako imamo za primjer 7 spratova nakon što pozovemo nosilo moramo prikazati sljedeće:

