# Open-Closed-Prinzip

[Zur�ck](../../../Resources/Readme_03_Design_Principles.md)

---

## Wesentliche Merkmale


#### Ziel / Absicht:

&ldquo;Klassen sollten f�r Erweiterungen offen, f�r �nderungen geschlossen sein&rdquo;

In anderen Worten:
Das Prinzip bedeutet w�rtlich genommen, dass man in der Lage sein sollte,
das Verhalten einer Klasse zu erweitern, ohne diese dabei zu �ndern.

Auf den ersten Blick mag das *Open-Closed-Prinzip* etwas seltsam erscheinen und die Frage aufwerfen,
wie man das Verhalten einer Klasse �ndern k�nnen soll, ohne diese zu �ndern?

Es gibt darauf Antworten im objektorientierten Design wie

  * dynamischer Polymorphismus,
  * statischer Polymorphismus und
  * C++-Templates

nur um einige M�glichkeiten aufzuz�hlen. 

Wir betrachten das *Open-Closed-Prinzip* an einem Beispiel:

#### Example: Violating the Open Closed Principle

```cpp
```

  * Wir betrachten eine Reihe von Produkten (Klasse `Product`) und filtern diese
    nach einigen ihrer Attribute. An dem Beispielcode ist nichts auszusetzen,
    solange sich die Anforderungen nicht mehr �ndern &ndash; was beim Software-Engineering niemals der Fall ist :).

  * Wir stellen uns nun der Situation, dass nachtr�glich
    Anforderungs�nderungen und einige neue Filter-Operationen verlangt werden.
    In diesem Fall sind die Klassen `Product` und `ProductFilter` erneut zu �ndern
    und neue Filtermethoden hinzuf�gen.

  * Dieser Ansatz ist problematisch, da wir zwei Attribute (`Color` und `Size`) 
    und drei Funktionen (`Color`, `Size` und ihre Kombination) haben.
    Ein weiteres Attribut h�tte zur Folge, dass acht neue Funktionen zu implementieren sind.
    Dieser Ansatz ist nicht nur nicht zielf�hrend,
    der bereits existierende, realisierte Quellcode ist zu modifizieren.
    Dies ist eine Verletzung des *Open-Closed-Prinzips*:
    Es besagt, dass das System f�r Erweiterungen offen, aber f�r Modifikationen geschlossen zu sein hat.
    Im vorliegenden Beispiel �ndern wir den vorhandenen Code, was eine Verletzung von OCP darstellt.


#### Example: Respecting the Open Closed Principle


Es gibt mehr als einen Weg, um das *Open-Closed-Prinzip* zu erreichen.
Das Design von Schnittstellen und das Hinzuf�gen einer Abstraktionsebene f�r Erweiterbarkeit
sind die am meisten verbreitete Vorgehensweise:

```cpp
```

###### Beachten Sie an dem Quellcode:
Die Filtermethode `filter` der Klasse `ProductFilter` ist nicht zu �ndern.
Sie kann jetzt mit allen Arten von Spezifikationen arbeiten!

#### Vorteile des *Open-Closed-Prinzips*

  * Expressiveness &ndash; Ausdruckskraft
  * Maintainability &ndash; Wartbarkeit
  * Flexibility &ndash; Flexibilit�t

---

[Zur�ck](../../../Resources/Readme_03_Design_Principles.md)

---
