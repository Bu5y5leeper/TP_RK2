# Flyweight Pattern

## Wesentliche Merkmale

#### Kategorie: *Structural Pattern*

#### Ziel / Absicht:

Das *Flyweight Pattern* ist ein Entwurfsmuster aus der Kategorie der *Structural Pattern*,
das verwendet wird, um den Ressourcenverbrauch eines Programms mit einer sehr gro�en Anzahl von Objekten zu minimieren.
Beim Erzeugen von vielen tausend identischen Objekten k�nnen zustandslose "Flyweight"-Objekte
den in Anspruch genommen Speicher auf ein vertretbares Ma� reduzieren.

#### Problem:

Manchmal arbeiten Programme mit einer gro�en Anzahl von Objekten, die dieselbe Struktur haben,
und einige Zust�nde dieser Objekte variieren nicht zeitlich.
Wenn wir den klassischen Ansatz verwenden (Instanzen erstellen, Instanzvariablen schreiben),
k�nnen sich die Speicher- bzw. Speicherbereichsanforderungen inakzeptabel erh�hen.
Das *Flyweight Pattern* stellt eine Alternative in diesem Kontext dar.

#### L�sung:

Ein so genanntes *Flyweight* ist ein Objekt, das den Speicherbedarf minimiert,
indem so viele Daten wie m�glich mit anderen �hnlichen Objekten geteilt werden.
Es gestattet, Objekte in gro�er Anzahl zu verwenden,
wenn eine einfache wiederholte Erzeugung entsprechender Objekte 
eine nicht akzeptablen Speicherbereich beanspruchen w�rde.
F�r jedes Objekt, das gemeinsam genutzte Daten verwendet,
wird nur ein Verweis (Referenz, Pointer) auf ein gemeinsam genutztes Objekt gespeichert.

Das *Flyweight Pattern* verwendet h�ufig eine Variation des *Factory Method* Entwurfsmusters
f�r die Erzeugung der gemeinsam genutzten Objekte.
Die Fabrik erh�lt eine Anfrage f�r eine *Flyweight* Instanz.
Wenn bereits ein �bereinstimmendes Objekt verwendet wird,
wird eine Referenz dieses Objekt zur�ckgegeben. Andernfalls wird ein neues *Flyweight* Objekt generiert.

#### Struktur (UML):

Das folgende UML-Diagramm beschreibt eine Implementierung des *Flyweight Patterns*.
Es besteht im Wesentlichen aus vier Teilen:

  * **FlyweightBase**: Definiert eine Schnittstelle, �ber die *Flyweight* Objekte einen externen
    Zustand empfangen und darauf operieren k�nnen.
  * **ConcreteFlyweight**: Implementiert die *Flyweight* Objekt Schnittstelle und f�gt Speicher f�r den intrinsischen Status (gemeinsam genutzten Status) hinzu, falls vorhanden.
    Ein ConcreteFlyweight-Objekt muss "gemeinsam nutzbar" (*sharable*) sein.
    Jeder Zustand, den dieses Objekt speichert, muss intrinsisch sein,
    d.h. er muss unabh�ngig vom Kontext des `ConcreteFlyweight`-Objekts sein.
  * **UnsharedFlyweight**: Nicht alle *Flyweight* Unterklassen k�nnen gemeinsam genutzt werden
    Die *Flyweight* Objekt Schnittstelle erm�glicht das Teilen, erzwingt es jedoch nicht
    Es ist �blich, dass `UnsharedFlyweight`-Objekte `ConcreteFlyweight`-Objekte als
    Kind-Objekte ab einer bestimmten Ebene in der Flyweight-Objektstruktur haben.
  * **FlyweightFactory**: Die *FlyweightFactory* erstellt und verwaltet *Flyweight* Objekte.
    Dar�ber hinaus verwaltet die Fabrik einen Pool unterschiedlicher *Flyweight* Objekte.
    Die Fabrik gibt bei einer entsprechenden Anforderung ein Objekt aus dem Pool zur�ck,
    falls es bereits erstellt wurde,
    oder f�gt dem Pool ein Neues hinzu und gibt dieses zur�ck, falls dies der Anforderung entspricht.


<img src="dp_flyweight.png" width="500">

Abbildung 1: Schematische Darstellung des *Flyweight Patterns*.


#### Conceptual Example:

Die Anregung zum konzeptionellen Beispiel finden Sie unter

[https://refactoring.guru/design-patterns](https://refactoring.guru/design-patterns/flyweight)

und

[https://www.codeproject.com](https://www.codeproject.com/Articles/438922/Design-Patterns-2-of-3-Structural-Design-Patterns#Flyweight)

vor.

#### Beginners Example:

#### 'Real-World' Beispiel:

To be done:

## Literaturhinweise

*Hinweise*:

---

[Zur�ck](../../Readme.md)

---
