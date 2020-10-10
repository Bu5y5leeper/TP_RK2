# Katalog der Anti-Pattern

## �berblick

Neben Entwurfsmustern gibt es auch so genannte Anti-Entwurfsmuster: Hierunter verstehen wir offensichtlich
(bekannte) Vorgehensweisen in der Software-Entwicklung, denen bereits zu Beginn des Entwicklungsprozesses
schlechte Aussichten auf eine qualitativ gelungene Architektur bescheinigt werden kann:


| Anti-Pattern | Kurzbeschreibung |
|:-------------- |----|
| [The Blob (a.k.a. God Object)](#God-Object) | Steht f�r eine einzelne Klasse, die die Verarbeitung monopolisiert und andere sekund�re Klassen, die letzten Endes nur Daten kapseln. |
| Continuous Obsolescence | Kontinuierliche Veralterung / Beschreibt eine Technologie, die sich so schnell �ndert, dass Entwickler Probleme haben, mit den aktuellen Softwareversionen Schritt zu halten und Kombinationen von Produktversionen zu finden, die zusammenarbeiten. |
| Lava Flow | Das *Lava Flow* Anti Pattern ist h�ufig in Systemen zu finden, die aus der Forschung heraus entstanden sind, aber in der Produktion gelandet sind. Es ist gekennzeichnet durch lavaartige "Fl�sse" fr�herer Entwicklungsversionen, die �ber die Codelandschaft verstreut sind und sich nun zu einer basaltartigen, unbeweglichen, im Allgemeinen nutzlosen Codemasse verh�rtet haben, an die sich niemand mehr erinnern kann. |
| Ambiguous Viewpoint | Objektorientierte Analyse- und Entwurfsmodelle (OOA&D) werden h�ufig dargestellt, ohne den vom Modell dargestellten Gesichtspunkt zu kl�ren (Gesch�fts-, Spezifikations- oder Implementierungsstandpunkt). |
| Functional Decomposition | Resultat von nicht objektorientierten Entwicklern, die eine Anwendung in einer objektorientierten Sprache entwerfen und implementieren. |
| Poltergeists | Poltergeister sind Klassen mit begrenzten Verantwortlichkeiten und Rollen, die im System ben�tigt werden. Daher ist ihr effektiver Lebenszyklus recht kurz. Poltergeister �berladen Software-Design und erzeugen unn�tige Abstraktionen. Sie sind �berm��ig komplex, schwer zu verstehen und schwer zu pflegen. |
| Boat Anchor | Unter einem �*Bootsanker*� (�*Boat Anchor*�) versteht man Software (oder Hardware), die im aktuellen Projekt keinen n�tzlichen Zweck erf�llt. Oft ist der �*Bootsanker*� eine kostspielige Anschaffung, was den Kauf noch ironischer macht. |
| Golden Hammer | Eine vertraute Technologie oder ein bekanntes Konzept, das zwanghaft auf (zu viele) Softwareprobleme angewendet wird. |
| Dead End | Die direkte �nderung von kommerzieller Software oder wiederverwendbarer Software f�hrt zu erheblichen Aufwendungen in der Wartung eines Softwaresystems. Das �*Dead End*� wird durch �ndern einer wiederverwendbaren Komponente erreicht, wenn die ge�nderte Komponente nicht mehr vom Lieferanten gewartet und unterst�tzt wird. |
| Spaghetti Code | Ad-hoc-Softwarestrukturen machen es schwierig, die Software zu erweitern und den Code zu optimieren. �*Spaghetti-Code*� zeugt von Software, die nur sehr wenig Softwarestruktur enth�lt. Codierung und progressive Erweiterungen beeintr�chtigen die Softwarestruktur in einem solchen Ausma�, dass die Struktur selbst f�r den urspr�nglichen Entwickler nicht klar genug ist, wenn dieser f�r l�ngere Zeit von der Software entfernt ist. |
| Input Kludge | Ein *Input Kludge* - zu Deutsch etwa "Eingabe-Flickschusterei, -Behelfsl�sung" ist eine Art von Fehler in der Software (ein Anti-Pattern), bei dem einfache Benutzereingaben nicht richtig behandelt werden. |
| [Input Kludge](#Input-Kludge) | Ein *Input Kludge* - zu Deutsch etwa "Eingabe-Flickschusterei, -Behelfsl�sung" ist eine Art von Fehler in der Software (ein Anti-Pattern), bei dem einfache Benutzereingaben nicht richtig behandelt werden. |
| Walking through a Minefield | Der Gebrauch von Software, die zum Kunden ausgeliefert wurde, kann mit dem Gehen durch ein Minenfeld verglichen werden. Dieses Mini-Anti-Muster ist auch bekannt als *Nothing Works* oder *Do You Believe in Magic*? In freigegebenen Softwareprodukten treten zahlreiche Fehler auf. Experten sch�tzen, dass der urspr�ngliche Quellcode zwei bis f�nf Fehler pro Codezeile enth�lt. Dies bedeutet, dass der Code zwei oder mehr �nderungen pro Zeile erfordert, um alle Fehler zu beseitigen. |
| [Cut-and-Paste Programming](#Cut-and-Paste-Programming) | Durch das Kopieren von Quellanweisungen wiederverwendeter Code f�hrt zu erheblichen Wartungsproblemen. |
| Mushroom Management | In einigen Software-Architekturkreisen gibt es eine explizite Richtlinie, die besagt, dass Systementwickler von den Endbenutzern des Systems zu isolieren sind. Anforderungen werden aus zweiter Hand von Vermittlern weitergeleitet, einschlie�lich Architekten, Managern oder Anforderungsanalysten. �*Mushroom Management*� legt zugrunde, dass die Anforderungen sowohl vom Endbenutzer als auch von den Entwicklern gut verstanden werden. Ferner wird davon ausgegangen, dass die Anforderungen stabil sind. |
| [Interface Bloat](#Interface-Bloat) | *Interface Bloat* sind Interfaces (Zusammenfassung mehrerer Methodenschnittstellen), die zu viele Methoden in einer einzigen Schnittstelle integrieren. |
| [Race Conditions](#Race-Conditions) | Unter einer "Race-Condition" versteht man im Ablauf eines multi-threading / multi-processing Programms eine Situation, die auftritt, wenn versucht wird, zwei oder mehr Funktionen/Methoden gleichzeitig ("parallel") auszuf�hren. |
| [Circular Dependencies](#Circular-Dependencies) | In der Softwareentwicklung ist eine zirkul�re Abh�ngigkeit eine Beziehung zwischen zwei oder mehreren Modulen, die entweder direkt oder indirekt voneinander abh�ngig sind. Solche Module werden auch als �*gegenseitig rekursiv*� (*mutually recursiv*) bezeichnet. |

Tabelle 1. Anti-Pattern


## Einige Antipattern im Detail

#### God Object

##### Beschreibung

Gefunden in Entw�rfen, in denen eine Klasse die Verarbeitung monopolisiert:

  * Konzentration zu vieler Funktionen (Methoden) in einem Teil des Designs (Klasse)
  * Wei� typischerweise alles dar�ber, was in der Anwendung passiert, und wei�, wie man mit allen Daten in der Anwendung interagiert
  * Oft wird es im Laufe der Zeit unglaublich schwierig, die  God Object Klasse zu warten, da �nderungen weitreichende Nebenwirkungen haben
  * �berm��ig kompliziert, weil es den Status eines Gro�teils der Anwendung verwaltet - und wird damit zum Mediator aller Abl�ufe in der Anwendung
  * Das Muster wird h�ufig in Mikrocontroller-Software verwendet, bei denen die zentrale Steuerung wichtiger ist als Eleganz und einfache Wartbarkeit der Software


##### Abhilfe

Zerlegen Sie die *God Object* Klasse und verteilen Sie die Verantwortlichkeiten neu.


#### Input Kludge 

##### Beschreibung

Ein *Input Kludge* - zu Deutsch etwa "Eingabe-Flickschusterei, -Behelfsl�sung" ist eine Art von Fehler in der Software (Anti-Pattern),
bei dem einfache Benutzereingaben nicht richtig behandelt werden.
Dies kann zu Abst�rzen beim Puffer�berlauf f�hren.

##### Identifizierung

Eine offensichtliche *Code Geruchsbel�stigung*, die auf dieses Muster hinweisen kann, sind Ad-hoc-Routinen zur Validierung von Eingaben.

*Beispiel*:

  * JavaScript-Validierungsfunktionen, die direkt in der Webseite oder in der View definiert sind.
  * Serverseitige Validierungsroutinen, die im Presentation Layer oder im Controller definiert ist.

###### Beispiel

```javascript
$('form').on('submit', function(event) {
    if (!(/^.*@.*\.(com|edu|net|org)$/g.exec($('#email').val()))) {
        alert('You must enter a valid email address.');
        return false;
    }
})
```

Unser erster Hinweis, dass es ein Problem geben k�nnte, besteht darin,
dass die Validierungsroutine (in diesem Fall `regex`) f�r diese bestimmte Eingabe ad-hoc definiert ist.
Dies bedeutet nicht sofort, dass ein Problem vorliegt, aber dies ist eine *Code Geruchsbel�stigung*, die bedeutet,
dass wir diese Code-Passagen mit einem gr��eren Augenmerk unterziehen sollten.

Bei n�herer Betrachtung wird es ziemlich schnell klar, dass dies definitiv ein *Input Kludge* ist.
Alle g�ltigen E-Mail-Adressen mit einem weniger gebr�uchlichen Domain-Suffix (z. B. `email@ddress.us`) werden abgelehnt.

Au�erdem w�rden ung�ltige E-Mail-Adressen akzeptiert (zum Beispiel `@.com`).


###### L�sung

Die L�sung f�r dieses Problem (und die meisten Eingabeprobleme) besteht darin,
eine gemeinsam genutzte, weit verbreitete und gr�ndlich getestete Bibliothek f�r Standardvalidierungen zu verwenden.

Hier ist unser Beispiel, das mithilfe einer fiktiven Validierungsbibliothek �berarbeitet wurde (die nat�rlich gr�ndlich getestet wurde):

```javascript
$('form').on('submit', function(event) {
    if (!$.isValid.email($('#email').val())) {
        alert('You must enter a valid email address.');
        return false;
    }
})
```


Weitere bekannte Vertreter f�r m�gliche *Input Kludge* �Schwachstellen:

  * CRT (C-Runtime-Library)

```cpp
strcpy 
```

  * SQL Injection

```cpp
<form action=�index.php� method="post">
    <input type="email" name="email" required="required"/>
    <input type="password" name="password"/>
    <input type="checkbox" name="remember_me" value="Remember me"/>
    <input type="submit" value="Submit"/>
</form>
```

Siehe eine Beschreibung hier:

[SQL Injection Tutorial](https://www.guru99.com/learn-sql-injection-with-practical-example.html)


#### Interface Bloat

##### Beschreibung

*Interface Bloat*, von Bjarne Stroustrup auch als *Fat Interfaces* und von Martin Fowler als *Refused Bequests* bezeichnet,
sind Interfaces (Zusammenfassung mehrerer Methoden), die zu viele Methoden in eine einzige Schnittstelle integrieren.
Wollte man eine derartige Schnittstelle implementieren, stellt man fest, dass die meisten Klassen auf Grund der Komplexit�t der Schnittstelle
keine Realisierung bereitstellen k�nnen.

##### Identifizierung

  * Eine Schnittstelle wird immer wieder mit neuen Methoden erweitert, ohne dass es zu einer Trennung kommt, sodass Sie eine monolithische Implementierungs-Klasse erhalten, die nur noch schwer zu warten und zu verwenden ist.
  * Die in einer vorhandenen Schnittstelle deklarierten Methoden erhalten immer wieder neue Parameter zu ihren Signaturen, sodass Sie st�ndig aktualisieren m�ssen und Ihre vorhandenen Anwendungen nicht abw�rtskompatibel sind.
  * Methoden in einer vorhandenen Schnittstelle werden immer wieder mit sehr �hnlichen Varianten �berladen (*method overloading*), was zu Schwierigkeiten bei der Auswahl der zu verwendenden relevanten Methode f�hren kann.

##### Abhilfe

Folge dem "Interface Segregation" Prinzip: Das Prinzip besagt, dass im Bereich der Softwareentwicklung kein
Entwickler einer Klasse gezwungen werden sollte, Methoden zu implementieren, die er nicht verwendet/ben�tigt.

Das "Interface Segregation Principle" (ISP) teilt sehr gro�e Schnittstellen in kleinere und spezifischere Schnittstellen auf,
sodass Clients nur die f�r sie interessanten Methoden kennen m�ssen.
Solche geschrumpften Schnittstellen werden auch Rollenschnittstellen (*role interfaces*) genannt.

Die Intention von ISP ist es, eine Menge von Klassen zu entkoppeln und somit flexibler interagieren zu k�nnen in Bezug auf
"Klassen umgestalten, �ndern und neu bereitstellen".

ISP ist eines der f�nf SOLID-Prinzipien des objektorientierten Designs!

#### Race Conditions

##### Beschreibung

Unter einer "Race-Condition" versteht man im Ablauf eines Multi-Threading / Multi-Processing Programms eine Situation,
die auftritt, wenn versucht wird, zwei oder mehr Funktionen/Methoden gleichzeitig ("parallel") auszuf�hren.
Aufgrund der Art des Ger�ts oder Systems m�ssen die Vorg�nge jedoch sequentiell ausgef�hrt werden,
um korrekt ausgef�hrt zu werden.

Ein Beispielszenario wird in Abbilding 1 dargestellt:

<img src="race_condition_revised.png" width="700">

Abbildung 1: Konkurrierender Zugriff auf gemeinsame Daten.


##### Abhilfe

Sogenannte "Mutex"-Objekte:

Der Sinn eines Mutex-Objekts (*"Mutual Exclusion"*) besteht darin, zwei Threads zu synchronisieren.
Wenn zwei Threads versuchen, auf eine einzelne Ressource zuzugreifen, besteht das allgemeine Muster darin,
dass der erste Thread versucht, das Mutex-Objekt zu "setzen" (`lock`), bevor er die kritische Code-Passage ausf�hrt. 
Wenn der zweite Thread versucht, dieselbe Code-Passage auszuf�hren, sieht er, dass das Mutex-Objekt gesetzt ist,
und wartet, bis der erste Thread vollst�ndig diese Code-Passage verlassen hat. 
Unter anderem es bei Verlassen der Code-Passage zwingend erforderlich, das Mutex-Objekt "zur�ck zu setzen" (`unlock`).
Nun kann der zweite Thread mit demselben Regelwerk () die  kritische Code-Passage ausf�hren.

Prinzipiell wird die Funktionalit�t eines Mutex-Objekts auf der Ebene eines Betriebssystems realisiert und eben damit auch
zur Verf�gung gestellt. In *Modern C++* gibt es eine Abstraktion von Mutex-Objekten in Gestalt mehrerer Klassen:

  * `std::mutex`
  * `std::lock_guard`
  * `std::unique_lock`
  * `std::scoped_lock`
 
Diese Klassen k�nnen zur Synchronisation von Threads in **einem** Prozess eingesetzt werden.
F�r die Inter-Prozess-Kommunikation sind sie nicht verwendbar!


#### Circular Dependencies

##### Beschreibung

Zirkul�re Abh�ngigkeiten (auch als zyklische Abh�ngigkeiten bezeichnet) treten auf, wenn zwei oder mehr Module aufeinander verweisen.
Dies k�nnte eine direkte Referenz sein (z.B. *A* -> *B* -> *A*) oder indirekt (*A* -> *B* -> *C* -> *A*):

##### Abhilfe

Es gibt verschiedene M�glichkeiten, um zirkul�re Abh�ngigkeiten zu beseitigen. Bei einer l�ngeren Kette, zum Beispiel *A* -> *B* -> *C* -> *D* -> *A*,
wird das zyklische Referenzmuster unterbrochen, wenn eine der Referenzen entfernt wird (z. B. die Referenz *D* -> *A*).
Dies mag manchmal ohne gro�e Probleme machbar sein, in anderen F�llen wiederum nicht.

F�r einfachere Muster wie *A* -> *B* -> *A* kann ein *Refactoring* erforderlich sein. M�glicherweise k�nnten die in *B* vorhandenen
Module nach *A* verschoben werden. Oder der erforderliche Code k�nnte in ein neues Modul *C* extrahiert werden,
auf das sowohl *A* als auch *B* verweisen.
Wenn die beiden Module ein �hnliches Verhalten aufweisen, k�nnten sie auch zu einem einzigen Modul kombiniert werden.


#### Copy-and-Paste Programming

##### Beschreibung

Dieses Anti-Pattern wird durch das Vorhandensein mehrerer �hnlicher - noch schlimmer: identischer - Codesegmente identifiziert,
die im gesamten Softwareprojekt verteilt sind.

Dies f�hrt zu einer Codeduplizierung, die kurzfristig positive Konsequenzen haben kann, z.B.
das schnellere Erreichen des Entwicklungsziels, da die Ma�nahmen zur Abhilfe der Codeduplizierungen in der Regel mit zus�tzlichem zeitlichem Aufwand verbunden sind.

In erster Linie sind es aber zwei Nachteile, die die Qualit�t der Software beeintr�chtigen:

  * �nderungen an einem derartigen Codesegment m�ssen mehrere Male im gesamten Projekt nachgezogen werden. Wird eine dieser Codeduplizierungen �bersehen,
   kann dies fatale Folgen haben.
  * Fehler in einem derartigen Codesegment m�ssen mehrere Male im gesamten Projekt behoben werden. Wird eine dieser Codeduplizierungen �bersehen,
   kann dies wiederum fatale Folgen haben.

##### Abhilfe

Die Behebung dieses Antipatterns zum Kopieren und Einf�gen ist keine �*One and Done*� L�sung.
Sobald ein und derselbe Codeblock mehrmals im Quellcode existiert, sollte jedes Auftreten in eine einzelne Funktion oder Methode abstrahieren werden.
Dann kann man statt des Codeblocks diese neue Funktion verwenden.
Schlie�lich lassen sich alle vorhandenen Codebl�cke in eine neu implementierte und getestete Funktion oder Methode umwandeln.

---

## Weiterarbeit

Ein interessantes Anti-Pattern zu einfachen Datenstrukturen findet sich unter

[Simple data structures](https://arne-mertz.de/2018/12/simple-data-structures/) (Abruf am 20.07.2020)

---

[Zur�ck](../Readme.md)

---
