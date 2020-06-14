# Chain of Responsibility

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


#### L�sung:

#### Struktur (UML):

Das folgende UML-Diagramm beschreibt eine Implementierung des *Command Patterns*.
Es besteht im Wesentlichen aus f�nf Teilen:

  * **Client**: Genereller Konsument der Klassen des Entwurfsmusters. Er erstellt das *Command Object* und verkn�pft es mit *Receiver*-Objekten.
  * **Receiver**: Objekt, das wei�, wie das Kommando (Methode) auszuf�hren ist.
  * **CommandBase**: Abstrakte Klasse (oder Schnittstelle) f�r *Command*-Objekte. Enth�lt Informationen �ber das *Receiver*-Objekt,
    das f�r die Ausf�hrung der Operation unter Verwendung der im *Command*-Objekt abgelegten Informationen verantwortlich ist.
  * **ConcreteCommand**: Konkrete Implementierung der abstrakten `CommandBase`-Klasse oder -Schnittstelle.
  * **Invoker**: Objekt, das entscheidet, wann das Kommando ausgef�hrt werden soll.


<img src="dp_command_pattern.png" width="700">

Abbildung 1: Schematische Darstellung des *Command Patterns*.


#### Conceptual Example:

Die Anregung zum konzeptionellen Beispiel finden Sie unter

[https://refactoring.guru/design-patterns](https://refactoring.guru/design-patterns/command/cpp/example#example-0)

und 

[https://www.codeproject.com](https://www.codeproject.com/Articles/455228/Design-Patterns-3-of-3-Behavioral-Design-Patterns#Command)

vor.

#### Beginners Example:

#### 'Real-World' Beispiel:

To be done:

"Robot Movements"

https://www.codeproject.com/Articles/455228/Design-Patterns-3-of-3-Behavioral-Design-Patterns#Command


## Literaturhinweise

*Hinweise*:

---

[Zur�ck](../../Readme.md)

---
