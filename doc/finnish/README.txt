ORDS

Mik‰ Ords on?

Ords on ohjelma jolla voi muun muassa harjoitella sanastoa.
Sit‰ levitet‰‰n Gnu General Public Licensen version 3 alla. Katso LICENSE lis‰tietojen saamiseksi.

ASENNUS

Asenna ohjelma purkamalla paketti ja suorittamalla komento `make` src/ kansiossa.
Siirr‰ `ords`-bin‰‰ritieodoto haluamaasi paikkaan, tai suorita komento `make install`, joka siirt‰‰ tiedoson oletusarvoisesti kotikansioon (`~`)
Jos haluat muuttaa asennuskohdetta, k‰yt‰ komentoa `make install "LOCATION=<sijainti>"`.

KƒYTT÷

T‰ll‰ hetkell‰ Ords tukee kahta tapaa k‰ytt‰‰ ohjelmaa: interaktiivinen tila ja komentoriviargumentit.
Avataksesi interaktiivisen tilan, k‰yt‰ komentoa `ords` ja sen j‰lkeen interaktiivisen tilan komentoja (kirjoita `help` saadaksesi tietoa eri komennoista)
Saadaksesi tiet‰‰ mit‰ argumenttej‰ voit k‰ytt‰‰, k‰yt‰ komentoa `ords -h` tai `ords --help`.
Versionumeron saat tiet‰‰ komennolla `ords -v` tai `ords --version`.

Lis‰‰ tietoa saat HELP-tiedostosta.

POLUT JA ASETUKSET

Ords s‰ilytt‰‰ kaikkea dataa datakansiossa, jossa ovat kaikki Ordsin .ords-p‰‰tteiset tiedostot.
Oletussijainti on `~/ords/`. Muuttaaksesi sit‰, vaihda `datapath`-direktiivi‰ Ordsin asetustiedostossa, `~/.ords.conf`.

MUUT TIEDOSTOT

/LICENSE:
	Sis‰lt‰‰ GPLv3-lisenssin.

/info/CHANGELOG.txt:
	Sis‰lt‰‰ tietoa muutoksista.

/info/FILES.txt (tai suomeksi /info/finnish/FILES.txt):
	Sis‰lt‰‰ tiedostolistauksen.

/info/DEVELOPER.txt (tai suomeksi /info/finnish/DEVELOPER.txt):
	Kertoo ohjelman sis‰isest‰ toiminnasta.

/info/HELP.txt (tai suomeksi /info/finnish/HELP.txt):
	Ohjeita ohjelman k‰ytˆst‰.

TEKIJƒT

Teemu Vasama <therryan1@gmail.com>
