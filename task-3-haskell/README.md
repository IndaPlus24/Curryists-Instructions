<img src="https://media1.tenor.com/m/_MRCAQMd_0wAAAAC/hyping-fire.gif" align="right" width="300" />

# 🍛 task 3: Turn up the heat

> [!IMPORTANT]
> Mycket av innehållet på sidan har modifierats efter övningen.
> Det berör hela **Del II**, teorifrågor 3, samt läsanvisningen.
> 
> På grund av ändringen är deadlinen för uppgiften förskjutet till söndag 22 sep, 23:59.
> 
> Se Discord-anslaget för mer information.

## Läsanvisning


- Learn you a Haskell:
    - [Kapitel 8: Datatyper](https://archive.is/NNJ6U)
    - [Kapitel 9: I/O](https://archive.is/RYn9G)


## Koduppgifter
### Del I: Heater (Statisk data)
Denna uppgift ska visa på hur man kan jobba med enkel data i
Haskell, lite som objekt i objektorienterade språk. Du får gärna använda *Record-syntax*
(se läsanvisningen ovan), men det är inte ett hårt krav.

I följande instruktioner finns det många steg. Du behöver inte spara varje steg,
det räcker med att pusha slutprodukten efter du är klar med allt.

1. Skapa en ny fil som heter "Heater.hs". I första raden ska det stå `module Heater where`.
    - Du behöver inte veta vad den raden gör än, den är till för rättningens skull.
    Om du vill kan du kan läsa mer om moduler i kapitel 7 i boken.
2. Skapa en ny datatyp vid namn `Heater` som innehåller ett fält vars typ är en `Double`.
3. Eftersom det är rätt trevligt att se en textrepresentation av datan,
se till att den har en instans av "Show". Det finns exempel i kapitlet ovan,
men här finns ett till exempel på hur det kan se ut:
```haskell
data MinFinaDatatyp = MinFinaDataTyp Int Int Bool Bool deriving (Show)
```
4. Gör en konstruktor vid namn `defaultHeater`, som tar inga argument
och returnerar data av typen `Heater`, som har ett fält `temperature`
med värde `15.0` (sparad som en `Double`).
5. Definiera två funktioner vid namn `warmer` och `cooler` vars
typ är `Heater -> Heater`. De ska höja respektive sänka temperaturen med
5 grader, och returnera en ny `Heater` med den nya temperaturen.
6. Modifiera nu `Heater`-datatypen till att innehålla två nya fält vid namn
`maxTemp` och `minTemp`, båda av typen Double.
7. `defaultHeater` ska nu även definiera en ursprunglig `minTemp`
som `-20.0`, och `maxTemp` som `30.0`.
8. Skapa även en ny funktion vid namn `makeHeater`, som tar två `Double`s
som input och ger tillbaka en `Heater`. Funktionen ska skapa en `Heater`
genom att först använda `defaultHeater`, och sedan modifiera `maxTemp`
och `minTemp` till respektive argument.
9. Modifiera nu `warmer` och `colder` till att respektera `Heater`-datans
min- och maxtemperatur. Om den nya temperaturen hamnar *utanför* intervallet,
ändra inte temperaturen.
10. Vi vill kunna finjustera temperaturändringen också. Lägg till ytterligare en fält
`increment` som defaultar till `5.0`. `makeHeater` ska ha en ny parameter som sätter
värdet på detta fält, och `warmer` och `colder` ska respektera detta värde när de
justerar temperaturen.
11. Sist men inte minst, skapa en `setIncrement`-funktion som tar en `Heater`
och en `Double`, och returnerar en ny `Heater` vars `increment` fält ska vara det nya talet.

### Del II: I/O

Hittills har vi fått köra våra program i GHCi, vilket fungerar, men det är inte så användbart
i praktiska sammanhang. Vi vill därför kunna kompilera programmet och interagera med den via
standard input/output (I/O) istället.

Man kompilerar ett Haskell-program med kommandot
```bash
ghc filnamn.hs
```
Du bör se tre filer genereras i mappen. Du kan radera de som slutar på `.o` och `.hi`:
[just nu är de irrelevanta.](https://stackoverflow.com/a/56403944) Den återstående filen är din *executable*,
som du kan köra i din terminal helt vanligt genom att kalla på den. (Obs: Jag har inte testat för Windows,
men [proceduren verkar vara samma.](https://stackoverflow.com/a/6306823))

> [!NOTE]
> Det är inte krav att pusha de kompilerade filerna till GitHub, bara källkoden räcker.
> Däremot måste du kunna kompilera och köra din kod, för att veta att den fungerar som förväntad.

1. Skapa en fil `Calculator.hs`. Det kompilerade programmet ska göra följande:
    - Be användaren att skriva ett tal (`Double`), välja ett av de fyra räknesätten
      (`+`, `-`, `*`, `/`), och sedan skriva in ytterligare ett tal (`Double`).
        - Du behöver inte ha felhantering för oväntat input. Vi antar att användaren
          kan följa instruktioner och inte kommer försöka få sönder programmet.
    - Räkna fram resultatet och visa det till användaren.
2. Skapa en fil `WordCount.hs`. Det kompilerade programmet ska göra följande när man kör det:
    - Be användaren att skriva in ett filnamn. (Filen existerar i samma mapp.)
    - Räkna fram antalet rader, ord och tecken i filen, och visa dem till användaren.
        - Som test: [beemovie.txt](beemovie.txt) ska returnera 4071 rader, 15802 ord
          och 86091 tecken, och beräkningen ska gå på en bråkdel av en sekund.
        - Du kan själv genomföra ytterligare tester med valfri textfil och Unix-kommandot `wc`.
          Programmet ska ge samma resultat som om du körde `wc filnamn.txt`.
    - **Till skillnad från förra veckans uppgift** så är endast blanksteg ord-delande.
        - `100.12aj)/` är ett ord, medan `a  9d     :` är tre ord.
        - Det kanske finns [existerande funktioner](https://hoogle.haskell.org/) som är
          användbart här...
3. Gå tillbaka till `Heater.hs` från **Del I**, och lägg till en `main`-funktion
   som gör följande vid körning:
    - Generera ett slumpmässigt heltal mellan (men inte inklusive) `-20` och `30`.
    - Skapa en `Heater` med `defaultHeater`-funktionen, och ändra `increment` till `1.0`.
    - Berätta för användaren det slumpgenerade heltalet: det är målet som
      användaren ska justera `temperature`-fältets värde till.
    - Prompta användaren med alternativ för att ändra temperaturen upp eller ner.
      Upprep detta tills `temperature` matchar målet exakt, varpå användaren får veta att
      hen har lyckats justera temperaturen korrekt, och programmet avslutas.

## Teorifrågor
Skriv in svaret på detta i en fil som heter `README.md` i docs.

#### Fråga 1
För din `Heater.hs`: Vad händer om "increment" är negativt?
Vilket sätt kan vi lösa det på?

#### Fråga 2
När man pratar om klasser i Haskell är det lite annorlunda från
definitionen i objektorienterade språk, och det kan vara lite
förvirrande för de som kommer från en objekt orienterad bakgrund. Men
om du skulle förklara skillnaden för en intresserad främling som inte
vet någonting om klasser i varken objektorienterade språk eller
funktionella, hur hade du gjort det då?

#### Fråga 3
Vi säger att Haskell är *purely functional*. Vad innebär det,
och varför bryter I/O mot den definitionen?