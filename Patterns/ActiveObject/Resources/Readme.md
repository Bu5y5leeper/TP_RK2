# Active Object Pattern

[Zur�ck](../../../Resources/Readme_05_Catalog.md)

---

## Wesentliche Merkmale

#### Kategorie: *Concurrency Pattern*

###### In einem Satz:

&ldquo;*Active Object* ist ein *Concurrency Pattern*, bei dem man versucht, den Aufruf einer Methode von ihrer Ausf�hrung zu trennen.&rdquo;

#### Ziel / Absicht:

Das *Active Object* entkoppelt den Methodenaufruf von der Methodenausf�hrung.
Der Methodenaufruf wird im Kontext des Client-Threads ausgef�hrt,
die Methodenausf�hrung selbst in einem Thread des *Active Objects*.

Das *Active Object* verwaltet (mindestens) einen Thread (Kontrollthread) und eine Liste (Warteschlange)
von Objekten, die einen Methodenaufruf beschreiben und die auszuf�hren sind.

Ein Methodenaufruf eines Clients reiht einen *Request* in der Warteschlange des *Active Objects* ein (auch als *ActivationList* bezeichnet).
Derartige *Requests* k�nnen bei der Ausf�hrung an einen Server weitergeleitet werden.

Das Pattern wurde ma�geblich von *Douglas C. Schmidt* von der Vanderbilt University entwickelt.
Er beschreibt es in dem Buch
[Pattern-Oriented Software Architecture: Volume 2](https://www.amazon.de/Pattern-Oriented-Software-Architecture-Concurrent-Networked/dp/0471606952)
auf folgende Weise:

  > Das *Active Object Pattern* entkoppelt die Methodenausf�hrung vom Methodenaufruf,
  um die Parallelit�t zu verbessern und den synchronisierten Zugriff auf Objekte zu vereinfachen,
  die sich in einem eigenen Kontrollthread befinden.

---

#### Struktur:

Die Schl�sselelemente des *Active Object* Patterns sind:

  * Proxy (oder auch Client) &ndash; Der Proxy stellt eine Schnittstelle f�r die �ffentlichen Member-Funktionen
  des aktiven Objekts bereit. Der Proxy l�st damit die Erstellung eines Request-Objekts
  in der *ActivationList* aus. Der Proxy l�uft im Client-Thread.

  * Dispatch Queue (auch *ActivationList*) &ndash; Die Aktivierungsliste
  verwaltet die ausstehenden Anfragen. Die Aktivierungsliste entkoppelt den Thread des Clients
  vom Thread des aktiven Objekts. Der Proxy f�gt Anforderungsobjekte ein und der Scheduler entfernt diese.
  Folglich muss der Zugriff auf die Aktivierungsliste serialisiert werden.

  * Scheduler &ndash; Der Scheduler l�uft im Thread des aktiven Objekts und entscheidet, welche Anfrage aus der Aktivierungsliste als n�chstes ausgef�hrt wird.

  * Result Handle (im Regelfall ein `std::future`-Objekt)  &ndash;
  Wenn der Request ein Ergebnis zur�ckgibt, erh�lt der Client zu diesem Zweck ein `std::future`-Objekt
  und kann dadurch das Ergebnis des Methodenaufrufs erhalten.
  Dieser Zugriff kann blockierend oder nicht-blockierend sein.

<img src="dp_active_object_01.svg" width="700">

*Abbildung* 1: Schematische Darstellung des *Active Object* Patterns.

---

#### Ein Vergleich

*Bemerkung*: Das *Active Object Pattern* weist �hnlichkeiten zum *Command Pattern* auf. 
Im Prinzip beschreibt es eine Variante des *Command Patterns* ausgelegt f�r Nebenl�ufigkeit.

---

#### Conceptual Example:

Das konzeptionelle Beispiel soll in einer vereinfachenden Betrachtung
die Schl�sselelemente des *Active Object* Patterns vorstellen.

Es treten im *Active Object* ein Scheduler und eine so genannte *ActivationList* auf:
Unter einer *ActivationList* verstehen wir eine FIFO-Warteschlange,
die einzelne Methodenaufrufe verwaltet.

Das Beispiel ist mit C++ 11 Sprachmitteln realisiert.
Es orientiert sich stark an dem Beispiel aus
[Wikipedia](https://en.wikipedia.org/wiki/Active_object),
das dort allerdings in Java realisiert ist.

Das konzeptionelle Beispiel besitzt &ndash; in Folge seiner vereinfachenden Darstellung &ndash; einige Nachteile:

  * Client (Proxy) und *Active Object* werden durch dasselbe Objekt dargestellt.
  * Die Methodenaufrufe liefern keinen Ergebniswert zur�ck.

[Quellcode](../ConceptualExample.cpp)

---

#### Erstes Real-World Example:

Das Beispiel veranschaulicht eine einfache Umsetzung des *Active Object* Patterns mit C++&ndash;Sprachmitteln wie
`std::future`, `std::packaged_task` und `std::jthread`.

Neben vielen Vereinfachungen wird auch gezeigt, wie ein berechnetes Ergebnis vom *Active Object* zum Client
transportiert werden kann.

---

#### Zweites Real-World Example:

Das &ldquo;Real-World&rdquo;-Beispiel berechnet die Summe der nat�rlichen Zahlen von 1 bis *n*.
Das k�nnte man nat�rlich in einem einzigen Thread abhandeln, und mit Hilfe der Gau�sche Summenformel lie�e sich
die Berechnung nochmals vereinfachen.
Dennoch habe ich dieses Beispiel gew�hlt, um zum Einen das Beispiel bzgl. des Anwendungsfalls 
einfach zu gestalten, und zum anderen, weil sich die  Summe der nat�rlichen Zahlen von 1 bis *n* auch abschnittweise berechnen l�sst.
An dieser Stelle kommen nun viele Teilaufgaben und ein *Active Object* ins Spiel.

Das Beispiel liegt in 2 Versionen vor:

[Client in synchroner Ausf�hrung](../ActiveObject_02.cpp)

[Client in asynchroner Ausf�hrung](../ActiveObject_03.cpp)

Das Beispiel gewinnt dann an Charme, wenn die vielen Tasks (Teilaufgaben) an das *Active Object* von unterschiedlichen
Threads aus eingestellt werden. Man vergleiche zu diesem Zweck die Ausgaben in der Konsole.


<img src="dp_active_object_02.svg" width="700">

*Abbildung* 2: Zusammenspiel der Komponenten des *Active Object* Patterns.

---

[Zur�ck](../../../Resources/Readme_05_Catalog.md)

---

## Literaturhinweise

Die Anregungen zum konzeptionellen Beispiel finden Sie unter

[Revisiting the Active Object Pattern - with C++11 Closures](https://www.codeproject.com/Articles/991641/Revisiting-the-Active-Object-Pattern-with-Cplusplu).

Die anderen Beispiele orientieren sich an Beispiel aus dem Blog von Rainer Grimm:

[Active Object](https://www.modernescpp.com/index.php/active-object/)

---

[Zur�ck](../../../Resources/Readme_05_Catalog.md)

---
