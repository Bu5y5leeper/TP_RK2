# Policy-Based Design

[Zur�ck](../../../Resources/Readme_05_Catalog.md)

---

## Wesentliche Merkmale

#### Kategorie: *Structural Pattern*

#### Ziel / Absicht:

###### In einem Satz:

&ldquo;*Policies* stellen Schnittstellen f�r konfigurierbare Belange einer Klasse dar.&rdquo;

#### Problem / Motivation

Wir bewegen uns im Problemfeld &ldquo;*Entwurfsentscheidungen*&rdquo;:

  * Stichwort:  &ldquo;*Wie man es macht, macht man es falsch&rdquo;.

  * Eine Strategie kann sein: Entscheidungen sollte nicht beim Entwickler einer Klasse liegen, sondern beim Anwender.





#### L�sung:

  * Ziel: Klassen konfigurierbar gestalten

  * Schaffung einer Auswahlm�glichkeit f�r verschiedene Verhaltensweisen durch den Anwender.
   

Damit sind wir beim Begriff der &ldquo;Policy&rdquo; angekommen:

  * *Policies* sind Schnittstellen f�r konfigurierbare Belange einer Klasse.
  * Genauer: Eine *Policy* ist eine Klasse oder ein Klassentemplate, die eine Schnittstelle als Dienstleistung zu anderen Klassen definiert. 
  * Eine *Policiy*-Klasse implementiert die von der *Polici* vorgegebene Schnittstelle.
  * Policies sind vom Benutzer der Klasse ausw�hlbar: der Benutzer kann das Verhalten der Host-Klasse durch geeignete Auswahl von Policy-Klassen anpassen

Die Idee des Policy-based Designs kann nun so formuliert werden:

  * Klassen mit komplexem Verhalten werden in eine *Host*-Klasse und mehrere kleinere *Policy*-Klassen zerlegt.
  * Jede *Policy*-Klasse kapselt einen Belang der *Host*-Klasse.
  * Verbindung der komplexen Klasse mit den Policy-Klassen �ber C++ Templates m�glich.

  
Policies sind vom Benutzer der Klasse ausw�hlbar:

  * Der Benutzer kann also das Verhalten der Host-Klasse durch geeignete Auswahl von Policy-Klassen anpassen


#### Struktur (UML):

Das folgende UML-Diagramm beschreibt eine Implementierung des *Adapter Patterns*.
Es besteht im Wesentlichen aus vier Teilen:

  * **Client**: Stellt die Klasse dar, die eine inkompatible Schnittstelle verwenden muss.
    Diese inkompatible Schnittstelle wird von der Klasse `Adaptee` implementiert.
  * **Target**: Definiert die Schnittstelle, die der Client kennt und verwendet.
  * **Adaptee**: Stellt eine Klasse dar, die eine vom Client ben�tigte Funktionalit�t bietet. Typischerweise unterst�tzt die `Adaptee`-Klasse die `Target`-Schnittstelle nicht.
  * **Adapter**: Konkrete Implementierung des Adapters. Diese Klasse �bersetzt die inkompatible Schnittstelle von `Adaptee` in die Schnittstelle, die der Client verwendet.

<img src="dp_adapter_01.svg" width="700">

*Abbildung* 1: Schematische Darstellung des *Adapter Patterns*.

Der Klassenname `Adaptee` steht stellvertretend f�r Service-Klassen, die es gilt,
�ber Adapter-Klassen verf�gbar zu machen.


---



## Typische Realisierung von *Policy*-Klassen

Es gibt zwei typische Vorgehensweisen zur Implementierung von *Policy*-Klassen: Komposition und Vererbung.

#### Komposition

Wir stellen eine Klasse `Logger` vor, deren Ausgaben mit Hilfe einer *Policy*-Klasse in eine Datei oder auf die Konsole
gelenkt werden k�nnen:

XXXX

Die Methode `log` der `Logger`-Klasse greift f�r Ausgaben auf das *Policy*-Objekt zur�ck. Hierin
dr�ckt sich die Konfigurierbarkeit der `Logger`-Klasse aus.


#### Vererbung




#### Komposition und Vererbung im Vergleich

Welchen Weg sollten wir einschlagen, wenn wir eine *Policy*-Klasse realisieren wollen?

Dazu machen wir zun�chst eine m�glicherweise �berraschende Aussage:
Die beiden Varianten unterscheiden sich in der Gr��e ihrer Objekte (Anzahl Bytes im Speicher)!
Woran liegt das?


Die beiden soeben betrachteten *Policy*-Objekte hatten keine Instanzvariablen.
Die Anzahl Bytes dieses Objekte ist jedoch nicht 0, sondern 1!

�berpr�fen k�nnen wir das mit Ausgaben der Gestalt

std::cout << sizeof(LogToConsole) << std::endl;

Diese Festlegung ist notwendig, da jedes Objekt in einem C++ ;ndash& Programm eine eindeutige Adresse haben muss:

LogToConsole p1;      // & p1 = ...
LogToFile p2;         // & p2 may not be & p1 !!!!

