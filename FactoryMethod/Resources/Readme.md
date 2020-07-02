# Factory Method Pattern

## Wesentliche Merkmale

##### Kategorie: Erzeugungsmuster / *Creational Pattern*

#### Ziel / Absicht:

Das *Factory Method Pattern* ist ein Entwurfsmuster, mit dem Objekte erstellt werden k�nnen,
ohne den Objekttyp anzugeben, der im Code erstellt werden soll.
Eine Factory-Klasse enth�lt eine Methode, mit der der erstellte Typ zur Laufzeit ermittelt werden kann.

#### L�sung:

Dieses Muster wird auch als *Virtual Constructor* Pattern bezeichnet.
Das *Factory*-Entwurfsmuster definiert eine Schnittstelle zum Erstellen eines Objekts
und �berl�sst die Auswahl des konkreten Klassentyps den Unterklassen.
Das Entwurfsmuster macht ein Software-Design leichter anpassbar und weniger abh�ngig 
von anderen Klassen.

#### Struktur (UML):

Das folgende UML-Diagramm beschreibt eine Implementierung des *Factory Method Patterns*.
Es besteht im Wesentlichen aus vier Teilen:

  * **FactoryBase**: Abstrakte Klasse (oder Schnittstelle) f�r konkrete *Factory*-Klassen,
    die die gesuchten Objekte zur�ckgeben.
    Diese Klasse enth�lt die Signatur der Methode `FactoryMethod`,
    die ein `ProductBase`-Objekt zur�ckliefert.
  * **ConcreteFactory**: Repr�sentiert eine konkrete Umsetzung der `FactoryBase`-Klasse.
    Normalerweise �berschreibt diese Klasse die generierende Methode
    `FactoryMethod` und gibt ein `ConcreteProduct`-Objekt zur�ck.
  * **ProductBase**: Basisklasse (oder Schnittstelle) f�r alle Produkte,
    die von konkreten *Factory*-Klassen hergestellt werden.
  * **ConcreteProduct**: Konkrete Implementierung der Klasse `ProductBase`.
    Konkrete `ProductBase`-Klassen sollten produktspezifische
    Funktionalit�ten enthalten. Objekte des Typs `ConcreteProduct` werden von Methoden
    der *Factory*-Klassen erstellt.

<img src="dp_factory_method.png" width="450">

Abbildung 1: Schematische Darstellung des *Factory Method Patterns*.

#### Hinweis:

Die beiden Entwurfsmuster *Abstract Factory* und *Factory Method* sind nicht 
miteinander zu verwechseln.

Sie haben zumindest gemeinsam, dass sie beide den Client von konkreten Typen entkoppeln.
Der Client kennt nur die Schnittstelle zur Factory und den Produkten. Welche Produkte konkret erstellt werden, entscheidet die Unterklasse/Implementierung der Schnittstelle. Der Client st�tzt sich allein auf Abstraktion.

Damit zu den Unterschieden:

**Abstract Factory**<br/>
  * Bietet eine Schnittstelle zum Erstellen von Familien verwandter oder abh�ngiger Objekte, ohne deren konkrete Klassen anzugeben.*
  * Ganze Produktfamilie wird erstellt.
  * Breite Schnittstelle
  * Schnittstelle (Abstract Factory) ist oft nur ein Interface und enth�lt keinen Implementierungscode.

**Factory Method**<br/>
  * Definiert eine Schnittstelle zum Erstellen eines Objekts, aber l�sst
    die Unterklassen entscheiden, welche Klasse instanziiert werden soll. Mit der Factory-Methode kann eine Klasse die Instanziierung auf Unterklassen verschieben
  * Schmale Schnittstelle
  * Schnittstelle ist oft abstrakt und enth�lt generischen Code (Herstellungscode, den alle Produkte durchlaufen m�ssen).
 
#### Conceptual Example:

Die Anregung zum konzeptionellen Beispiel finden Sie unter

[https://refactoring.guru/design-patterns](https://refactoring.guru/design-patterns/factory-method/cpp/example#example-0)

und 

[https://www.codeproject.com](https://www.codeproject.com/Articles/430590/Design-Patterns-1-of-3-Creational-Design-Patterns#FactoryMethod)

vor.

## Literaturhinweise

*Hinweise*:

---

[Zur�ck](../../Readme_05_Catalog.md)

---


