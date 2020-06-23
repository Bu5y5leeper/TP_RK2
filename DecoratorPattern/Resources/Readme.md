# Decorator Pattern

## Wesentliche Merkmale

##### Kategorie: *Structural Pattern*

#### Ziel / Absicht:

Das *Decorator Pattern* ist ein strukturelles Entwurfsmuster, das die Funktionalit�t eines Objekts erweitert,
indem es dieses mit einer oder mehreren Dekorationsklassen "umh�llt", oder gewisserma�en dekoriert.
*Decorator* Klassen k�nnen vorhandene Elemente �ndern und zur Laufzeit neue Methoden und Eigenschaften hinzuf�gen.


##### Hinweis:

Das Spezialisieren (Vererbung) einer Klasse ist typischerweise das Erste, was einem einf�llt,
wenn man das Verhalten eines Objekts �ndern (erweitern) m�chte.
Die Vererbung weist jedoch einige schwerwiegende Einschr�nkungen auf, die es zu beachten gilt:

  * Die Vererbung ist ein statisches Konzept, also etwas, was zur �bersetzungszeit festgelegt sein muss.
    Zur Laufzeit l�sst sich das Verhalten eines bestimmten Objekts nicht �ndern.
    Ferner kann man nur ein ganzes Objekt durch ein anderes Objekt ersetzen, das aus einer anderen Unterklasse erstellt wurde.
    Das *Decorator Pattern* zielt auf das �ndern von Verhaltensweisen bestimmter Methoden ab.
  * Unterklassen k�nnen nur eine �bergeordnete Klasse haben. In den meisten Sprachen l�sst das Prinzip der Vererbung nicht zu,
    dass eine Klasse das Verhalten mehrerer Klassen gleichzeitig erbt (Prinzip der Mehrfachvererbung, in C++ allerdings m�glich)

Eine M�glichkeit, diese Einschr�nkungen zu �berwinden, ist die Verwendung von
*Aggregation* oder *Komposition* anstelle von Vererbung.
Beide Alternativen funktionieren fast gleich: Ein Objekt hat einen Verweis (Referenz, Zeiger) 
auf ein anderes und *delegiert* ihm dadurch T�tigkeiten.
Bei der Vererbung kann das Objekt diese Arbeit *selbst* ausf�hren,
es *erbt* das Verhalten von seiner Oberklasse.

Mit diesem Ansatz (Gebrauch eines Verweises) k�nnen Sie das verkn�pfte "Hilfs"-Objekt leicht durch ein
anderes ersetzen und so das Verhalten des Containers zur Laufzeit �ndern.
Ein Objekt kann das Verhalten mehrerer Klassen verwenden, indem es Verweise auf mehrere Objekte verwaltet und an diese alle Arten von Arbeit delegieren.

<img src="dp_decorator_01.png" width="500">

Abbildung 1: Vererbung versus Aggregation.

#### Problem:

Das Objekt, das Sie verwenden m�chten, f�hrt die grundlegenden Funktionen aus, die Sie ben�tigen.
M�glicherweise m�ssen Sie dem Objekt jedoch noch einige zus�tzliche Funktionalit�ten hinzuf�gen,
die vor oder nach der Basisfunktionalit�t des betrachteten Objekts auszuf�hren sind.

#### L�sung:

*Wrapper* oder H�lle ist der alternative Kurzname f�r das Decorator-Pattern,
der die Hauptidee des Musters klar zum Ausdruck bringt. Ein "Wrapper" ist ein Objekt,
das mit einem "Ziel"-Objekt verkn�pft werden kann. Das Wrapper-Objekt enth�lt die gleichen Methoden
wie das Ziel und delegiert alle eingehenden Requests an es.
Der Wrapper kann das Verhalten jedoch �ndern,
indem er entweder vor oder nach dem Weiterleiten der Anforderung an das Ziel
zus�tzliches Verhalten hinzuf�gt.

#### Struktur (UML):

