# EVE Online

[EVE Evolved](EVE_Evolved.md)
## Charbild

https://image.eveonline.com/Character/1676205336_1024.jpg


## EVE Contractdaten auslesen
Chars des Accounts

https://api.eveonline.com/account/Characters.xml.aspx?keyID=&vCode=&characterID


## Achanjiati: 1676205336
vCode=
keyID=

## Contracts

https://api.eveonline.com/char/Contracts.xml.aspx?keyID=&vCode=&characterID=1676205336

### Nur einen Contract

https://api.eveonline.com/char/Contracts.xml.aspx?keyID=&vCode=&characterID=1676205336&contractID=83421936

### Abgeschlossener Hobgoblin Contract

https://api.eveonline.com/char/Contracts.xml.aspx?keyID=&vCode=&characterID=1676205336&contractID=82453672

### Details eines spezifischen Contracs

https://api.eveonline.com/char/ContractItems.xml.aspx?keyID=&vCode=&characterID=1676205336&contractID=82453672

```
<eveapi version="2"><currentTime>2014-07-07 23:28:34</currentTime><result><rowset name="itemList" key="recordID" columns="recordID,typeID,quantity,rawQuantity,singleton,included"><row recordID="1339236437" typeID="2455" quantity="1" singleton="0" included="1"/><row recordID="1339236438" typeID="2455" quantity="1" singleton="0" included="1"/><row recordID="1339236439" typeID="2455" quantity="1" singleton="0" included="1"/><row recordID="1339236440" typeID="2455" quantity="1" singleton="0" included="1"/><row recordID="1339236441" typeID="2455" quantity="1" singleton="0" included="1"/><row recordID="1339236442" typeID="2455" quantity="1" singleton="0" included="1"/><row recordID="1339236443" typeID="2455" quantity="1" singleton="0" included="1"/><row recordID="1339236444" typeID="2455" quantity="1" singleton="0" included="1"/><row recordID="1339236445" typeID="2455" quantity="1" singleton="0" included="1"/><row recordID="1339236446" typeID="2455" quantity="1" singleton="0" included="1"/></rowset></result><cachedUntil>2024-06-04 23:54:44</cachedUntil></eveapi>
```

**typeID** = Hobgoblin
**quantity** = Menge der Items
**recordID** = scheint unwichtig zu sein


## EVE  Online Static Database Dump
-> Siehe everasidel.sh
* Dieses muss noch erweitert werden damit es die benötigten Tabellen gleich aktualisiert.
* Das Datum der Erstellung wird beibehalten.
* Also kann mittels Skript das Erstelldatum ermittelt werden.
* Um nun zu überprüfen ob der Dump eingespielt werden soll muss überprüft werden ob der TimeStamp mit jenem des letzten Versuches überein stimmt oder abweicht
* Ist der TS jünger kann eingespielt werden.


Letzten Timestmap ermitteln
wget https://www.fuzzwork.co.uk/dump/
grep "mysql-latest" index.html > line.txt
-> "     <a href="mysql-latest.tar.bz2">mysql-latest.tar.bz2</a>                    2014-01-25 02:04   62M"
Wie gelange ich nun konkret an den TimeStamp?

```
tail -f ~/service/reminder/log/main/current | tai64nlocal
tail -f ~/logs/error_log | tai64nlocal
```

EVE Zeichen ≡



## Storytechnisch interessante Corps
* Ishukone
* Material Acquisition
* Nugoeihuvi Corporation
* Malkalen Reconstruction
* Caldari Steel
* Caldari Constructions


## EVE Market Tools
* http://goonmetrics.com/market_scan/
* http://eve-prosper.blogspot.de/

```
DELETE c2 FROM KR_characterUpdatesPrio c2
WHERE c2.characterID in (
  SELECT c1.characterID
  FROM KR_characterUpdates c1
  WHERE c1.lastUpdate IS NOT NULL
  AND c1.lastUpdate != '2099-01-01'
)
```

## Befüllung der Tabelle KR_killCount
```
    INSERT INTO KR_killCount
    select curdate() - 1, shipTypeID, count(killID) AS count(killID)
    from KR_participants
    where ((shipTypeID in (23757))
    and (isVictim = 1)
    and (cast(kill_time as date) = (curdate() - 1)))
    23757,23915,23911,24483
```

## Industrie
[Copyslots](Copyslots.md)

## Auswertungen
[EVE Frachter Kills Losses](EVE_Frachter_Kills_Losses.md)
## CSM Members
[CSM Overview](CSM/CSM_Index.md)