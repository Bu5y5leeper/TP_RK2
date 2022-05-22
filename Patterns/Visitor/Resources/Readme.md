# Visitor Pattern

[Zur�ck](../../../Resources/Readme_05_Catalog.md)

---

<img src="dp_visitorpattern_intro.png" width="600" />

<sup>(Credits: [Blog von Vishal Chovatiya](http://www.vishalchovatiya.com/category/design-patterns/))</sup>

---

## Wesentliche Merkmale

#### Kategorie: *Behavioral Pattern*

#### Ziel / Absicht:

###### In einem Satz:

&ldquo;Hinzuf�gen einer neuen Operation f�r eine Gruppe �hnlicher Objekte oder Hierarchien.&rdquo;

Das *Visitor Pattern* ist ein Entwurfsmuster aus der Kategorie der *Behavioral Pattern*,
das eine Menge strukturierter Daten von den Funktionen trennt,
die auf ihr ausgef�hrt werden. Dies unterst�tzt zum einen das Prinzip der "losen Kopplung"
und es erm�glicht zum anderen das Hinzuf�gen zus�tzlicher Operationen, ohne an den Datenklassen �nderungen vornehmen zu m�ssen.

Im Kern geht es darum, eine Hierarchie von Klassen und Operationen auf diesen Klassen voneinander zu trennen.

#### Prinzip:

Das Muster definiert eine Art Infrastruktur f�r den Zugriff auf komplexe dynamische Daten- und Objektstrukturen.
Dabei wird der dynamischen Struktur eine Methodenschnittstelle gegeben, die ein sogenanntes &ldquo;Besucher&rdquo;-Objekt entgegennimmt
und �ber alle Daten der Struktur schleust. Das &ldquo;Besucher&rdquo;-Objekt l�uft also an allen Elementen der Struktur entlang
und wird von den Elementen �ber eine Methode &ldquo;akzeptiert&rdquo;.
Die Konvention besteht darin, diese Methode `accept` zu nennen.
Dabei ruft das Strukturelement eine Methode im &ldquo;Besucher&rdquo;-Objekt auf,
die speziell f�r den Typ des Strukturelements geschrieben wurde und eine Referenz oder einen Zeiger
auf das Strukturelement in ihrer Parameterliste hat.
Damit hat der Visitor wiederum die Chance, eine Operation auf dem Strukturelement auszuf�hren
und dabei auf dessen Typ zu reagieren.

Der Sinn des Visitors besteht darin, die eigentliche Operation auf den Daten von der Traver�sierung
der Verwaltungs�struktur zu trennen. Aus der Entkopplung dieser beiden Aspekte entstehen
Freiheitsgrade f�r Variationen dieses Entwurfsmusters.


#### L�sung:

Die Traver�sierung wird durch die erw�hnte Infra�struktur aus Methoden �bernommen.
Die durch den Visitor transpor�tierte Operation wird in einer Kindklasse der Visitor�schnitt�stelle implementiert.
Damit lassen sich beliebige Operationen definieren
und durch den allgemeinen Traversierungs�mechanismus in die Objekt�struktur tragen.
Mit dem Namen des Visitors wird das Verhalten des Musters gew�rdigt.
Das Visitor�objekt geht die Objekte in der Objekt�struktur &ldquo;besuchen&rdquo;.

Das Ergebnis der Trennung von Objektstruktur und Funktionen (Algorithmen) ist ein Datenmodell
mit eingeschr�nkter Funktionalit�t und einer Gruppe von &ldquo;*Besuchern*&rdquo;,
die Operationen auf den Daten ausf�hren.
Ein weiterer Vorteil ist die M�glichkeit, einen neuen *Besucher* hinzuf�gen zu k�nnen,
ohne dabei die vorhandene Struktur �ndern zu m�ssen. 
Die Daten-Klassen sind mit Attributen (Eigenschaften, *getter*/*setter*-Methoden) so zu erstellen,
dass diese vom &ldquo;Besucher&rdquo;-Objekt geeignet verwendet werden k�nnen.
Typischerweise wird das Datenobjekt als Parameter an eine Methode des &ldquo;Besucher&rdquo;-Objekts �bergeben
(die Konvention besteht darin, diese Methode `visit` zu nennen).

#### Struktur (UML):

Das folgende UML-Diagramm beschreibt eine Implementierung des *Visitor Patterns*.
Es besteht im Wesentlichen aus sechs Teilen:

  * **Client**: Anwender des *Visitor Patterns*. Er verwaltet die Objektstruktur und weist die Objekte innerhalb der Struktur an,
    wann ein Besucher akzeptiert werden soll.
  * **ObjectStructure**: Dies ist eine Klasse, die alle Objekte enth�lt, die besucht werden k�nnen.
    Es bietet einen Mechanismus zum Traversieren aller Elemente.
    Diese Struktur muss nicht zwingend eine *Collection* sein, es kann irgend eine komplexe Struktur sein, beispielsweise ein *Composite Object*.
  * **ElementBase**: Stellt eine Abstraktionsschnittstelle dar, die die `accept`-Operation deklariert. Dies ist der Einstiegspunkt, an dem ein Objekt vom Besucherobjekt &ldquo;besucht&rdquo; werden kann.
    Jedes Objekt aus einer *Collection* sollte diese Abstraktionsschnittstelle implementieren, um besucht werden zu k�nnen.
  * **ConcreteElement**: Diese Klassen erben von der abstrakten Basisklasse `ElementBase` oder implementieren eine Schnittstelle
    und definieren eine `accept`-Operation. Das *Visitor*-Objekt wird durch die `accept`-Operation an dieses Objekt �bergeben.
  * **VisitorBase**: Deklariert eine `visit`-Methode (Operation) f�r jede Klasse von `ConcreteElement` in der Objektstruktur.
    Der Name und die Signatur der Operation identifizieren die Klasse, die die Anforderung an den Visitor sendet.
    Auf diese Weise kann der Besucher die konkrete Klasse des besuchten Elements bestimmen.
    So kann der Besucher direkt �ber diese spezielle Schnittstelle auf die fraglichen Elemente zugreifen.
  * **ConcreteVisitor**: Implementiert jede von einem Visitor deklarierte Operation (Methode).
    Jede Operation implementiert ein Fragment eines Algorithmus, der f�r die entsprechende Klasse oder das entsprechende Objekt in der Objektstruktur definiert ist.
    `ConcreteVisitor` stellt den Kontext f�r den Algorithmus bereit und speichert seinen lokalen Status.
    Dieser Zustand sammelt h�ufig Ergebnisse w�hrend des Durchlaufens der Struktur.

<img src="dp_visitor_pattern.svg" width="600">

*Abbildung* 1: Schematische Darstellung des *Visitor Patterns*.

---

#### Conceptual Example:

[Quellcode](../ConceptualExample.cpp)

*Hinweis*: Im konzeptionellen Beispiel ist der Aspekt `enable_shared_from_this` und `shared_from_this` 
mit abgehandelt.

---

Die Anregungen zum konzeptionellen Beispiel finden Sie unter

[https://refactoring.guru/design-patterns](https://refactoring.guru/design-patterns/visitor/cpp/example#example-0)

und 

[https://www.codeproject.com](https://www.codeproject.com/Articles/455228/Design-Patterns-3-of-3-Behavioral-Design-Patterns#Visitor)

vor.

#### 'Real-World' Beispiel:

Im Buch [Entwurfsmuster: Das umfassende Handbuch](https://www.amazon.de/Entwurfsmuster-umfassende-Handbuch-Matthias-Geirhos/dp/3836227622)
von Matthias Geirhos findet sich zu diesem Entwurfsmuster ein Beispiel aus der Welt des Onlinehandels vor.
Sagen wir, ein Onlineh�ndler w�rde B�cher, Spiele und Videos verkaufen.
Das ist nichts Neues, und ein Warenkorb mit B�chern, Spielen und Videos stellt auch keine gro�e Herausforderung dar.

Nun aber kommen die Methoden ins Spiel. Mit den Elementen eines Warenkorbs kann man sehr unterschiedliche Dinge anstellen wie zum Beispiel:

  * Berechnung des Gesamtpreises aller Artikel im Warenkorb,
  * Zusammenstellung des Inhalts des Warenkorbs als HTML f�r die Website des Onlinehandels,
  * Erstellung einer Rechnung zum Inhalt des Warenkorbs als PDF,
  * ...

Und nat�rlich gibt es noch viele Methoden, die nur einzelnen Klassen (`Buch`, `Spiel`, ...) vorbehalten sind.

Damit sind wir im Zentrum des Musters angekommen: Es trennt die Klassenhierarchie von den Operationen, die
stattdessen in eine zweite Hierarchie wandern. Und anstatt die Operation direkt aufzurufen,
erstellen wir ein Objekt f�r diese auszuf�hrende Operation (den so genannten *Visitor*) und �bergeben es
dem Objekt der fachlichen Hierarchie (der so genannten *ObjectStructure*),
die dann die Operation aufruft.

Studieren Sie den Beispielcode aus dem Buch und f�hren Sie diesen in ein C++-Programm �ber. Betrachten Sie hierzu auch *Abbildung* 2:

<img src="dp_visitor_pattern_onlineshop.svg" width="700">

*Abbildung* 2: Ein Onlinehandel modelliert mit dem *Visitor Pattern*.

Studieren Sie die Realisierung der zwei *Visitor*-Klassen, eine f�r die Berechnung des Gesamtpreises aller Artikel im Warenkorb und eine weitere
zur Darstellung des Inhalts des Warenkorbs in HTML.

Implementieren Sie zwei weitere *Visitor*-Klassen: Eine namens `CountVisitor`, die einfach die Anzahl aller Artikel im Warenkorb bestimmt.
Und eine zweite Klasse `TextVisitor`, die den Inhalt des Warenkorbs in textueller Form f�r eine Versandbest�tigung zusammenstellt.


## Weiterarbeit:

Eng verwandt mit dem  *Visitor Pattern* ist das  *Double Dispatch* Pattern. Siehe hierzu

[Visitor and Double Dispatch](https://refactoring.guru/design-patterns/visitor-double-dispatch)

und 

[Double Dispatch in C++](http://www.vishalchovatiya.com/double-dispatch-in-cpp/)

---

[Zur�ck](../../../Resources/Readme_05_Catalog.md)

---
