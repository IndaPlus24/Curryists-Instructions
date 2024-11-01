<img src="https://media1.tenor.com/m/fCr2RtR8H3QAAAAC/terminator-sunglasses.gif" align="right" width="300" />

# 🍛 task 8: Localized AI uprising

Året är 2027, och [Dead Internet Theory](https://en.wikipedia.org/wiki/Dead_Internet_theory) är nu allmänt känt som sanning. För att blåsa upp spelarsiffran har de flesta spelföretag infört massvis med AI-spelare, och matcher spelas 24/7 utan mänskliga interaktioner.

[Den realiteten är vi på väg mot](https://www.youtube.com/watch?v=YCqnD40Q5T8), men vi kan skynda på resan mot vår egen förintelse genom att själv införa AI-spelare i våra spel.

> [!IMPORTANT]
> **Uppgiften är en fortsättning av task 7.** Ni ska alltså fortsätta utveckla spelet. Om ni inte är färdig med "bas-spelet" så kan ni också fortsätta med det.

## Lästips

Inget nytt information! Se förra veckans README för länkar.

### Parprogramming

Som nämnt förra veckan, ni uppmuntras att använda er av parprogramming, dock så är det inte krav. Läs mer om parprogrammering [här](https://www.csc.kth.se/tcs/projects/cerise/parprogrammering/) (Viggos text) eller [här](https://docs.google.com/presentation/d/1EqzllrCRI6eMPgXCrsd5rBgkSNi6n0BNFQrEhIsXNI8/edit#slide=id.g30a56e61277_0_14) (min sammanfattning).

## Koduppgift

Tasken är en fortsättning av spelet ni gjorde förra veckan. Ni ska alltså, förutom grundkraven från förra veckan, också uppnå följande nya krav:

- Spelet ska kunna populeras med AI-spelare. Nedan är några förslag på hur det kan gå till med olika speltyper:
    - För ett MMO- eller open world-liknande spel: Det kan finnas en adminpanel eller konsol där man kan ge kommando för att skapa och ta bort AI-spelare från spelvärlden.
    - För ett typiskt brädspel med begränsat antal spelare: Den mänskliga spelaren väljer antalet spelare som ska ersättas med AI innan spelet börjar.
- En AI-spelare interagerar med spelet på samma sätt som en mänsklig spelare kan. De behöver såklart inte vara *bra* på spelet eller ens veta vad de håller på med, men de bör inte kunna göra saker som vanliga spelare inte kan.

Här kommer också några frivilliga förslag som ni kan implementera (inte krav):

- Skriv flera olika algoritmer för AI-spelarna att följa, och admin/spelaren kan bestämma vilken algoritm som används. Till exempel, för en brädspelsmotståndare är det bra om spelaren kan välja svårighet (hur smart AI:n är).