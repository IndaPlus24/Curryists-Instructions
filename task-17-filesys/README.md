# 🍾Task 17: (Fil)Systemet

Nu när vi har gått igenom en hel del assembly i de senaste tasksen hoppas jag att ni också känner hur vi börjar öppna upp den svarta lådan som är datorn och behärska hur saker fungerar ***på riktigt***. Men jag får motvilligt erkänna att det finns vissa saker i den svarta lådan som blir onekligen svårare att förstå om vi tittar på dem genom linsen av assemblyspråk. *För att gå vidare måste vi resa ut till länder där vi inte längre kommer att prata datorns språk, länder där vi kommer att finna mycket märkliga och mycket användbara verktyg och tekniker...*

Denna vecka har alla våra gemene INDA grupper lyckats ena sig kring ett och samma tema: datastrukturen träd. För att knyta ihop det med vår mission - att knäcka den svarta lådan som är datorn - finns det ett ämne som samlar allt detta inom ett paket: **filsystem**. Vi använder dem varje dag för att hålla ordning på vår data, och det räcker med att köra kommandot `tree` för att se hur de är uppbyggda som trädstrukturer.. Men de är också någonting som man tar för givet. Vad händer egentligen när man skapar en fil i en hierarkisk mappstruktur?

**Till task 17 har ni i uppgift att skapa en implementation av ett hierarkiskt filsystem!**
**OBS:** Ert filsystem behöver INTE gå att använda som ett riktigt filsystem som sparar filer till lagringen, ni kan reservera en bit minne i ert program och använda det för att skapa filer temporärt för uppgiftens skull.

## 📖 Resurser

### Byggstenarna av ett filsystem
- YouTube kanalen *CrashCourse* har en video där de går igenom byggstenarna av både filer och filsystem. Viktigaste delen för den här uppgiften är vid 4:49 och framåt, men de använder vissa begrepp som bara förklaras tidigare i videon:
[ Files & File Systems: Crash Course Computer Science #20 ](https://youtu.be/KN8YgJnShPM?si=mZ60XCnc3UG9oAi6)

- Denna korta video av kanalen *Udacity* förklarar hur en *file allocation table* och en *directory file* kan användas tillsammans för att kunna ladda in filer från ett lagringsutrymme:
[ File Allocation Table ](https://youtu.be/V2Gxqv3bJCk?si=svT-xfujyWgl3-uk)

### Hantera minne i strukturerade programmeringsspråk
- Ni borde redan ha en känsla för minneshantering efter det vi har jobbat med i assembly, men syntaxen för att göra samma sak i strukturerade programmeringsspråk kan kännas lite främmande beroende på vad ni har jobbat med tidigare. Kanalen *Low Level* har en video där han går väldigt grundligt igenom hur pekare och pekarsyntax fungerar i C: [ you will never ask about pointers again after watching this video ](https://youtu.be/2ybLD6_2gKM?si=3blrb6y-UaRbZCp3)

### *Structs*
- Structs, och koncept som bygger vidare på dem som objekt, kan göra den här uppgiften mycket lättare. Denna video från *Boot Dev* går kort och koncist igenom vad en struct egentligen är i C och hur man använder dem: [ What are Structs in C? ](https://youtu.be/7daqauCVJZg?si=weR96YdumSwHHsFH)

## 🏛 Uppgifter

### 17.1: Skrivna lösningar

(You may write your answers in English if you wish 🇬🇧)

**17.1.1:** Vilka är fördelarna och nackdelarna med att ett filsystem fragmenterar filer över många olika minnesblock?

**17.1.2:** Att hierarkiska filsystem är byggda på en trädstruktur innebär att vi kan använda algoritmer som [*breadth first search*](https://en.wikipedia.org/wiki/Breadth-first_search) och [*depth first search*](https://en.wikipedia.org/wiki/Depth-first_search) för att leta igenom dem. Om man börjar leta från root-mappen, vilken hade passat bäst för att hitta en fil och vilken hade passat bäst för att hitta en mapp?

### 17.2: Kodupppgifter 
Ni får implementera filsystemet i någon av följande språk:
- **C** (förmodligen enklast med det vi har gått igenom hittils)
- **Rust**
- **Zig** (gigachad)

Ni ska använda någon av dessa programmeringsspråk eftersom de stödjer manuell minneshantering! Vi vill ju förstå hur filsystemet faktiskt ser ut och används när vi tittar in i datorens komponenter 👀

**17.2.1:** Definiera ett enkelt filsystem. Det ska stödja följande krav:
- Filer ska kunna ha namn upp till minst 32 tecken långa.
- Det ska gå att ha åtminstone upp till 32 filer/mappar i en mapp

**17.2.2:** I ditt program där ditt filsystem körs ska du också implementera några kommandon för att faktiskt kunna använda filsystemet:

- `list` ska skriva ut de filerna/mappar som är i mappen man befinner sig i
- `cd` ska ändra den nuvarande mappen till en annan mapp som användaren specifierar.
- `maketxt` ska ta emot en sträng och skapa en textfil med den på filsystemet.
- `delete` ska låta användaren radera en fil från filsystemet.

**17.2.3 (frivillig)(+ 100 coolpoäng):** Återskapa funktionaliteten hos `tree` kommandot i Linux i ditt program som hanterar ditt filsystem.

## TODOs:
- [ ] Fördelar/nackdelar med fragmentering
- [ ] DFS vs BFS
- [ ] Definiera ett filsystem
- [ ] Använda filsystemet
- [ ] Farm cool points 😎

Om ni har några frågor, var inte rädda för att pinga mig på Discord! Ni kan alltid göra regularuppgiften om ni känner att jag har varit för elak med min plusuppgift den här veckan. Lycka till!!! 😁

---
## Syfte
Genom att ni nu har haft en uppgift i att koppla assemblerspråk til strukturerade programmeringsspråk ska ni nu ha en känsla för hur saker sker inuti datorn även när vi skriver kod på ett strukturerad programmeringsspråk som vi behöver kompileras. Vi knyter ihop temat av att förstå vad som händer inuti datorn med att gå vidare till ett strukturerad programmeringsspråk och med träd datastrukturer genom att förstå och implementera ett filsystem, någonting som både visar fördelarna med ett strukturerad programmeringsspråk och är tillräckligt lågnivå för att våra kunskaper om hur datorn fungerar ska komma till hjälp. 


