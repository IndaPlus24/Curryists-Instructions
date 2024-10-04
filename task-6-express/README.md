<img src="https://media1.tenor.com/m/Dyh8HqynJTMAAAAC/neocities-button-neocities.gif" align="right" width="300" />

# 🍛 task 6: Return to Web 1.0

Välkommen till webbprogrammering! Det är ett fantastiskt landskap
med väldigt mycket att se. I den här tasken kommer ni att få bygga
en liten hemsida med en väldigt väldigt enkel API.

## Lästips

- [Google slides för övningen](https://docs.google.com/presentation/d/1dS0GeYya1fXAtcMGjeh4oprPL8zBRv2Rx_SCZGbmSuQ/edit?usp=sharing)
- Del I
    - [W3Schools](https://www.w3schools.com/) har många bra tutorials och är en lämplig plats att börja lära sig webbprogramming.
    - [MDN Web Docs](https://developer.mozilla.org/) är världens bästa dokumentation för (vanilla) HTML/CSS/JS. Testa söka här om du kör fast.
    - [Fireships JavaScript in 100 seconds](https://www.youtube.com/watch?v=DHjqpvDnNGE) (visas på övningen)
- Del II
    - [Fireships RESTful API in 11 minutes](https://www.youtube.com/watch?v=-MTSQjw5DrM) (visas på övningen)
        - (Kanske lite överkurs...? Det är inte nödvändigt att installera Insomnia (som används i videon för att visualisera API calls) eftersom vi håller på med mycket enkla API:er, men du får gärna använda den om du tycker att det underlättar.)

## Koduppgifter

### Del I: Web 1.0

1. Skapa en hemsida som består av tre sidor: `index.html`, `time.html`, `write.html`. Skapa även `style.css` som importeras av alla tre sidor.
2. Skapa en `<header>`-element som består av länkar i en rad. Med dem ska användaren kunna navigera mellan de tre sidorna.
    - `<a>`-elementen ska vara större än den lilla länktexten (rimligtvis som `inline-block`?), annars är det ganska svårt att klicka från t.ex. mobilen.
    - För enkelhetens skull implementerar vi inte elementet som komponent än, så när du har skrivit elementet kan du copypastea den in i varje HTML-fil. Däremot ska CSS-stylen för elementet ligga i det gemensamma `style.css`.
3. Huvudinnehållet i `index.html` ska vara <a href="https://http.cat/200.jpg" target="_blank">den här bilden</a> (eller vilken bild/gif du vill så länge det inte är överdrivet stort) samt en länk till <a href="https://www.youtube.com/watch?v=xvFZjo5PgG0" target="_blank">den här videon</a> (eller vilken extern sida du vill).
    - Båda elementen ska vara horisontellt centrerade i mitten av skärmen. Det går att fixa med t.ex. `flexbox` men det är överkurs för denna task, det räcker med att sätta `margin`.
    - Definiera med CSS en maximal bredd på bilden. Detta gör att bildens storlek skalar med skärmens storlek.
4. I `time.html` ska det finnas en `<script>`-tagg som använder `setInterval()`-metoden för att anropa en funktion varje sekund.
    - Den här funktionen ska ändra på ett textelements `innerHTML` sådant att den visar hur lång tid man har spenderat på sidan.
        - Till exempel, när man öppnar sidan ska det stå `0:00` på sidan, och varje gång funktionen kallas ökar timern med 1 sekund.
        - Notera att sekundvisaren ska alltid ha två siffror (så den ska börja på 0 om sekunden är ensiffrig), och när den är 60 ska minutvisaren incrementeras. Du behöver inte hantera timmar, så minutvisaren får gå över 60.
    - I samma funktion ska den ändra på ett annat textelement för att visa den nuvarande tiden på användarens enhet, ner till sekunden. Tiden ska vara formatterad till att vara mänskligt läsbar, så du får inte bara skriva ut ett Unix timestamp. (Visa datum är frivilligt.)
        - Tips: Det finns en väldigt enkel lösning som involverar `Date()`.
5. I `write.html` ska det finnas en `<input>`, en `<button>` och en `<ul>`. Skapa även en `write.js` i samma mapp som importeras av sidan: här ska all JS-kod för sidan ligga.
    - När man trycker på knappen ska den kalla på en JS-funktion som läser värdet i `<input>`-fältet. Sedan skapas en ny listelement i `<ul>`, vars innehåll är värdet. Slutligen ska `<input>`-fältet tömmas.
    - Det nya listelementet ska ligga längst upp i listan.
    - Om `<input>`-fältet är tomt ska funktionen istället visa i röd text (någonstans på sidan) att input saknas. Denna varningstext varar tills nästa gång användaren lyckas skriva in ny text till listan.

Allt som inte står specificerade ovan (CSS, layout, annat text och bilder, mobile compatibility etc) får du implementera & lägga till hur du vill!

### Del II: Cats cats cats

Förberedelser:

1. Installera NodeJS här: https://nodejs.org/en
2. Öppna terminalen i `src`-mappen och skapa en NodeJS-projekt med `npm init -y`.
    - `-y` betyder att du accepterar alla default-värde: du kan köra utan den om du vill se alla alternativ.
3. Se till att alla filer du skapat i Del I är i din projektmapp. Om inte, flytta in dem.
4. Lägg till express genom att köra `npm i express` i mappen.

Actual uppgift:

1. Skapa en rutt `/wisdom` och en array av minst 3 strängar (vad som helst). När användaren besöker rutten ska hen få en random sträng, rimligtvis med `res.send()`.
2. Skapa rutterna `/`, `/time` och `/write`. När användaren besöker dessa rutter ska hen få se motsvarande HTML-sida. (`index.html` motsvarar `/`.)
3. Skapa en rutt `/cat/:code`. När användaren besöker rutten returneras en HTML-sida vars enda element är bilden `https://http.cat/CODE.jpg` (där "CODE" är parametern som användaren skrev in).

## Teorifrågor

1. Vad är skillnaden mellan en "weakly typed" och en "strongly typed" språk? (Eller "weak typing" vs "strong typing")

2. Förklara varför det här returnerar sant i JS: `0 == []`