# Katalog der Entwurfsmuster

Historisch gesehen wurde eine erste Aufstellung f�r Software Entwurfsmuster
von den vier Autoren Erich Gamma, Richard Helm, Ralph Johnson und John Vlissides im Jahre 1994
in einem Buch mit dem Titel "Design Patterns - Elemente wiederverwendbarer objektorientierter Software" gegeben.

Diese Autoren, zusammen auch als "*Gang of Four*" ("*GOF*") bekannt,
nehmen hier eine Kategorisierung der von ihnen beschriebenen Entwurfsmuster
in die drei Kategorien Erzeugungs-, Struktur- und Verhaltensmuster
(*Creational*, *Structural* und *Behavioral Design Patterns*) vor. Eine Aufstellung 
der einzelnen Entwurfsmuster dieser Kategorien finden Sie nachstehend in Abbildung 1 vor:

<img src="Resources/dp_overview.png" width="700">

Abbildung 1: Software Entwurfsmuster nach Erich Gamma, Richard Helm, Ralph Johnson und John Vlissides ("*GoF*").

#### Entwurfsmuster nach Gamma, Helm, Johnson und Vlissides

##### Erzeugungssmuster

In der Softwareentwicklung sind Erstellungsmuster (so genannte *Creational Patter*) Entwurfsmuster,
die sich mit Objekterstellungsmechanismen befassen und in Situationen verwendet werden,
in denen die klassischen Formen der Objekterzeugung zu Entwurfsproblemen f�hren
oder die Komplexit�t des Codes erh�hen.

| Muster | Kurzbeschreibung |
|:-------------- |----|
| [Factory Method](FactoryMethod/Resources/Readme.md) | Das **Factory Method** Entwurfsmuster dient der Entkopplung des Clients von der konkreten Instanziierung einer Klasse. Das erstellte Objekt kann elegant ausgetauscht werden.. |
| [Abstract Factory](AbstractFactory/Resources/Readme.md) | Das **Abstract Factory** Design Pattern dient der Definition einer zusammenh�ngenden Familie aus Produkten. Die Familien k�nnen elegant ausgetauscht werden. |
| [Builder](Builder/Resources/Readme.md) | Erm�glicht schrittweises Erstellen komplexer Objekte. |
| [Prototype](Prototype/Resources/Readme.md) | Erstellen von Kopien vorhandener Objekte, ohne den Code von diesen Klassen abh�ngig zu machen. |
| [Singleton](Singleton/Resources/Readme.md) | Das **Singleton** Entwurfsmuster sorgt daf�r, dass es von einer Klasse nur eine einzige Instanz gibt und diese global zug�nglich ist. |

Tabelle 1. Erzeugungsmuster (*Creational Design Patterns*).

##### Strukturmuster

Strukturmuster beschreiben, wie sich Objekte und Klassen zu gr��eren Strukturen zusammensetzen lassen,
ohne dabei einen Verlust an Flexibilit�t und Effizient einzugehen.

| Muster | Kurzbeschreibung |
|:-------------- |----|
| [Adapter](AdapterPattern/Resources/Readme.md) | Erm�glicht die Interaktion von Objekten mit inkompatiblen Schnittstellen. |
| [Bridge](Bridge/Resources/Readme.md) | Aufteilung einer gr��eren Klasse oder einer Reihe eng verwandter Klassen in zwei separate Hierarchien - Abstraktion und Implementierung. |
| [Composite Pattern](CompositePattern/Resources/Readme.md) | Das **Composite** Entwurfsmuster erm�glicht es, eine verschachtelte (Baum)Struktur einheitlich zu behandeln, unabh�ngig davon, ob es sich um ein atomares Element oder um ein Beh�lter f�r weitere Elemente handelt. Der Client kann elegant mit der Struktur arbeiten. |
| [Decorator](DecoratorPattern/Resources/Readme.md) | Hinzuf�gen neuen Verhaltens zu Objekten, indem diese Objekte in speziellen H�llen-Objekten platziert werden, die dieses Verhalten besitzen. |
| Facade | Bereitstellung einer vereinfachten Schnittstelle zu einer Bibliothek, einem Framework oder einer Menge von Objekten. |
| [Flyweight](Flyweight/Resources/Readme.md) | Erm�glicht es, Objekte ressourcenschonended anzulegen, indem diese gemeinsame Zustandsdaten zwischen mehreren Objekten teilen, anstatt derartige Zustandsdaten in jedem Objekt zu duplizieren. |
| [Proxy](Proxy/Resources/Readme.md) | Bereitstellung eines Platzhalters (Stellvertreters) f�r ein anderes Objekt. Das Proxy-Objekt steuert den Zugriff auf das urspr�ngliche Objekt. Vor oder nach der Ausf�hrung der eigentlichen Anforderung am urspr�nglichen Objekt lassen sich zus�tzliche Aktionen erg�nzen. |

Tabelle 2. Strukturmuster (*Structural Design Patterns*).

##### Verhaltensmuster

Verhaltensentwurfsmuster betrachten Algorithmen und der Aufteilung von Verantwortlichkeiten zwischen Objekten.

