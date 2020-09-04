# Flyweight Pattern

## Wesentliche Merkmale

#### Kategorie: *Structural Pattern*

#### Ziel / Absicht:

Das *Flyweight Pattern* ist ein Entwurfsmuster aus der Kategorie der *Structural Pattern*,
das verwendet wird, um den Ressourcenverbrauch eines Programms mit einer sehr gro�en Anzahl von Objekten zu minimieren.
Beim Erzeugen von vielen tausend identischen Objekten k�nnen zustandslose "Flyweight"-Objekte
den in Anspruch genommen Speicher auf ein vertretbares Ma� reduzieren.

#### Problem:

Manchmal arbeiten Programme mit einer gro�en Anzahl von Objekten, die dieselbe Struktur haben,
und einige Zust�nde dieser Objekte haben stets denselben Wert.
Wenn wir den klassischen Ansatz verwenden (Instanzen erstellen, Instanzvariablen schreiben),
k�nnen sich die Speicher- bzw. Speicherbereichsanforderungen inakzeptabel erh�hen.
Das *Flyweight Pattern* stellt eine Alternative in diesem Zusammenhang dar.

#### Beispiel:

Zum Verst�ndnis des  *Flyweight* Entwurfsmusters spielen zwei Begriffe eine Rolle: *Intrinsischer* und *extrinsischer* Zustand.
Dazu ein Beispiel: Betrachten wir als Beispiel einen Texteditor. Pro Eingabe eines Zeichens wird ein Objekt einer Klasse `Character` erstellt.
Zu den Attributen der `Character`-Klasse z�hlen zum Beispiel `name` (welches Zeichen), `font` (welche Schriftart) und
`size` (welche Zeichengr��e). Diese Informationen m�ssen wir nicht jedes Mal kopieren, wenn der Benutzer ein  Zeichen eingibt,
da sich der Buchstabe 'B' nicht von einem anderen 'B' unterscheidet. 
Wenn der Client erneut ein 'B' eingibt, geben wir einfach das Objekt zur�ck, das wir bereits zuvor erstellt haben.
All dies bezeichnen wir als *intrinsische* Zust�nde (Name, Schriftart, Gr��e), da sie von den verschiedenen Objekten gemeinsam genutzt werden k�nnen!

Jetzt f�gen wir der Klasse `Character` weitere Attribute hinzu, zum Beispiel `row` (Zeile) und `col` (Spalte).
Sie geben die Position eines Zeichens im Dokument an. Diese Attribute k�nnen niemals dieselben sein, auch nicht f�r dieselben Zeichen,
da keine zwei Zeichen dieselbe Position in einem Dokument haben k�nnen.
Diese Zust�nde werden als *extrinsische* Zust�nde bezeichnet und k�nnen von den betrachteten Objekten nicht gemeinsam genutzt werden.

An Stelle der beiden Fachw�rter *intrinsischer* und *extrinsischer* Zustand spricht
man auch von *repeatingState* und *uniqueState*.

#### L�sung:

Ein so genanntes *Flyweight* ist ein Objekt, das den Speicherbedarf minimiert,
indem so viele Daten wie m�glich mit anderen �hnlichen Objekten geteilt werden.
Es gestattet, Objekte in gro�er Anzahl zu verwenden,
wenn eine einfache wiederholte Erzeugung entsprechender Objekte 
einen nicht akzeptablen Speicherbereich beanspruchen w�rde.
F�r jedes Objekt, das gemeinsam genutzte Daten verwendet,
wird nur ein Verweis (Referenz, Pointer) auf ein gemeinsam genutztes Objekt gespeichert.

Das *Flyweight Pattern* verwendet h�ufig eine Variation des *Factory Method* Entwurfsmusters
f�r die Erzeugung der gemeinsam genutzten Objekte.
Die Fabrik erh�lt eine Anfrage f�r eine *Flyweight* Instanz.
Wenn bereits ein �bereinstimmendes Objekt verwendet wird,
wird eine Referenz dieses Objekt zur�ckgegeben. Andernfalls ist ein neues *Flyweight* Objekt zu generieren.

#### Struktur (UML):

Das folgende UML-Diagramm beschreibt eine Implementierung des *Flyweight Patterns*.
Es besteht im Wesentlichen aus vier Teilen:

  * **Flyweight**: Beschreibt eine Klasse *Flyweight*, die den Teil des Status des zu betrachtenden Objekts enth�lt, der von mehreren Objekten gemeinsam genutzt werden kann.
    Dieses Objekt kann mehrfach verwendet werden. Der im *Flyweight* Objekt gespeicherte Zustand wird als "intrinsisch" oder "repeating" bezeichnet.
    Der Zustand, der an die Methoden des *Flyweight* Objekt �bergeben wird, wird als "extrinsisch" bezeichnet.
    Ein Flyweight-Objekt muss "gemeinsam nutzbar" (*sharable*) sein.
    Jeder Zustand, den dieses Objekt speichert, muss intrinsisch sein.
  * **FlyweightBase**: Abstraktion der Klasse *Flyweight* zu einem Schnittstellentyp.
  * **UnsharedFlyweight**: Nicht alle *Flyweight* Objekte k�nnen gemeinsam genutzt werden.
    Die `UnsharedFlyweight`-Klasse enth�lt den extrinsischen Status, der f�r alle `UnsharedFlyweight`-Objekte eindeutig (*unique*) ist.
    Wenn ein `UnsharedFlyweight`-Objekt mit einem `Flyweight`-Objekt gepaart wird,
    repr�sentiert es den vollst�ndigen Status des zu betrachtenden Objekts.
  * **FlyweightFactory**: Die *FlyweightFactory* (Fabrik) erstellt und verwaltet *Flyweight* Objekte.
    Dar�ber hinaus verwaltet die Fabrik einen Pool unterschiedlicher *Flyweight* Objekte.
    Die Fabrik gibt bei einer entsprechenden Anforderung ein Objekt aus dem Pool zur�ck,
    falls es bereits erstellt wurde,
    oder f�gt dem Pool ein Neues hinzu und gibt dieses zur�ck, falls dies der Anforderung entspricht.


<img src="dp_flyweight_pattern.svg" width="800">

Abbildung 1: Schematische Darstellung des *Flyweight Patterns*.


#### Conceptual Example:

[Quellcode 1](../ConceptualExample01.cpp)

[Quellcode 2](../ConceptualExample02.cpp)

Die Anregungen zum konzeptionellen Beispiel finden Sie unter

[https://refactoring.guru/design-patterns](https://refactoring.guru/design-patterns/flyweight)

und

[https://www.codeproject.com](https://www.codeproject.com/Articles/438922/Design-Patterns-2-of-3-Structural-Design-Patterns#Flyweight)

vor.

## Literaturhinweise

*Hinweise*:

---

[Zur�ck](../../../Resources/Readme_05_Catalog.md)

---
