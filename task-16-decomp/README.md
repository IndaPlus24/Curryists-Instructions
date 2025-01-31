# ⚙️ Task 16: Reverse gear, reverse engineer

I förra veckans task lärde vi oss hur man använder en stack datastruktur i ett *riktigt* programmeringsspråk genom att strunta helt i en kompilator och skriva om C kod till assembly för hand. Att kunna göra det är onekligen coolt, men i den redan nischade jobbmarknaden för assemblyprogrammerare så är det en nisch inom en nisch att kunna skriva ett assemblyprogram från grunden.

En mycket vanligare uppgift för en assemblyprogramerare är att istället göra det omvända: att kunna tolka befintlig assemblykod och till och med skriva om det till ett högre nivå språk. 

**I den här uppgiften kommer vi att gå igenom konsten av *reverse engineering* och dekompilering av binära, exekverbara program.**

## 📖 Resurser

### Komma igång med MIPS assembly

- YouTube kanalen *Low Level* har en video där han går igenom hur man skriver Hello World i MIPS assembly på närmare 10 minuter: [ You Can Learn MIPS Assembly in 15 Minutes | Getting Started Programming Assembly in 2021 ](https://youtu.be/5AN4Fo0GiBI?si=3_p2_ve4ZiRswi7l)
- Datablad för alla standard 32-bitars MIPS instruktioner: [MIPS Reference Sheet](https://www.kth.se/social/files/563c63c9f276547044e8695f/mips-ref-sheet.pdf)

### Introduktion till reverse engineering

- YouTube kanalen *Low Level* har en video där han går igenom grunderna i reverse engineering: [  how reverse engineering makes you a better programmer  ](https://youtu.be/1d-6Hv1c39c?si=aMki87nLsFvh5QjF)

OBS i denna video dekompilerar han ett program kompilerad för ARM64, men det ger ändå en bild över tankesättet man ska ha för reverse engineering. 

### Mjukvara

- För att kunna dekompilera de binära filerna ni har fått i era repon måste ni använda en dekompilerare för MIPS assembly. Om ni kör en debianbaserad linuxutgåva kan ni ladda ner paketet [`binutils-mips-linux-gnu`](https://manpages.debian.org/bullseye/binutils-mips-linux-gnu/index.html) så får ni tillgång till kommandot `mips-linux-gnu-objdump` som kan hantera program kompilerade för MIPS. För att dekompilera ett program kör man följande kommando:
```shell
$ mips-linux-gnu-objdump -d min_fil
```
Detta kommer att skriva ut assemblyinstruktionerna som filen innehåller till terminalen. Du kan spara det till en fil genom att använda `>` operatorn i kommandotolken:
```shell
$ mips-linux-gnu-objdump -d min_fil > min_fil.S
```
Det finns mer avancerade dekompilatorer (t.ex. Ghidra, IDA) som kan ta assemblykod och vidare dekompilera den till ett högre nivå språk (exempelvis C). **Ni får inte använda en dekompilerare för att direkt generera icke-assembly kod från den binära filen!**


## 🏛 Uppgifter

### 15.1: Skrivna lösningar

(You may write your answers in English if you wish 🇬🇧)

**15.1.1**: Vad är ett praktiskt användningsområde för att kunna dekompilera mjukvara och tolka assemblykod? Ge minst ett exempel.

**15.1.2**: Finns det sätt som man kan kompilera mjukvara på som kan göra det svårare att dekompilera? 

### 15.2: Kodupppgifter 

**15.2.1:** Skriv om den binära filen `mystery_box_1` på valfritt språk. Det kan till och med vara pseudokod, i så fall kan ni lämna svaren i `docs/`. Viktigast är att du visar att du förstår vad den exekverbara filen gör genom att beskriva det.

**15.2.2:** Gör samma för `mystery_box_2`.

**15.2.3 (frivillig) (SVÅR) (men ändå cool): Gör samma för** `mystery_box_3`

## TODOs:
- [ ] 15.1.1 Dekompilering användningsområden
- [ ] 15.1.2 Kan det bli svårare? (😭)
- [ ] 15.2.1 Dekompilering 1
- [ ] 15.2.2 Dekompilering 2
- [ ] 15.2.3 Establish dominance.

Om ni har några frågor, var inte rädda för att pinga mig på Discord! Ni kan alltid göra regularuppgiften om ni känner att jag har varit för elak med min plusuppgift den här veckan. Lycka till!!! 😁
