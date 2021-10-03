# Stadtrunde

Die Stadtrunde in [[Scherbenwelten]] war wie folgt organisiert.

* Eine Stadtrunde wird zur Hauptauswertung (morgens gegen 6:00 Uhr) gemacht
* Eine weitere Stadtrunde kann pro Tag manuell (per Buttonklick: "Übersicht > Stadtname > Stadtzug") eingeleitet werden.
* Die Stadtrunde ist vergleichbar mit der Produktionsrunde für normale Gebäude - zu diesem Zeitpunkt werden:
	
  * Waren verbraucht
  * Waren produziert
  * Steuern eingenommen
  * ...alles was dazugehört
  * Die Einwohnerzahl steigt um abgerundet 6%.
   Wenn das mehr als das Maximum ist, dann fällt sie um abgerundet 10%.
   (In diesem Fall müssen nur 75% der jetzigen Einwohnerzahl mit Gebäuden versorgt werden).

## Milizen
* Milizen schützen die Stadtgebäude vor Angriffen.
* Wenn eine Anzahl von X Milizen in der Stadt sind, dann wird ein Stadtgebäude durch 2X/Gebäudezahl verteidigt.
	• Die mögliche Anzahl der Milizen richtet sich nach der der Anzahl der Kasernen.
 Normal sind 1% der Stadtbevölkerung Milizen, je in der Stadt gebaute Kaserne kommt 1%-Punkt hinzu, die man mehr Milizen anheuern kann
 (Einstellen kann man dies im Stadtverwaltungs-Menü unter "Übersicht > Stadtname > Rekrutierung bis:").
* Mehr als 100 Milizen kosten 10 GS pro Stadtrunde. 105 Milizen kosten also 5*10 GS = 50 GS.
* Die Anzahl der Milizen richtet sich nach der Einwohnerzahl vor der Stadtrunde.
* Milizen bekommen maximal 50 Einheiten Zuwachs pro Tag.
 (Bei extrem kleinen Städten schwankt die Zahl der Milizen sehr stark).


## Lagerraum
* Wenn man kein Lagerhaus hat, besitzt die Stadt 4.000 Lagerplatz für Waren.
* Sobald man ein Lagerhaus baut, kommen 4000 als Grundlagerkapazität dazu und das Rathaus zählt als Lagerhaus mit, so dass die Stadt 8.000 Lagerplatz hat.
* Der Vorteil von Lagerhäusern ist, dass die Waren dort diebstahlsicher gelagert sind.
* Ein Lagerhaus verursacht laufende Kosten (wird jede Stadtrunde abgezogen)
* Je Lagerhaus (unausgebaut) gibt es 4000 Lager dazu. Je Ausbau kommen dann 400 dazu.

## Bevölkerungsverteilung
* Man kann einstellen, welche Rassen in der Stadt leben sollen.
* Die verschiedenen Rassen verbrauchen unterschiedlich viel Rohstoffe.
* Die Bevölkerungsverteilung lässt sich pro Tag um 1%-Punkt ändern.
* Die Änderungswünsche werden von oben nach unten abgearbeitet.

## Bevölkerungsmaximum
* Die Einwohnerzahl muss durch folgende Gebäude gedeckt sein:
  * Tavernen
  * Arenen
  * Theater
  * Magistraturen
* Das Rathaus zählt jeweils als erstes Bauwerk dieser Art.

**Erläuterung:
 Wenn man eine Arena hat und eine Taverne, kann man trotzdem nur 4.000 Einwohner haben, da die Tavernen-Versorgung (2.000 vom Rathaus + 2.000 von der Taverne) kleiner ist als die Arenen-Versorgung (10.000 vom Rathaus + 10.000 von der Arena).**

## Stadtkasse
* Zu jeder Stadtrunde werden Steuern eingenommen, und zwar von jedem nicht arbeitenden Einwohner 1 GS.
* Der Marktplatz deiner Stadt füllt oder leert die Stadtkasse. Man kann eine Handelssteuer erheben, so dass jeder, der Waren an die Stadt verkauft, einen Teil des Umsatzes an die Stadtkasse abführen muss.
* Wenn in der Stadt der Startpunkt (und somit das Ziel) einer Karawane ist und diese die Stadt wieder erreicht, kommt 10% des Karawanenertrages (in Goldstücken) in die Stadtkasse.
* Auf dem Marktplatz kann der Bürgermeister Geld zwischen der Stadtkasse und der Kasse der Laufgruppe hin- und hertransferieren.
  
## Gebäudemaximum
* Wie viele Gebäude du in der Stadt haben kannst hängt von der Größe der Stadt ab.
* Dabei zählen alle Gebäude, auch private, Kultstätten und Stadttore.
* Stadtmauern, Kunstobjekte, Wald und Ähnliches zählen nicht als Gebäude.
* Wenn die Stadt mal kleiner wird (so dass das Gebäudemaximum unter die tatsächliche Gebäudezahl fällt), bleiben die Gebäude bestehen, man kann nur keine neuen errichten.
 Es kann dann sein, dass Ausbauten verfallen.

