<img src="https://media1.tenor.com/m/1u15ulrFh1EAAAAC/asc.gif" align="right" width="300" />

# 🍛 task 7: The peer-to-peer experience

Som det gamla ordspråket lyder, "two heads are better than one." Den här tentaperioden (plus veckan efter) (mest veckan efter, jag vill inte be er parprogrammera under tentaP) ska vi ta reda på om påståendet är sant genom påtvingat samarbete, där ni ska få göra en hemsida som i sin tur utsätter användarna för påtvingat samarbete. It's the circle of life.

## LÄS DET HÄR FÖRST INNAN NI BÖRJAR

**Uppgiften är ett grupparbete mellan 2-3 personer.** Börja så här:

1. En person i gruppen skapar en privat repo i `inda-24`-organisationen (där ni har lämnat in all er kod so far). Ni kan döpa den till vadsomhelst, men namnet måste börja med era KTH-ID:er för att undvika konflikter med andra vanliga repos, t.ex. `namn1-namn2-awesome-game`
2. Personen som skapade repon behöver bjuda in de andra i gruppen till repon som collaborators. Det gör man genom att gå in i inställningar för repon.
3. Någon i gruppen måste ge mig länken till er repo. Detta görs smidigast genom att DM:a mig på Discord.
4. Börja programmera!

## Lästips

- [Google slides för övningen](https://docs.google.com/presentation/d/1EqzllrCRI6eMPgXCrsd5rBgkSNi6n0BNFQrEhIsXNI8/edit?usp=sharing)
- [Our lord and savior Viggo Kann: om parprogrammering](https://www.csc.kth.se/tcs/projects/cerise/parprogrammering/)
- [Fireship: WebSockets & socket.io](https://www.youtube.com/watch?v=1BfCnjr_Vjg)
- [En liten IRC-chatt jag gjorde i gymnasiet](chat_example/)
- [W3Schools: NodeJS File System Module](https://www.w3schools.com/nodejs/nodejs_filesystem.asp)

### Parprogramming

Parprogramming är en viktig färdighet att ha. Läs mer om parprogrammering [här](https://www.csc.kth.se/tcs/projects/cerise/parprogrammering/) (Viggos text) eller [här](https://docs.google.com/presentation/d/1EqzllrCRI6eMPgXCrsd5rBgkSNi6n0BNFQrEhIsXNI8/edit#slide=id.g30a56e61277_0_14) (min sammanfattning).

Ni måste inte tillämpa arbetssättet i ert arbete, men det är rekommenderat att ni försöker med det åtminstone en gång.

## Koduppgift

Målet med denna task är att skapa en MMO ([Massive Multiplayer Online](https://en.wikipedia.org/wiki/Massively_multiplayer_online_game))-upplevelse! Det behöver självklart inte vara World of Warcraft-nivå av MMORPG, utan det räcker med något som liknar [agar.io](https://en.wikipedia.org/wiki/Agar.io).

På övningen har vi pratat om socket.io, men **ni får utveckla spelet i vilket språk eller omgivning ni vill.** Nedan följer några grundläggande specifikationer för spelet, men vad spelet faktiskt går ut på är helt upp till er!

- Spelet ska kunna spelas i webbläsaren.
    - *Det är INTE ett strikt krav* om ni verkligen vet vad ni håller på med, men browser-spel är väldigt nice i att man behöver inte installera något på sin dator för att spela, och därmed behöver man inte bry sig om olika operativsystem.
- *Om det är lämpligt för speltypen* bör spelaren också kunna välja namn och annat customization.
- Spelarna i spelvärlden ska kunna kommunicera (förmedla information utan att direkt påverka spelets status, t.ex. textchatt) och interagera (aktioner som påverkar spelet direkt, t.ex. attack) med varandra på något vis.
- Beroende på speltypen så ska spelaren kunna "förlora" och/eller "vinna" spelet.
    - Exempel: i [agar.io](https://en.wikipedia.org/wiki/Agar.io) kan man förlora genom att bli dödad av en annan spelare, men spelet har inte ett förbestämt mål, utan "målet" är bara att växa större och ranka upp i leaderboarden.
    - Exempel: i [cursors.io](https://cursors.uvias.com/) kan man inte förlora spelet, förutom att ladda om hemsidan och starta om från nivå 1. Däremot kan man vinna spelet genom att klara sista nivån.
    - Exempel: i Minecraft (speciellt [Minecraft Classic](https://classic.minecraft.net) eftersom det kan spelas i webbläsaren) finns det inget sätt att vinna eller förlora spelet på. (Om ni vill göra en purely sandbox-spel som denna, försök ha rimligt mycket innehåll i spelet för spelarna att leka med.)
- Beroende på speltypen kan det vara lämpligt med en gräns på antalet spelare. (t.ex. det är ganska svårt att spela *Fyra-i-rad* med 40 spelare på samma bräde.)
    - I så fall måste spelarna få veta varför de inte kan ansluta sig till spelet.
- Spelet ska lagra och läsa information (t.ex. spelets och spelarnas stadier) i någon sorts databas på serverns sida (server-side).
    - Jag rekommenderar att använda [`fs`-modulen](https://www.w3schools.com/nodejs/nodejs_filesystem.asp) för att låta servern skriva till och läsa från JSON-filer server-side.

### Extra utmaningar 
Här är några förslag på funktioner ni kan lägga till i spelet. **Dessa krävs inte för uppgiften** men kan vara roliga utmaningar.

- *Om det är lämpligt för speltypen* så kan en klient agera som "servern", t.ex. Kahoot eller Jackbox Games där en person har spelet på sin skärm, och andra spelare anslutar på sina enheter med en rumkod.
    - Detta kan också kombineras med `fs` för att se till att spelet inte dör ifall "server"-spelaren disconnectar av någon anledning.
- *Om det är lämpligt för speltypen*, en spelare som disconnectar ska få återuppta spelet från där hen lämnade.
- Validera spelarnas input, så att de inte kan fuska genom att ändra variabler på sin sida.

## Ska hela spelet vara klart till övning 7?

Om man jobbar riktigt bare-minimum så kan man säkert få ihop ett basic spel på en vecka som möter alla krav, men jag vill gärna att ni tar er tid och gör ett spel ni tycker om. Därför har jag planerat enligt följande:

- På övning 7 (fredagen efter tentaP) kommer ni få visa upp ert spel, men **spelet måste inte vara färdigt just då.**
- För task 8 (och task 9?) kommer ni få lägga till lite extra funktionaliteter till ert spel. Ni kan ta er tid och fixa klart spelet under de veckorna.