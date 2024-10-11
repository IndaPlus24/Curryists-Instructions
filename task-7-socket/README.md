<img src="https://media1.tenor.com/m/1u15ulrFh1EAAAAC/asc.gif" align="right" width="300" />

# 🍛 task 7: The peer-to-peer experience

Som det gamla ordspråket lyder, "two heads are better than one." Den här tentaperioden (plus veckan efter) (mest veckan efter, jag vill inte be er parprogrammera under tentaP) ska vi ta reda på om påståendet är sant genom påtvingat samarbete, där ni ska få göra en hemsida som i sin tur utsätter användarna för påtvingat samarbete. It's the circle of life.

## Lästips

- [Google slides för övningen](https://docs.google.com/presentation/d/1EqzllrCRI6eMPgXCrsd5rBgkSNi6n0BNFQrEhIsXNI8/edit?usp=sharing)
- [Our lord and savior Viggo Kann: om parprogrammering](https://www.csc.kth.se/tcs/projects/cerise/parprogrammering/)
- [Fireship: WebSockets & socket.io](https://www.youtube.com/watch?v=1BfCnjr_Vjg)
- [En liten IRC-chatt jag gjorde i gymnasiet](chat_example/)

## Koduppgift

Det finns mycket rum för personlighet i uppgiften den här veckan, så ta chansen och göra något kul! Som minimumkrav vill jag se följande:

- I ett par ska ni skapa en spel-likt plattform som användarna kan ansluta sig till via webbläsaren.
- På plattformen ska användarna kunna kommunicera med varandra på något vis.
- Denna kommunikation ska, för vissa bestämda villkor, leda till något utfall. Till exempel, om alla användare trycker på en knapp, så ändras bakgrundsfärgen för alla användare.
- Med dessa utfall, bestäm någon sorts "win/loss condition", så att man kan "vinna" eller "förlora" enligt er definition av vad det innebär.

**Frivilliga tillägg:**
- Om ni vill så kan ni lagra data i en databas, t.ex. MySQL. Annars är det fine att data endast sparas på client-side och rensas vid refresh.
- Ni kan försöka validera användarens input, så att de t.ex. inte kan fuska genom att ändra variabler på sin sida.