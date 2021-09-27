---
modified: 2021-09-27T10:25:01+02:00
---

# Künstliche Intelligenz: Spiele zwischen Behaviour Trees und neuronalen Netzwerken

Jakob Rasmussen von Apex Game Tool auf der Unite 2016

Figuren in Computerspielen müssen mehr können als den Weg zu finden und einen Feind zu treffen. Technische Lösungen gibt es mehrere, in der Praxis könnte sich die Utility AI durchsetzen, sagte Jakob Rasmussen von Apex Game Tools bei einem Entwicklertreffen.


Der Dämon feuert bei einem Punktewert von 80 einen Schuss auf einen Gegner ab und geht bei einem Punktewert von 60 in Deckung. Es dürfte klar sein, was er macht: schießen. Das ist - extrem vereinfacht - auch schon das Grundprinzip von Utility AI. Auf dem Entwicklertreffen Unite 2016 in Amsterdam hat der Informatiker Jakob Rasmussen dafür geworben, künftig verstärkt auf dieses Verfahren zu setzen.


Mit seiner Firma [Apex Game Tools](apexgametools.com) bietet er eine entsprechende Middleware an, die auf Utility AI setzt. Tatsächlich hat das Verfahren Vorteile. Es ist mit Blick auf Komplexität, Ressourcenverbrauch und Anwendungsfreundlichkeit zwischen den meist noch genutzten Wenn-Dann-Verkettungen (den Behaviour Trees) sowie den aufwendigen neuronalen Netzwerken angesiedelt.


Bei Behaviour Trees wird es schon knifflig, wenn minimal komplexere Entscheidungen anstehen. Wenn ein computergesteuerter Soldat etwa weiß, dass er noch drei Kugeln hat, aber vier Feinde auf ihn einstürmen - was soll er dann tun?


Laut Rasmussen wäre Utility AI damit nicht überfordert: Jeder von vielen Möglichkeiten würden variable Werte zugewiesen, die Aktion mit dem höchsten Wert werde ausgeführt. Das habe zusätzlich den Vorteil, dass Entwickler das Verhalten der KI-Charaktere durch ein Zufallselement abwechslungsreich und unvorhersehbar gestalten könnten.


## Flexible Feinde


Auch deshalb eigne sich Utility AI für Indiegames mit ungewöhnlichen Ideen, weil dort die Künstliche Intelligenz in der Lage sein müsse, flexibel zu reagieren. Das Verfahren soll nicht nur kämpfen, sondern auch mit anderen Aktionen funktionieren, etwa mit menügestützten Dialogsystemen. Auch dabei könnten Indiegames profitieren, weil sich durch einen hohen Überraschungsfaktor der Widerspielwert der manchmal eher kurzen Titel erhöhen könnte.


Langfristig sieht aber auch Rasmussen die großen Vorteile neuronaler Netzwerke. Für kleine und mittlere Studios seien die Herausforderungen jedoch hoch: In der Praxis seien selbst mit leistungsstarker Hardware immer wieder stundenlange Rechendurchgänge nötig, und die Ergebnisse seien manchmal - typisch für das Verfahren - anders als erwartet.