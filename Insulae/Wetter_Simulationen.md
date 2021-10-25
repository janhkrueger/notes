# Wetter Simulationen


http://kiwi.atmos.colostate.edu/pubs/CISE.pdf

http://kiwi.atmos.colostate.edu/BUGS/publications.html


http://ualr.edu/jdberleant/courses/IFSC7310/15minutePresentation.pdf
http://ualr.edu/jdberleant/papers/4pagePaperMM5.pdf


http://ualr.edu/jdberleant/courses/IFSC7310/40minutePresentation.pdf


Hadley Zellen

https://en.wikipedia.org/wiki/Hadley_cell
BUGS:

http://kiwi.atmos.colostate.edu/BUGS/geodesic/


Wie kann das, performanceschonend, Integriert werden?


Fragen



Wie kann der Quellcode der Gebäudeverwaltung modular gehalten werden ohne bei jedem neuen Gebäude das Programm neu übersetzen zu müssen?



Unit Tests
Catch könnte eine alternative sein:
    https://github.com/philsquared/Catch




PostGres C++
http://www.postgresql.org/docs/7.2/static/libpqplusplus.html
http://www.tutorialspoint.com/postgresql/postgresql_c_cpp.htm


Git Hooks
Erledigt 06.01.2015
Diese werden als post-receive abgelegt


Bash Skript welches die einzelnen Kompiliervorgange startet. Notwendige Gedangen: wie kann sicher gestellt werden das nur bei einem Erfolg die Datei verschoben wird?


Lokal: git push
Server: im post-receive Hook wird das repository nach /var/insulae/repo ausgecheckt
    zu beginn eine Mail das der Prozess startete


    cd  /var/insulae/repo/
    env -i git pull /var/git/insulae.git/ master


Dann wird folgendes ausgeführt:
    cd /var/insulae/repo/batch/Insulae-Wachstum/Debug
    make clean
    make all
    mv -f Insulae-Wachstum /var/games/insulae
    Am Ende eine Mail das der Prozess abgeschlossen ist.


Halt für jeden Job entsprechend. Wobei das wiederrum in eine im insulae/batch Ordner liegende Shell Datei ausgelagert werden kann.
Denkbar sind auch das nachdem checkout die PHP-Files nach /root/htdocs/janhkrueger/insulae/php verschoben werden. So wird auch diese Basis stets aktuell gehalten


# Weiteres Vorgehen:
Final abgeschlossen 06.01.2015
    * Einbindung von Config-Files in Insulae-Wachstum
    * Verschieben des Projektes in das GIT-Repository
    * Einrichten GIT-Hook um Insulae-Wachstum bei einem Check-In direkt zu compilieren und auszuliefern






# Gebäude


## Folgende Attribute besitzt jedes Gebäude
* Haustyp
* Besitzer
* Ausbau 1
* Ausbau 2
* Ausbau 3
* Ausbau 4
* Zustand
* Waffen
* Wachen
* Lager
* Grosse Ausbauten
* Vorräte
* Quest (Y/N)
* Eingeschaltet (Y/N)
* Haustypursprung
* Struktur
* Aktiv (Y/N)
---
* Hausname
* Anmerkungen
* Baugrund
* Bauland
* Bau_Steine
* Bau_Holz
* Bau_Eisen
* Stadtgebäude (Y/N)
* Benötigtes Baurecht
* Erforderliche Bauzeit
* Artikel (der/die/das)
* Beschreibung
---
* Ausbauname
* Reihenfolge in welcher der Ausbau angezeigt wird
* Welche Ware durch den Ausbau produziert wird
* Welche Fertigkeit für den Betrieb des Ausbaus benötigt wird
* Aktiv  (Y/N)
---
* Ausbau Ware
* Warenmenge
* Reihenfolge
* Ware für Ausbau aktiv  (Y/N)






# Gemischt


### runwhen Konfig bei uberspace
nano ~/etc/insulae/run-baustellen/run


ln -s ~/etc/insulae/run-baustellen ~/service


svc -a ~/service/run-baustellen


tail -f ~/service/run-baustellen/log/main/current | tai64nlocal
tail -f ~/service/run-ermittle_statistiken/log/main/current |  tai64nlocal


tail ~/service/postgresql/log/main/current | tai64nlocal




# Kartenkorrektur
* 25 -1889 100 das Feld ist zu löschen
