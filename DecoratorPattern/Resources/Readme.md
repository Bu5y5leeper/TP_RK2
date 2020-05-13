# Decorator Pattern

## Wesentliche Merkmale

##### Kategorie: *Behavioral Pattern*

#### Ziel / Absicht:

Das Decorator Pattern ist ein konzeptionelles Muster,
mit dem Objekte dynamisch um neue Verhaltensweisen erweitert werden k�nnen,
indem sie in spezielle *Wrapper*-Objekte (H�llen-Objekte) eingebettet werden.

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
die vor nach der Basisfunktionalit�t des betrachteten Objekts auszuf�hren ist.



#### L�sung:



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


#### Struktur (UML):

<img src="dp_decorator_02.png" width="600">

Abbildung 2: Vererbung versus Aggregation.


Bild abgleichen mit

http://www.vincehuston.org/dp/decorator.html
und Buch von Shalloway ....



#### Ein Beispiel:

###### Grundlagen:


## Anwendungen des Design Pattern in der STL:

  * TBD



## Anwendungsbeispiel:

  * TBD


## Literaturhinweise

https://www.bfilipek.com/2018/01/pimpl.html

https://www.geeksforgeeks.org/pimpl-idiom-in-c-with-examples/



https://www.gamasutra.com/view/news/167098/Indepth_PIMPL_vs_pure_virtual_interfaces.php

https://stackoverflow.com/questions/825018/pimpl-idiom-vs-pure-virtual-class-interface



https://marcmutz.wordpress.com/translated-articles/pimp-my-pimpl-reloaded/


https://www.fluentcpp.com/2017/09/22/make-pimpl-using-unique_ptr/



---

[Zur�ck](../../Readme.md)

---

## Weiterarbeit:

a) Ein voll funktionsf�higes Beispiel (mit COpy und MOveable) implementieren.

b) Bridge

c) Wenn Zeit: Einen Vergleich Pimpl vs Interface Inheritance herstellen.