| Muster | Kurzbeschreibung |
|:-------------- |----|
| [Chain of Responsibility](ChainOfResponsibility/Resources/Readme.md) | Erm�glicht das Weiterleiten von Anforderungen entlang einer Kette von Handlern. Nach Erhalt einer Anforderung entscheidet jeder Handler, die Anforderung entweder zu verarbeiten oder an den n�chsten Handler in der Kette weiterzuleiten. |
| [Command Pattern](CommandPattern/Resources/Readme.md) | Das **Command** Entwurfsmuster erm�glicht die Modularisierung von Befehlen und Aufrufen. Auf elegante Weise k�nnen Befehle r�ckg�ngig gemacht, protokolliert oder in einer Warteschlange gelegt werden. |
| Interpreter | Das **Interpreter** Entwurfsmuster definiert eine Repr�sentation f�r die Grammatik einer Sprache und die M�glichkeit, S�tze dieser Sprache zu interpretieren. |
| [Iterator](IteratorPattern/Resources/Readme.md) | Erm�glicht das Traversieren (Durchlaufen) von Elementen einer listenartigen Datenstruktur, ohne die zugrunde liegende Darstellung (Liste, Array,  Stapel, Baum usw.) bekannt zu machen. |
| Mediator | Das **Mediator** Muster dient zum Steuern des kooperativen Verhaltens von Objekten, wobei Objekte nicht direkt kooperieren, sondern �ber einen Vermittler. |
| [Memento](Memento/Resources/Readme.md) | Das **Memento** Entwurfsmuster dient der Erfassung und Spaicherung des internen Zustands eines Objektes. Hiermit kann man den vorherigen Status eines Objekts speichern und wiederherstellen, ohne Details der Implementierung preisgeben zu m�ssen. |
| [Observer](Observer/Resources/Readme.md) | Das **Observer** Entwurfsmuster ist f�r Situation geeignet, in denen ein oder mehrere Objekte benachrichtigt werden m�ssen, sobald sich der Zustand eines bestimmten Objekts �ndert. |
| [State](StatePattern/Resources/Readme.md) | 	Das **State** Entwurfsmuster erm�glicht die elegante Modellierung von zustandsabh�ngigen Verhalten eines Objekts. Je nach internen Zustand �ndert sich das Verhalten des Objekts, es scheint, als h�tte das Objekt seine Klasse ge�ndert. |
| [Strategy Pattern](StrategyPattern/Resources/Readme.md) | Beschreibt eine Familie von Algorithmen, kapselt jeden einzelnen und macht sie austauschbar. Das Strategiemuster erm�glicht es, den Algorithmus unabh�ngig von ihn nutzenden Klienten zu variieren. |
| [Template Method](TemplatePattern/Resources/Readme.md) | Definiert das Grundger�st eines Algorithmus in einer Oberklasse, l�sst Unterklassen bestimmte Schritte des Algorithmus �berschreiben, ohne dabei �nderungen an der prinzipiellen Algorithmusstruktur zu gestatten. |
| Visitor | Befasst sich mit der Trennung von Algorithmen von den Objekten, mit denen sie arbeiten. |

Tabelle 3. Verhaltensmuster (*Behavioral Design Patterns*).

#### Weitere Entwurfsmuster

Neben diesen klassischen Entwurfsmustern finden sich in verschiendenen Publikationen weiterere
Gruppierungen von Entwurfsmustern. In B�chern �ber "Modern C++" st��t man h�ufig auf folgende Entwurfsmuster:

| Muster | Kurzbeschreibung |
|:-------------- |----|
| RAII (Resource Acquisition Is Initialization) | Objektlebenszeit und Ressourcenverwaltung |
| [Opaque Pointer / Pimpl](OpaquePointer/Resources/Readme.md)  | *Pointer to implementation* |
| [Null Object](NullObject/Resources/Readme.md) | Null Objekt |
| SFINAE | *Substitution failure is not an error* |
| CRTP | *Curiously recurring template pattern* |

Tabelle 4: Weitere Software (*Modern C++*)

In einem weiteren Buch [Robert Nystrom](https://gameprogrammingpatterns.com/),
aktuell bei der Fa. Google in der Entwicklung der Programmiersprache Dart besch�ftigt,
finden sich weitere interessante Entwurfsmuster:

| Muster | Kurzbeschreibung |
|:-------------- |----|
| Double Buffer | TBD |
| Game Loop | TBD |
| Update Method | TBD |

Tabelle 5. Sequencing Patterns

sowie

| Muster | Kurzbeschreibung |
|:-------------- |----|
| Bytecode | TBD |
| Subclass Sandbox | TBD |
| Type Object | TBD |

Tabelle 6. Behavioral Patterns

und

| Muster | Kurzbeschreibung |
|:-------------- |----|
| Component | TBD |
| Event Queue | TBD |
| Service Locator | TBD |

Tabelle 7. Decoupling Patterns

und

| Muster | Kurzbeschreibung |
|:-------------- |----|
| Data Locality | TBD |
| Dirty Flag | TBD |
| Object Pool | TBD |

Tabelle 8. Optimization Patterns

F�r den Entwurf von Oberfl�chen gibt es im Prinzip drei "Klassiker"

| Muster | Kurzbeschreibung |
|:-------------- |----|
| MVC | Model-View-Controller |
| MVP | Model-View-Presenter |
| MVVM | Model View View-Model |

Tabelle 9. Entwurfsmuster f�r Oberfl�chen

---

[Zur�ck](Readme.md)

---