Wenn zwei Objekte nacheinander im Speicher angeordnet sind, betr�gt der Unterschied der beiden Adressen zwischen ihnen
die Gr��e des ersten Objekts (plus Padding, falls erforderlich). 

Um folglich zu verhindern, dass sich die beiden Objekte p1 und p2 an derselben Adresse befinden,
erfordert der C++ Standard, dass ihre Gr��e mindestens gleich ein Byte ist.

Im Umfeld der Vererbung kommt hier eine interessante Beobachtung ins Spiel:

Wenn beispielsweise die Policy `LogToConsole` keine Instanzvariablen besitzt, 
k�nnen wir von der sogenannten &ldquo;Empty Base Class Optimization&rdquo; profitieren.

Sie besagt, dass in diesem Fall eine Policy-Klasse 
*nicht* die Gr��e des `Logger`-Objekts erh�ht.

Bei der Komposition von Klassen ist dies eben nicht der Fall, da  `LogToConsole` mindestens ein Byte zur Gr��e des `Logger`-Objekts hinzuf�gt.
Ber�cksichtigt man noch Padding und Ausrichtung im Speicher, k�nnen hier gleich eine stattliche Anzahl von Bytes hinzugelangen.


Folglich ist bei vielen Policy-Objekt das Footprint ihrer Anwendung in der Variabte der Vererbung g�nstiger.


template <typename OutputPolicy>
class Logger : private OutputPolicy





---

#### Conceptual Example:

[Quellcode](../ConceptualExample.cpp)

---

#### Beispiele zum Adapter Pattern in der STL:

XXX


---

#### Abgrenzung zu anderen Entwurfsmustern / Programmier-Idiomen:


  * Das *Policy-Based Design* ist ein Programmier-Paradigma, das auf einem C++&ndash;Idiom basiert, das unter der Bezeichnung &ldquo;*Policies*&rdquo; bekannt ist.
    Es wird h�ufig als Compile-Time-Variante des *Strategy Patterns* angesehen.


---

#### Real-World Example:

Wir demonstrieren den Einsatz des Adapter Patterns anhand des folgenden Beispiels,
in dem wir ein Audio-Player-Ger�t betrachten, das nur *MP3*-Dateien abspielen kann,
aber einen erweiterten Audio-Player verwenden m�chte, um *VLC*- und *MP4*-Dateien abspielen zu k�nnen.

Ausgangspunkt ist eine Schnittstelle `MediaPlayer` und eine konkrete Klasse `AudioPlayer`,
die die `MediaPlayer`-Schnittstelle implementiert.
`AudioPlayer` Objekte spielen nur Audiodateien im MP3-Format ab.

Wir haben ferner eine zus�tzliche Schnittstelle `AdvancedMediaPlayer` und konkrete Klassen zur Verf�gung,
die die `AdvancedMediaPlayer`-Schnittstelle implementieren.
Diese Klassen k�nnen Dateien im *VLC*- und *MP4*-Format abspielen.

Wir wollen nun erreichen, dass die `AudioPlayer` Klasse auch die Formate *VLC* und *MP4* wiedergibt.
Um dies zu erreichen, erstellen wir eine Adapterklasse `MediaAdapter`.
Diese Klasse `MediaAdapter` implementiert einerseits die `MediaPlayer`-Schnittstelle,
um damit die Kompatibilit�t zu dieser Schnittstelle aufrecht zu erhalten. 
Zum Anderen benutzt sie (*hat-sie*) eine Instanz der Klasse `AdvancedMediaPlayer`,
um auch die weiteren Formate *VLC* und *MP4* abspielen zu k�nnen.

Ein Redesign der Klasse `AudioPlayer` verwendet nun die Adapterklasse `MediaAdapter`.
Die Klasse `AudioPlayer` kennt nach wie vor nicht die tats�chlichen Klassen, die das gew�nschte Format wiedergeben k�nnen.
Sie reicht allerdings bei Benutzung der Klasse `AudioPlayer` und bei Anforderung entsprechender Audiotypen
diese an die Adapterklasse weiter, so dass die Anforderung doch unterst�tzt werden kann.

*Hinweis*: Der Client-Code wird bei Einhaltung des Patterns nicht an die konkrete Adapterklasse gekoppelt,
sondern er darf nur �ber die vorhandene Client-Schnittstelle mit dem Adapter zusammenarbeiten
(im vorliegenden Beispiel: Schnittstelle `MediaPlayer`). Auf diese Weise lassen sich neue Adapterklassen
in das Programm einf�hren, ohne inkompatibel zum vorhandenen Client-Code zu sein!

---

## Literaturhinweise

Die Anregungen zum konzeptionellen Beispiel finden Sie unter

[https://refactoring.guru/design-patterns](https://refactoring.guru/design-patterns/adapter/cpp/example#example-0)

vor.

---

[Zur�ck](../../../Resources/Readme_05_Catalog.md)

---

===========================================================================================================
===========================================================================================================
===========================================================================================================