Das folgende UML-Diagramm beschreibt eine Implementierung des *Decorator Patterns*.
Es besteht im Wesentlichen aus vier Teilen:

  * **Component**: Abstrakte Basisklasse f�r alle konkreten Komponenten und Decorator-Klassen.
    Diese Klasse definiert diejenigen Klassenelemente, die standardm��ig von diesen Klassentypen implementiert werden m�ssen.
  * **ConcreteComponent**: Diese Klasse erbt von der Klasse `Component`. Es kann diese Klasse mehrfach geben. Es damit jeweils einen Objekttyp definiert,
    der von einer Decorator-Klasse umh�llt wird.
  * **DecoratorBase**: Stellt die abstrakte Basisklasse f�r alle Decorator-Klassen dar. Es wird ein Konstruktor hinzugef�gt,
    der ein `Component-Objekt` als Parameter akzeptiert. Das �bergebene Objekt ist die Komponente, die umh�llt wird.
    Da das umh�llte Objekt von `Component` erben muss, kann es sich um ein `ConcreteComponent`-Objekt
    oder ein anderes Decorator-Objekt handeln. Auf diese Weise k�nnen mehrere Decorator-Objekte auf ein einzelnes Objekt angewendet werden.
  * **ConcreteDecorator**: Diese Klasse repr�sentiert ein konkretes Decorator-Objekt f�r eine Komponente.
    Es kann einige zus�tzliche Methoden enthalten, die die Funktionalit�t der Komponente erweitern.
    Die `operation`-Methoden k�nnen auf zwei Arten verwendet werden:
    Sie k�nnen unver�ndert bleiben und in diesem Fall wird die Basisklassenmethode der Komponente aufgerufen
    oder die `operation`-Methode kann ge�ndert werden oder vollst�ndig durch eine neue Implementierung ersetzt werden.

<img src="dp_decorator_02.png" width="650">

Abbildung 2: Schematische Darstellung des *Decorator* Patterns.


###### Hinweis:

W�hrend ein Dekorateur seine Funktionalit�t vor oder nach Weiterleiten der Anforderung an das Objekt,
was es dekoriert, hinzuf�gen kann, sollte die Kette der Instanziierung
immer mit dem `ConcreteComponent`-Objekt enden.

#### Implementierung:

Erstellen Sie eine abstrakte Klasse, die sowohl die urspr�ngliche Klasse darstellt
als auch die neuen Methoden besitzt, die der Klasse hinzugef�gt werden sollen.
Platzieren Sie in den Dekoratoren die neuen Methoden-Anrufe
vor oder nach den Anrufen an das eingeh�llte Objekt, um die richtige Reihenfolge zu erhalten.

#### Pro / Kontra:

###### Pros:

  * Das Verhalten eines Objekts kann erweitert werden, ohne eine neue Unterklasse erstellen zu m�ssen.
  * Einem Objekt k�nnen zur Laufzeit Verantwortlichkeiten hinzugef�gt oder daraus entfernt werden.
  * Es k�nnen mehrere Verhaltensweisen kombiniert werden, indem man ein Objekt in mehrere Dekoratoren einh�llt.
  * *Single Responsibility Principle*: Eine monolithische Klasse,
    die viele m�gliche Verhaltensvarianten implementiert, kann so in mehrere kleinere Klassen unterteilt werden.

###### Kontras:

  * Es ist schwierig, einen bestimmten Wrapper vom Wrapper-Stapel zu entfernen.
  * Es ist schwierig, einen Dekorateur so zu implementieren, dass sein Verhalten nicht von der Reihenfolge im Dekorationsstapel abh�ngt.
  * Der anf�ngliche Konfigurationscode von Ebenen (H�llen) sieht m�glicherweise nicht sehr gut aus.

#### Beispiel:

Siehe Verzeichnis *ConceptualExample*.


## Anwendungsbeispiel:

  * TBD


## Literaturhinweise

*Hinweise*:

Die Anregungen zu den Beispielen findet man unter

[refactoring.guru](https://refactoring.guru/design-patterns/decorator/cpp/example#example-0)<br>(abgerufen am 23.06.2020).

und 

[Dmitri Nesteruk "Design Patterns in Modern C++](https://github.com/Apress/design-patterns-in-modern-cpp)<br>(abgerufen am 14.05.2020).

---

[Zur�ck](../../Readme.md)

---

## Weiterarbeit:

a) Beispiel Dmitri Nesteruk !!!

