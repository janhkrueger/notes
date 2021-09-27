# Import eines alten Backups
    psql "host=insulaedbserver.postgres.database.azure.com sslmode=require port=5432 user=insulaeadmin@insulaedbserver dbname=insulaedb"   < insulae_db_20190313_1220.sql

# Servername
    insulaedbserver.postgres.database.azure.com
    
Anmeldename des Serveradministrators: insulaeadmin@insulaedbserver
