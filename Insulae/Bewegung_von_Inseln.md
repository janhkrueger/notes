# Bewegung von Inseln

Eine Sache welche ich bisher nicht behandelt habe in Insulae ist die Bewegung von Inseln. Warum auch immer, habe ich doch sehr viele Modifikationen für Inseln schon umgesetzt.
Wie auch immer, eine Positionsveränderung von Inseln steht nun auf dem Plan. Voraussetzung dafür ist das eine Insel klar definiert werden kann und alle auf der Insel sich befindlichen Objekte ebenfalls bewegt werden.
Zu bewegende Objekte
	• Spieler (inklusive Monster)
	• Gebäude (inklusive Monsternester)
	• Städte
	• Portale
	• Endpunkte für Routen
	• Potentiell Startpunkte für Routen
	• Schilder
	• Schätze
	• Karawanen
	• Trigger
	
Karten
Die Abgrenzung spezifischer Inseln ist recht leicht. Ein Blick in das Datenmodell:

	• karte_id
	• karte_x
	• karte_y
	• karte_w
	• karte_gelaende
	• karte_land
Für eine Positionsveränderung sind nur die ersten vier, speziell das erste Attribut _karte_id_ interessant. _karte_id_ definiert das ein Feld der Weltkarte zu einer abgegrenzten Insel gehört. Darüber in Kombination mit _karte_x_, _karte_y_ und _karte_w_ kann exakt bestimmt werden das ein Feld zur Insel __A__ und nicht zur Insel __B__ gehört.
Nachdem mittels einer recht simplen Abfrage ermittelt wurde welche Felder zu einer Insel gehören ist zu prüfen ob auf diesem Feld ein Objekt vorhanden ist welches im Abschnitt _Zu bewegende Objekte_ definiert wurde.
Bei der technischen Durchführung ist zwingend die gesamte Operation in einer Transaktion zu behandeln um im Fehlerfall alle Schritte zurück drehen zu können, gleichzeitig um zu verhindern das während der durchgeführten Updates keine anderen Jobs oder Spieleraktionen die Position relevanter Objekte verändern.

Speicherort der Positionsdaten
Spieler
Die Position eines Spielers ist in der Relation spieler.spieler_pos abgelegt. Monster sind hier ebenfalls mit enthalten. Die Relevanten Felder lauten:

	• spieler_id
	• spieler_x
	• spieler_y
	• spieler_w
	• spieler_altx
	• spieler_alty
	• spieler_altw
Gebäude
Die Daten sind in der Relation welt.haus_pos abgelegt. Hiervon sind auch die Monsternester abgedeckt.
	• wh_haus
	• wh_x
	• wh_y
	• wh_w
Städte
Relation: Stadt.stadt_pos
	• stadt_id
	• stadt_x
	• stadt_y
	• stadt_w
Portale
Relation: welt.portal
	• portal_sx
	• portal_sy
	• portal_sw
