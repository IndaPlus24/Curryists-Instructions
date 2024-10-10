Det här är en hemsida jag tror att jag gjorde för webbserverprogramming, en kurs jag läste i gymnasiet. Om ni vill så kan ni använda koden som stöd.

För att starta hemsidan på `localhost:5000`, kom ihåg att först installera paketen med `npm i`, sedan köra `node source.js`.

MySQL-koden i `source.js` är utkommenterad eftersom den inte är relevant för just uppgiften, men den borde kunna användas om en databas skapas med följande instruktioner:
```sql
CREATE DATABASE IF NOT EXISTS irc CHARACTER SET ascii;
USE irc;
CREATE TABLE IF NOT EXISTS res (
	ifthis VARCHAR(64) NOT NULL,
    thenthat VARCHAR(128) NOT NULL
);
INSERT INTO res (ifthis, thenthat) VALUES ('hello system', 'Hello, %u!');
INSERT INTO res (ifthis, thenthat) VALUES ('help', '%u, consider visiting our help center at: https://example.com/');
INSERT INTO res (ifthis, thenthat) VALUES ('ping', 'Pong!')
```