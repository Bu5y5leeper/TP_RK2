# Single-Responsibility-Prinzip

[Zur�ck](../../../Resources/Readme_03_Design_Principles.md)

---

## Wesentliche Merkmale


#### Ziel / Absicht:

&ldquo;Eine Klasse sollte nur einen Grund haben, ge�ndert zu werden&rdquo;

In anderen Worten:
Das *Single-Responsibility-Prinzip* besagt, dass Klassen bis zu dem Punkt &ldquo;koh�rent&rdquo; (semantisch zusammenh�ngend) sein sollten,
dass sie eine einzige Verantwortung haben, wobei Verantwortung als &ldquo;ein Grund f�r die �nderung&rdquo; definiert wird.

#### Example violating the Single Responsibility Principle

```cpp
01: class Journal
02: {
03:     std::string               m_title;
04:     std::vector<std::string>  m_entries;
05: 
06: public:
07:     explicit Journal(const std::string& title) : m_title{ title } {}
08: 
09:     void addEntries(const std::string& entry) {
10:         static uint32_t count = 0;
11:         count++;
12:         std::string text = std::to_string(count) + ": " + entry;
13:         m_entries.push_back(text);
14:     }
15: 
16:     auto getEntries() const { return m_entries; }
17: 
18:     void save(const std::string& filename, std::ostream& os) {
19: 
20:         for (auto& s : m_entries) {
21:             os << s << std::endl;
22:         }
23:     }
24: };
```

  * Das obige C++-Beispiel k�nnte in Ordnung zu sein, solange es nur eine einzelne Dom�nenklasse gibt, z. B. `Journal`.
    Dies ist jedoch in einer realen Anwendung normalerweise nicht der Fall.
  * Wenn wir beginnen, weitere Dom�nenklassen wie `Book`, `File` usw. hinzuzuf�gen,
    ist die Speichermethode `save` f�r alle Dom�nenklassen separat zu implementieren.
  * Das eigentliche Problem entsteht, wenn die Speicherfunktionalit�t ge�ndert werden soll.
    Zum Beispiel w�re es denbkbar, dass eines Tages die Daten an Stelle in Dateien in einer Datenbank abgelegt werden sollen.
    In diesem Fall m�sste man jede Dom�nenklassenimplementierung durchlaufen und den gesamten Code �ndern,
    was nat�rlich v�llig sinnlos ist.
  * Der Versto� gegen das Single-Responsibility-Prinzip in diesem Beispiel ist offensichtlich:
    Die Klasse `Journal` besitzt zwei Gr�nde, um ge�ndert zu werden:
    * �nderungen im Zusammenhang mit der `Journal` Klasse
    * �nderungen im Zusammenhang mit der Persistenz (Datenablage) der `Journal` Klasse

// ===============================================

http://www.vishalchovatiya.com/single-responsibility-principle-in-cpp-solid-as-a-rock/


ALT

#### Problem:

Das *Bridge Pattern* genie�t einen guten Ruf,
da sich mit ihm die abstrakten Elemente der Klasse von den Implementierungsdetails trennen lassen.
Dieses Muster ist vor allem dann zu empfehlen,
wenn die betrachteten Klassen h�ufig variieren,
da sich dann �nderungen an der Codebasis bei minimalem Wissen �ber das Programm leicht durchf�hren lassen.

Betrachten wir ein Beispiel, in dem eine Implementierung auf zwei oder mehreren Realisierungen fu�t.
Zum Beispiel ein Programm, das die Persistenz von Objekten auf verschiedenen Plattformen (Betriebssystemen) realisiert.
Einige Objekte sollen in einer Datenbank und andere Objekte wiederum im Dateisystem des unterlagerten
Betriebssystems gespeichert werden. 
Wird das Programm um diese Funktionalit�t &ldquo;straight forward&rdquo; erweitert,
sind Probleme vorprogrammiert, da die Abstraktion mit der Implementierung verkn�pft wird.
In diesem Fall ist es besser, das *Bridge Pattern*  zu verwenden und die Abstraktion von der Implementierung zu trennen.
Wird dieses Muster nicht verwendet, kann man die Beobachtung machen,
dass Implementierungsdetails in einer Abstraktion enthalten sind.

