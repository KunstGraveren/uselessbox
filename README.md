# uselessbox  
Een 'overbodige' doos is een fascinerend en vaak humoristisch project dat perfect is voor beginners. Het is een eenvoudig apparaat dat in feite één functie heeft: het inschakelen van een schakelaar en vervolgens zichzelf weer uitschakelen.

Hier is een samenvatting en uitleg van de code, samen met de verschillen tussen elke actie, en een eenvoudig schakelschema:

### Code Samenvatting:
- Het systeem gebruikt een Arduino Nano met:
  - Een servo motor (`handServo`) die een "hand" beweging bestuurt.
  - Een WS2812 LED (`FastLED`) die de status aangeeft.
  - Een schakelaar verbonden met pin 3, waarmee door acties gewisseld wordt.
- Wanneer de schakelaar wordt ingedrukt, triggert een interrupt (`handleSwitchInterrupt`) dat de variabele `action` verhoogt, en deze loopt van 1 tot 7.
- De `loop()` controleert de waarde van `action` en voert verschillende vooraf ingestelde sequences uit, met servo-bewegingen, vertragingen en seriële berichten.
- Elke actie simuleert een andere "truc" zoals het openen van een doos, het bewegen van de hand, waggelen, etc.
- Tijdens een actie wordt de LED rood; na afloop gaat hij terug naar blauw.

---

### Verschillen tussen de acties:

| **Actie** | **Beschrijving** | **Belangrijkste bewegingen & effecten** |
|--------------|-------------------|-----------------------------------------|
| **1** | Doos openen, hand naar beneden bewegen, waggelen, dan sluiten | Servo beweegt van 180° naar 35°, daarna naar 26°, dan weer omhoog |
| **2** | Deels openen van de doos, wachten, volledig openen, hand naar beneden, waggelen, dan sluiten | Servo gaat naar 170°, dan naar 35°, dan naar 26°, daarna weer omhoog |
| **3** | Onrustig openen, daarna hand naar beneden, waggelen, dan sluiten | Servo snel bounce tussen 180° en 165°, daarna naar 35°, dan weer omhoog naar 180° |
| **4** | Doos openen, hand naar beneden, waggelen, dan sluiten | Servo van 180° naar 35°, dan weer omhoog naar 180° |
| **5** | Langzaam openen, meerdere keren waggelen, dan sluiten | Servo langzaam van 180° naar 26°, daarna tussen 75° en 40° waggelen, dan weer omhoog |
| **6** | Langzaam openen, hand waggelen, dan sluiten | Servo van 180° naar 26° op een langzamer tempo, dan weer omhoog |
| **7** | Tot een bepaald punt openen, waggelen, volledig openen, dan sluiten | Servo van 180° naar 60°, tussen 60° en 40° waggelen, dan weer omhoog naar 180° |

---

### Schakelschema:
**Benodigdheden:**
- Arduino Nano
- Schakelaar MTS102 ON-ON
- Servo motor SG90
- WS2812B LED-strip (1 LED)

**Aansluitingen:**
<img width="1055" height="1560" alt="image" src="https://github.com/user-attachments/assets/e6bfdbff-8b79-42b7-83c0-9afd3b47a8c4" />

```
[Arduino]
 D2 ----> Data pin voor LED (WS2812B)
 D3 ----> Schakelaar ----> GND (met interne pull-up ingeschakeld)
 D4 ----> Signaalpin servo
 +5V ----> V+ servo / V+ LED
 GND ----> GND servo / GND schakelaar / GND LED
```

---

**Kort overzicht:**
- De schakelaar zorgt voor het wisselen tussen acties.
- De LED geeft visuele feedback: blauw standaard, rood tijdens uitvoeren.
- De servo beweegt volgens de gekozen actie, met vertragingen en waggelen voor een grappig effect.
