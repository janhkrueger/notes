# Infrastruktur

[[AzureConnectstring]]

Nach dem Verkauf läuft die Entwicklungsumgebung derzeit auf einen [[RaspberryPi]], die Quellcodeverwaltung in [[Git]] besitzt ihr primäres Repository in [[GitLab]].

Die Instanzen laufen alle mit [[Linux]].
Technisch wurde zuletzt [[Docker]] eingesetzt, begleitet mit einem Umstieg auf eine neue [[NeueTechnischePlattformFuerInsulae]]. Details siehe [[Docker-Container]].
Gleichfalls wurde analysiert Insulae auf Microsoft Azure zu betreiben. Technisch möglich, insbesondere für die Datenbank, wurde dies jedoch nicht weiter verfolgt.

Die API wird im Hinblick auf Performance und Last mittels Bombard gemessen, siehe [[API-Performance_Messen]].

[[Konfigurationen]].

## offene Punkte
Einbau der [[Infrastruktur-PostGreSQL_Compression]].
Ausbau der bestehenden [[UnitTests]].