Ein weiterer Vorteil des *Bridge Patterns* ist die M�glichkeit, Implementierungsdetails zur Laufzeit zu �ndern.
Dies erm�glicht es dem Benutzer, Implementierungen zu wechseln, um auf diese Weise zu bestimmen,
wie die Software mit anderen Systemen zusammenarbeitet.

#### L�sung:

#### Struktur (UML):

Das folgende UML-Diagramm beschreibt eine Implementierung des *Bridge Patterns*.
Es besteht im Wesentlichen aus vier Teilen:

  * **Abstraction**: Definiert eine Abstraktionsschnittstelle. Sie fungiert als Basisklasse f�r andere verfeinerte Abstraktionsklassen.
    Sie bezieht sich auch auf eine bestimmte Implementierung, die f�r plattformspezifische Funktionen verwendet wird.
  * **RefinedAbstraction**: Stellt eine verfeinerte Variation einer Abstraktionsschnittstelle dar,
    enth�lt jedoch keine Implementierungsdetails. *De facto* erweitert sie nur die Abstraktion.
  * **Implementor**: Definiert die Schnittstelle f�r Implementierungsklassen.
  * **ConcreteImplementor**: Diese Klasse erbt von der Klasse `Implementor`. Es kann mehr als eine Instanz von `Implementor`-Klassen geben,
    die dieselbe Schnittstelle unterst�tzen, aber plattformspezifische Funktionen bereitstellen.

<img src="dp_bridge_pattern_01.svg" width="600">

*Abbildung* 1: Schematische Darstellung des *Bridge Patterns*.


#### Conceptual Example:

[Quellcode 1](../ConceptualExample01.cpp) &ndash; Sehr einfache Version

[Quellcode 2](../ConceptualExample02.cpp) &ndash; Ein etwas ausf�hrlicheres Beispiel

---

#### 'Real-World' Beispiel:

Bei diesem Muster steht eine Schnittstelle im Mittelpunkt,
die als Br�cke fungiert, die die Funktionalit�t konkreter Klassen unabh�ngig
von den Schnittstellenimplementierungsklassen macht.
Beide Klassentypen k�nnen strukturell ver�ndert werden, ohne sich gegenseitig zu beeinflussen.

Wir demonstrieren die Verwendung des Bridge-Entwurfsmusters anhand des folgenden Beispiels,
in dem ein Kreis in verschiedenen Farben mit derselben abstrakten Basisklassenmethode,
aber unterschiedlichen Bridge-Implementiererungsklassen gezeichnet werden kann.

In *Abbildung* 2 finden Sie eine `IDrawAPI`-Schnittstelle vor, die als Bridge-Schnittstellenklasse fungiert,
und zwei konkrete Klassen `RedCircleDrawer` und `GreenCircleDrawer`,
die die `IDrawAPI`-Schnittstelle implementieren.

`Shape` ist eine abstrakte Klasse und besitzt einen `IDrawAPI`-Schnittstellenzeiger
(*Raw*-Pointer oder Smart-Pointer). In der Anwendung finden Sie ein Beispiel, in dem ein Kreis mit zwei verschiedenen Farben 
gezeichnet wird:

<img src="dp_bridge_pattern_02.svg" width="600">

*Abbildung* 2: Ein Anwendungsbeispiel des *Bridge Patterns*.

---

Die Anregungen zum konzeptionellen Beispiel finden Sie unter

[https://refactoring.guru/design-patterns](https://refactoring.guru/design-patterns/bridge/cpp/example#example-0)

und 

[https://www.codeproject.com](https://www.codeproject.com/Articles/438922/Design-Patterns-2-of-3-Structural-Design-Patterns#Bridge)

vor.

---

[Zur�ck](../../../Resources/Readme_03_Design_Principles.md)

---
