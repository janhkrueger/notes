---
created: 2021-09-27T00:13:05+02:00
modified: 2021-09-30T17:52:52-04:00
---

# Abfragen

### Spieler mit der Anzahl der aktiven Gruppenmitglieder

```
SELECT s.spieler_id, s.spieler_name, count(charakter_id)
FROM spieler.spieler s, spieler.charakter c
WHERE s.spieler_aktiv = 'j'
AND s.spieler_monster = 'n'
AND c.charakter_spieler = s.spieler_id
AND c.charakter_haus IS NULL
AND c.charakter_stadt IS NULL
AND c.charakter_lebenspunkte > 0
GROUP BY s.spieler_id
ORDER BY s.spieler_id ASC
```

### Gruppenchars Chars eines Spielers
```
SELECT c.*
FROM spieler.spieler s, spieler.charakter c
WHERE s.spieler_aktiv = 'j'
AND s.spieler_monster = 'n'
AND c.charakter_spieler = s.spieler_id
AND c.charakter_haus IS NULL
AND c.charakter_stadt IS NULL
AND s.spieler_id = 1000000006
ORDER BY s.spieler_id ASC
```

### Ein zufälliger Ort an dem es zuletzt unter null Grad C° sind.
```
SELECT s.*
FROM welt.weatherbasics s
WHERE s.surveydate IN (
SELECT max(c.surveydate) as letztes
FROM welt.weatherbasics c
GROUP BY c.id
)
AND temperature < 0
order by random()
LIMIT 1
```

### Die zuletzt eingelesenen Wetterdaten, nach Ort
```
SELECT s.*
FROM welt.weatherbasics s
WHERE s.surveydate IN (
SELECT max(c.surveydate) as letztes
FROM welt.weatherbasics c
GROUP BY c.id
)
```

### Haustypen der Kultstätten ermitteln
```
SELECT haus_id, haus_name, haus_internerkommentar
FROM haus
WHERE haus_name = 'Kultstätte'
AND haus_id != 45;
```

```
SELECT haus_id
FROM haus
WHERE haus_name = 'Kultstätte'
AND haus_id != 45;
```

```
SELECT h.wh_haus as id, a.haus_internerkommentar as godname, p.wh_x as x, p.wh_y as y, p.wh_w as w, p.wh_phase as phase, 1000000000 as worldid
FROM archetyp.haus a, welt.haus h, welt.haus_pos p
WHERE a.haus_name = 'Kultstätte'
AND a.haus_id != 45
AND h.wh_haustyp = a.haus_id
AND p.wh_haus = h.wh_haus
AND p.wh_aktiv = 'j'
```


### Neuen Spieler einfügen
#### (Veraltet, vergangene Datenstruktur aus 2005)
```
INSERT INTO player.player ("spieler_id", "spieler_name", "spieler_aktionen", "spieler_mailadresse", "spieler_nation", "spieler_lehnsherr", "spieler_handelsvertrauen", "spieler_kopfgeldvertrauen", "spieler_geld", "spieler_kampfruhm", "spieler_politikruhm", "spieler_morde", "spieler_eroberungen", "spieler_wissen", "spieler_gott", "spieler_glaube", "spieler_glaubensstufe", "spieler_apmaximum", "spieler_grafikpfad", "spieler_apregeneration", "spieler_geschlecht", "spieler_loesch_zeit", "spieler_sperrzeit", "spieler_auf_schiff", "spieler_tavernenverbot", "spieler_forenverbot", "spieler_forenberechtigung", "spieler_tavernenfarbe", "spieler_politikpunkte", "spieler_aktiv", "spieler_avataradresse", "spieler_wappenadresse", "spieler_luftschiff", "spieler_ausgeloggt", "spieler_nationstitel", "spieler_rollenspielpunkte", "spieler_rpzuwachs", "spieler_baurecht", "spieler_stadt", "spieler_untergrund", "spieler_verwaltung", "spieler_beschreibung", "spieler_monster", "spieler_startseite", "spieler_aktionen_uebertrag", "spieler_pp_max", "spieler_glaube_gestern", "spieler_bild", "spieler_lehebeginn", "spieler_ppzuwachs_gestern", "spieler_swid", "spieler_titelherkunft", "spieler_titel")
VALUES (1000000006, 'San Achanjiati Mentem Mortis', '5000', NULL, '1000000005', '1000000005', '10', '10', '0', '0', '0', '0', '0', '0', '0', '0', '0', '5000', 'bilder/', '12', 'm', NULL, NULL, '0', 'n', 'n', '1', '000000', '0', 'n', '', '', '0', 'n', NULL, '0', '0', '1', 'n', 'n', 'n', '0', 'n', 'gruppe.php', '0', '150', '0', 'charakter/h_1.gif', '0', '0', NULL, '1000000003', '');
```


### Unklar
```
SELECT * FROM "charakter_fertigkeit" WHERE "charakter_id" = '120' AND "fertigkeit_id" = '1000000010'
```

```
SELECT c.charakter_id, TRUNC(cf.fertigkeit_stufe * 10) as maxmana FROM spieler.charakter c, spieler.charakter_fertigkeit cf WHERE c.charakter_beruf in (19, 14, 18, 9) AND c.charakter_lebenspunkte > 0 AND cf.charakter_id = c.charakter_id AND cf.fertigkeit_id = 1000000010
```

### Volkverbrauch für Stadtrunde

```
SELECT v.volk_id as raceID, vv.verbrauch_ware as usageGood, vv.verbrauch_menge as usageAmount,
res.se_prozent as racePercentageCurrent,
res.se_soll_prozent as racePercentageTarget, v.volk_name as raceName
FROM archetyp.volk v, archetyp.volk_verbrauch vv, stadt.einwohner res
WHERE vv.verbrauch_volk = volk_id
AND v.volk_id = res.se_volk
AND res.se_stadt = '1000000003'
ORDER BY raceid ASC, usagegood ASC
```

Wichtig zu wissen: Eine Rasse kann mehrfach vorkommen, für jede verbrauchte Ware einmal.

| raceid | usagegood | usageamount | racepercentagecurrent | racepercentagetarget | racename
| --- | --- | --- | --- | --- | --- |
| 1000000000 | 41 | 0.1 | 40 | 40 | Untote |
| 1000000029 | 32 | 0.1 | 60 | 60 | Nekropolit |
| 1000000029 | 41 | 0.1 | 60 | 60 | Nekropolit |
