# Composite Pattern

## Wesentliche Merkmale

##### Kategorie: *Structural Pattern*

#### Ziel / Absicht:

Das *Composite Entwurfsmuster* ist ein strukturelles Entwurfsmuster,
mit dem Sie Objekte zu Baumstrukturen zusammensetzen und dann mit diesen Strukturen arbeiten k�nnen,
als w�ren sie einzelne Objekte.

#### Problem:

Der Einsatz des *Composite Entwurfsmuster* ist nur dann sinnvoll,
wenn sich die Kernstruktur der Anwendung als Baum dargestellen l�sst.

Stellen Sie sich beispielsweise vor, Sie haben zwei Arten von Objekten:
Produkte und Kartons. Ein Karton kann mehrere Produkte sowie mehrere kleinere Kartons enthalten.
Diese kleinen Kartons k�nnen wiederum Produkte oder sogar kleinere Kartons usw. aufnehmen.

Angenommen, Sie m�chten ein Bestellsystem erstellen, das diese Klassen verwendet.
Bestellungen k�nnen einfache Produkte ohne Verpackung sowie mit Produkten gef�llte Kartons und andere Kartons enthalten.
Wie w�rden Sie den Gesamtpreis einer solchen Bestellung bestimmen?

Sie k�nnen den direkten Ansatz ausprobieren:
Packen Sie alle Kartons aus, gehen Sie alle Produkte durch und berechnen Sie dann die Gesamtsumme.
Das w�re in der realen Welt machbar.
In einem Programm ist es jedoch nicht so einfach wie das Ausf�hren einer Wiederholungsschleife.
Sie m�ssen die Klassen der Produkte und Schachteln, die Sie durchlaufen,
die Verschachtelungsebenen der Schachteln und andere unangenehme Details im Voraus kennen.
All dies macht den direkten Ansatz entweder sehr umst�ndlich oder sogar unm�glich.


#### L�sung:

Die zentrale Idee des *Composite Entwurfsmusters* ist es, mit einer gemeinsamen Schnittstelle sowohl
f�r Produkte als auch f�r Kartons zu arbeiten. Aufgabe dieser Schnittstelle w�re es an dem betrachteten Beispiel,
eine Methode zur Berechnung des Gesamtpreises zu deklarieren.

Wie k�nnte eine derartige Methode aussehen?
F�r ein Produkt wird einfach der Produktpreis zur�ckgegeben.
Bei einer Schachtel wird jeder Artikel in der Schachtel �berpr�ft, der Preis abgefragt und eine Gesamtsumme f�r diese Schachtel zur�ckgegeben.

Wenn eines dieser Elemente eine kleinere Schachtel w�re, w�rde diese Schachtel auch ihren Inhalt usw. durchgehen, bis die Preise aller inneren Komponenten berechnet wurden.
Eine Schachtel kann sogar zus�tzliche Kosten zum Endpreis hinzuf�gen, wie z.B. Verpackungskosten oder �hnliches.

Der gro�e Vorteil dieses Ansatzes besteht darin, dass Sie sich nicht um die konkreten Objekte k�mmern m�ssen (Produkt oder Karton),
aus denen der Baum besteht. Sie m�ssen nicht wissen, ob es sich bei einem Objekt um ein einfaches Produkt oder eine gro�e Schachtel mit vielen Einzelteilen handelt.
Sie k�nnen die Objekte alle gleich �ber die gemeinsame Schnittstelle behandeln.
Wenn Sie eine Methode aufrufen, �bergeben die Objekte selbst die Anforderung an den Baum.

#### Struktur (UML):

<img src="dp_composite_pattern.png" width="600">

Abbildung: Schematische Darstellung des *Composite Entwurfsmusters*.


## Anwendungen des Design Pattern in der STL:

  * TBD

## Anwendungsbeispiel:

  * TBD

* Siehe Stockmayer File and Directory !!!*


Beispiele:

Die Beispiele zu diesem Pattern orientieren sich an:

[https://refactoring.guru/design-patterns/strategy](https://refactoring.guru/design-patterns/strategy/java/example)


## Literaturhinweise

http://www.martinbroadhurst.com/list-the-files-in-a-directory-in-c.html

https://github.com/achimoraites/DesignPatterns/blob/master/CompositePattern/FileSystem/src/ui/FileSystem.java

https://www.codingame.com/playgrounds/5659/c17-filesystem


# TODO

Beispiel mit arithmetischen Ausdr�cken:

https://nick79.gitlab.io/mnblog/post/composite_design_pattern/

---

[Zur�ck](../../Readme.md)

---
