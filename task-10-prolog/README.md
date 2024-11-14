<img src="https://media1.tenor.com/m/saWRs1C3YccAAAAd/spock-dazzling-display.gif" align="right" width="300" />

# 🍛 task 10: Prolog? How about you provide some logs?

Vi drar igång DD1338 med ett programmeringsspråk som beter sig på ett väldigt unikt sätt. *Prolog* (som enligt vissa källor står för LOGical PROgramming trots att det inte heter Logpro) är ett språk som används primärt för att genomföra logiska bevis. Alltså går allt i språket ut på true/false, och det skapar lite intressanta sätt att skriva algoritmer på.

## Lästips

- [Prolog beginner guide](https://github.com/aychtang/prolog-beginner-guide) (Lätt att komma igång med)
- [Learn Prolog Now!](https://lpn.swi-prolog.org/lpnpage.php?pageid=online) (Basically officiell litteratur. Vi kommer inte hålla på med Prolog *så* mycket, men vissa kapitel kan vara användbar)
- [Officiell dokumentation](https://www.swi-prolog.org/search?for=) (Prolog har *väldigt* många inbyggda predikat som kan underlätta väldigt mycket.)

## Komma igång

**Alternativ 1:** Nuförtiden behöver man inte installerat något för att köra Prolog, utan det går att köra i webbläsaren direkt: https://swish.swi-prolog.org/

- För "Create a program/notebook here", välj "Program".
- På vänster sida är där du skriver programkoden, och i nedre högra hörnet skriver du dina queries.

**Alternativ 2:** Om man känner sig speciellt fancy får man självklart installera Prolog också: https://www.swi-prolog.org/

- Skriv `swipl` i konsolen/terminalen för att starta SWI-Prolog-environmenten, eller `swipl filnamn.pl` för att ladda in Prolog-filen `filnamn.pl` direkt (om den finns i samma directory).
- I SWI-Prolog, skriv `[filnamn].` för att ladda in Prolog-filen `filnamn.pl` (om den finns i samma directory).

Här är ett exempelprogram samt några exempelqueries för att testa om du har lyckats få Prolog att fungera:

```prolog
child(stefán, stefánsson).
child(stefán, stefánsdóttir).
child(agnes, stefánsson).
child(kristi, almarsson).
child(klaus, klausdóttir).
child(almar, almarsson).

married(X,Y) :-
    child(X,Z),
    child(Y,Z),
    not(X == Y).
```

```
?- child(klaus, klausdóttir).
true.

?- child(stefán, X).
X = stefánsson ;
X = stefánsdóttir.

?- married(agnes, stefán).
true.

?- married(kristi, X).
X = almar.
```

## Koduppgifter

Skriv alla följande predikat i samma fil, tack!

**OBS: Det finns väldigt många användbara predikat i Prologs standardbibliotek, dock så får du inte använda en predikat som bara löser uppgiften direkt åt dig, t.ex. 
[sum/3](https://www.swi-prolog.org/pldoc/doc_for?object=sum/3) för uppgift 2.**

### Uppgift 0 (frivilligt warmup)

Skriv en predikat `factorial(N,F)` som tar in ett heltal `N` och binder `F` till dess fakultet. Exempel:
```
?- factorial(5,F).
F = 120.
```

### Uppgift 1

Skriv en predikat `sequence(Start, End, List)` som tar in två heltal `Start` och `End`, och binder `List` till en lista av siffror från `Start` (inklusive) till `End` (exklusive). Exempel:
```
?- sequence(0,5,List).
List = [0, 1, 2, 3, 4].
```

### Uppgift 2

Skriv en predikat `sum(List,S)` som tar in en lista av heltal `List`, och binder `S` till summan av alla talen. Exempel:
```
?- sum([10,5,40],S).
S = 55.
```

### Uppgift 3

Skriv en predikat `shuffle(InList,OutList)` som tar in en lista `InList`, skyfflar den, och binder `OutList` till resultatet. Exempel:
```
?- shuffle([1,5,3,2],Out).
Out = [3,5,2,1].
```
Här rekommenderas [Fisher-Yates shuffle](https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle). Du behöver nog använda predikatet [random/3](https://www.swi-prolog.org/pldoc/man?predicate=random/3).