---
created: 2021-09-27T12:52:20+02:00
modified: 2021-09-27T12:52:26+02:00
---

# Docker Batchjob starten mit mounted volumes

Dadurch wird ein Job innerhalb des Containers ausgeführt. Nach Ausführung werden temporäre Volumes und Daten wieder entfernt (--rm).
Es werden ein zentrales  Logverzeichnis sowie die Konfiguration von extern gemounted.
Ebenfalls ist es wichtig das richtig Netzwerk (network=docker_insulae-network) zu nutzen damit der Datenbankserver auch gefunden wird.

Der konkret aufgerufene Job ist in diesem Beispiel "/home/insulae/insulae-bin/DailyTownCalc"

    docker run --rm --network=docker_insulae-network -v /home/insulae/insulae-log/:/home/insulae/insulae-log/ -v /home/insulae/insulae-conf/:/home/insulae/insulae-conf/ -it janhkrueger/insulae-batch:1.0.0  /home/insulae/insulae-bin/DailyTownCalc

#Docker