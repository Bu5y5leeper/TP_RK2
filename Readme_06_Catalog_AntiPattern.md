# Katalog der Anti-Pattern

TODO: 

Ebenfalls einf�hren

https://arne-mertz.de/2018/12/simple-data-structures/

als Anti-Pattern

Neben Entwurfsmustern gibt es auch so genannte Anti-Entwurfsmuster: Hierunter verstehen wir offensichtlich
(bekannte) Vorgehensweisen in der Software-Entwicklung, denen bereits zu Beginn des Entwicklungsprozesses
schlechte Aussichten auf eine qualitativ gelungenge Architektur bescheinigen kann:

| Anti-Pattern | Kurzbeschreibung |
|:-------------- |----|
| The Blob | TBD |
| Continuous Obsolescence | TBD |
| Lava Flow | TBD |
| Ambiguous Viewpoint | TBD |
| Functional Decomposition | TBD |
| Poltergeists | TBD |
| Boat Anchor | TBD |
| Golden Hammer | TBD |
| Dead End | TBD |
| Spaghetti Code | TBD |
| Input Kludge | TBD |
| Walking through a Minefield | TBD |
| Cut-and-Paste Programming | TBD |
| Mushroom Management | TBD |

Tabelle 1. Anti-Pattern

Weitere Anti-Pattern:

| Anti-Pattern | Kurzbeschreibung |
|:-------------- |----|
| God Object | TBD |
| Input Kludge | TBD |
| Interface Bloat | TBD |
| Race Conditions | TBD |
| Circular Dependency | TBD |
| Copy and Paste Programming | TBD |

Tabelle 2. Weitere Anti-Pattern


## Input Kludge 

#### Beschreibung

Ein *Input Kludge* - zu deutsch etwa "Eingabe-Flickschusterei, -Behelfsl�sung" ist eine Art von Fehler in der Software (ein Anti-Pattern),
bei dem einfache Benutzereingaben nicht richtig behandelt werden.
Dies kann zu Abst�rzen beim Puffer�berlauf f�hren.

Bekannteste Vertreter:

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

#### Abhilfe

## Interface Bloat

#### Beschreibung

*Interface Bloat*, von Bjarne Stroustrup auch als *Fat Interfaces* und von Martin Fowler als *Refused Bequests* bezeichnet,
sind Interfaces (Zusammenfassung mehrerer Methodenschnittstellen), die zu viele Methoden in einer einzigen Schnittstelle integrieren.
Wollte man eine derartige Schnittstelle implementieren, stellt man fast, dass die meisten Klassen auf Grund der Komplexit�t der Schnittstelle
keine Realisierung bereitstellen k�nnen.

#### Abhilfe

Folge dem "Interface Segregation" Prinzip: Das Prinzip besagt, dass im Bereich der Softwareentwicklung kein
Entwickler einer Klasse gezwungen werden sollte, Methoden zu implementieren, die er nicht verwendet/ben�tigt.

Das "Interface Segregation Principle" (ISP) teilt sehr gro�e Schnittstellen in kleinere und spezifischere Schnittstellen auf,
sodass Clients nur die f�r sie interessanten Methoden kennen m�ssen.
Solche geschrumpften Schnittstellen werden auch Rollenschnittstellen (role interfaces) genannt. 

Die Intention von ISP ist es, eine Menge von Klassen entkoppeln zu k�nnen und somit flexibler interagieren zu k�nnen in Bezug auf
"Klassen umgestalten, �ndern und neu bereitstellen"

ISP ist eines der f�nf SOLID-Prinzipien des objektorientierten Designs!

## Race Conditions

#### Beschreibung

Unter einer "Race-Condition" versteht man im Ablauf eines multi-threading / multi-processing Programms eine Situation,
die auftritt, wenn versucht wird, zwei oder mehr Funktionen/Methoden gleichzeitig ("parallel") auszuf�hren.
Aufgrund der Art des Ger�ts oder Systems m�ssen die Vorg�nge jedoch sequentiell ausgef�hrt werden,
um korrekt ausgef�hrt zu werden.

#### Abhilfe

Mutex.

---

[Zur�ck](Readme.md)

---


