# Template Method Pattern

## Wesentliche Merkmale

##### Kategorie: *Behavioral Pattern*

#### Ziel / Absicht:

Definiert das prinzipielle Grundger�st eines Algorithmus in einer zentralen Methode.
Diese lagert einen oder vorzugsweise mehrere Teilschritte in Methoden abgeleiteter Klassen aus.
�nderungen an den Teilschritten haben keine Auswirkungen auf die Arbeitsweise (Realisierung)
der zentralen Methode.

Das Template Method Pattern ist ein Verhaltensentwurfsmuster,
das das Grundger�st eines Algorithmus in einer Oberklasse definiert,
Unterklassen jedoch bestimmte Schritte des Algorithmus �berschreiben l�sst,
ohne dabei seine prinzipielle Struktur zu �ndern.

#### Problem:

Es gibt eine Methode oder anders formuliert, eine Reihe von auszuf�hrenden Schritten (Teilmethoden),
die auf einer h�heren Abstraktionsebene
festgelegt sind (Reihenfolge der Ausf�hrung, Bereitstellung von Parametern, ...).

In einer niedrigeren Abstraktionsebene (Detailebene) k�nnen die Teilmethoden eine unterschiedliche Implementierung haben.


#### L�sung:

Das *Template Method Pattern* schl�gt vor, dass Sie einen Algorithmus in eine Reihe von Schritten aufteilen,
diese Schritte in Methoden umwandeln und diese Methoden in einer einzigen �Vorlagenmethode� aufrufen,
daher auch der Name dieses Entwurfsmusters.
Die Schritte k�nnen entweder abstrakt sein oder eine Standardimplementierung aufweisen.
Um den Algorithmus zu verwenden, muss der Client eine eigene Unterklasse bereitstellen, alle abstrakten Schritte implementieren und bei Bedarf einige der optionalen Schritte �berschreiben
Die Vorlagenmethode sollte dabei nicht �berschrieben oder ver�ndert werden.

Das *Template Method Pattern* erm�glicht die Realisierung von variierenden Teilschritten, w�hrend ein konsistenter Grundprozess beibehalten wird.


#### Struktur (UML):

<img src="dp_template_method_pattern.svg" width="600">

Abbildung: Schematische Darstellung des *Template Method Patterns*.


#### Hinweis:

Template Method Pattern und Strategy Pattern besitzen viele Gemeinsamkeiten. Ein Unterschied zwischen den beiden Mustern ist,
dass das Template Method Pattern auf Vererbung beruht, dass Strategy Pattern hingehen auf Komposition.

## Anwendungsbeispiel:

In Spezialisierungen der Oberklasse k�nnen bzw. sollten ein oder mehrere Teilmethoden �berschrieben werden,
um die **Template Methode* in der Oberklasse zu vervollst�ndigen. 

Die Skelett-Methode ist davon ausgenommen - die prinzipielle Struktur des Algorithmus ist beizubehalten,
also nicht zu ver�ndern.


#### Beispiele:

Die Beispiele zu diesem Pattern orientieren sich an:

[https://refactoring.guru/design-patterns/strategy](https://refactoring.guru/design-patterns/strategy/java/example)

---

[Zur�ck](../../../Resources/Readme_05_Catalog.md)

---