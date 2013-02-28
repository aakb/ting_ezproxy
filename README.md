ting_ezproxy
============

Modulet benyttes til at validere låneren i forbindelse med ezproxy.

Låneren godkendes på basis af relevante lånerkategorier og evt. blokeringskoder.
Modulet kræver patch til AlmaClient.class.php så lånerkategorier kan håndteres.

Ezproxy skal sættes op som beskrevet på CGI Authentication, http://www.oclc.org/support/documentation/ezproxy/usr/cgi.htm
dog med den begrænsning at urlen skal encodes via "^R"

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

Værdien af CITIZENUSERGROUP og SECRET benyttes i nærværende administration

