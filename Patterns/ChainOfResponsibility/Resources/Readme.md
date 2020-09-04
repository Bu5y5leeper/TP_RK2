# Chain of Responsibility Pattern

## Wesentliche Merkmale

#### Kategorie: *Behavioral Pattern*

#### Ziel / Absicht:

Das *Chain of Responsibility Pattern* ist ein Entwurfsmuster,
das eine verkettete Liste von Methoden (*Handlern*) definiert,
von denen jede eine bestimmte Anforderung (Funktionalit�t) verarbeiten kann.
Wenn eine Anforderung an die Liste gesendet wird,
wird sie zun�chst dem ersten Handler in der Liste �bergeben.
Nun entscheidet jeder Handler f�r sich, die Anforderung entweder zu verarbeiten oder
diese an den n�chsten Handler in der Liste weiterzuleiten.

#### Problem:

Im Prinzip betrachten wir das Problem, dass ein bestimmtes Ereignis von einem anderen Objekt zu verarbeiten ist.
Das *Chain of Responsibility Pattern* ist eine formale Beschreibung dieses Problems.
Wir haben in diesem Muster eine *Quelle* (*Ereignis*, *Event*) und mehrere Objekte, die auf dieses Ereignis reagieren wollen.
Das Ereignis wird bei Eintreten an das erste Verarbeitungsobjekt �bergeben.
Dieses kann den Befehl verarbeiten (oder auch nicht) und/oder an seinen Nachfolger senden.
Dies wird solange fortgesetzt, bis der Befehl verarbeitet wurde oder das Ende der Kette erreicht ist.
Das Objekt, das den Befehl sendet (das Ereignis ausgel�st hat), wei� nicht, welches Objekt in der Kette aller Verarbeitungsobjekte
den Befehl verarbeitet hat.

Bzgl. der Verarbeitung sind mehrere Szenarien denkbar: Hat ein Verarbeitungsobjekt die Anfrage �bernommen,
kann es das Weiterreichen der Anfrage an die noch vorhandenen Objekte in der Kette unterlassen ("*Single-Cast*" Szenario).
Umgekehrt ist es denkbar, dass eine Anfrage prinzipiell die gesamte Kette aller Verarbeitungsobjekte durchl�uft.
Kein, ein oder mehrere Objekte k�nnen hierbei ihren Beitrag zur Abarbeitung des Ereignisses beitragen.


#### L�sung:

Das Pattern erm�glicht es, eine Anfrage an eine Kette von Verarbeitungsobjekten zu senden,
ohne wissen zu m�ssen, welches Objekt / welche Objekte die Anfrage bearbeiten.
Die Anfrage wird entlang der Kette weitergeleitet, bis ein oder mehrere Empf�nger die Anfrage bearbeiten.
Es kann auch sein, dass das Ereignis von keinem Empf�nger bearbeitet wird.
Der Absender eines Ereignisses ist nicht mit einem bestimmten Empf�nger direkt verbunden.


#### Struktur (UML):

Das folgende UML-Diagramm beschreibt eine Implementierung des *Chain of Responsibility Patterns*.
Es besteht im Wesentlichen aus drei Teilen:

  * **Client**: Diese Klasse �bergibt das Ereignis (die Anforderung) an das erste Objekt in der Kette der Verarbeitungsobjekte.
  * **HandlerBase**: Repr�sentiert eine Schnittstelle oder Basisklasse f�r die konkreten Handler einer Verarbeitungskette.
    Typischerweise enth�lt es eine Instanzvariable, die auf das n�chste Handlerobjekt in der Verarbeitungskette verweist.
  * **ConcreteHandler**: Konkrete Implementierung der `HandlerBase`-Klasse.


<img src="dp_chain_of_responsibility.svg" width="700">

Abbildung 1: Schematische Darstellung des *Chain of Responsibility Patterns*.


#### Conceptual Example:

[Quellcode](../ConceptualExample.cpp)

---

Die Anregungen zum konzeptionellen Beispiel finden Sie unter

[https://refactoring.guru/design-patterns](https://refactoring.guru/design-patterns/chain-of-responsibility/cpp/example#example-0)

und 

[https://www.codeproject.com](https://www.codeproject.com/Articles/455228/Design-Patterns-3-of-3-Behavioral-Design-Patterns#Chain)

vor.

## Weiterarbeit:

Siehe das Beispiel unter

https://www.codeproject.com/Articles/455228/Design-Patterns-3-of-3-Behavioral-Design-Patterns#Command

---

[Zur�ck](../../../Resources/Readme_05_Catalog.md)

---
