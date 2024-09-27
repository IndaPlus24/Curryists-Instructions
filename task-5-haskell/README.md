<img src="https://media1.tenor.com/m/TgpQCGv2R8YAAAAd/4d-gaming-gaming.gif" align="right" width="300" />

# 🍛 task 5: Keep hands inside vehicle

Nu när vi kan kompilera vårt program är det dags att bygga (lite mer)
seriösa program! Den här veckan använder vi oss av `cabal` samt
`gtk3`-hackagen (haskell package) för att skapa ett program med ett
grafiskt gränssnitt. Vi kommer sedan testa programmet genom att själv
skriva tester för den och köra med `HUnit`.

## Läsanvisning
- Del I:
    - [A Guide to Gtk3 with Haskell](http://www.bildungsgueter.de/HaskellGtk3En/Pages/TOC.htm), kapitel "First Window".
        - Många exempelkod i guiden använder `import "gtk3" Graphics.UI.Gtk`.
        Om det inte fungerar, testa `import Graphics.UI.Gtk`.
    - [Officiell dokumentation](https://hackage.haskell.org/package/gtk3-0.15.0/docs/Graphics-UI-Gtk.html)
- Del II:
    - [HUnit 1.0 User's Guide](https://wiki.haskell.org/HUnit_1.0_User's_Guide)

## Koduppgifter

### Del Ø: Sätta upp projektet

I [sample-cabal-project](sample-cabal-project/) kan ni hitta ett
demo-projekt, och då behöver man bara köra `cabal update` och `cabal build`.
Däremot så är det bra att känna till hur man sätter upp sina
egna projekt.

0. Se till att du har [GHCup](https://www.haskell.org/ghcup/) och 
[Cabal](https://www.haskell.org/cabal/) installerad. (När du har
GHCup kan du köra `ghcup install cabal`.)
1. I ditt repo, gå in i din `/src`-mapp, **skapa en ny mapp `/calculator`**,
och kör `cabal init`.
2. Du kommer få väldigt många frågor i terminalen relaterad till
projektet. Det går bra att köra default-valet på allt. (Förutom val av
licens: där får du ingen default, men du kan välja whatever, jag kommer
knappast sno din kod.)
3. Gå till `.cabal`-filen som har genererats i mappen, hitta raden som
börjar på `build-depends:`, och lägg till `, gtk3` i slutet av
raden. Detta säger åt kompilatorn att använda hackagen när den bygger
programmet.
4. Kör `cabal update` och `cabal install gtk3`.
5. Kör `cabal build`. **Det här kan ta länge.**
6. Efter det kan du köra `cabal run` för att kontrollera att programmet
körs.

> [!CAUTION]
> I `/src/calculator`-mappen, lägg till filen `.gitignore` där du skriver
> följande:
> 
> `/dist-newstyle`
> 
> Det hindrar git från att committa och pusha 3 000+ filer som genereras
> av att du bygger projektet.

### Del I: Bygga en miniräknare

Skapa ett miniräknare som tar in ett enkelt matematiskt uttryck och
beräknar den. När man kör programmet med `cabal run` ska det visa ett
fönster med följande innehåll:
- en displayruta (`label`) som visar det nuvarande uttrycket. Den ska
börja tomt.
- 10 knappar, en för varje siffra 0-9. När man trycker på dem ska
motsvarande siffra "skrivas in" i displayrutan.
- 2 knappar som lägger till ett plustecken resp. minustecken i
displayrutan, men bara om den senaste inputen är en siffra. (Så att man
inte kan ha flera plus eller minus i rad.)
- 1 knapp som tar bort den senaste inputen.
- 1 knapp som rensar all input.
- 1 knapp som beräknar formeln som finns i displayrutan, och
ersätter displayrutans innehåll med resultatet.

Själva beräkningen ska ske i en separat, "pure" funktion som heter
`calculate`, tar in en sträng (formeln) och returnerar ett heltal
(resultatet).

### Del II: Testa beräkningen

Nu är det dags att kontrollera att beräkningen fungerar! För att göra
det enkelt (och att jag inte hade tid att kasta ihop något mer komplext)
(mest den andra anledningen) så kör vi tester på följande vis:

1. Skapa en ny fil i `/src` som heter `CalculatorTest.hs`.
2. Kopiera innehållet i [CalculatorTest.hs](CalculatorTest.hs) till filen.
3. Lägg in din miniräknarfunktion i filen.
4. Starta ghci via `cabal repl --build-depends HUnit`, och importera sedan
filen med `:l filnamn.hs`.
5. Kör `runTestTT tests` och observera resultatet.

Om allt ger rätt output, grattis! Du är klar med Del I. (För en extra uppgift
som inte bedöms, hantera felaktiga input och testa med `test7` och `test8`.)

> [!TIP]
> Om du vill se ett exempel, se [HUnitExample.hs](HUnitExample.hs). Funktionerna där
> passerar inte alla tester — som övning (frivilligt) kan du försöka att fixa
> dem.

Det andra du ska göra i Del II är att skriva dina egna tester. I
[NumeralTest.hs](NumeralTest.hs) ser du ett program **(INTE FÄRDIGT JUST NU)** som
saknar tester. Er uppgift blir att skriva tester så att vi kan kontrollera att
programmet kör som förväntad, och rätta till buggar om något inte stämmer.
Se testernas namn för ledtråd på vad du borde testa för.

## Teorifrågor
Skriv in svaret på detta i en fil som heter `README.md` i docs.

#### Fråga 1
`cabal` är inte samma sak som `cabal install` (aka `cabal-install`).
Förklara skillnaden.

#### Fråga 2
Nämn en likhet och två skillnader mellan `stack` (Haskell Tool Stack)
och `cabal install`. Det kan handla om implementation, hur de fungerar
"under the hood", användargränsnittet osv.

#### Fråga 3
Varför är unit tests viktiga / bra att ha? Nämn en anledning.