# 🍛 2: It's time to cook

## Läsanvisningar
Det är rekommenderad att läsa fram till kapitel 6 i boken http://learnyouahaskell.com

(Arkiverad länk för fungerande CSS: https://archive.is/qvoOT)

## Koduppgifter
Lös alla fyra uppgifter på denna länk: https://kth.kattis.com/courses/DD1360/progp24/assignments/fymgmo/problems/kth.progp.warmup
(Ni får gärna samarbeta med varandra i gruppen!)

## Teorifrågor
Svara även på följande frågor:

1. Förklara steg för steg vad som händer i följande kod, och varför det går att skriva så i Haskell.
```haskell
let evenNumbers = [ 2 * n | n <- [1..]]
print (take 1000000 evenNumbers)
```

2. Vad innebär rekursion?

3. Varför fungerar följande funktion i t.ex. Haskell (första kodblocket), men inte i t.ex. javascript (andra kodblocket)?
```haskell
sum :: Integral n, Num n => n -> n -> n
sum s 0 = s
sum s n = sum (s + n) (pred n)
```

```javascript
function sum(s, n) {
     if(n == 0){
         return s;
     } else{
         return sum(s + n, n - 1);
     }
}
```

## Inlämning och rättning
Lösningarna ska lämnas in genom att kopiera in den här mappen in i ert vanliga
repo. Ta bort de filer som finns där från början.

När jag rättar kommer jag att lämna ett issue med titeln 'pass' eller
'komplettering' eller 'fail'. Om ni har fått pass är ni godkända. Om ni har en
issue med titeln 'komplettering' kommer det att finna några saker jag vill att
ni ändrar innan jag kan godkänna er. Vanligtvis skriver jag vad det är jag vill
att ni ändrar i kommentarerna. När ni har utfört ändringarna så vill jag att ni
svarar med en kommentar på det issuet.
'Fail' förklarar nog sig självt.
