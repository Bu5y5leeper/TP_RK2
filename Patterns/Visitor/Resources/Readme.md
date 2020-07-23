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

http://www.vishalchovatiya.com/double-dispatch-in-cpp/#:~:text=Double%20Dispatch%20in%20C%2B%2B%20is,tables%20of%20respective%20two%20objects.



#### Struktur (UML):

Das folgende UML-Diagramm beschreibt eine Implementierung des *Visitor Patterns*.
Es besteht im Wesentlichen aus sechs Teilen:

  * **Client**: Anwender des *Visitor Patterns*. Er verwaltet die Objektstruktur und weist die Objekte innerhalb der Struktur an,
    wann ein Besucher akzeptiert werden soll.
  * **ObjectStructure**: Dies ist eine Klasse, die alle Objekte enth�lt, die besucht werden k�nnen.
    Es bietet einen Mechanismus zum Traversieren aller Elemente.
    Diese Struktur muss nicht zwingend eine *Collection* sein, es kann irgend eine komplexe Struktur sein, beispielsweise ein *Composite Object*.
  * **ElementBase**: Stellt eine Abstraktionsschnittstelle dar, die die `accept`-Operation deklariert. Dies ist der Einstiegspunkt, an dem ein Objekt vom Besucherobjekt "besucht" werden kann.
    Jedes Objekt aus einer *Collection* sollte diese Abstraktionsschnittstelle implementieren, um besucht werden zu k�nnen.
  * **ConcreteElement**: Diese Klassen erben von der abstrakten Basisklasse `ElementBase` oder implementieren eine Schnittstelle
    und definieren eine `accept`-Operation. Das *Visitor*-Objekt wird durch die `accept`-Operation an dieses Objekt �bergeben.
  * **VisitorBase**: Deklariert eine `visit`-Methode (Operation) f�r jede Klasse von `ConcreteElement` in der Objektstruktur.
    Der Name und die Signatur der Operation identifizieren die Klasse, die die Anforderung an den Visitor sendet.
    Auf diese Weise kann der Besucher die konkrete Klasse des besuchten Elements bestimmen.
    So kann der Besucher direkt �ber diese spezielle Schnittstelle auf die fraglichen Elemente zugreifen.
  * **ConcreteVisitor**: Implementiert jede von einem Visitor deklarierte Operation (Methode).
    Jede Operation implementiert ein Fragment eines Algorithmus, der f�r die entsprechende Klasse oder das entsprechende Objekt in der Objektstruktur definiert ist.
    `ConcreteVisitor` stellt den Kontext f�r den Algorithmus bereit und speichert seinen lokalen Status.
    Dieser Zustand sammelt h�ufig Ergebnisse w�hrend des Durchlaufens der Struktur.

<img src="dp_visitor_pattern.svg" width="600">

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

[Zur�ck](../../../Resources/Readme_05_Catalog.md)

---
