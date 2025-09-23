
![](instructions-images/uselessbox.png)

<!-- TOC -->

- [Onderdelen:](#onderdelen)
    - [Geprinte onderdelen:](#geprinte-onderdelen)
    - [Montage:](#montage)
    - [Electronica:](#electronica)
    - [Tools:](#tools)
- [Voorbereiding:](#voorbereiding)
    - [Pin headers in de bodemplaat:](#pin-headers-in-de-bodemplaat)
    - [LED:](#led)
    - [Bedrading:](#bedrading)
    - [Servo in de bracket:](#servo-in-de-bracket)
    - [Combineren van Draden:](#combineren-van-draden)
- [Solderen:](#solderen)
    - [Ver-tinnen:](#ver-tinnen)
    - [Bedrading Solderen aan de Arduino:](#bedrading-solderen-aan-de-arduino)
    - [Arduino Pinnen Solderen:](#arduino-pinnen-solderen)
    - [LED Solderen aan de Arduino:](#led-solderen-aan-de-arduino)
    - [PowerOn](#poweron)
- [Montage:](#montage)
    - [Box:](#box)

<!-- /TOC -->

# Onderdelen:

## Geprinte onderdelen: 

- 1x achterkant
- 1x voorkant
- 1x bodem
- 1x deksel
- 2x zijkant
- 2x scharnier connector 
- 6x koppel connector 
- 1x arm
- 1x servo mount 
- 1x event logo 

## Montage:

- 8x M3 x 6mm
- 8x M3 x 8mm 

## Electronica:

- 4x 2 pins header
- 1x SG90 servo 
- 1x MTS-102 Schakelaar
- 1x Arduino Nano
- 1x WS2812B LED
- 1x USB kabel 

## Tools:

- 1x M3 Inbus (2.5) 
- 1x Soldeerbout 
- 1x Tin 
- 1x Zijknip tang
- 1x Punt tang 

---

# 1. Voorbereiding: 

## **Pin headers in de bodemplaat:**
<img align="right" width="20%" src="instructions-images/bodem_pins.png">

Neem vier 2-pins connectoren en plaats deze in de buitenste hoeken van de bodemplaat. Zorg ervoor dat de korte uiteinden van de pinnen naar beneden gericht zijn, zodat ze stevig in de bodem kunnen worden bevestigd.

- Duw de pinnen voorzichtig naar beneden totdat ze gelijk zijn met de onderkant van de bodemplaat.

<br><br>


## **LED:** 


- Plaats de nano op de pinnen

<!-- align="right" -->
<img  width="40%" src="instructions-images/led-01.png">


 - 1. \- Buig de LED in de juiste vorm, zodat deze uitkomt bij de aangegeven pinnen. Gebruik hiervoor het punt tangetje.

  \*\*vraag hulp indien nodig om ervoor te zorgen dat deze goed gepositioneerd / gebogen wordt.

  Let op ze “platte zijde” van de led

<!-- align="left" -->
<img  width="40%" src="instructions-images/led-02.png">

---

## **Bedrading:** 


<img align="right" width="30%" src="instructions-images/servo-kabel.png">

- Vouw de kabel van de servo zoals op de foto is aangegeven.

  **Let op, de kant met de connector is dus iets langer dan het stuk wat overblijft aan de servo.**  
    
  - Knip deze door op de vouw  
      
  - Knip ook de connector eraf  
      
  - Split en strip de uiteinden van alle draden aan beide zijden. Zorg ervoor dat je ongeveer 3 mm van de isolatie verwijdert.

  - Split de kabel die **NIET** aan de servo zit volledig, zodat je 3 losse kabels overhoud (geel, rood, zwart)

  - Knip de rode (losse draad) doormidden

## **Servo in de bracket:** 

- Schuif de kabels door het daarvoor bedoelde gat

  - **LET OP, deze schuift strak in de behuizing, letop dat de bedrading niet klem zit  \!\!**

- Schuif voorzichtig al begeleidend met de kabel de servo op zijn plek

- Schroef de servo in backet vast

<img align="right" width="20%" src="instructions-images/servo-mount-01.png">
<img width="40%" src="instructions-images/servo-mount-02.png">

---

## **Combineren van Draden:** 

  - Neem de losse **ZWARTE / BRUIN** draad en de **ZWARTE / BRUIN** draad van de servo.  
      
  - Twist deze twee draden samen zodat ze goed met elkaar verbonden zijn.

<img width="40%" src="instructions-images/bedrading-twist.png">



---

# 2.Solderen:

## **Ver-tinnen:** 

<img align="right" width="20%" src="instructions-images/bedraging-vertinnen.png">

- Ver-tin de uiteinden van de draden die je zojuist hebt gestript en hebt samengevoegd.  
    
  - Ver-tin de uiteinden van de schakelaar  
    
    Dit houdt in dat je een dunne laag soldeermetaal (tin) aanbrengt op de blootgestelde koperdraden om een betere verbinding te creëren als je ze soldeert.

    <img width="30%" src="instructions-images/bedraging-switch.png">

  - knip de overige lengte van de vertinde uitbeides af zodat er 1/1.5mm over blijft om aan de arduino/switch te solderen

---

## **Bedrading Solderen aan de Arduino:** 

**LED:**

<img align="right" width="22.75%" src="instructions-images/circuit.png">
<img align="right" width="30%" src="instructions-images/circuit-con.png">

   1. Grijs (+) 	\-\> 5v op de Arduino \*(ICSP pins)  
   2. Grijs (-) 	\-\> GND op de Arduino \*(ICSP pins)  
   3. Rood (signaal)	\-\> D2 op de Arduino  
        
**Schakelaar:**  

   4. Zwart 		\-\> GND op de Arduino  
   5. Geel (signaal) \-\> D3 op de Arduino  
        
**Servo:**

   6. Rood (+) 	\-\> 5V op de Arduino  
   7. Zwart (-) 	\-\> GND op de Arduino  
   8. Geel (signaal) \-\> D4 op de Arduino

**\**Condensator:**  

   9. (+) 	\-\> 5V op de Arduino  
   10. (-) 	\-\> GND op de Arduino  
   

** Sommige Nano icm de servo zorgt ervoor dat die in een "restart" loop komt, indien dit gebeurd plaats/gebruik de Condensator (16v 470uF) volgends de tekening.

---

Stapsgewijs gaan wij de draden solderen aan de Arduino. We beginnen met de gecombineerde zwarte draad van de servo en de schakelaar. Soldeer deze aan de **GND** pin van de Arduino.

<img width="30%" src="instructions-images/solderen-01.png">

Neem het andere uiteinde van de zwarte draad en soldeer deze aan de middelste pin van de schakelaar. 

**Soldeer de draden “ zijwaarts" op de schakelaar.**

<img width="30%" src="instructions-images/solderen-02.png">

Soldeer het gehalveerde losse rode draad aan **D2** pin van de Arduino. (die straks naar de led gaat)

<img width="30%" src="instructions-images/solderen-03.png">

Soldeer de losse gele draad (signaal) op de schakelaar (deze gaat op een van de buitenste pinnen) 

**Soldeer deze "zijwaarts" op de schakelaar**

Het andere uiteinde van de gele draad gaat naar de **D3** pin van de Arduino.

<img width="30%" src="instructions-images/solderen-04.png">

Neem de rode draad van de servo en soldeer deze aan de **5V** pin van de Arduino.

<img width="30%" src="instructions-images/solderen-05.png">

Neem de gele draad van de servo en soldeer deze aan de **D4** pin op de Arduino.

<img width="30%" src="instructions-images/solderen-06.png">

**Indien de condensator nodig is, soldeer deze over de **5V** en de **GND**

**LET OP: er is een MIN en een PLUS kant. De kant met witte streep met - - - - moet naar de GND!**

<img width="30%" src="instructions-images/circuit-con.png">



---

## **Arduino Pinnen Solderen:**  


- Soldeer de Arduino Nano vast aan de pinnen die je in stap 2 hebt geplaatst. Dit is alleen zodat de Arduino Nano blijft zitten in de box. 1 van de 2 pennen is voldoende om dit resultaat te krijgen.

  - Let goed op dat je de juiste gaten gebruikt; je dient de buitenste twee soldeergaten aan de hoeken van de Nano te gebruiken voor een correcte en stevige verbinding.

  ** uitzondering voor de arduino nano, die extra pinnen hebben. Hierdoor zal deze de één na laaste pinnen bevatten aan de niet usb kant.

  <img width="75%" src="instructions-images/solderen-07.png">  

## **LED Solderen aan de Arduino:** 
  
  <img align="right" width="10%" src="instructions-images/led-circuit.png">

  - Plaats de LED op zijn plek. (platte zijde zit aan de rechterkant, in de foto)

  - Soldeer de (-) aan de **GND** pin van de Arduino. \*(ICSP pins)  
      
  - Soldeer de (+) aan pin **5V** van de Arduino. \*(ICSP pins)  
      
  - Soldeer de rode draad die je eerder op **D2** van de Arduino hebt gesoldeerd, vast aan de (data) pin van de LED.

  
    <img width="75%" src="instructions-images/solderen-08.png">

---

## **PowerOn** 

Alles klaar? Laat iemand van de Makerspace je soldeerwerk controleren, waar gezamenlijk een check wordt gedaan door hem aan te sluiten op stroom.

De led en de servo zouden hun eerste beweging moeten maken. Dit zorgt er ook voor, dat de servo op zijn “uit” positie komt te staan, zodat wanneer de arm gemonteerd wordt deze de juiste plek heeft.

Issues?
- Blijft de Arduino Nano resetten? --> Soldeer de Condensator!

---

# 3\. Montage: 

## **Box:** 

Monteer de hoek connectors en de servo bracket aan de zijplaten. Let op dat er een boven- en onderkant is. Waar de gleuf zit is de onderkant van het paneel.

- 4 connectoren aan de ene kant, en 2 connectoren op de andere kant.  
- Draai deze nog niet helemaal vast, maar zo dat de connector nog net kan bewegen.
<img width="100%" src="instructions-images/montage-01.png">

  Monteer de schakelaar in de voorplaat waarbij de gele draad naar beneden moet. 
  
<img width="50%" src="instructions-images/montage-02.png">

  Monteer de servo mount aan de zijplaat.
  
<img width="50%" src="instructions-images/montage-03.png">

  Plaats de zijplaat met de servo en de voorplaat op de bodem. deze klikt soort van vast in de rand

<img width="50%" src="instructions-images/montage-04.png">

  Schroef nu via de voorkant (de kant die aansluit met de zijkant) nu vast met 2 boutjes

  Neem de Servo handel uit het zakje van de servo, en klik deze in de arm. Het makkelijkst is deze met de schuivende beweging erin te klikken.

<img width="50%" src="instructions-images/montage-05.png">

Monteer de arm, zodat deze met de punt van de arm horizontaal gelijk is met de box. Dit zodat de deksel dicht kan.

<img width="50%" src="instructions-images/montage-06.png">

**PS, mocht de Arduino nog niet aan geweest zijn, is dit hét moment om dit te doen. Dit zodat deze de servo in de 180 graden stand zet (sluit stand / box dicht).**

Als de arm gemonteerd is, kan je controleren of die goed zit, door hem op stroom aan te sluiten. Als de arm goed zit, schroef de arm vast.

**PAS OP schroefje, is heel klein\!**

<img width="50%" src="instructions-images/montage-07.png">

Plaats de andere zijde

Schroef deze vast aan de voorkant, met 2 boutjes

Plaats achterplaat.

Schroef onderste 2 bouten van de achterplaat vast

<img width="50%" src="instructions-images/montage-08.png">

Klik de scharnieren aan de top vast, doe dit met beleid.

<img width="50%" src="instructions-images/montage-09.png">

**PAS OP: de vleugels zijn nogal gevoelig en kunnen snel breken\! Vraag iemand om te helpen, als het niet lukt.**

<img width="50%" src="instructions-images/montage-10.png">

Plaats de bovenplaat

Schroef de scharnieren met bovenste 2 schroeven vast.

<img width="50%" src="instructions-images/montage-11.png">

Klaar\! En veel plezier \!


© kunstgraveren.nl 2025
