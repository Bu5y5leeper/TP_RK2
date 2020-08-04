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

<img src="dp_factory_method_pattern.svg" width="550">

Abbildung 1: Schematische Darstellung des *Factory Method Patterns*.

#### Hinweis 1:

Die beiden Entwurfsmuster *Simple Factory* und *Factory Method* sind nicht 
miteinander zu verwechseln.

**Simple Factory**<br/>
  * Mit dem *Simple Factory* Pattern versuchen wir, die Details in der Erstellung eines Objekts vor dem Anrufer (Client) zu abstrahieren.
    Das einzige, was der Client wei�, indem er eine Methode aufruft und den gew�nschten Parameter �bergibt, ist,
    dass er ein Objekt eines bestimmten Typs erh�lt. Aber wie dieses Objekt erstellt wird, wei� der Client-Code nicht.

**Factory Method**<br/>
  * Das *Factory Method* Pattern bietet sich an, wenn die Anforderungen an die Erstellung eines Objekts mehr als nur der Aufruf des `new`-Operators sind.
    Sind zur Erzeugung des Objekts mehrere Schritte notwendig, m�chte man diese Schritte ggf. anpassen k�nnen
    oder sind diese Schritte bei verschiedenen Objekten unterschiedlich, verwendet man das *Factory Method* Pattern.
  * Oder anders ausgedr�ckt: 
    Gibt es einen Algorithmus / eine Strategie, um die Erzeugung einer Produktfamilie zu steuern,
    dann kommt das *Factory Method* Pattern in Betracht. Dieses l�sst sich gut mit dem *Template Pattern*, oder auch *Strategy Pattern* kombinieren,
    da man mit einer Schablone (Template) die Schritte zum Erstellen des untergeordneten Elements abstrahieren kann.

In den Beispielen zu diesem Entwurfsmuster findet sich ein Programm mit den Klassen `ITelevision`, `LEDTelevision`, `OledTelevision`,
`AbstractFactory`, `LEDTVFactory` und `OledTVFactory` vor. Studieren Sie die Methode `orderTV`. Beschreiben Sie,
wie diese Methode mit dem *Template Pattern* zusammenh�ngt.


#### Hinweis 2:

Die beiden Entwurfsmuster *Abstract Factory* und *Factory Method* sind nicht 
miteinander zu verwechseln.

Sie haben zumindest gemeinsam, dass sie beide den Client von konkreten Typen entkoppeln.
Der Client kennt nur die Schnittstelle zur Factory und den Produkten. Welche Produkte konkret erstellt werden, entscheidet die Unterklasse/Implementierung der Schnittstelle. Der Client st�tzt sich allein auf Abstraktion.

Damit zu den Unterschieden:

**Abstract Factory**<br/>
  * Bietet eine Schnittstelle zum Erstellen von Familien verwandter oder abh�ngiger Objekte, ohne deren konkrete Klassen anzugeben.
  * Ganze Produktfamilie wird erstellt.
  * Breite Schnittstelle.
  * Schnittstelle (Abstract Factory) ist oft nur ein Interface und enth�lt keinen Implementierungscode.

**Factory Method**<br/>
  * Definiert eine Schnittstelle zum Erstellen eines Objekts, aber l�sst
    die Unterklassen entscheiden, welche Klasse instanziiert werden soll. Mit dem *Factory Method Pattern*  kann eine Klasse die Instanziierung auf Unterklassen verschieben.
  * Schmale Schnittstelle.
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

[Zur�ck](../../../Resources/Readme_05_Catalog.md)

---


