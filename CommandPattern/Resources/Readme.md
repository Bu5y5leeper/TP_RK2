# Command Pattern

## Wesentliche Merkmale

#### Kategorie: *Behavioral Pattern*

#### Ziel / Absicht:

Das *Command Pattern* ist ein Entwurfsmuster aus der Kategorie der *Behavioral Pattern*,
das eine Anforderung (einen *Request*, einen Befehl) in ein eigenst�ndiges Objekt umwandelt,
das alle Informationen �ber die Anforderung enth�lt.
Der Befehl kann dann nach Bedarf aufgerufen werden, h�ufig als Teil einer Reihe von Befehlen,
die in der Warteschlange (*Queue*) abgelegt sind.
Die Befehle in einer Warteschlange k�nnen auf diese Weise sequentiell abgearbeitet werden,
denkbar sind auch Rollback/Undo-Funktionalit�ten.

#### Problem:

Das *Command Pattern* ist ein Entwurfsmuster, bei dem alle zur Ausf�hrung einer Methode erforderlichen Informationen
in einem Objekt gekapselt sind, das sofort verwendet oder zum sp�teren Gebrauch aufbewahrt werden kann.
Dieses Objekt f�hrt nichts aus, es enth�lt nur Informationen.

Es gibt drei Schl�sselbegriffe, die zu definieren sind: *Client*, *Invoker* und *Receiver*.
Der *Client* erstellt das Befehlsobjekt ("*Command Object*").
Das *Invoker*-Objekt entscheidet, wann die Methode, deren Informationen (Parameter) im *Command Object* abgelegt sind, aufgerufen werden soll.
Das *Receiver*-Objekt ist eine Instanz einer Klasse, die den Ablaufcode der Methode enth�lt.


#### L�sung:

#### Struktur (UML):

Das folgende UML-Diagramm beschreibt eine Implementierung des *Command Patterns*.
Es besteht im Wesentlichen aus f�nf Teilen:

  * **Client**: Genereller Konsument der Klassen des Entwurfsmusters. Es erstellt die *Command Object* und verkn�pft sie mit *Receiver*-Objekten.
  * **Receiver**: Objekt, das wei�, wie das Kommando (Methode) auszuf�hren ist.
  * **CommandBase**: Abstrakte Klasse (oder Schnittstelle) f�r *Command*-Objekte. Es enth�lt Informationen �ber das *Receiver*-Objekt,
    das f�r die Ausf�hrung einer Operation unter Verwendung der im *Command*-Objekt gekapselten Informationen verantwortlich ist.
  * **ConcreteCommand**: Konkrete Implementierung der abstrakten `CommandBase`-Klasse oder -Schnittstelle.
  * **Invoker**: Objekt, das entscheidet, wann das Kommando ausgef�hrt werden soll.


<img src="command_pattern.png" width="400">

Abbildung 1: Schematische Darstellung des *Command Patterns*.


#### Conceptual Example:

Die Anregung zum konzeptionellen Beispiel finden Sie unter

[https://refactoring.guru/design-patterns](https://refactoring.guru/design-patterns/command/cpp/example#example-0)

vor.


#### Beginners Example:

#### 'Real-World' Beispiel:


## Literaturhinweise

*Hinweise*:

---

[Zur�ck](../../Readme.md)

---
