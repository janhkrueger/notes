---
created: 2021-09-27T00:13:05+02:00
modified: 2021-09-30T17:52:52-04:00
---

# Azure Connect String

Anbinding von [InsualeInfrastruktur]] an eine bei Azure gehostete PostGreSQL Datenbank.
Analyse im Rahmen der [[NeueTechnischePlattformFuerInsulae]].

## Import eines alten Backups
    psql "host=insulaedbserver.postgres.database.azure.com sslmode=require port=5432 user=insulaeadmin@insulaedbserver dbname=insulaedb"   < insulae_db_20190313_1220.sql

## Servername
    insulaedbserver.postgres.database.azure.com

Anmeldename des Serveradministrators: insulaeadmin@insulaedbserver
