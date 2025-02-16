# 🖧 Task 18: The Not-Particularly-Social Network
Från länkade listor till stackar och träd, alla dessa datastrukturer bygger på att man kan sammanlänka noder med kanter. Den här veckan tar vi det konceptet och tittar på dess *final form*: **Grafer**.

Grafer kan i princip användas för att modellera allt där disjunkta saker är kopplade till varandra på något sätt. Allt från busshållplatser i en stad, till vänner i en vänkrets, till mer nischade saker som olika tillstånd i ett program (se [*State Diagram*](https://en.wikipedia.org/wiki/State_diagram)). Grafer är väldigt applicerbara i många situationer, och på grund av det är det viktigt att vi förstår hur vi navigerar dem effektivt, speciellt inom datorvärlden där vi finner en av de mest vanligt förekommande användningar för grafmodeller: **Nätverk**. 

Att datorer kan kommunicera med varandra i ett nätverk är ett hörnsten i hur vi använder datorer idag. Hela internet är ett slags nätverk mellan större delen av alla världens datorer. Denna vecka ska ni **skriva ett program som kommer låta era datorer kommunicera med varandra över ett lokalt nätverk!**

## 📖 Resurser

### Komma igång med nätverksprogrammering
Denna YouTube video av Handy Scripts visar kort hur man skapar program i C för att både skicka och att ta emot ett meddelande över ett nätverk: [ *The Most Simple UDP Client Server Program In C!* ](https://youtu.be/lUyaV4haBUE?si=DN5ousgCXZ9t3T6O)

Notera att han skriver två olika program: en *server* och en *klient*.  I vanliga fall är skillanden mellan en server och en klient att en klient skickar meddelanden till servern först, och servern lyssnar efter meddelanen, behandlar dem och skicar tillbaka resultatet. I videon skickas dock inte informationen tillbaka till klienten, utan servern tar emot meddelandet och behandlar den (genom att printa den till terminalen). 

YouTube videon [*How to Send and Recieve UDP Packets*](https://youtu.be/5PPfy-nUWIM?si=WS5U8Xmii3HSTYnh) av Jacob Sorber  är ett till exempel på hur man skriver ett program för att ta emot och skicka meddelanden över ett nätverk (med UDP). Den här videon är lite längre och han förklarar vissa av begreppen/koncepten under tiden han skriver programmet.

### Begrepp
Det finns många nya begrepp inom nätverksprogrammering om man kommer in i det för första gången. Videon [*Sockets & Ports - Simply Explained in 2 Minutes*](https://youtu.be/8zS7CaFCH0c?si=Rk9afTHGwPvWDVCm) av Logic Hive går igenom två av de viktigaste begreppen att förstå till uppgiften. 

Ni kanske märker i skelettkoden att det finns en lite mysterisk variabel `sockfd`. Det står alltså för *socket file descriptor*, vilket är en ID (lagrad som en `int`) som operativsystemet använder för att man ska komma åt en socket. Videon [ *Sockets and Pipes Look Like Files (Unix/fdopen)* ](https://youtu.be/il4N6KjVQ-s?si=zvIeNVROHtSqJ1OK) av Jacob Sorber förklarar hur file descriptors är kopplade till hur vi använder sockets i C. För mer information om vad en file descriptor är, titta igenom videon  [ *POSIX File Descriptors* ](https://youtu.be/D22yMLXmols?si=5llNXj7JlJLGbSYv) av kanalen programming101.

## 🏛 Uppgifter

### 18.1: Skrivna lösningar

(You may write your answers in English if you wish 🇬🇧)

**18.1.1:** Förklara skillnaderna mellan hur en graf över en nätverk som använder en server och flera klienter och en nätverk där datorer kommunicerar fritt mellan varandra (peer-to-peer) skulle se ut.

**18.1.2:** I den här uppgiften jobbar vi med en *oviktad* graf; vi har inte bestämt någon kostnad för att ansluta till någon över nätverket. Till skillnad från uppgiften är "kostnaden" för att kommunicera mellan två noder (oftast en tidskostnad) i ett datornätverk väldigt viktigt. Ge ett exempel på en metod som används för att hitta det effektivaste sättet (kostar minst) att ta sig mellan två noder i ett nätverk.

### 18.2: Kodupppgifter 
I kodskelettet för uppgiften (finns i `src/`) finns det ett antal `TODO`s, så er uppgift den här veckan går mest ut på att fylla i det som saknas där. Men i punktform kan det mer eller mindre skrivas som:

**Implementera följande kommandon i ditt program:**

**18.2.1:** `discover`: skickar ett broadcast-meddelande över nätverket för att hämta användarnamnen och IP-addresserna till alla på nätverket.

**18.2.2:** `connect <username>`: skapar en anslutning (riktad kant) mellan din dator och datorn hos den anvgivna användaren.

**18.2.3:** `find <username>`: returnerar en lista över anslutningar mellan din dator och datorn hos den angivna datorn. Exempel: `john` är ansluten till `mark`, och `mark` är ansluten till `luke`. `john` kör `find luke` och får utskriften i terminalen: `john -> mark -> luke`

**OBS** Denna gång är alla koduppgifterna obligatoriska!

## TODOs:
- [ ] Implementera `discover`
- [ ] Implementera `connect`
- [ ] Implementera `find`

Om ni har några frågor, var inte rädda för att pinga mig på Discord! Ni kan alltid göra regularuppgiften om ni känner att jag har varit för elak med min plusuppgift den här veckan. Lycka till!!! 😁

---
## Syfte
Syftet med uppgiften är att koppla systemprogrammering med lägrenivåsspråk som C med datorstrukturen grafer genom att visa hur datornätverk kan arbetas med som en graf och hur vi kan använda grafteoretiska koncept (som sökalgoritmer för grafer) för att arbeta med en datornätverk. Att jobba med uppgiften ska också ge en förståelse för grunderna i nätverksprogrammering. 