Egal wie groß die Stadt ist, 20 Gebäude kann man immer bauen.
* Von 20.000 bis 50.000 Einwohner kommt je 1.500 ein Gebäude dazu.
* Von 50.000 bis 100.000 Einwohner kommt alle 2.500 Einwohner ein Gebäude dazu.
* Ab 100.000 Einwohner kommt alle 4.000 Einwohner ein Gebäude dazu.

```
mind. Einwohner	max. Gebäude
		21.500	21
		23.000	22
		24.500	23
		26.000	24
		27.500	25
		29.000	26
		30.500	27
		32.000	28
		33.500	29
		35.000	30
		36.500	31
		38.000	32
		39.500	33
		41.000	34
		42.500	35
		44.000	36
		45.500	37
		47.000	38
		48.500	39
		50.000	40
		52.500	41
		55.000	42
		57.500	43
		60.000	44
		62.500	45
		65.000	46
		67.500	47
		70.000	48
		72.500	49
		75.000	50
		77.500	51
		80.000	52
		82.500	53
		85.000	54
		87.500	55
		90.000	56
		92.500	57
		95.000	58
		97.500	59
		100.000	60
		104.000	61
		108.000	62
		...	...
```

## Ausbautenmaximum
* Für 1.000 AP kann man die meisten Innenstadtgebäude ausbauen.
* Damit erhöht sich der Nutzen und der Verbrauch des Gebäudes entsprechend.
* Das Ausbautenmaximum für ein Gebäude richtet sich nach der Einwohnerzahl.
 Pro volle 1.000 Einwohner kann ein Gebäude um eine Stufe ausgebaut werden.
* Ein Ausbau verfällt, wenn das Ausbautenmaximum (in Folge von Stadtschrumpfung) kleiner als 3/4 wird oder weniger als 3/4 der zum Unterhalt benötigten Arbeiter zur Verfügung stehen. Der 20. Ausbau beispielsweise verfällt, wenn die Einwohnerzahl der Stadt unter 15.000 fällt.
* Unausgebaute Schulen können bis Skill 50 ausbilden. Pro Ausbau können sie einen Skillpunkt mehr ausbilden.
  
## Torbegrenzung
* Eine Stadt kann zunächst einmal maximal 10 Stadttore haben.
* Pro angefangene 100.000 Einwohner kann man ein weiteres Tor bauen.
* Man kann in einer Stadt nur ein Tor pro Tag errichten.

## Arbeitermaximum
* Es können maximal 25% der Einwohner zu Arbeiten eingespannt werden
* Pro Stadtgebäude werden 100 Arbeiter benötigt
* Pro Ausbau weitere 10 Arbeiter
* Wenn weniger als 3/4 der für einen Ausbau benötigten Arbeiter zur Verfügung stehen, verfällt der Ausbau.

## Petroleumverbrauch
* Pro Ausbau werden 1/10 Petroleum verbraucht, wobei ein unausgebautes Gebäude als 10 Ausbauten gezählt wird.
* Hierbei zählen alle Gebäude.
* Lagerausbauten von Privatgebäuden zählen nicht mit.
* Die Ersten 100 Ausbauten sind kostenlos.
* Es wird normal gerundet, so dass 104 Ausbauten nichts kosten, 105 1 Petroleum, 115 2 usw.

## Ruhm und PP
* Pro 25 Einwohner bekommst man 1 Politikruhm
* Pro 5.000 Einwohner bekommt man 1 PP pro Tag.

## Gebäude abschalten
* Produktions- und Versorgungsgebäude, die man nicht benötigt, kann man abschalten.
* Sie verbrauchen dann nichts und tragen auch nichts zum Petroleumverbrauch bei.
* Das Gebäudemaximum wird durch das Abschalten nicht umgangen.

## Neuwahlen
* Wenn die Einwohnerzahl der Stadt 10 Tage in Folge oder unter 500 fällt, wird der Bürgermeister automatisch abgesetzt.
 Sein Einfluss sinkt auf 0, der Einfluss aller anderen um die Hälfte.
* Man kann sich zur Neuwahl aufstellen.
* Wenn man mehrere Tage nicht spielen kann und Neuwahlen verhindern will, kann man das Bürgermeisteramt für 2.000 AP an einen anderen Spieler abgeben oder seinen Account sitten lassen.
* Automatische turnusmäßige Wahlen gibt es nicht.

## Stadt umbenennen
* Für 5.000 AP und 250.000 GS kann man seiner Stadt einen neuen Namen geben.

