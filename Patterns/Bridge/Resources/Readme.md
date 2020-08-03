# Bridge Pattern

## Wesentliche Merkmale

#### Kategorie: *Structural Pattern*

#### Ziel / Absicht:

Das *Bridge Pattern* ist ein strukturelles Entwurfsmuster,
mit dem sich eine gro�e Klasse oder eine Reihe eng verwandter Klassen in zwei separate Hierarchien aufteilen lassen - 
Abstraktion und Implementierung - die beide unabh�ngig voneinander entwickelt werden k�nnen.


#### Problem:

Das *Bridge Pattern* genie�t einen guten Ruf,
da sich mit ihm die abstrakten Elemente der Klasse von den Implementierungsdetails trennen lassen.
Dieses Muster ist vor allem dann zu empfehlen,
wenn die betrachteten Klassen h�ufig variieren,
da sich dann �nderungen an der Codebasis bei minimalem Wissen �ber das Programm leicht durchf�hren lassen.

Betrachten wir ein Beispiel, in dem eine Implementierung auf zwei oder mehreren Realisierungen fu�t.
Zum Beispiel ein Programm, das die Persistenz von Objekten auf verschiedenen Plattformen (Betriebssystemen) realisiert.
Einige Objekte sollen in einer Datenbank und andere Objekte wiederum im Dateisystem des unterlagerten
Betriebssystems gespeichert werden. 
Wird das Programm um diese Funktionalit�t "straight forward" erweitert,
sind Probleme vorprogrammiert, da die Abstraktion mit der Implementierung verkn�pft wird.
In diesem Fall ist es besser, das *Bridge Pattern*  zu verwenden und die Abstraktion von der Implementierung zu trennen.
Wird dieses Muster nicht verwenden, kann man die Beobachtung machen,
dass Implementierungsdetails in einer Abstraktion enthalten sind.

Ein weiterer Vorteil des *Bridge Patterns* ist die M�glichkeit, Implementierungsdetails zur Laufzeit zu �ndern.
Dies erm�glicht es dem Benutzer, Implementierungen zu wechseln, um auf diese Weise zu bestimmen,
wie die Software mit anderen Systemen zusammenarbeitet.


#### L�sung:


#### Struktur (UML):

Das folgende UML-Diagramm beschreibt eine Implementierung des *Bridge Patterns*.
Es besteht im Wesentlichen aus vier Teilen:

  * **Abstraction**: Definiert eine Abstraktionsschnittstelle. Sie fungiert als Basisklasse f�r andere verfeinerte Abstraktionsklassen.
    Sie bezieht sich auch auf eine bestimmte Implementierung, die f�r plattformspezifische Funktionen verwendet wird.
  * **RefinedAbstraction**: Stellt eine verfeinerte Variation einer Abstraktionsschnittstelle dar,
    enth�lt jedoch keine Implementierungsdetails. De facto erweitert sie nur die Abstraktion.
  * **Implementor**: Definiert die Schnittstelle f�r Implementierungsklassen.
  * **ConcreteImplementor**: Diese Klasse erbt von der Klasse `RefinedAbstraction`. Es kann mehr als eine Instanz von `Implementor`-Klassen geben,
    die dieselbe Schnittstelle unterst�tzen, aber plattformspezifische Funktionen bereitstellen.


<img src="dp_bridge_pattern.svg" width="600">

Abbildung 1: Schematische Darstellung des *Bridge Patterns*.


#### Conceptual Example:

Die Anregung zum konzeptionellen Beispiel finden Sie unter

[https://refactoring.guru/design-patterns](https://refactoring.guru/design-patterns/bridge/cpp/example#example-0)

und 

[https://www.codeproject.com](https://www.codeproject.com/Articles/438922/Design-Patterns-2-of-3-Structural-Design-Patterns#Bridge)

vor.

#### Beginners Example:

#### 'Real-World' Beispiel:

To be done.


## Literaturhinweise

*Hinweise*:

---

[Zur�ck](../../../Resources/Readme_05_Catalog.md)

---
