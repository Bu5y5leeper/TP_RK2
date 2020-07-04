# *Null Object* Entwurfsmuster

## Wesentliche Merkmale

Das *Null Object Pattern* ist ein Entwurfsmuster, das sich der Thematik von Null-Referenzen annimmt.
Null-Referenzen gibt es in anderen Programmiersprachen sehr wohl, in C++ sind sie per Definition nicht existent.
Wir sprechen daher besser von so genannten *Null*-Objekten, also Objekten, die keinerlei Funktionalit�t haben.

Der Sinn des Musters besteht darin, einer Referenz ein Objekt zuzuweisen, das keine Aktion ausf�hrt.
Dadurch wird erreicht, dass die Referenz zu jedem Zeitpunkt auf ein g�ltiges Objekt verweist,
was Behandlungen von Sonderf�llen (das Nichtvorhandensein) er�brigt.

#### Kategorie: *Behavioural Pattern*

#### Ziel / Absicht:

Objekte ohne Funktionalit�t stellen nat�rlich einen Sonderfall dar.
Sie k�nnen Sinn ergeben, wenn reale Daten - zum Beispiel in einem Testszenario - nicht verf�gbar sind,
man aber das Standardverhalten der Software trotzdem bereitstellen m�chte.
Das Null-Objekt spiegelt folglich eine "*Do-Nothing*"-Beziehung wieder.

#### Problem:

Das  *Null Object* Entwurfsmuster befreit uns von der Pflicht, zur Laufzeit Abfragen bzgl. gewisser Zust�nde vornehmen zu m�ssen.
�berall im Quellcode, wo �berpr�fungen auf Nullwerte erforderlich w�ren (was in C++ bei Referenzen ohnehin nicht m�glich ist),
kommen Nullobjektklassen zum Einsatz.

#### L�sung:

Im *Null Object* Entwurfsmuster erstellen wir zun�chst eine abstrakte Klasse,
die die verschiedenen auszuf�hrenden Operationen definiert.

Davon leiten wir reale Klassen ab, die die eigentliche Funktionalit�t implementieren und schlie�lich eine Null-Objekt Klasse,
die *keine* Implementierung der Basisklasse bereitstellt. Um es anderes zu formulieren: Streng genommen stellt auch die
Null-Objekt Klasse eine Implementierung der Basisklasse dar, aber eben mit leeren Methodenr�mpfen.

Nun kann man die Null-Objekt Klasse �berall dort einsetzen, wo aus welchen Gr�nden auch immer,
eine Klasse mit einer realen
Realisierung (tempor�r) nicht anwendbar ist.


#### Struktur (UML):

<img src="db_null_object.png" width="500">

Abbildung 1: Schematische Darstellung des *Null Object* Entwurfsmusters.

#### Conceptual Example:

Die Anregung zum konzeptionellen Beispiel finden Sie unter

[https://refactoring.guru/design-patterns](https://refactoring.guru/design-patterns/composite/cpp/example#example-0)

vor.

#### Beginners Example:

#### 'Real-World' Beispiel:


## Literaturhinweise

*Hinweise*:

Die Anregungen zu den Beispielen zum Null Object Pattern stammen aus

[Null Object Design Pattern in C++](https://iq.opengenus.org/null-object-design-pattern-cpp/)<br>(abgerufen am 15.05.2020).

[Dmitri Nesteruk "Design Patterns in Modern C++](https://github.com/Apress/design-patterns-in-modern-cpp)<br>(abgerufen am 14.05.2020).

---

[Zur�ck](../../Readme_05_Catalog.md)

---
