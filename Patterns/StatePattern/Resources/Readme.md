# State Pattern

## Wesentliche Merkmale

#### Kategorie: *Behavioral Pattern*

#### Ziel / Absicht:

Das *State Pattern* ist ein Entwurfsmuster aus der Kategorie der *Behavioral Pattern*.

Das Muster beschreibt, wie ein Objekt sein Verhalten in Abh�ngigkeit
von seinem aktuellen internen Zustand vollst�ndig �ndern kann.
Es scheint, als h�tte das Objekt seine Klasse ge�ndert.

#### Problem:

Dass sich der Zustand eines Objekts ver�ndert, ist zun�chst einmal eine grundlegende Eigenschaft der OO-Programmierung.
Klassen besitzen einen Zustand, �ber das Verhalten (Methoden) der Klasse �ndert sich dieser Zustand.
Was ist nun das Besondere am *State Pattern* Entwurfsmuster?

Manchmal �ndert sich ein Zustand eines Objekts so grundlegend, dass man sich w�nschen w�rde, man h�tte ein Objekt einer anderen Klasse.
Und genau das leistet dieses Muster: Wenn sich der Zustand �ndert, wird das Objekt ausgetauscht, genauer der Teil, der den Zustand abbildet.

Ein gerne zitiertes Beispiel f�r dieses Muster ist ein Objekt der Java-Klasse `Thread`.
Dieses kann eine Reihe sehr unterschiedlicher Zust�nde annehmen:

<img src="java_thread_states.png" width="500">

Abbildung 2: Der Lebenszyklus eines `Thread`-Objekts.

Zu Beginn ist ein `Thread`-Objekt noch nicht gestartet (*ready_to_run*). Danach wird es gestartet (*running*) und der Thread l�uft,
bis er sein nat�rliches Ende erreicht (*dead*). Es kann auch vorkommen, dass der Thread angehalten (*blocked* oder *sleeping*) und wieder fortgesetzt wird (*waiting*).
Es wird deutlich, dass ein Thread, der gerade inaktiv ist, sich v�llig anders verh�lt als ein Thread, der l�uft oder sich schon beendet hat.
Die klassische Herangehensweise an ein derartiges Problem  w�re die Festlegung einer Reihe von Zustandsvariablen. 
Und eine Menge von `if`- und/oder `switch`-Anweisungen, die zerstreut in der Klasse vorliegen und versuchen,
die Komplexit�t in den Griff zu bekommen.

#### L�sung:

Nicht so bei diesem Muster: Das *State Pattern* trennt das eigentliche Objekt und das Objekt, das seinen Zustand verk�rpert.
�ndert sich der Zustand, wird dieses Zustandsobjekt ausgetauscht.
Da hinter jedem Zustandsobjekt eine Klasse steckt, wird der Code f�r jeden Zustand fein s�uberlich von dem Code der anderen Zust�nde getrennt.

Das Verhalten ist zur Laufzeit �nderbar, ohne dass die f�r den Zugriff auf das Objekt
verwendete bzw. vorhandene Schnittstelle sich �ndert.
Die �nderungen sind im Kontext des Objekts verborgen.

Dieses Muster ist sehr n�tzlich beim Erstellen von Software Zustandsautomaten,
bei denen sich die Funktionalit�t eines Objekts je nach Status grundlegend �ndert.

#### Struktur (UML):

Das folgende UML-Diagramm beschreibt eine Implementierung des *State Patterns*.
Es besteht im Wesentlichen aus drei Teilen:

  * **Context**: Diese Klasse hat Zugriff auf das konkrete Statusobjekt,
    das das Verhalten gem�� seinem aktuellen Status bereitstellt. Ohne dieses Entwurfsmuster w�rde die Klasse `Context` die gesamte Funktionalit�t realisieren m�ssen.
  * **StateBase**: Abstrakte Klasse f�r konkrete Zustandsklassen.
    Sie definiert die Schnittstelle, die von der `Context`-Klasse verwendet wird und die in irgendeiner Form mit den Zust�nden zu tun hat.
  * **ConcreteState**: Konkrete Implementierung der `StateBase`-Klasse.
    Die Funktionalit�t dieser Objekte wird von der `Context`-Klasse genutzt.

<img src="dp_state_pattern.svg" width="600">

Abbildung 2: Schematische Darstellung des *State Patterns*.


#### Conceptual Example:

*Hinweis*:

Das *Conceptual Example* liegt in drei Versionen vor:

  * Ein einfaches Beispiel - mit *raw*-Zeigern 
  * Dasselbe Beispiel - mit `std::shared_ptr`-Zeigern
  * Ein zweites einfaches Beispiel

Die Anregung zum konzeptionellen Beispiel finden Sie unter

[https://refactoring.guru/design-patterns](https://refactoring.guru/design-patterns/state/cpp/example#example-0)

und 

[https://www.codeproject.com](https://www.codeproject.com/Articles/455228/Design-Patterns-3-of-3-Behavioral-Design-Patterns#State)

vor.

#### 'Real-World' Example:

Im Buch [Entwurfsmuster: Das umfassende Handbuch](https://www.amazon.de/Entwurfsmuster-umfassende-Handbuch-Matthias-Geirhos/dp/3836227622)
von Matthias Geirhos findet sich zu diesem Entwurfsmuster ein Beispiel zur Modellierung eines Bewerbungsprozesses vor.
Einem Bewerbungsprozess k�nnen in naheliegender Weise Zust�nde wie *Eingegangen*, *Eingeladen* usw. zugeordnet werden.
Sehen Sie die detaillierte Beispielbeschreibung ab Seite 336 an.

Schreiben Sie den Beispielcode aus dem Buch in ein C++-Programm um. Verwenden Sie hierzu die Klassennamen aus Abbildung 3:

<img src="dp_state_pattern_job_application.svg" width="700">

Abbildung 3: Ein Bewerbungsprozess modelliert mit dem *State Pattern*.

Erstellen Sie eine Testmethode, die exemplarisch eine Bewerbung vom Status *Received* (*Eingegangen*) bis zum Status *Hired* (*Eingestellt*) verfolgt.

---

[Zur�ck](../../../Resources/Readme_05_Catalog.md)

---
