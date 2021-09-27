---
created: 2021-09-27T13:09:05+02:00
modified: 2021-09-27T13:09:31+02:00
---

# Debian Login und Logout Kommandos

/bin/bash nutzt unter Debian die Datei .bashrc und nicht .profile oder .bash_profile

Um beim logout (exit) Befehle auszuführen (zb Dateien zu löschen, Historien leeren)
Kann unter $HOME/bin/logout.sh eine Sammlung der Tasks angelegt werden.

Dann folgende Zeile in die $HOME/.bashrc einfügen:

	trap $HOME/bin/logout.sh 0
	
Die Trap weist die Shell an das Kommando nach (bei?) Beenden auszuführen.
