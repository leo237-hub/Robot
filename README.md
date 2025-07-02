# Coding Standard
Die folgenden Regeln sind während der Entwicklung zu befolgen.
Diese Richtlinien werden dynamisch aktualisiert.
1. [Schlechte Praktiken](#1-schlechte-praktiken)
2. [Umfang der Funktionen](#2-funktionsgröße)
3. [Verschachtelung](#3-verschachtelung)
4. [Kommentare](#4-kommentare)
5. [Zweck des Geltungsbereichs](#5-geltungsbereich)
6. [MAKROS](#6-makros)
7. [Namenskonvention](#7-namenskonvention)
8. [Commits](#8-commits)
9. [Ausnahmen/Fehlerbehandlung](#9-ausnahmen-und-fehler)
10. [Form](#10-Form)
11. [Kontrollflussgraph](#11-Kontrollflussgraph)

## 1. Schlechte Praktiken
Die folgenden Praktiken sollten niemals ohne triftigen Grund verwendet werden.

- **GOTO-Anweisungen**: Führen zu unlesbarem, fehleranfälligem Spaghetti-Code
    - **Nicht überprüfen von Rückgabewerten**: Das Nicht-Überprüfen von Rückgabewerten bei Nicht-Void-Funktionen führt zu unerwartetem/fehleranfälligem Verhalten.
    - **Nicht initialisierte Variablen**: Unvorhersehbares Verhalten, besonders bei der Verwendung von Rohzeigern.

## 2. Funktionsgröße
    Die Größe des Geltungsbereichs von Funktionen und Klassen sollte ein bestimmtes Limit nicht überschreiten, um die Lesbarkeit zu erhalten.
    1. Die Größe von Funktionen sollte generell unter **35 Codezeilen** gehalten werden, um nicht gegen das **Single-Responsibility-Prinzip** zu verstoßen. Dies ist keine harte Grenze, Ausnahmen können vorkommen, sollten aber die **Ausnahme** sein.
    2. Die Größe von Klassen (dies bezieht sich nur auf die Header-Deklaration, nicht auf die Implementierung) sollte **70 Codezeilen** nicht überschreiten. Dies ist eine großzügige Grenze, was bedeutet, dass das Ziel sein sollte, tatsächlich weit unter 70 zu bleiben. Wir wollen keine monolithischen Klassen.

## 3. Verschachtelung
    Bei der Arbeit mit Schleifen/if-Anweisungen/case-Anweisungen sollte es eine harte Grenze geben, wie tief die Verschachtelung erlaubt ist.
        Verschachtelung macht den Code **exponentiell** unleserlich.
        Die Grenze für Verschachtelung ist 2, das bedeutet Folgendes:

```
if(condition) {
    if(anotherCondition) {
        // Keine weiteren if-Anweisungen!
    }
}
```
**Sollte es einen Fall geben, in dem die Verschachtelung eine dritte Ebene erreicht, sollte der Code überarbeitet werden. Dies ist eine harte Grenze.**

## 4. Kommentare
Kommentare sind eine gute Praxis und sind durch ihre Abwesenheit schädlicher als durch ihren Überfluss. Um die Lesbarkeit zu erhalten, sollten Kommentare in Logikblöcken geschrieben werden.
```
/*
Kommentiere hier, was der nächste Block von
Code tut, kommentiere nicht Zeile für Zeile.
*/

int userInput = convertInput(userStringInput);
if(userInput == 5) {
    cout << "User inputted 5 << endl;
}
```
Eine Klasse/Funktion sollte immer zu Beginn einen Kommentar haben, der Zweck, Verhalten, Eingabe- und Ausgabewerte definiert.

## 5. Geltungsbereich
Dieser Teil ist entscheidend, um gute OOP-Praktiken einzuhalten.
**Eine Funktion oder eine Klasse sollte immer nur eine Sache tun, dadurch können wir die DRY- und SRP-Prinzipien einhalten.**
Einschließlich aller Funktionalitäten, die wir bereits kodiert haben, ohne über Abhängigkeiten nachdenken zu müssen und uns zu wiederholen.

## 6. MAKROS
Bei der Verwendung von konstanten, wiederkehrenden Variablen, die als Referenzwert verwendet werden, sollten diese mit Enums/Defines behandelt werden, um die Lesbarkeit zu erhalten, und nicht mit inkonsistent benannten Variablen.

## 7. Namenskonvention
Um einen kohärenten Stil zu bewahren und die Lesbarkeit zu erhalten, ist die Namenskonvention für Klassen und Variablen camelCase.
Zur Referenz:
[https://en.wikipedia.org/wiki/Camel_case](url)
 In diesem Projekt beginnt die Konvention mit Kleinbuchstaben, das heißt, wir verwenden nicht CamelCase, sondern **camelCase**.

## 8. Commits
 Commits sollten mit einem kohärenten Stück Code durchgeführt werden, das heißt, keine halbfertigen Funktionen hochladen. Die Commit-Nachricht sollte explizit erklären, was geändert wurde und ob eine neue Funktion getestet wurde.
#### **Bitte bevor ein Commit gepushed wird, den commit nochmal ueberpruefen**

## 9. Ausnahmen und Fehler

 Eine ordnungsgemäße Ausnahme- und Fehlerbehandlung stellt sicher, dass die Anwendung robust, debuggbar ist und nicht unerwartet abstürzt. Die folgenden Richtlinien gelten:

 - **Immer bekannte Ausnahmen abfangen**: Behandle alle bekannten Ausnahmetypen elegant. Verwende keine leeren `catch(...)` Blöcke.

 ```cpp
 try {
    doSomething();
} catch (const std::runtime_error& e) {
    logError(e.what());
}
```

### 10. Form
Bei Header Definition, ist **#pragma** once zu benutzen und **using namespace std;**

Die Einrueckungen und Position dieser Klammer ** {}** ist mit den Befehl astyle zu vereinheitlichen.
Abweichung von der Form sind **nicht akzeptiert**.

## 11. Kontrollflussgraph
-  **Kontrollflussgraph** für die Methode Empfangesignal(signaltyp Signal) in  BewegungsRoboter.cpp:


        +-------------------+
        |   Methodenstart   |
        +-------------------+
                  |
                  v
        +-----------------------------+
        | if (!roboterAktiv)          |
        +-----------------------------+
           |true                |false
           v                    v
+-------------------+   +-----------------------------+
|   stoppen();      |   | switch(Signal)              |
|   return;         |   +-----------------------------+
+-------------------+           |
                                v
                +-------------------------------+
                | case signaltyp::Vorvaerts     |
                +-------------------------------+
                | if (blockVorwaerts)           |
                +-------------------------------+
                   |true                |false
                   v                    v
            +-------------+      +-----------------+
            | stoppen();  |      | vorwaerts(0.8); |
            +-------------+      +-----------------+
                   |                    |
                   v                    v
                [Ende]                [Ende]

                +-------------------------------+
                | case signaltyp::Rueckwaerts   |
                +-------------------------------+
                | rueckwaerts(0.8);             |
                +-------------------------------+
                        |
                        v
                      [Ende]

                +-------------------------------+
                | case signaltyp::Rechts        |
                +-------------------------------+
                | drehenrechts(0.6);            |
                +-------------------------------+
                        |
                        v
                      [Ende]

                +-------------------------------+
                | case signaltyp::Links         |
                +-------------------------------+
                | drehenlinks(0.6);             |
                +-------------------------------+
                        |
                        v
                      [Ende]

                +-------------------------------+
                | case signaltyp::keine/default |
                +-------------------------------+
                | stoppen();                    |
                +-------------------------------+
                        |
                        v
                      [Ende]


- **Kontrollflussgraph** für double LidarSensor::measureBeam(int beamIndex, const std::vector<Obstacle>& obstacles) aus Lidarsensor.cpp


+-----------------------------+
| Methodenstart               |
+-----------------------------+
           |
           v
+-----------------------------+
| Initialisierungen           |
| (angle, sensorX, sensorY,   |
| closestDist)                |
+-----------------------------+
           |
           v
+-----------------------------+
| for (Obstacle obs :         |
| obstacles)                  |
+-----------------------------+
           |
           v
+-----------------------------+
| dx, dy berechnen            |
+-----------------------------+
           |
           v
+-----------------------------+
| proj berechnen              |
+-----------------------------+
           |
           v
+-----------------------------+
| if (proj < 0 ||             |
| proj > maxRange)            |
+-----------------------------+
      |true           |false
      v               v
+-----------+   +----------------------+
| continue  |   | perpDist berechnen   |
+-----------+   +----------------------+
                      |
                      v
            +-----------------------------+
            | if (perpDist <= obs.radius) |
            +-----------------------------+
                  |true           |false
                  v               v
        +-------------------+   (zurück zu
        | offset,           |    nächstem
        | distToObstacle    |    Obstacle)
        | berechnen         |
        +-------------------+
                  |
                  v
        +-------------------------------+
        | if (distToObstacle >= 0 &&    |
        |     distToObstacle <          |
        |     closestDist)              |
        +-------------------------------+
              |true           |false
              v               v
        +----------------+   (zurück zu
        | closestDist =  |    nächstem
        | distToObstacle |    Obstacle)
        +----------------+
              |
              v
        (zurück zu nächstem
         Obstacle)
           |
           v
+-----------------------------+
| return closestDist          |
+-----------------------------+
