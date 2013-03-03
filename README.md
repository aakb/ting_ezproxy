Ting Ezproxy Authentication
============

Modulet benyttes til at authenticere brugeren i forbindelse med Ezproxy.

Ezproxy er en proxy-server der benyttes til at stille databaser til rådighed for kommunens biblioteks-brugere.

Brugeren starter på ting-sitet hvor der er link til databasen - enten til selve databasen eller dybe link til konkrete artikler/sider m.m.

Disse link går via Ezproxy, som før linket kan proxies, kræver at brugeren er authenticeret og denne opgave overdrages til nærværende modul.
Brugeren logger ind, det valideres om man er bosat i kommunen og kontrollen gives endeligt tilbage til Ezproxy.

Dette sker kun første gang (pr session) - de efterfølgende link fra ting-sitet bliver proxiet med det samme.

Valideringen sker på basis af lånerkategorier og evt. blokeringskoder der afleveres af Alma.
Modulet kræver [patch til AlmaClient.class.php](https://github.com/bombycilla/alma/commit/83d96e26f8795d0ad676d08179a180263d6fc4fe) så lånerkategorier kan håndteres.

Der er 4 "skærmbilleder" som skal configureres:

1) hvor loginformen indsættes. Her bør betingelser o.lign. præsenteres. Man logger ind og sendes til 2). Bemærk at 1) kun vises hvis man ikke er logget ind på ting-sitet.

2) vises når man er logget ind og indeholder det endelige link til Ezproxy. Betingelser o.lign præsenteres også her (da 1) ikke altid ses af brugeren). Det er dog muligt at slå visning af 2) fra, således at man sendes direkte til ezproxy efter login.

3) vises hvis man ikke er bosat i kommunen, dvs ikke har de korrekte lånerkategorier.

4) vises hvis man er blokeret, er redaktør eller der i øvrigt er fejl i forbindelse med login.

Linket på 2) er oprettet via Ezproxys Ticket-metode og kræver mindst Ezproxy version XX.
Opsætning er beskrevet på http://www.oclc.org/support/documentation/ezproxy/usr/cgi.htm
Bemærk at urlen skal encodes via "^R" - ellers risikerer man at drupal får encodet/decodet de forkerte dele af urlen.

Opsætning af Ezproxy kræver følgende i user.txt

```
::CGI=http://TING-SITE/ezproxy_authentication?url=^R
::Ticket
AcceptGroups CITIZENUSERGROUP
TimeValid 10
MD5 SECRET
Expired; Deny expired.htm
/Ticket
```

Værdien af CITIZENUSERGROUP skal svare til indstillingerne i modulet her og i config.txt. Kan udelades men dette er ikke testet.

En SECRET af passende længde vælges med omhu og indtastes i administrationen.

Lokalt på ezproxy-serveren findes en default udgave af expired.htm som kan tilrettes hvis ønskeligt.
Urlen fra 2) har en tidsbegrænsning bestemt af TimeValid (her 10 minutter).
