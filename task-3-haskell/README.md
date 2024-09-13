<img src="https://media1.tenor.com/m/_MRCAQMd_0wAAAAC/hyping-fire.gif" align="right" width="300" />

# 🍛 task 3: Turn up the heat

## Läsanvisning

- Learn you a Haskell:
    - [Kapitel 8](https://archive.is/NNJ6U)
    - [Kapitel 11](https://archive.is/mO1Cv)
    - Just denna vecka kommer vi inte hålla på med input/output (IO), så du kan skippa kapitel 9 för nu. Däremot är det bra förberedelse till nästa veckas task.
    - Om du får tid över kan du också läsa på kapitel 12 inför nästa vecka.

Monoider brukar vara lite svårare att få grepp på, eftersom det är svårt att jämföra dem till objektorienterade språk. ChatGPT kan vara ganska bra på att förklara saker om du ber den att använda en liknelse eller metafor!

Här är lite andra resurser som kan vara till hjälp:

- [En väldigt matematisk förklaring på monoider](https://www.youtube.com/watch?v=bsp5pJlw6R0)
- [Officiell dokumentation på en monoids definition](https://hackage.haskell.org/package/base-4.10.0.0/docs/Data-Monoid.html)
- [Haskell-Wiki har en entry om monoider](https://wiki.haskell.org/Monoid)



## Koduppgifter
### Del I: Heater (Statisk data)
Denna uppgift ska visa på hur man kan jobba med enkel data i
Haskell, lite som objekt i objektorienterade språk. Du får gärna använda *Record-syntax* (se läsanvisningen ovan), men det är inte ett hårt krav.

I följande instruktioner finns det många steg. Du behöver inte spara varje steg, det räcker med att pusha slutprodukten efter du är klar med allt.

1. Skapa en ny fil som heter "Heater.hs". I första raden ska det stå `module
Heater where`.
    - Du behöver inte veta vad den raden gör än, den är till för rättningens skull. Om du vill kan du kan läsa mer om moduler i kapitel 7 i boken.
2. Skapa en ny datatyp vid namn `Heater` som innehåller ett fält vars typ är en `Double`.
3. Eftersom det är rätt trevligt att se en textrepresentation av datan,
se till att den har en instans av "Show". Det finns exempel i kapitlet ovan, men här finns ett till exempel på hur det kan se ut:
```haskell
data MinFinaDatatyp = MinFinaDataTyp Int Int Bool Bool deriving (Show)
```
4. Gör en konstruktor vid namn `defaultHeater`, som tar inga argument och returnerar objekt av typen `Heater`, som har ett fält `temperature` med värde `15.0` (sparad som en `Double`).
5. Definiera två funktioner vid namn `warmer` och `cooler` vars
typ är `Heater -> Heater`. De ska höja respektive sänka temperaturen med
5 grader, och returnera en ny `Heater` med den nya temperaturen.
6. Modifiera nu `Heater`-datatypen till att innehålla två nya fält vid namn
`maxTemp` och `minTemp`, båda av typen Double.
7. `defaultHeater` ska nu även definiera en ursprunglig `minTemp` som `-20.0`, och `maxTemp` som `30.0`.
8. Skapa även en ny funktion vid namn `makeHeater`, som tar två `Double`s
som input och ger tillbaka en `Heater`. Funktionen ska skapa en `Heater` genom att först använda `defaultHeater`, och sedan modifiera `maxTemp` och `minTemp` till respektive argument.
9. Modifiera nu `warmer` och `colder` till att respektera `Heater`-datans min- och maxtemperatur. Om den nya temperaturen kommer hamna utanför intervallet, ändra inte temperaturen.
10. Vi vill kunna finjustera temperaturändringen också. Lägg till ytterligare en fält `increment` som defaultar till `5.0`. `makeHeater` ska ha en ny parameter som sätter värdet på detta fält, och `warmer` och `colder` ska respektera detta värde när de justerar temperaturen.
11. Sist men inte minst, skapa en `setIncrement`-funktion som tar en `Double`
och en `Heater`, och returnerar en ny `Heater` vars
`increment` fält ska vara det nya talet.

### Del II: Monoider
Monoider är ett exempel på hur man kan göra abstraktioner för att
hitta väldigt generella logiska strukturer.

Här kommer ett exempel på hur beräkning av medelvärde kan uttryckas som monoid.

```haskell
import Data.Monoid

data Medelvarde = Medelvarde Double Double deriving (Show)

fromMedelvärde (Medelvärde a 0) = 0
fromMedelvärde (Medelvärde a b) = a / b

instance Monoid Medelvärde where
     mempty = Medelvärde 0 0
     mappend (Medelvärde _ 0) a = a
     mappend a (Medelvärde _ 0) = a
     mappend (Medelvärde s1 n1) (Medelvärde s2 n2) =
	  Medelvärde (s1 + s2) (n1 + n2)
```
(Det här är ett exempel. När du själv skriver koden så kommer det inte nödvändigtvis se ut på samma sätt.)

Du ska nu definiera två monoid-instanser för datatyperna `Addition` och `Produkt` för nummer. Tips: du kan begränsa en instans definitions
algebraiska typ till att vara av en viss klass. Instans-signaturen kan då se ut
på följande sätt:
```haskell
instance (Num a) => Monoid (Addition a) where
```

1. Börja med att skapa en ny fil med namn `MonoidFoo.hs`, och skriv `module MonoidFoo where` i första raden.
2. Definiera två datatyper vid namn `Addition` och `Produkt`. dessa ska båda ta en *type parameter* (se kap 8) som definierar vilken typ den innehåller.
3. Sedan kan du definiera monoid-instanserna. Kom ihåg att identitetselementet (eller `mempty`) är 0 för Addition, och 1 för Produkt.

```haskell
additionTest = mconcat (map Addition [1..10])
-- har du gjort rätt ska additionTest ha värdet 55

productTest = mconcat (map Produkt [1..5])
-- har du gjort rätt ska productTest ha värdet 120
```



## Teorifrågor
Skriv in svaret på detta i en fil som heter `README.md` i docs.

#### Fråga 1
För din `Heater.hs`: Vad händer om "increment" är negativt? Vilka sätt kan vi lösa det på?

#### Fråga 2
När man pratar om klasser i Haskell är det lite annorlunda från
definitionen i objektorienterade språk, och det kan vara lite
förvirrande för de som kommer från en objekt orienterad bakgrund. Men
om du skulle förklara skillnaden för en intresserad främling som inte
vet någonting om klasser i varken objektorienterade språk eller
funktionella, hur hade du gjort det då?

#### Fråga 3
Att generalisera data så som Haskell gör är inte alltid självklar i
alla språk. Men i t.ex Java och C++ kan man göra det till en viss grad.
Varför vill man kunna göra detta?

#### Fråga 4
Många saker är monoider när man tänker lite på det. Kan du komma på
några exempel? På vilket sätt är de monoider?