## Das Stadtmenü des Bürgermeisters
Das Stadt-Menü erreicht man über "Übersicht > Stadtname"en Namen der Stadt klickst.
In der ersten Zeile sieht man, welche Waren die Stadt aktuell eingelagert hat (zu beachten ist, dass man hier nicht sieht, welche Waren in den Stadttoren, Schmieden oder Brauereien in der Stadt eingelagert sind).

## Die Stadtregeln
Im **"Stadtmenü des Bürgermeisters"** gibt es den Link **"Regeln für Bürgermeister"** - diese lauten wie folgt:
	1. Zwischen Stadteingang und Stadttor dürfen maximal 5 in direkter Linie begehbare Felder liegen
	2. Existiert kein Stadttor, dürfen zwischen Stadteingang und Rathaus maximal 5 in direkter Linie begehbare Felder liegen
	3. Der Stadteingang muß außerhalb der Stadtmauern liegen (mit anderen Worten vom Eingang müssen unendlich viele Felder erreichbar sein, ohne ein Tor durchschreiten zu müssen)
	4. Zwischen 2 Stadttoren und an den beiden Eingängen jedes Stadttors muß mindestens 1 begehbares Feld liegen
	5. Zu jedem Gebäude muß ein möglicher Weg existieren (kein Gebäude darf eingebaut werden)
	6. Das Rathaus darf vom Stadteingang überirdisch maximal 500 AP entfernt liegen bei normaler Laufgeschwindigkeit
	7. Bei Verstoß gegen eine oder mehrere dieses Regeln wird das Bürgermeisteramt aberkannt

Neben den oben genannten Einstellungsmöglichkeiten kann man auch eine Stadtankündgung machen, die genauso wie eine Gebäudeankündigung funktioniert.


## Neue Gebäude
09.12.09 
**Stadtgebäude**: Ab 200.000 Einwohner werden 10.000 Einwohner je zusätzlichem Gebäude benötigt. 
**Stadtgebäude: Die Kosten für ein Stadtgebäude steigen.** Derzeit kostet das Errichten eines neuen Gebäudes in der Innenstadt grundsätzlich 10.000 Goldstücke. Jedes Gebäude nach dem ersten, das errichtet werden soll, wird 1.000 Goldstücke mehr kosten. Ab dem hundertsten Gebäude werden die Schritte auf 2.000 Goldstücke angehoben. Für je einhundert errichtete Gebäude werden die Schritte um weitere 1.000 Goldstücke erhöht. 
**Stadtgebäude: Ausbauten an Stadtgebäuden werden in Zukunft Werkzeuge verbrauchen.** Der erste Ausbau eines Gebäudes wird 1 Werkzeug kosten, der hundertste wird 100 Werkzeuge kosten, der tausendste 1000 Werkzeuge usw. Der Ausbauer muss die Werkzeuge mit sich führen. 


**Neues Stadtgebäude: Markt**. Ab 500.000 Einwohner wird je 500.000 Einwohner ein Markt benötigt. Es werden je 10.000 Fleisch, Getreide, Holz, Stein und Fisch pro Stadtrunde verbraucht und 50 Thaum und 50 Kakao produziert. 
**Neues Stadtgebäude: Siechenhaus**. Ab 1 Mio Einwohner wird je 100.000 Einwohner ein Siechenhaus benötigt. Verbrauch 200 Bücher, 200 Glas, 400 Petro, 100 Tran und 100 Kräuter. 

Wer bereits über dem Gebäudelimit ist, kann trotzdem je einen Markt und ein Siechenhaus zu den normalen Kosten errichten. 
Die beiden neuen Stadtgebäude können zwar bereits errichtet werden, aber beschränken die maximale Einwohnerzahl erst ab Anfang Januar 2010.

**Neues Gebäude: Fischerhütte**. Fischerhütten können direkt angrenzend an Anleger errichtet werden. Sie sind umso produktiver, je mehr Wasser im Umkreis von zwei Feldern vorhanden sind. Die Fischproduktion hängt vom Fischen-Skill der Insassen ab. Die Tranproduktion hängt vom Kochen- und vom Alchemie-Skill ab und kann nicht durch Ausbauten gesteigert werden. Je Tran werden 500 Fisch und ein Petroleum verbraucht. Es werden erst die Fische produziert und im Lager abgelegt, erst dann ggf zu Tran weiterverarbeitet. 
**Armeeverbrauch** wird in der Armeeübersicht detaillierter dargestellt. 
**Bugfix:** ´Die Einwohner von ... werden unruhig´ sollte wieder angezeigt werden 

**Karawanen**: Massenwaren werden in der jeweiligen Mangeljahreszeit nichtmehr geliefert. 

[//begin]: # "Autogenerated link references for markdown compatibility"
[Scherbenwelten]: Scherbenwelten "Scherbenwelten"
[//end]: # "Autogenerated link references"