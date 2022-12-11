# EVE Frachter Kills / Losses

## Top Kill
```
select `p1`.`allianceID` AS `allianceID`,`p1`.`allianceName` AS `allianceName`,count(`p1`.`killID`) AS `kills` from `KR_participants` `p1` where (`p1`.`killID` in (select `p2`.`killID` from `KR_participants` `p2` where ((`p2`.`shipTypeID` in (20183,20185,20187,20189,34328)) and (`p2`.`isVictim` = 1))) and (`p1`.`finalBlow` = 1) and (`p1`.`allianceName` is not null) and (`p1`.`allianceID` <> 0)) group by `p1`.`allianceName` order by count(`p1`.`killID`) desc limit 0,5
```


## TOP Looser
```
select `KR_participants`.`allianceID` AS `allianceID`,`KR_participants`.`allianceName` AS `allianceName`,count(`KR_participants`.`killID`) AS `losses` from `KR_participants` where ((`KR_participants`.`shipTypeID` in (20183,20185,20187,20189,34328)) and (`KR_participants`.`isVictim` = 1) and (`KR_participants`.`allianceName` is not null) and (`KR_participants`.`allianceID` <> 0)) group by `KR_participants`.`allianceName` order by count(`KR_participants`.`killID`) desc limit 0,5
```

## Erweiterung
Die FrachterIds nicht mehr hart hinterlegen sondern auch aus invTypes und invGroups lesen.