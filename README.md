Ting Ezproxy Authentication
============

Modulet benyttes til at authenticere brugeren i forbindelse med Ezproxy.

Ezproxy er en proxy-server der benyttes til at stille databaser til r�dighed for kommunens biblioteks-brugere.

Brugeren starter p� ting-sitet hvor der er link til databasen - enten til selve databasen eller dybe link til konkrete artikler/sider m.m.

Disse link g�r via Ezproxy, som f�r linket kan proxies, kr�ver at brugeren er authenticeret og denne opgave overdrages til n�rv�rende modul.
Brugeren logger ind, det valideres om man er bosat i kommunen og kontrollen gives endeligt tilbage til Ezproxy.

Dette sker kun f�rste gang (pr session) - de efterf�lgende link fra ting-sitet bliver proxiet med det samme.

Valideringen sker p� basis af l�nerkategorier og evt. blokeringskoder der afleveres af Alma.
Modulet kr�ver [patch til AlmaClient.class.php](https://github.com/bombycilla/alma/commit/83d96e26f8795d0ad676d08179a180263d6fc4fe) s� l�nerkategorier kan h�ndteres.

Der er 4 "sk�rmbilleder" som skal configureres:

1) hvor loginformen inds�ttes. Her b�r betingelser o.lign. pr�senteres. Man logger ind og sendes til 2). Bem�rk at 1) kun vises hvis man ikke er logget ind p� ting-sitet.

2) vises n�r man er logget ind og indeholder det endelige link til Ezproxy. Betingelser o.lign pr�senteres ogs� her (da 1) ikke altid ses af brugeren). Det er dog muligt at sl� visning af 2) fra, s�ledes at man sendes direkte til ezproxy efter login.

3) vises hvis man ikke er bosat i kommunen, dvs ikke har de korrekte l�nerkategorier.

4) vises hvis man er blokeret, er redakt�r eller der i �vrigt er fejl i forbindelse med login.

Linket p� 2) er oprettet via Ezproxys Ticket-metode og kr�ver mindst Ezproxy version XX.
Ops�tning er beskrevet p� http://www.oclc.org/support/documentation/ezproxy/usr/cgi.htm
Bem�rk at urlen skal encodes via "^R" - ellers risikerer man at drupal f�r encodet/decodet de forkerte dele af urlen.

Ops�tning af Ezproxy kr�ver f�lgende i user.txt

```
::CGI=http://TING-SITE/ezproxy_authentication?url=^R
::Ticket
AcceptGroups CITIZENUSERGROUP
TimeValid 10
MD5 SECRET
Expired; Deny expired.htm
/Ticket
```

V�rdien af CITIZENUSERGROUP skal svare til indstillingerne i modulet her og i config.txt. Kan udelades men dette er ikke testet.

En SECRET af passende l�ngde v�lges med omhu og indtastes i administrationen.

Lokalt p� ezproxy-serveren findes en default udgave af expired.htm som kan tilrettes hvis �nskeligt.
Urlen fra 2) har en tidsbegr�nsning bestemt af TimeValid (her 10 minutter).
