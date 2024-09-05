# Curryists-Instructions
Uppgiftsbeskrivningar och allmänna kursinformation för plusgruppen "Curryists".

### Kurslitteratur
- Learn You a Haskell for Great Good!
  - [Originalsidan](https://learnyouahaskell.com/) saknar CSS och ser ful ut. Använd [denna arkiverad länk](https://archive.is/qvoOT) istället

### Hur lämnar jag in mina lösningar?

1. Hitta din repo med motsvarande task-siffra på [KTH GitHub](https://gits-15.sys.kth.se/inda-24/).
2. Clone:a repot till din dator.
3. Lägg in dina lösningar i repot. Lägg kod under `/src` och textsvar under `/docs` (skapa mappen om den inte finns).
5. Pusha den.

Det är såklart alltid okej att göra Regular-tasks om du inte känner för att göra veckans Plus-task.

## Haskell quick start

### Installation

Om du kör på Linux, eller WSL (Windows Subsystem for Linux) på Windows:
```bash
sudo apt install ghc
```
Om du kör på MacOS:
```bash
homebrew install ghc
```

### Köra Haskell-kod med GHCI

GHCi är en interaktiv miljö för GHC (Glasgow Haskell Compiler). Efter du har installerat GHC så kan du starta GHCi genom att skriva `ghci` i terminalen.

När du är inne i GHCi så kan du börja definiera och kalla på funktioner direkt, rad för rad. Här är några användbara kommandon:
- `:l <filnamn>.hs` för att ladda in en Haskell-fil. Du behöver göra det här innan du kan kalla på funktioner i filen.
- `:set +s` gör så att alla funktionsanrop returnerar även hur mycket tid det tog att köra anropet.

### Haskell exempelfil

```haskell
-- definierar funktionen helloworld, som returnerar "hello world!"
helloworld = "hello world!"

-- definierar funktionen factorial, som tar ett heltal och returnerar dess fakultet.
factorial :: Integer -> Integer -- man måste inte skriva typsignaturet, men det gör funktionen mer lättläslig.
factorial x = if x == 0
            then 1
            else x * factorial (x-1)
```
