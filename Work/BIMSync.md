---
modified: 2021-09-28T10:25:01+02:00
---

# Bim Sync

- Einen Blick auf den aktuellen Stand CI/CD werfen
- Schauen welche Herausforderungen uns in naher Zukunft erwarten
- Prüfen was uns aktuell fehlt
- Tickets erstellen / ergänzen.


Bis 1.10 
- Prüfen Connectivity (XLD Prod zu BIM Environments)
- Prüfen welche User werden für die Verbindung benötigt
- Beauftragung MSSQL für Konfigure (Test, Prod)
- Beauftragung MSSQL für XLR (Test, Prod)
- Implementierung Plugin Synchronization Konfigure - XLD (für die Anlage von Infrastructure) - Edi
- Defintion Notifizierung per Email für Releasedeployments
- Beauftragung techn. User für den Betrieb von XLR und Konfigure in Dev/Prod
Bis 8.10
- Connectivity (wenn nicht vorhanden) beauftragt und implementiert
- User (wenn nicht vorhanden) beauftragt
- onboarding Environments, Infrastructure in XLD, Konfigure.io (Ausführen als Admin)
- Anpassungsaufwand Applikationen identifiert (z.B. externalisiern der Konfiguration)
- Definition/Dokumentation User/Rollenmodell/Berechtigungskonzept XLD, Jira, Jenkins, BitBucket, SonarQube, Konfigure, XLR
- Migration Konfigure auf MSSQL (Test)
- Migration XLR auf MSSQL (Test)
- Prüfen Anpassungen Jira für neue ToolChain
- Definiton der Abhängigkeiten von BIM (von anderen Projekten / Produkten)
Bis 15.10
- Implementierung Plugin Konfigure zur Synchronisation zu ArgoCD - Edi/Manuel
- Portierung Automic Plugin für XLR (von XLD)
- User für die Verbindungen zu BIM Infrastructure implementiert
- BIM Infrastructure check erfolgreich
- Onboarding auf Jenkins erfolgreich (Erzeugen eines Releases (Branches,Tags, Update Jira Tickets)
- manuelles onboarding Applikation (Demo) auf XLD, Konfigure
- Einbindung BIM in SonarQube
Bis 22.10
- Implementierung Plugin von XLR zu ArgoCD (für das auslösen eines Deployments)
- Migration OpenShift Build BIM von Jenkins CH auf Jenkins DE
- Anpassungen Applikationen durchgeführt
- automatisches Provisionieren von Artefakten (und Versionen) in XLD, Konfigure
- Implementierung User/Rollenmodell
- Installation XLR, Konfigure in Prod
Bis 29.10
- Tranfer Templates / etc für XLR von Test auf Prod
- Deployment auf BIM INT mit der neuen ToolChain (als Test)
- Unterstützung für die Implementierung Zabbix/Dynatrace Monitoring BIM 
Bis 05.11.
- Releasedeployment mit den neuen Verfahren


Weitere Themen:
- Definition NotifizierungsVerteiler pro Umgebung und Applikation / Projekt
- Konfig Deployments
- 5-stellige Releasenummern
- DiAS Start / Stop mit Automic nach einem Releasedeployment
- Vereinheitlichen Releasebuild SIP-NEU
- IIB Unterstützung
- Testautomatisierung K2

Risiken:
- Infrastruktur DB2, Windows
- Separate Pakete für Datenbankupdates
- Rollbacks für nicht-K2 Projekte

Später:
- Test(s)
- Migration Jenkins Workflow auf XLR
- Automatische QualityGates
- Datahub automatisches Deployment
- Tool/Prozess Self-onboarding
