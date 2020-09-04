# Prototype Pattern

## Wesentliche Merkmale

##### Kategorie: Erzeugungsmuster / *Creational Pattern*

#### Ziel / Absicht:

Das *Prototype Pattern* ist ein Entwurfsmuster,
das zum Instanziieren einer Klasse auf das Kopieren oder Klonen der Eigenschaften eines vorhandenen Objekts zur�ckgreift.
Das neue Objekt ist eine exakte Kopie des Prototyps, erm�glicht jedoch �nderungen, ohne das Original zu ver�ndern.

#### Problem:

Mit dem *Prototype* Entwurfsmuster k�nnen wir die Komplexit�t des Erstellens
neuer Instanzen vor dem Client verbergen. Das Konzept besteht darin, ein vorhandenes Objekt zu kopieren,
anstatt eine neue Instanz (samt dazugeh�riger Klasse) von Grund auf neu zu erstellen.
Dies kann bisweilen mit einem recht zeitintensiven Aufwand verbunden sein.

Das vorhandene Objekt fungiert als Prototyp eines neuen Objekts und besitzt seinen Status.
Das neu kopierte Objekt kann dieselben Eigenschaften bei Bedarf �ndern.
Dieser Ansatz spart Ressourcen und Zeit, insbesondere wenn die Objekterstellung nicht-trivial ist.

#### L�sung:

Das *Prototype* Entwurfsmuster stammt aus der Kategorie der Erzeugungssmuster.
Das Entwurfsmuster ist erforderlich, wenn die Objekterstellung zeitaufw�ndig und kostspielig ist.
Daher erstellen wir ein neues Objekt auf Basis eines vorhandenen Objekts.

Diese Art der Objekterstellung wird als *Klonen* bezeichnet.
Wenn das urspr�ngliche Objekt geklont wird, ist das neue Objekt - in Abh�ngigkeit von der Implementierung
der `clone`-Methode - eine flache (*shallow*) oder tiefe (*deep*) Kopie.
Diese Kopie dupliziert alle Eigenschaften und Felder des urspr�nglichen Objekts.
Wenn eine Eigenschaft vom Referenztyp ist, sollte vom referenzierten Objekt ebenfalls eine tiefe Kopie erstellt werden,
um insgesamt zu einer echten Kopie des urspr�nglichen Objekts zu gelangen.

In manchen Programmiersprachen wird die `clone`-Methode automatisch bereitgestellt bzw. vom Programmersteller erzwungen:

  * **Java**:<br/>
    ```java
    @Override
    protected Object clone() throws CloneNotSupportedException {
      ...
    }
    ```

  * **.NET Framework**:<br/>
    ```java
    public object Clone () {
      ...
    }
    ```

Dies ist in C++ so nicht der Fall. Eine `clone`-Methode (gleichwertig: Kopierkonstruktor) ist am Ursprungsobjekt bei Anwendung des
*Prototype Patterns* explizit bereitzustellen

#### Struktur (UML):

Das folgende UML-Diagramm beschreibt eine Implementierung des *Prototype Patterns*.
Es besteht im Wesentlichen aus zwei Teilen:

  * **Prototype**: Abstrakte Basisklasse, die eine (abstrakte) `clone`-Methode besitzt. 
    Die `clone`-Methode liefert ein Prototypobjekt zur�ck.
  * **ConcretePrototype**: Klasse, die sich von der Prototype-Basisklasse ableitet. Sie kann zus�tzliche Funktionen enthalten.
    In dieser Klasse wird die `clone`-Methode �berschrieben.

<img src="dp_prototype_pattern.svg" width="500">

Abbildung 1: Schematische Darstellung des *Prototype Patterns*.

#### Hinweis:

In JavaScript ist das *Prototype Pattern* quasi nativ enthalten.

Die Erstellung von Objekten erfolgt hier - unter anderem - auf der Basis von so genannten
"Konstruktorfunktionen", die als Blaupausen f�r neue Objekte verwendet werden k�nnen,
man spricht dabei auch von der so genannten *"Prototypischen Vererbung"*.


#### Conceptual Example:

[Quellcode 1](../ConceptualExample01.cpp)

[Quellcode 2](../ConceptualExample02.cpp)

[Quellcode 3](../ConceptualExample03.cpp)

Die Anregungen zum konzeptionellen Beispiel finden Sie unter

[https://refactoring.guru/design-patterns](https://refactoring.guru/design-patterns/prototype/cpp/example#example-0)

und 

[https://www.codeproject.com](https://www.codeproject.com/Articles/430590/Design-Patterns-1-of-3-Creational-Design-Patterns#Prototype)

vor.

---

[Zur�ck](../../../Resources/Readme_05_Catalog.md)

---

