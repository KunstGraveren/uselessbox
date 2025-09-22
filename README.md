
**!! UPDATE !!**

Voor die de Useless Box hebben gemaakt tijdens The Reality 2025.

  - Bekende problemen:
      
      - Herstartende Nano
          - Servo vraagt net iets te veel stroom van de nano, waardoor een restart plaatsvindt. Een (16v 470uF) over de + servo / GND heen lost dit op.

      - Niet bereiken van de schakelaar

  - Code Fixes:

      - v1.1: 
        - Eind posities zijn niet meer hardcoded, schakelaar interrupt is gebruikt om te "detecteren" wanneer de servo moet stoppen.
        
---

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

### Schakelschema:
**Benodigdheden:**
- Arduino Nano
- Schakelaar MTS102 ON-ON
- Servo motor SG90
- WS2812B LED-strip (1 LED)
- **Condensator (16v 470uF)

** Sommige Nano icm de servo zorgt ervoor dat die in een "restart" loop komt, indien dit gebeurd plaats/gebruik de condensator volgends de tekening.


**Aansluitingen:**

<img width="40%" alt="image" src="https://github.com/user-attachments/assets/e6bfdbff-8b79-42b7-83c0-9afd3b47a8c4" />
<img width="40%" alt="image" src="https://github.com/user-attachments/assets/83f27311-656a-47eb-88c0-1975f5dd8bba" />


```
[Arduino]
    D2    ---->     Data pin voor LED (WS2812B)
    D3    ---->     Schakelaar ----> GND (met interne pull-up ingeschakeld)
    D4    ---->     Signaalpin servo
    +5V   ---->     V+ servo / V+ LED ---|
                                          -> Condensator
    GND   ---->     GND servo -----------|
                    GND schakelaar ------| 
                    GND LED -------------|
```
