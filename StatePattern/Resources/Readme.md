# State Pattern

## Wesentliche Merkmale

#### Kategorie: *Behavioral Pattern*

#### Ziel / Absicht:

Das *State Pattern* ist ein Entwurfsmuster aus der Kategorie der *Behavioral Pattern*.

Das Muster beschreibt, wie ein Objekt sein Verhalten in Abh�ngigkeit
von seinem aktuellen internen Zustand vollst�ndig �ndern kann.
Es scheint, als h�tte das Objekt seine Klasse ge�ndert.

#### Problem:

    
#### L�sung:

Mit diesem Entwurfsmuster l�sst sich das Verhalten eines Objekts
als Reaktion auf �nderungen seines internen Zustands �ndern.
Das Verhalten ist zur Laufzeit �nderbar, ohne dass die f�r den Zugriff auf das Objekt
verwendete bzw. vorhandene Schnittstelle sich �ndert.
Die �nderungen sind im Kontext des Objekts verborgen.

Dieses Muster ist sehr n�tzlich beim Erstellen von Software Zustandsautomaten,
bei denen sich die Funktionalit�t eines Objekts je nach Status grundlegend �ndert.

#### Struktur (UML):

Das folgende UML-Diagramm beschreibt eine Implementierung des *State Patterns*.
Es besteht im Wesentlichen aus drei Teilen:

  * **Context**: Diese Klasse hat Zugriff auf das konkrete Statusobjekt,
    das das Verhalten gem�� seinem aktuellen Status bereitstellt.
  * **StateBase**: Abstrakte Klasse f�r konkrete Zustandsklassen.
    Sie definiert die Schnittstelle, die von der `Context`-Klasse verwendet wird.
  * **ConcreteState**: Konkrete Implementierung der `StateBase`-Klasse.
    Die Funktionalit�t dieser Objekte wird von der Kontextklasse genutzt.

<img src="dp_state_pattern.png" width="500">

Abbildung 1: Schematische Darstellung des *State Patterns*.


#### Conceptual Example:

*Hinweis*:

Das *Conceptual Example* liegt in drei Versionen vor:

  * Ein einfaches Beispiel - mit *raw*-Zeigern 
  * Dasselbe Beispiel - mit `std::shared_ptr`-Zeigern
  * Ein zweites einfaches Beispiel

Die Anregung zum konzeptionellen Beispiel finden Sie unter

[https://refactoring.guru/design-patterns](https://refactoring.guru/design-patterns/state/cpp/example#example-0)

und 

[https://www.codeproject.com](https://www.codeproject.com/Articles/455228/Design-Patterns-3-of-3-Behavioral-Design-Patterns#State)

vor.

#### Beginners Example:

#### 'Real-World' Beispiel:

## Literaturhinweise

*Hinweise*:

---

[Zur�ck](../../Readme_05_Catalog.md)

---
