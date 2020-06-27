# Abstract Factory

## Wesentliche Merkmale

##### Kategorie: Erzeugungsmuster / *Creational Pattern*

#### Ziel / Absicht:

Das *Abstract Factory* Pattern ist ein Entwurfsmuster,
mit dem Gruppen miteinander verwandter Objekte erstellt werden k�nnen,
ohne dass die genauen konkreten Klassen angegeben werden m�ssen, die dabei verwendet werden sollen.
Eine von mehreren Factory-Klassen generiert die jeweiligen Objektmengen.

#### Problem:

Dieses Muster ist sehr gut, wenn Sie die Details der Objektinstanziierung trennen m�chten.
Im Allgemeinen haben Fabriken mehr als eine Factory-Methode.
Jede Factory-Methode kapselt den `new`-Operator und die konkreten, plattformspezifischen Klassen.
Jede Plattform wird dann von einer Klasse rer�sentiert, die sich von einer der Fabriken ableitet.

#### Struktur (UML):

Das folgende UML-Diagramm beschreibt eine Implementierung des *Abstract Factory Patterns*.
Es besteht im Wesentlichen aus f�nf Teilen:

  * **Client**: Ein Client benutzt ausschlie�lich Methoden der beiden (abstrakten)
    Klassen `AbstractFactory` und `AbstractProduct`.
  * **AbstractFactory**: Abstrakte Basisklasse f�r alle konkreten Factory-Klassen, die miteinander verwandte Objekte erzeugen.
    F�r jeden Objekttyp, der instanziiert wird, ist eine Methode enthalten.
  * **ConcreteFactory**: Diese Klasse leitet sich von `AbstractFactory` ab.
    `ConcreteFactory` �berschreibt die Methoden von `AbstractFactory`, die neue miteinander verwandte Objekte generieren.
  * **AbstractProduct**: Basisklasse f�r alle Arten von Objekten, die von einer Factory erstellt werden k�nnen.
  * **ConcreteProduct**: Konkrete Implementierung der `AbstractProduct`-Klasse.
    Es kann nat�rlich mehrere Klassen geben, die sich von der `AbstractProduct`-Klasse mit jeweils
    spezifischer Funktionalit�t ableiten.

<img src="dp_abstract_factory.png" width="800">

Abbildung 1: Schematische Darstellung des *Abstract Factory* Entwurfsmusters.

Die Klassen `ProductA` und `ProductB` sind Stellvertreter der `ConcreteProduct` Klasse
aus Abbildung 1.

#### 'Real-World' Example:

Im  'Real-World' Beispiel zu diesem Entwurfsmuster wird
die Herstellung verschiedener Fahrzeugtypen verschiedener Hersteller betrachtet.
Es gibt eine abstrakte Fabrikschnittstelle namens `IVehicleFactory` (*abstract Factory*)
und zwei konkrete Fabrikimplementierungen namens `FordFactory`  und `MitsubishiFactory`. 
`IVehicleFactory` verf�gt �ber drei Methoden `createEconomyCar`, `createRacingCar` und `createSUV`,
mit denen `Vehicle`-Objekte zur�ckgegeben werden.
Die Klasse `Vehicle` ist eine abstrakte Basisklasse f�r alle konkreten Produkte.

---

[Zur�ck](../../Readme_05_Catalog.md)

---
