# Visitor Pattern

## Wesentliche Merkmale

#### Kategorie: *Behavioral Pattern*

#### Ziel / Absicht:

Das *Visitor Pattern* ist ein Entwurfsmuster aus der Kategorie der *Behavioral Pattern*,
das eine Menge strukturierter Daten von den Funktionen trennt,
die auf ihr ausgef�hrt werden k�nnen. Dies unterst�tzt zum einen eine lose Kopplung
und es erm�glicht zum anderen das Hinzuf�gen zus�tzlicher Operationen, ohne an den Datenklassen �nderungen vornehmen zu m�ssen.

#### Problem:

Das Ergebnis der Trennung von Objektstruktur und Funktionen (Algorithmen) ist ein Datenmodell
mit eingeschr�nkter Funktionalit�t und einer Gruppe von "*Besuchern*",
die Operationen auf den Daten ausf�hren.
Ein weiterer Vorteil ist die M�glichkeit, einen neuen *Besuchern* hinzuf�gen zu k�nnen,
ohne dabei die vorhandene Struktur �ndern zu m�ssen. 
Die Klassen Daten sind mit Attributen (Eigenschaften, *getter*/*setter*-Methoden) so zu erstellen,
dass diese vom "Besucher"-Objekt geeignet verwendet werden k�nnen.
Typischerweise wird das Datenobjekt als Parameter an eine Methode des "Besucher"-Objekts �bergeben
(die Konvention besteht darin, diese Methode `visit` zu nennen).

#### L�sung:

TO BE DONE:

https://refactoring.guru/design-patterns/visitor-double-dispatch




#### Struktur (UML):

Das folgende UML-Diagramm beschreibt eine Implementierung des *Visitor Patterns*.
Es besteht im Wesentlichen aus sechs Teilen:

  * **Client**: XXX
  * **ObjectStructure**: XXX
  * **ElementBase**: XXX
  * **ConcreteElement**: XXX
  * **VisitorBase**: XXX
  * **ConcreteVisitor**: XXX

<img src="dp_xxx.png" width="500">

Abbildung 1: Schematische Darstellung des *Visitor Patterns*.


#### Conceptual Example:

Die Anregung zum konzeptionellen Beispiel finden Sie unter

[https://refactoring.guru/design-patterns](https://refactoring.guru/design-patterns/command/cpp/example#example-0)

und 

[https://www.codeproject.com](https://www.codeproject.com/Articles/455228/Design-Patterns-3-of-3-Behavioral-Design-Patterns#Visitor)

vor.

#### Beginners Example:

#### 'Real-World' Beispiel:

To be done:



"PersonCaretaker"

https://www.codeproject.com/Articles/455228/Design-Patterns-3-of-3-Behavioral-Design-Patterns#Memento


## Literaturhinweise

*Hinweise*:

---

[Zur�ck](../../Readme_05_Catalog.md)

---
