ting_ezproxy
============

Modulet benyttes til at validere l�neren i forbindelse med ezproxy.

L�neren godkendes p� basis af relevante l�nerkategorier og evt. blokeringskoder.
Modulet kr�ver patch til AlmaClient.class.php s� l�nerkategorier kan h�ndteres.

Ezproxy skal s�ttes op som beskrevet p� CGI Authentication, http://www.oclc.org/support/documentation/ezproxy/usr/cgi.htm
dog med den begr�nsning at urlen skal encodes via "^R"

Fra Ezproxy user.txt:

```
::CGI=http://DINGHOST/ezproxy_authentication?url=^R
::Ticket
AcceptGroups CITIZENUSERGROUP
TimeValid 10
MD5 SECRET
Expired; Deny expired.htm
/Ticket
```

V�rdien af CITIZENUSERGROUP og SECRET benyttes i n�rv�rende administration

