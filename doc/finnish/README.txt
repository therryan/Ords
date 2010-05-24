ORDS

Mikä Ords on?

Ords on ohjelma jolla voi muun muassa harjoitella sanastoa.
Sitä levitetään Gnu General Public Licensen version 3 alla. Katso LICENSE lisätietojen saamiseksi.

ASENNUS

Asenna ohjelma purkamalla paketti ja suorittamalla komento `make` src/ kansiossa.
Siirrä `ords`-binääritieodoto haluamaasi paikkaan, tai suorita komento `make install`, joka siirtää tiedoson oletusarvoisesti kotikansioon (`~`)
Jos haluat muuttaa asennuskohdetta, käytä komentoa `make install "LOCATION=<sijainti>"`.

KÄYTTÖ

Tällä hetkellä Ords tukee kahta tapaa käyttää ohjelmaa: interaktiivinen tila ja komentoriviargumentit.
Avataksesi interaktiivisen tilan, käytä komentoa `ords` ja sen jälkeen interaktiivisen tilan komentoja (kirjoita `help` saadaksesi tietoa eri komennoista)
Saadaksesi tietää mitä argumenttejä voit käyttää, käytä komentoa `ords -h` tai `ords --help`.
Versionumeron saat tietää komennolla `ords -v` tai `ords --version`.

Lisää tietoa saat HELP-tiedostosta.

POLUT JA ASETUKSET

Ords säilyttää kaikkea dataa datakansiossa, jossa ovat kaikki Ordsin .ords-päätteiset tiedostot.
Oletussijainti on `~/ords/`. Muuttaaksesi sitä, vaihda `datapath`-direktiiviä Ordsin asetustiedostossa, `~/.ords.conf`.

MUUT TIEDOSTOT

/LICENSE:
	Sisältää GPLv3-lisenssin.

/info/CHANGELOG.txt:
	Sisältää tietoa muutoksista.

/info/FILES.txt (tai suomeksi /info/finnish/FILES.txt):
	Sisältää tiedostolistauksen.

/info/DEVELOPER.txt (tai suomeksi /info/finnish/DEVELOPER.txt):
	Kertoo ohjelman sisäisestä toiminnasta.

/info/HELP.txt (tai suomeksi /info/finnish/HELP.txt):
	Ohjeita ohjelman käytöstä.

TEKIJÄT

Teemu Vasama <therryan1@gmail.com>
