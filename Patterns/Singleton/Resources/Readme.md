# Singleton Pattern

## Wesentliche Merkmale

##### Kategorie: Erzeugungsmuster / *Creational Pattern*

#### Ziel / Absicht:

Das *Singleton Pattern* ist ein Entwurfsmuster, mit dem sichergestellt wird,
dass es zu einer Klasse nur eine einzige Instanz gibt.
Immer wenn neue Objekte einer Singleton-Klasse ben�tigt werden,
wird die zuvor erstellte Einzelinstanz bereitgestellt.

#### Problem:

In einigen F�llen ist es wichtig, zu einer konkreten Klasse maximal nur eine Instanz zu haben.
Zum Beispiel dann wenn man nur einen einzigen globalen Zugriffspunkt
auf eine begrenzte Ressource ben�tigt. 

W�rde man eine derartige globale Variable erstellen, die kopiert wird,
w�rde dies zu mehreren Zugriffspunkten f�hren und damit zu Dateninkonsistenzen f�hren.

*Beispiele*:
  * Stream Objekte von C++: `std::cout`, `std::cin` und `std::cerr`.
  * `HttpContext`-Klasse (Java, C# und andere).
 
Ein weiteres Beispiel f�r Singletons sind Klassen wie zum Beispiel `Color`.
W�rde man - zum Beispiel bei jeder Notwendigkeit im Gebrauch einer Farbe wie zum Beispiel *rot* -
ein entsprechendes `Color`-Objekt erzeugen, w�rde man die Speicherplatzanforderungen
dieser Anwendung nicht mehr in den Griff bekommen. 

Aus diesem Grund gibt es in den entsprechenden Frameworks (JSEE, .NET) f�r diesen
Anwendungsfall zugeschnittene (leicht
modifizierte `getSingleton`) Methoden, die f�r jeweils eine Farbe immer dasselbe Objekt
zur�ckliefern:

```c#
// C# / .NET Framework
public static Color FromArgb (byte a, byte r, byte g, byte b);
```

Nat�rlich setzt dies voraus, dass die Klasse Color in derartigen Anwendungsf�llen
*immutable*, also unver�nderbar ist. Andernfalls k�nnte zur Laufzeit aus einer
roten eine blaue Farbe werden, was so sicherlich nicht erw�nscht ist.


#### L�sung:

#### Struktur (UML):

Das folgende UML-Diagramm beschreibt eine Implementierung des *Singleton Patterns*.
Es besteht nur aus einer einzigen Klasse:

  * **Singleton**: Dieser Klasse besitzt eine statische Methode `getSingleton`,
    die pro Aufruf eine einzelne Instanz zur�ckgibt (Referenz, Zeiger),
    die in einer privaten Variablen residiert.

<img src="dp_singleton_pattern.png" width="300">

Abbildung 1: Schematische Darstellung des *Singleton Patterns*.

#### Conceptual Example:

Die Anregung zum konzeptionellen Beispiel finden Sie unter

[https://refactoring.guru/design-patterns](https://refactoring.guru/design-patterns/singleton/cpp/example#example-0)

und 

[https://www.codeproject.com](https://www.codeproject.com/Articles/430590/Design-Patterns-1-of-3-Creational-Design-Patterns#Singleton)

vor.

#### Beginners Example:

#### 'Real-World' Beispiel:

## Literaturhinweise

*Hinweise*:

TO BE DONE:

Ein guter Aufsatz, wie shared_ptr, weak_ptr und Singletons zusammenarbeiten !!!

http://btorpey.github.io/blog/2014/02/12/shared-singletons/


---

[Zur�ck](../../../Resources/Readme_05_Catalog.md)

---
